#include "FFT4.h"

channel_t IdentityBuf;
channel_t MultiplyBuf;
channel_t Transit2Buf;
channel_t TransitBuf;
channel_t AddBuf;
channel_t SubtractBuf;

void fft4_source() { // FFT4.str:45
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&TransitBuf.buffer_out, 1.0); // FFT4.str:46
    ENDFOR
}
void fft4_identity() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&IdentityBuf.buffer_out, pop_float(&IdentityBuf.buffer_in));
    ENDFOR
}
void fft4_multiply() { // FFT4.str:52
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&MultiplyBuf.buffer_out, (2 * pop_float(&MultiplyBuf.buffer_in))); // FFT4.str:53
    ENDFOR
}
void fft4_add() { // FFT4.str:58
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&AddBuf.buffer_out, (peek_float(&AddBuf.buffer_in, 0) + peek_float(&AddBuf.buffer_in, 1))); // FFT4.str:59
        pop_float(&AddBuf.buffer_in); // FFT4.str:60
        pop_float(&AddBuf.buffer_in); // FFT4.str:61
    ENDFOR
}
void fft4_subtract() { // FFT4.str:66
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&SubtractBuf.buffer_out, (peek_float(&SubtractBuf.buffer_in, 0) - peek_float(&SubtractBuf.buffer_in, 1))); // FFT4.str:67
        pop_float(&SubtractBuf.buffer_in); // FFT4.str:68
        pop_float(&SubtractBuf.buffer_in); // FFT4.str:69
    ENDFOR
}
void fft4_float_printer() { // FFT4.str:74
    FOR(uint32_t, i, 0, <, TheGlobal_N, i++)
        printf("%f\n", pop_float(&TransitBuf.buffer_out)); // FFT4.str:75
    ENDFOR
}
void fft4_init() { // FFT4.str:7
    init_buffer_float(&IdentityBuf.buffer_in);
    init_buffer_float(&IdentityBuf.buffer_out);
    init_buffer_float(&MultiplyBuf.buffer_in);
    init_buffer_float(&MultiplyBuf.buffer_out);
    init_buffer_float(&AddBuf.buffer_in);
    init_buffer_float(&AddBuf.buffer_out);
    init_buffer_float(&SubtractBuf.buffer_in);
    init_buffer_float(&SubtractBuf.buffer_out);
    init_buffer_float(&Transit2Buf.buffer_out);
    init_buffer_float(&TransitBuf.buffer_out);
}

void fft4_split_weighted_round_robin_1() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
}

void fft4_split_weighted_round_robin_2() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/4 , i++)
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
}

void fft4_split_weighted_round_robin_4() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/8 , i++)
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
}

void fft4_split_weighted_round_robin_8() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/4 , i++)
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_N/4 , i++)
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
    
    FOR(uint32_t, i, 0, <, TheGlobal_N/4 , i++)
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_N/4 , i++)
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
}

void fft4_split_weighted_round_robin_16() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&IdentityBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR

    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&MultiplyBuf.buffer_in, pop_float(&TransitBuf.buffer_out));
    ENDFOR
}


void fft4_join_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&Transit2Buf.buffer_out, pop_float(&IdentityBuf.buffer_out));
        push_float(&Transit2Buf.buffer_out, pop_float(&MultiplyBuf.buffer_out));
    ENDFOR
}
void fft4_split_duplicate() {
    FOR(uint32_t, i, 0, <, TheGlobal_N , i++)
        float tmp = pop_float(&Transit2Buf.buffer_out);
        push_float(&AddBuf.buffer_in, tmp);
        push_float(&SubtractBuf.buffer_in, tmp);
    ENDFOR
}

void fft4_join_weighted_round_robin_1() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/2 , i++)
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
    ENDFOR
}

void fft4_join_weighted_round_robin_2() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/4 , i++)
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
    ENDFOR
}

void fft4_join_weighted_round_robin_4() {
    FOR(uint32_t, i, 0, <, TheGlobal_N/8 , i++)
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
        
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
    ENDFOR
}

void fft4_join_weighted_round_robin_8() {
    FOR(uint32_t, j, 0, <, TheGlobal_N/4 , j++)
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
    ENDFOR

    FOR(uint32_t, j, 0, <, TheGlobal_N/4 , j++)
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
    ENDFOR

    FOR(uint32_t, j, 0, <, TheGlobal_N/4 , j++)
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
    ENDFOR

    FOR(uint32_t, j, 0, <, TheGlobal_N/4 , j++)
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
    ENDFOR
}

void fft4_join_weighted_round_robin_16() {
    FOR(uint32_t, j, 0, <, TheGlobal_N/2 , j++)
        push_float(&TransitBuf.buffer_out, pop_float(&AddBuf.buffer_out));
    ENDFOR

    FOR(uint32_t, j, 0, <, TheGlobal_N/2 , j++)
        push_float(&TransitBuf.buffer_out, pop_float(&SubtractBuf.buffer_out));
    ENDFOR
}


int main(int argv, char** argc) {
    fft4_init();

    FOR(uint32_t, i, 0, <, MAX_ITERATION, i++)
    	fft4_source();
        
        fft4_split_weighted_round_robin_1();
            fft4_identity();
            fft4_multiply();
        fft4_join_round_robin();
        fft4_split_duplicate();
            fft4_add();
            fft4_subtract();
        fft4_join_weighted_round_robin_1();
        
        fft4_split_weighted_round_robin_2();
            fft4_identity();
            fft4_multiply();
        fft4_join_round_robin();
        fft4_split_duplicate();
            fft4_add();
            fft4_subtract();
        fft4_join_weighted_round_robin_2();
        
        fft4_split_weighted_round_robin_4();
            fft4_identity();
            fft4_multiply();
        fft4_join_round_robin();
        fft4_split_duplicate();
            fft4_add();
            fft4_subtract();
        fft4_join_weighted_round_robin_4();
        
        fft4_split_weighted_round_robin_8();
            fft4_identity();
            fft4_multiply();
        fft4_join_round_robin();
        fft4_split_duplicate();
            fft4_add();
            fft4_subtract();
        fft4_join_weighted_round_robin_8();
        
        fft4_split_weighted_round_robin_16();
            fft4_identity();
            fft4_multiply();
        fft4_join_round_robin();
        fft4_split_duplicate();
            fft4_add();
            fft4_subtract();
        fft4_join_weighted_round_robin_16();
        
        fft4_float_printer();
    ENDFOR
    return EXIT_SUCCESS;
} 
