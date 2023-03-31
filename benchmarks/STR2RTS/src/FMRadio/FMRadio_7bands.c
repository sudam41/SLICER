#include "FMRadio_7bands.h"

TheGlobal_t TheGlobal;

channel_t SubtracerBuf[TheGlobal_eqBands-1];
channel_t EqSplitBuf[TheGlobal_eqBands-1];
channel_t AnonFilter_a0Buf;
channel_t EqualizerBuf;
channel_t LowPassFilter4SBuf;
channel_t EqualizerBuf;
channel2_t BPFCoreBuf[TheGlobal_eqBands-1];

void fm7b_subtracter(uint32_t k) {
    push_float(&SubtracerBuf[k].buffer_out, peek_float(&SubtracerBuf[k].buffer_in, 1) - peek_float(&SubtracerBuf[k].buffer_in, 0));
    pop_float(&SubtracerBuf[k].buffer_in); 
    pop_float(&SubtracerBuf[k].buffer_in);
}

void fm7b_equalizer() {
    float sum = 0;
    FOR(uint32_t, i, 0, <, TheGlobal_eqBands-1, i++)
      sum += pop_float(&AnonFilter_a0Buf.buffer_in);
    ENDFOR
    push_float(&EqualizerBuf.buffer_out, sum);
}

void fm7b_amplify(uint32_t k) {
    push_float(&EqSplitBuf[k].buffer_out, pop_float(&SubtracerBuf[k].buffer_out) * TheGlobal.eqGain[k]); 
}

void fm7b_lowpass_filter(uint32_t k, uint32_t l) {
    float sum = 0;
    FOR(uint32_t, i, 0, <, TheGlobal_numberOfTaps, i++)
      sum += peek_float(&BPFCoreBuf[k].buffer_in[l], i) * TheGlobal.coeff[k+l][i];
    ENDFOR
    push_float(&BPFCoreBuf[k].buffer_out[l], sum);
    pop_float(&BPFCoreBuf[k].buffer_in[l]);
}

void fm7b_low_pass_filter_4samp() {
    float sum = 0;
    FOR(uint32_t, i, 0, <, TheGlobal_numberOfTaps, i++)
      sum += peek_float(&LowPassFilter4SBuf.buffer_in, i) * TheGlobal.coeff_4s[i];
    ENDFOR
    push_float(&LowPassFilter4SBuf.buffer_out, sum);
    
    //decimate 4 samples after outputting 1
    FOR(uint32_t, i, 0, <, 4, i++)
	pop_float(&LowPassFilter4SBuf.buffer_in);
    ENDFOR
    pop_float(&LowPassFilter4SBuf.buffer_in);
}

void fm7b_fmdemodulator() {
    float mGain = TheGlobal_maxAmplitude * (TheGlobal_samplingRate / (TheGlobal_bandwidth * M_PI));

    float temp = 0;
    //may have to switch to complex?
    temp = (float)(peek_float(&LowPassFilter4SBuf.buffer_out, 0) * peek_float(&LowPassFilter4SBuf.buffer_out, 1));
    //if using complex, use atan2
    temp = (float)(mGain * atan(temp));

    pop_float(&LowPassFilter4SBuf.buffer_out);
    push_float(&EqualizerBuf.buffer_in, temp);
}

void fm7b_float_one_source() {
    FOR(uint32_t, k, 0, <, 5, k++)
        push_float(&LowPassFilter4SBuf.buffer_in, TheGlobal.source_x++);
    ENDFOR
}


void fm7b_float_printer() {
    printf("%f\n", pop_float(&EqualizerBuf.buffer_out));
}

void fm7b_init() {
    // first gain doesn't really correspond to a band
    TheGlobal.eqGain[0] = 0;
    FOR(uint32_t, i, 0, <, TheGlobal_eqBands-1, i++)
	// the gain grows linearly towards the center bands
	float val = (((float)(i+1-1))-(((float)(TheGlobal_eqBands-2))/2.0)) / 5.0;
	TheGlobal.eqGain[i] = val > 0 ? 2.0-val : 2.0+val;
    }

    float m = TheGlobal_numberOfTaps - 1;
    // LowPassFilter_4samp    , 
    float w = 2 * M_PI * TheGlobal_cutoffFrequency / TheGlobal_samplingRate;
    FOR(uint32_t, i, 0, <, TheGlobal_numberOfTaps, i++)
        if (i - m/2 == 0)
            TheGlobal.coeff_4s[i] = w / M_PI;
        else
            TheGlobal.coeff_4s[i] = sin(w * (i - m / 2)) / M_PI / (i - m / 2) * (0.54 - 0.46 * cos(2 * M_PI * i / m));
    ENDFOR
    
    // LowPassFilter(uint32_t k, float cutoff) {
    FOR(uint32_t, b, 0, <, TheGlobal_eqBands, b++)
        float cutoff = (float)exp(b * (log(TheGlobal_high) - log(TheGlobal_low)) / (TheGlobal_eqBands - 1) + log(TheGlobal_low));
        float w = 2 * M_PI * cutoff / TheGlobal_samplingRate;
        FOR(uint32_t, i, 0, <, TheGlobal_numberOfTaps, i++)
            if (i - m / 2 == 0)
                TheGlobal.coeff[b][i] = w / M_PI;
            else
                TheGlobal.coeff[b][i] = sin(w * (i - m / 2)) / M_PI / (i - m / 2 ) * (0.54 - 0.46 * cos(2 * M_PI * i/ m));
        ENDFOR
    ENDFOR
        
    init_buffer_float(&LowPassFilter4SBuf.buffer_in);
    init_buffer_float(&LowPassFilter4SBuf.buffer_out);
    init_buffer_float(&EqualizerBuf.buffer_in);
    init_buffer_float(&EqualizerBuf.buffer_out);
    init_buffer_float(&AnonFilter_a0Buf.buffer_in);
        
    FOR(uint32_t, i, 0, <, TheGlobal_eqBands-1, i++)
        init_buffer_float(&EqSplitBuf[i].buffer_in);
        init_buffer_float(&EqSplitBuf[i].buffer_out);
        init_buffer_float(&BPFCoreBuf[i].buffer_in[0]);
        init_buffer_float(&BPFCoreBuf[i].buffer_out[0]);
        init_buffer_float(&BPFCoreBuf[i].buffer_in[1]);
        init_buffer_float(&BPFCoreBuf[i].buffer_out[1]);
        init_buffer_float(&SubtracerBuf[i].buffer_in);
        init_buffer_float(&SubtracerBuf[i].buffer_out);
    ENDFOR
                
    TheGlobal.source_x = 0;
    // Initialisation
    FOR(uint32_t, i, 0, <, 379, i++)
        push_float(&LowPassFilter4SBuf.buffer_in, TheGlobal.source_x++); // FloatOneSource
    ENDFOR
    FOR(uint32_t, i, 0, <, 64, i++)
        fm7b_low_pass_filter_4samp();
    ENDFOR
    FOR(uint32_t, i, 0, <, 63, i++)
        fm7b_fmdemodulator();
    ENDFOR
    FOR(uint32_t, i, 0, <, 63, i++)
        fm7b_split1_duplicate();
    ENDFOR
    FOR(uint32_t, i, 0, <, 63, i++)
        FOR(uint32_t, j, 0, <, TheGlobal_eqBands-1, j++)
            fm7b_split2_duplicate(j);
        ENDFOR
    ENDFOR
}

void fm7b_split1_duplicate() {
    float val = pop_float(&EqualizerBuf.buffer_in);
    FOR(uint32_t, i, 0, <, TheGlobal_eqBands-1, i++)
        push_float(&EqSplitBuf[i].buffer_in, val);
    ENDFOR
}

void fm7b_join1_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_eqBands-1, i++)
        push_float(&AnonFilter_a0Buf.buffer_in, pop_float(&EqSplitBuf[i].buffer_out));
    ENDFOR
}

void fm7b_split2_duplicate(uint32_t i) {
    float val = pop_float(&EqSplitBuf[i].buffer_in);
    push_float(&BPFCoreBuf[i].buffer_in[0], val);
    push_float(&BPFCoreBuf[i].buffer_in[1], val);
}

void fm7b_join2_round_robin(uint32_t i) {
    push_float(&SubtracerBuf[i].buffer_in, pop_float(&BPFCoreBuf[i].buffer_out[0]));
    push_float(&SubtracerBuf[i].buffer_in, pop_float(&BPFCoreBuf[i].buffer_out[1]));
}

int main(int argc, char **argv) {
    fm7b_init();
    
    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        fm7b_float_one_source();
        //decimate 4 samples after outputting 1
        fm7b_low_pass_filter_4samp();
        fm7b_fmdemodulator();
        fm7b_split1_duplicate();
        FOR(uint32_t, i, 0, <, TheGlobal_eqBands-1, i++)
            fm7b_split2_duplicate(i);
                fm7b_lowpass_filter(i, 0);
                fm7b_lowpass_filter(i, 1);
            fm7b_join2_round_robin(i);

            fm7b_subtracter(i);
            fm7b_amplify(i);
        ENDFOR
        fm7b_join1_round_robin();
        fm7b_equalizer();
        fm7b_float_printer();
    ENDFOR
    return EXIT_SUCCESS;
}
