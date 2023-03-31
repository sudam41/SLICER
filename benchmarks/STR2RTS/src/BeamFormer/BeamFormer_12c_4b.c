#include "BeamFormer_12c_4b.h"

#include "sim_api.h"

InputGenerate_t InputGenerateBuf[TheGlobal_numChannels];
BeamFirFilter_t BeamFirFilterBuf[2*TheGlobal_numChannels+TheGlobal_numBeams];
BeamForm_t BeamFormBuf[TheGlobal_numBeams];
Magnitude_t MagnitudeBuf[TheGlobal_numBeams];

buffer_float_t mid_buffer;

void  bf12c4b_input_generate(int myChannel) { // BeamFormer.str:51
    SimNamedMarker(5, __func__);
    FOR(uint32_t, reps, 0, <, 2 , reps++)
        float tmp = sqrt(InputGenerateBuf[myChannel].curSample * myChannel);

        if (TheGlobal_targetBeam == myChannel && InputGenerateBuf[myChannel].curSample == TheGlobal_targetSample) { // BeamFormer.str:52
            push_float(&(InputGenerateBuf[myChannel].buffer_out), tmp); // BeamFormer.str:53
            push_float(&(InputGenerateBuf[myChannel].buffer_out), tmp + 1); // BeamFormer.str:54
        } 
        else { // BeamFormer.str:55
            push_float(&(InputGenerateBuf[myChannel].buffer_out), -(tmp)); // BeamFormer.str:56
            push_float(&(InputGenerateBuf[myChannel].buffer_out), -(tmp + 1)); // BeamFormer.str:57
        }
        InputGenerateBuf[myChannel].curSample++; // BeamFormer.str:59
        if ((InputGenerateBuf[myChannel].curSample >= TheGlobal_numSamples)) { // BeamFormer.str:60
            InputGenerateBuf[myChannel].curSample = 0; // BeamFormer.str:61
        }
    ENDFOR
}

void  bf12c4b_float_printer(int i) { // BeamFormer.str:66
    SimNamedMarker(5, __func__);
    printf("%f\n", pop_float(&(MagnitudeBuf[i].buffer_out))); // BeamFormer.str:66
}

void  bf12c4b_beam_fir_filter_coarse(int myChannel) { // BeamFormer.str:86    
    SimNamedMarker(5, __func__);
    
    FOR(uint32_t, reps, 0, <, 2 , reps++)
        float real_curr = 0; // BeamFormer.str:87
        float imag_curr = 0; // BeamFormer.str:88
        int modPos; // BeamFormer.str:90

        BeamFirFilterBuf[myChannel].realBuffer[(TheGlobal_numCoarseFilterTaps-1 - BeamFirFilterBuf[myChannel].pos)] = 
                pop_float(&(InputGenerateBuf[myChannel].buffer_out)); // BeamFormer.str:91
        BeamFirFilterBuf[myChannel].imagBuffer[(TheGlobal_numCoarseFilterTaps-1 - BeamFirFilterBuf[myChannel].pos)] = 
                pop_float(&(InputGenerateBuf[myChannel].buffer_out)); // BeamFormer.str:92

        modPos = TheGlobal_numCoarseFilterTaps - 1 - BeamFirFilterBuf[myChannel].pos; // BeamFormer.str:93
        FOR(uint32_t, i, 0, <, TheGlobal_numCoarseFilterTaps, i++) // BeamFormer.str:94
            real_curr += BeamFirFilterBuf[myChannel].realBuffer[modPos] * BeamFirFilterBuf[myChannel].real_weight[i] + 
                         BeamFirFilterBuf[myChannel].imagBuffer[modPos] * BeamFirFilterBuf[myChannel].imag_weight[i]; // BeamFormer.str:95
            imag_curr += BeamFirFilterBuf[myChannel].imagBuffer[modPos] * BeamFirFilterBuf[myChannel].real_weight[i] + 
                         BeamFirFilterBuf[myChannel].realBuffer[modPos] * BeamFirFilterBuf[myChannel].imag_weight[i]; // BeamFormer.str:97
            modPos = ((modPos + 1) & (TheGlobal_numCoarseFilterTaps-1)); // BeamFormer.str:99
        ENDFOR

        BeamFirFilterBuf[myChannel].pos = (BeamFirFilterBuf[myChannel].pos + 1) & (TheGlobal_numCoarseFilterTaps-1); // BeamFormer.str:101
        push_float (&(BeamFirFilterBuf[myChannel].buffer_out), real_curr); // BeamFormer.str:102
        push_float (&(BeamFirFilterBuf[myChannel].buffer_out), imag_curr); // BeamFormer.str:103

        BeamFirFilterBuf[myChannel].count += TheGlobal_coarseDecimationRatio; // BeamFormer.str:107
        if (BeamFirFilterBuf[myChannel].count == TheGlobal_numSamples) { // BeamFormer.str:108
            BeamFirFilterBuf[myChannel].count = 0; // BeamFormer.str:109
            BeamFirFilterBuf[myChannel].pos = 0; // BeamFormer.str:110
            FOR(uint32_t, i, 0, <, TheGlobal_numCoarseFilterTaps, i++) // BeamFormer.str:111
                BeamFirFilterBuf[myChannel].realBuffer[i] = 0; // BeamFormer.str:112
                BeamFirFilterBuf[myChannel].imagBuffer[i] = 0; // BeamFormer.str:113
            ENDFOR
        }
    ENDFOR
}
void  bf12c4b_beam_fir_filter_fine(int myChannel) { // BeamFormer.str:86
    SimNamedMarker(5, __func__);
   uint32_t channelBufNum = TheGlobal_numChannels+myChannel;
    float real_curr = 0; // BeamFormer.str:87
    float imag_curr = 0; // BeamFormer.str:88
    int modPos; // BeamFormer.str:90
    
    BeamFirFilterBuf[channelBufNum].realBuffer[TheGlobal_numFineFilterTaps -1 - BeamFirFilterBuf[channelBufNum].pos] = 
            pop_float(&(BeamFirFilterBuf[myChannel].buffer_out)); // BeamFormer.str:91
    BeamFirFilterBuf[channelBufNum].imagBuffer[TheGlobal_numFineFilterTaps -1 - BeamFirFilterBuf[channelBufNum].pos] = 
            pop_float(&(BeamFirFilterBuf[myChannel].buffer_out)); // BeamFormer.str:92
    
    modPos = TheGlobal_numFineFilterTaps -1 - BeamFirFilterBuf[channelBufNum].pos; // BeamFormer.str:93
    FOR(uint32_t, i, 0, <, TheGlobal_numFineFilterTaps, i++) // BeamFormer.str:94
        real_curr += BeamFirFilterBuf[channelBufNum].realBuffer[modPos] * BeamFirFilterBuf[channelBufNum].real_weight[i] + 
                     BeamFirFilterBuf[channelBufNum].imagBuffer[modPos] * BeamFirFilterBuf[channelBufNum].imag_weight[i]; // BeamFormer.str:95
        imag_curr += BeamFirFilterBuf[channelBufNum].imagBuffer[modPos] * BeamFirFilterBuf[channelBufNum].real_weight[i] + 
                     BeamFirFilterBuf[channelBufNum].realBuffer[modPos] * BeamFirFilterBuf[channelBufNum].imag_weight[i]; // BeamFormer.str:97
        modPos = ((modPos + 1) & (TheGlobal_numFineFilterTaps -1)); // BeamFormer.str:99
    ENDFOR
    
    BeamFirFilterBuf[channelBufNum].pos = (BeamFirFilterBuf[channelBufNum].pos + 1) & (TheGlobal_numFineFilterTaps -1); // BeamFormer.str:101
    push_float (&(BeamFirFilterBuf[channelBufNum].buffer_out), real_curr); // BeamFormer.str:102
    push_float (&(BeamFirFilterBuf[channelBufNum].buffer_out), imag_curr); // BeamFormer.str:103
    
    pop_float(&(BeamFirFilterBuf[myChannel].buffer_out)); // BeamFormer.str:105
    pop_float(&(BeamFirFilterBuf[myChannel].buffer_out)); // BeamFormer.str:105
    
    BeamFirFilterBuf[channelBufNum].count += TheGlobal_fineDecimationRatio; // BeamFormer.str:107
    if (BeamFirFilterBuf[channelBufNum].count == TheGlobal_numPostDec1) { // BeamFormer.str:108
        BeamFirFilterBuf[channelBufNum].count = 0; // BeamFormer.str:109
        BeamFirFilterBuf[channelBufNum].pos = 0; // BeamFormer.str:110
        FOR(uint32_t, i, 0, <, TheGlobal_numFineFilterTaps, i++) // BeamFormer.str:111
            BeamFirFilterBuf[channelBufNum].realBuffer[i] = 0; // BeamFormer.str:112
            BeamFirFilterBuf[channelBufNum].imagBuffer[i] = 0; // BeamFormer.str:113
        ENDFOR
    }
}
void  bf12c4b_beam_fir_filter_mf(int myChannel) { // BeamFormer.str:86
    SimNamedMarker(5, __func__);
    uint32_t channelBufNum = 2*TheGlobal_numChannels+myChannel;
    float real_curr = 0; // BeamFormer.str:87
    float imag_curr = 0; // BeamFormer.str:88
    int modPos; // BeamFormer.str:90
    
    BeamFirFilterBuf[channelBufNum].realBuffer[TheGlobal_mfSize -1 - BeamFirFilterBuf[channelBufNum].pos] = 
            pop_float(&(BeamFormBuf[myChannel].buffer_out)); // BeamFormer.str:91
    BeamFirFilterBuf[channelBufNum].imagBuffer[TheGlobal_mfSize -1- BeamFirFilterBuf[channelBufNum].pos] = 
            pop_float(&(BeamFormBuf[myChannel].buffer_out)); // BeamFormer.str:92
    
    modPos = TheGlobal_mfSize -1 - BeamFirFilterBuf[channelBufNum].pos; // BeamFormer.str:93
    FOR(uint32_t, i, 0, <, TheGlobal_mfSize, i++) // BeamFormer.str:94
        real_curr += BeamFirFilterBuf[channelBufNum].realBuffer[modPos] * BeamFirFilterBuf[channelBufNum].real_weight[i] + 
                     BeamFirFilterBuf[channelBufNum].imagBuffer[modPos] * BeamFirFilterBuf[channelBufNum].imag_weight[i]; // BeamFormer.str:95
        imag_curr += BeamFirFilterBuf[channelBufNum].imagBuffer[modPos] * BeamFirFilterBuf[channelBufNum].real_weight[i] + 
                     BeamFirFilterBuf[channelBufNum].realBuffer[modPos] * BeamFirFilterBuf[channelBufNum].imag_weight[i]; // BeamFormer.str:97
        modPos = ((modPos + 1) & (TheGlobal_mfSize -1)); // BeamFormer.str:99
    ENDFOR
    
    BeamFirFilterBuf[channelBufNum].pos = (BeamFirFilterBuf[channelBufNum].pos + 1) & (TheGlobal_mfSize -1); // BeamFormer.str:101
    push_float (&(BeamFirFilterBuf[channelBufNum].buffer_out), real_curr); // BeamFormer.str:102
    push_float (&(BeamFirFilterBuf[channelBufNum].buffer_out), imag_curr); // BeamFormer.str:103

    BeamFirFilterBuf[channelBufNum].count += 1; // BeamFormer.str:107
    if (BeamFirFilterBuf[channelBufNum].count == TheGlobal_numPostDec2) { // BeamFormer.str:108
        BeamFirFilterBuf[channelBufNum].count = 0; // BeamFormer.str:109
        BeamFirFilterBuf[channelBufNum].pos = 0; // BeamFormer.str:110
        FOR(uint32_t, i, 0, <, TheGlobal_mfSize, i++) // BeamFormer.str:111
            BeamFirFilterBuf[channelBufNum].realBuffer[i] = 0; // BeamFormer.str:112
            BeamFirFilterBuf[channelBufNum].imagBuffer[i] = 0; // BeamFormer.str:113
        ENDFOR
    }
}

void  bf12c4b_beam_form(int myBeamId) { // BeamFormer.str:189
    SimNamedMarker(5, __func__);
    float real_curr = 0; // BeamFormer.str:190
    float imag_curr = 0; // BeamFormer.str:191
    
    FOR(uint32_t, i, 0, <, TheGlobal_numChannels, i++) // BeamFormer.str:192
        float real_pop = pop_float(&(BeamFormBuf[myBeamId].buffer_in)); // BeamFormer.str:193
        float imag_pop = pop_float(&(BeamFormBuf[myBeamId].buffer_in)); // BeamFormer.str:194
        real_curr += ((BeamFormBuf[myBeamId].real_weight[i] * real_pop) - (BeamFormBuf[myBeamId].imag_weight[i] * imag_pop)); // BeamFormer.str:195
        imag_curr += ((BeamFormBuf[myBeamId].real_weight[i] * imag_pop) + (BeamFormBuf[myBeamId].imag_weight[i] * real_pop)); // BeamFormer.str:197
    ENDFOR
                
    push_float(&(BeamFormBuf[myBeamId].buffer_out), real_curr); // BeamFormer.str:200
    push_float(&(BeamFormBuf[myBeamId].buffer_out), imag_curr); // BeamFormer.str:201
    printf("%d ---> %f - %f\n", myBeamId, real_curr, imag_curr);
}

void  bf12c4b_magnitude(int i) { // BeamFormer.str:206
    SimNamedMarker(5, __func__);
    
    float f1 = pop_float(&(BeamFirFilterBuf[2*TheGlobal_numChannels+i].buffer_out)); // BeamFormer.str:207
    float f2 = pop_float(&(BeamFirFilterBuf[2*TheGlobal_numChannels+i].buffer_out)); // BeamFormer.str:208
    
    push_float(&(MagnitudeBuf[i].buffer_out), (float )(sqrt(((f1 * f1) + (f2 * f2))))); // BeamFormer.str:209
}

void bf12c4b_split_round_robin() {
    SimNamedMarker(5, __func__);
}

void bf12c4b_join_round_robin() {
    SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_numChannels, i++)
        push_float(&mid_buffer, pop_float(&(BeamFirFilterBuf[TheGlobal_numChannels+i].buffer_out)));
        push_float(&mid_buffer, pop_float(&(BeamFirFilterBuf[TheGlobal_numChannels+i].buffer_out)));
    ENDFOR
}

void bf12c4b_split_duplicate() {
    SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, 2*TheGlobal_numChannels, i++)
        float tmp = pop_float(&mid_buffer);
        FOR(uint32_t, j, 0, <, TheGlobal_numBeams, j++) // BeamFormer.str:33
            push_float(&(BeamFormBuf[j].buffer_in), tmp);
        ENDFOR
    ENDFOR
}

void bf12c4b_join2_round_robin() {
    SimNamedMarker(5, __func__);
}

void BeamFormer_init() {
    init_buffer_float(&mid_buffer);
    
    FOR(uint32_t, i, 0, <, TheGlobal_numChannels , i++) // BeamFormer.str:22
        InputGenerateBuf[i].curSample = 0; // BeamFormer.str:48

        init_buffer_float(&(InputGenerateBuf[i].buffer_out));
    
        BeamFirFilterBuf[i].pos = 0; // BeamFormer.str:79
        BeamFirFilterBuf[i].count = 0;
        FOR(uint32_t, j, 0, <, TheGlobal_numCoarseFilterTaps, j++) // BeamFormer.str:80
            int idx = (j + 1); // BeamFormer.str:81
            BeamFirFilterBuf[i].real_weight[j] = (sin(idx) / ((float )(idx))); // BeamFormer.str:82
            BeamFirFilterBuf[i].imag_weight[j] = (cos(idx) / ((float )(idx))); // BeamFormer.str:83
        }
        init_buffer_float(&(BeamFirFilterBuf[i].buffer_out));
        
        BeamFirFilterBuf[TheGlobal_numChannels+i].pos = 0; // BeamFormer.str:79
        BeamFirFilterBuf[TheGlobal_numChannels+i].count = 0;
        FOR(uint32_t, j, 0, <, TheGlobal_numFineFilterTaps, j++) // BeamFormer.str:80
            int idx = (j + 1); // BeamFormer.str:81
            BeamFirFilterBuf[TheGlobal_numChannels+i].real_weight[j] = (sin(idx) / ((float )(idx))); // BeamFormer.str:82
            BeamFirFilterBuf[TheGlobal_numChannels+i].imag_weight[j] = (cos(idx) / ((float )(idx))); // BeamFormer.str:83
        ENDFOR

        init_buffer_float(&(BeamFirFilterBuf[TheGlobal_numChannels+i].buffer_out));
    ENDFOR
    
    FOR(uint32_t, i, 0, <, TheGlobal_numBeams, i++) // BeamFormer.str:33
        FOR(uint32_t, j, 0, <, TheGlobal_numChannels, j++) // BeamFormer.str:183
            int idx = (j + 1); // BeamFormer.str:184
            BeamFormBuf[i].real_weight[j] = sin(idx) / ((float )(i + idx)); // BeamFormer.str:185
            BeamFormBuf[i].imag_weight[j] = cos(idx) / ((float )(i + idx)); // BeamFormer.str:186
        ENDFOR

        init_buffer_float(&(BeamFormBuf[i].buffer_out));
        init_buffer_float(&(BeamFormBuf[i].buffer_in));
    
        BeamFirFilterBuf[2*TheGlobal_numChannels+i].pos = 0; // BeamFormer.str:79
        BeamFirFilterBuf[2*TheGlobal_numChannels+i].count = 0;
        FOR(uint32_t, j, 0, <, TheGlobal_mfSize, j++) // BeamFormer.str:80
            int idx = (j + 1); // BeamFormer.str:81
            BeamFirFilterBuf[2*TheGlobal_numChannels+i].real_weight[j] = (sin(idx) / ((float )(idx))); // BeamFormer.str:82
            BeamFirFilterBuf[2*TheGlobal_numChannels+i].imag_weight[j] = (cos(idx) / ((float )(idx))); // BeamFormer.str:83
        ENDFOR
        init_buffer_float(&(BeamFirFilterBuf[2*TheGlobal_numChannels+i].buffer_out));
        
        init_buffer_float(&(MagnitudeBuf[i].buffer_out));
    ENDFOR
}

int main(int argv, char** argc) {
    // Test to see if we can use sim functions.
    if (SimInSimulator()) {
        printf("API Test: Running in the simulator\n"); fflush(stdout);
    } else {
        printf("API Test: Not running in the simulator\n"); fflush(stdout);
    }
    // Marker: uses default python marker script.
    // Verbose marker flag set in simulationcontrol/run.py
    SimNamedMarker(5, __func__);


    BeamFormer_init();
    
    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        bf12c4b_split_round_robin();
        FOR(uint32_t, i, 0, <, TheGlobal_numChannels, i++)
            bf12c4b_input_generate(i);
            bf12c4b_beam_fir_filter_coarse(i);
            bf12c4b_beam_fir_filter_fine(i);
        ENDFOR
        bf12c4b_join_round_robin();
        bf12c4b_split_duplicate();
        FOR(uint32_t, i, 0, <, TheGlobal_numBeams, i++) // BeamFormer.str:33
            bf12c4b_beam_form(i);
            bf12c4b_beam_fir_filter_mf(i);
            bf12c4b_magnitude(i);
            bf12c4b_float_printer(i);
        ENDFOR
        bf12c4b_join2_round_robin();
    ENDFOR
    
    return EXIT_SUCCESS;
} 
