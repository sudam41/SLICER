#include "DCT2.h"

#include "sim_api.h"

channel_t AnonFilter_a0Buf;
channel_t AnonFilter_a1Buf;
iDCT_1D_reference_fine_t iDCT_1D_reference_fineBuf[2*TheGlobal_SIZE];

buffer_float_t mid_buffer;

void  dct2_idct_1d_reference_fine(int index) { // DCT2.str:344
	SimNamedMarker(5, __func__);
    FOR(uint32_t, x, 0, <, TheGlobal_SIZE, x++) // DCT2.str:345
        float tempsum = 0; // DCT2.str:346
        FOR(uint32_t, u, 0, <, TheGlobal_SIZE, u++) // DCT2.str:347
            tempsum += (iDCT_1D_reference_fineBuf[index].coeff[x][u] * peek_float (&(iDCT_1D_reference_fineBuf[index].buffer_in), u)); // DCT2.str:348
        ENDFOR
        push_float (&(iDCT_1D_reference_fineBuf[index].buffer_out), tempsum); // DCT2.str:350
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, i++) // DCT2.str:354
        pop_float (&(iDCT_1D_reference_fineBuf[index].buffer_in)); // DCT2.str:354
    ENDFOR
}

void  dct2_printer() { // DCT2.str:96
	SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE*TheGlobal_SIZE , i++)
        push_float (&AnonFilter_a0Buf.buffer_out, ((float )(pop_int (&FileReaderBufInt)))); // DCT2.str:97
    ENDFOR
}
void  dct2_writer() { // DCT2.str:103
	SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE*TheGlobal_SIZE , i++)
        push_int(&FileWriterBufInt, ((int )(floor((pop_float (&AnonFilter_a1Buf.buffer_in) + 0.5f))))); // DCT2.str:104
    ENDFOR
}

void  dct2_init() { // DCT2.str:34
    FileReader_init(TheGlobal_FILEIN, "int");
    init_buffer_float(&AnonFilter_a0Buf.buffer_out);
    
    //Y reference
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, i++) // DCT2.str:180
        FOR(uint32_t, x, 0, <, TheGlobal_SIZE, (x)++) // DCT2.str:335
            FOR(uint32_t, u, 0, <, TheGlobal_SIZE, (u)++) // DCT2.str:336
                float Cu = 1; // DCT2.str:337
                if (u == 0) { // DCT2.str:338
                    Cu = (1 / sqrt(2)); // DCT2.str:338
                }
                iDCT_1D_reference_fineBuf[i].coeff[x][u] = ((0.5f * Cu) * cos((((u * 3.141592653589793f) * ((2.0f * x) + 1)) / (2.0f * TheGlobal_SIZE)))); // DCT2.str:339
            ENDFOR
        ENDFOR
        init_buffer_float(&(iDCT_1D_reference_fineBuf[i].buffer_in));
        init_buffer_float(&(iDCT_1D_reference_fineBuf[i].buffer_out));
    ENDFOR
    
    //X reference
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, (i)++) // DCT2.str:169
        FOR(uint32_t, x, 0, <, TheGlobal_SIZE, (x)++) // DCT2.str:335
            FOR(uint32_t, u, 0, <, TheGlobal_SIZE, (u)++) // DCT2.str:336
                float Cu = 1; // DCT2.str:337
                if (u == 0) { // DCT2.str:338
                    Cu = (1 / sqrt(2)); // DCT2.str:338
                }
                iDCT_1D_reference_fineBuf[TheGlobal_SIZE+i].coeff[x][u] = ((0.5f * Cu) * cos((((u * 3.141592653589793f) * ((2.0f * x) + 1)) / (2.0f * TheGlobal_SIZE)))); // DCT2.str:339
            ENDFOR
        ENDFOR
        init_buffer_float(&(iDCT_1D_reference_fineBuf[TheGlobal_SIZE+i].buffer_in));
        init_buffer_float(&(iDCT_1D_reference_fineBuf[TheGlobal_SIZE+i].buffer_out));
    ENDFOR
    
    init_buffer_float(&(AnonFilter_a1Buf.buffer_in));
    FileWriter_init(TheGlobal_FILEOUT, "int");
    init_buffer_float(&mid_buffer);
}

void dct2_split_round_robin_y() {
	SimNamedMarker(5, __func__);

    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, (i)++)
        FOR(uint32_t, j, 0, <, TheGlobal_SIZE, (j)++)
            // -- we use the jth buffer to spread the work
            push_float(&(iDCT_1D_reference_fineBuf[j].buffer_in), pop_float(&AnonFilter_a0Buf.buffer_out));
        ENDFOR
    ENDFOR
}
void dct2_join_round_robin_y() {
	SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, (i)++)
        FOR(uint32_t, j, 0, <, TheGlobal_SIZE, (j)++)
            push_float(&mid_buffer, pop_float(&(iDCT_1D_reference_fineBuf[i].buffer_out)));
        ENDFOR
    ENDFOR
}

void dct2_split_round_robin_x() {
	SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, (i)++)
        FOR(uint32_t, j, 0, <, TheGlobal_SIZE, (j)++)
            // -- we use the jth buffer to spread the work
            push_float(&(iDCT_1D_reference_fineBuf[TheGlobal_SIZE+j].buffer_in), pop_float(&mid_buffer));
        ENDFOR
    ENDFOR
}
void dct2_join_round_robin_x() {
	SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_SIZE, (i)++)
        FOR(uint32_t, j, 0, <, TheGlobal_SIZE, (j)++)
            push_float(&AnonFilter_a1Buf.buffer_in, pop_float(&(iDCT_1D_reference_fineBuf[TheGlobal_SIZE+i].buffer_out)));
        ENDFOR
    ENDFOR
}

int main(int argv, char** argc) {
    dct2_init();
    
    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        FileReader(TheGlobal_SIZE*TheGlobal_SIZE);
        dct2_printer();
        dct2_split_round_robin_y(); // DCT2.str:179
        FOR(uint32_t, i, 0, <, TheGlobal_SIZE, i++) // DCT2.str:180
            dct2_idct_1d_reference_fine(i);
        ENDFOR
        dct2_join_round_robin_y(); // DCT2.str:183
        
        dct2_split_round_robin_x(); // DCT2.str:168
        FOR(uint32_t, i, 0, <, TheGlobal_SIZE , i++) // DCT2.str:169
            dct2_idct_1d_reference_fine(TheGlobal_SIZE+i);
        ENDFOR
        dct2_join_round_robin_x(); // DCT2.str:172
        dct2_writer();
        FileWriter(TheGlobal_SIZE*TheGlobal_SIZE);
    ENDFOR
    
    FileReader_close();
    FileWriter_close();
    
    return EXIT_SUCCESS;
} 
