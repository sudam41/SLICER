#include "Audiobeam_15mics.h"

#include "sim_api.h"

Interpolate_t InterpolateBuf[TheGlobal_NUM_MICS];
Printer_t PrinterBuf;
Average_t AverageBuf;

void audiobeam_average() { // /tmp/Audiobeam.str:184
	SimNamedMarker(5, __func__);
    float sum = 0; // /tmp/Audiobeam.str:185
    FOR(uint32_t, i, 0, <, TheGlobal_NUM_MICS, i++) // /tmp/Audiobeam.str:187
        float val = pop_float(&(AverageBuf.buffer_in)); // /tmp/Audiobeam.str:188
        sum += val; // /tmp/Audiobeam.str:189
    ENDFOR
    push_float(&(AverageBuf.buffer_out), (sum / ((float) (TheGlobal_NUM_MICS)))); // /tmp/Audiobeam.str:192
}

void audiobeam_interpolate(int mic) { // /tmp/Audiobeam.str:206
	SimNamedMarker(5, __func__);
    float low_sample = peek_float(&(InterpolateBuf[mic].buffer_in), (InterpolateBuf[mic].low_index - 1)); // /tmp/Audiobeam.str:213
    float high_sample = peek_float(&(InterpolateBuf[mic].buffer_in), (InterpolateBuf[mic].high_index - 1)); // /tmp/Audiobeam.str:214
    float value = (((high_sample - low_sample) * InterpolateBuf[mic].delay_offset) + low_sample); // /tmp/Audiobeam.str:215
    
    push_float(&(InterpolateBuf[mic].buffer_out), (value * InterpolateBuf[mic].weights[mic])); // /tmp/Audiobeam.str:217
    pop_float(&(InterpolateBuf[mic].buffer_in)); // /tmp/Audiobeam.str:218
}

void audiobeam_printer() { // /tmp/Audiobeam.str:227
	SimNamedMarker(5, __func__);
    printf("%f %f\n", PrinterBuf.time_index, pop_float(&(AverageBuf.buffer_out))); // /tmp/Audiobeam.str:232
    PrinterBuf.time_index += TheGlobal_TIMEINDEX_INCR; // /tmp/Audiobeam.str:236
}

void audiobeam_init() { // /tmp/Audiobeam.str:43
    FOR(uint32_t, i, 0, <, TheGlobal_NUM_MICS, i++) // /tmp/Audiobeam.str:33
        TheGlobalBuf.MIC_LOCATIONS[i][0] = 1.5f; // /tmp/Audiobeam.str:34
        TheGlobalBuf.MIC_LOCATIONS[i][1] = (2.79f + (i * 0.03f)); // /tmp/Audiobeam.str:35
        TheGlobalBuf.MIC_LOCATIONS[i][2] = 0.0f; // /tmp/Audiobeam.str:36
    ENDFOR
    
    TheGlobalBuf.SOURCE_LOCATION[0] = 100;
    TheGlobalBuf.SOURCE_LOCATION[1] = 200;
    TheGlobalBuf.SOURCE_LOCATION[2] = 10;
    
    FileReader_init(TheGlobal_FILEIN, "float");
    
    float delays[TheGlobal_NUM_MICS]; // /tmp/Audiobeam.str:77
    float min_delay = 1.0E38f; // /tmp/Audiobeam.str:80
    float weights [TheGlobal_NUM_MICS]; // /tmp/Audiobeam.str:111

    FOR(uint32_t, i, 0, <, TheGlobal_NUM_MICS, i++) // /tmp/Audiobeam.str:82
        float distance = sqrt(
            (TheGlobalBuf.MIC_LOCATIONS[i][0] - TheGlobalBuf.SOURCE_LOCATION[0]) * (TheGlobalBuf.MIC_LOCATIONS[i][0] - TheGlobalBuf.SOURCE_LOCATION[0]) + 
            (TheGlobalBuf.MIC_LOCATIONS[i][1] - TheGlobalBuf.SOURCE_LOCATION[1]) * (TheGlobalBuf.MIC_LOCATIONS[i][1] - TheGlobalBuf.SOURCE_LOCATION[1]) + 
            (TheGlobalBuf.MIC_LOCATIONS[i][2] - TheGlobalBuf.SOURCE_LOCATION[2]) * (TheGlobalBuf.MIC_LOCATIONS[i][2] - TheGlobalBuf.SOURCE_LOCATION[2])
        ); // /tmp/Audiobeam.str:83
        delays[i] = ((distance / TheGlobal_SOUND_SPEED) * TheGlobal_SAMPLING_RATE); // /tmp/Audiobeam.str:90
        if (delays[i] < min_delay) { // /tmp/Audiobeam.str:92
            min_delay = delays[i]; // /tmp/Audiobeam.str:93
        }
    ENDFOR

    min_delay = (floor(min_delay) - 1); // /tmp/Audiobeam.str:97
    FOR(uint32_t, i, 0, <, TheGlobal_NUM_MICS, i++) // /tmp/Audiobeam.str:99
        delays[i] -= min_delay; // /tmp/Audiobeam.str:100
    ENDFOR

    if (!TheGlobal_HAMMING) { // /tmp/Audiobeam.str:114
        FOR(uint32_t, i, 0, <, TheGlobal_NUM_MICS, i++) // /tmp/Audiobeam.str:115
            weights[i] = 1; // /tmp/Audiobeam.str:116
        ENDFOR
    } 
    else { // /tmp/Audiobeam.str:119
        // (TheGlobal_NUM_MICS % 2) == 1 // /tmp/Audiobeam.str:119
        int index = 0; // /tmp/Audiobeam.str:120
        int half = TheGlobal_NUM_MICS / 2; // /tmp/Audiobeam.str:121v
        FOR2(int, y, -(half), <=, half, TheGlobal_NUM_MICS, y++) // /tmp/Audiobeam.str:122
            weights[(index)++] = 0.54f + (0.46f * cos((3.141592653589793f * y) / half)); // /tmp/Audiobeam.str:123
        ENDFOR
    }

    FOR(uint32_t, mic, 0, <, TheGlobal_NUM_MICS, mic++) // /tmp/Audiobeam.str:173
        FOR(uint32_t, i, 0, <, TheGlobal_NUM_MICS, i++)
            InterpolateBuf[mic].weights[i] = weights[i];
        ENDFOR

        float micdelay = delays[mic];
        InterpolateBuf[mic].delays_mic = micdelay; // /tmp/Audiobeam.str:200
        InterpolateBuf[mic].low_index = (int) (floor(micdelay)); // /tmp/Audiobeam.str:201
        InterpolateBuf[mic].high_index = (int) (ceil(micdelay)); // /tmp/Audiobeam.str:202
        InterpolateBuf[mic].delay_offset = (micdelay - InterpolateBuf[mic].low_index); // /tmp/Audiobeam.str:203

        init_buffer_float(&(InterpolateBuf[mic].buffer_in));
        init_buffer_float(&(InterpolateBuf[mic].buffer_out));
    ENDFOR
    
    init_buffer_float(&(AverageBuf.buffer_in));
    init_buffer_float(&(AverageBuf.buffer_out));

    PrinterBuf.time_index = 0; // /tmp/Audiobeam.str:224
}

void audiobeam_split_round_robin() {
	SimNamedMarker(5, __func__);
    FOR(uint32_t, mic, 0, <, TheGlobal_NUM_MICS, mic++)
        push_float(&(InterpolateBuf[mic].buffer_in), pop_float(&FileReaderBufFloat));
    ENDFOR
}

void audiobeam_join_round_robin() {
	SimNamedMarker(5, __func__);
    FOR(uint32_t, mic, 0, <, TheGlobal_NUM_MICS, mic++)
        push_float(&(AverageBuf.buffer_in), pop_float(&(InterpolateBuf[mic].buffer_out)));
    ENDFOR
}

int main(int argv, char** argc) {
    audiobeam_init();
    
    FileReader(195); 
    FOR(uint32_t, i, 0, <, 13, i++)
        audiobeam_split_round_robin(); 
    ENDFOR
    
    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        FileReader(TheGlobal_NUM_MICS);
               
        audiobeam_split_round_robin();
        
        FOR(uint32_t, mic, 0, <, TheGlobal_NUM_MICS, mic++)
            audiobeam_interpolate(mic);
        ENDFOR

        audiobeam_join_round_robin();
        audiobeam_average();
        audiobeam_printer();
    ENDFOR
    
    FileReader_close();
    
    return EXIT_SUCCESS;
}
