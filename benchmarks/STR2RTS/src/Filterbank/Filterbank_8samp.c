#include "Filterbank_8samp.h"

TheGlobal_t TheGlobal;
channel_t SourceBuf;
channel_t SinkBuf;
channel_t DelayNStartBuf[TheGlobal_N_samp];
channel_t DelayNEndBuf[TheGlobal_N_samp];
channel_t fb8s_down_sampBuf[TheGlobal_N_samp];
channel_t BranchBuf[TheGlobal_N_samp];
channel_t fb8s_up_sampBuf[TheGlobal_N_samp];
channel_t fb8s_combineBuf;

float current = 0.0;
void fb8s_source() {
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
        push_float(&SourceBuf.buffer_out, current);
        if (current > TheGlobal_MAX_SOURCE) {
            current = 0.0;
        } 
        else {
            current = current + 1.0;
        }
    ENDFOR
}

void fb8s_sink() {
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
        printf("%f\n", pop_float(&SinkBuf.buffer_in));
    ENDFOR
}

void fb8s_delay_n_start(uint32_t k) {
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
        push_float(&DelayNStartBuf[k].buffer_out, pop_float(&DelayNStartBuf[k].buffer_in));
    ENDFOR
}
void fb8s_delay_n_end(uint32_t k) {
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
        push_float(&DelayNEndBuf[k].buffer_out, pop_float(&DelayNEndBuf[k].buffer_in));
    ENDFOR
}

void fb8s_fir_filter_h(uint32_t k) {
    FOR(uint32_t, j, 0, <, TheGlobal_N_samp, j++) 
        float sum = 0;
        FOR(uint32_t, i, 0, <, TheGlobal_N_col, i++) 
            sum += peek_float(&DelayNStartBuf[k].buffer_out, i) * TheGlobal.H[k][TheGlobal_N_col - 1 - i];
        ENDFOR
        pop_float(&DelayNStartBuf[k].buffer_out);
        push_float(&fb8s_down_sampBuf[k].buffer_in, sum);
    ENDFOR
}
void fb8s_fir_filter_f(uint32_t k) {
    FOR(uint32_t, j, 0, <, TheGlobal_N_samp, j++) 
        float sum = 0;
        FOR(uint32_t, i, 0, <, TheGlobal_N_col, i++) 
            sum += peek_float(&DelayNEndBuf[k].buffer_out, i) * TheGlobal.F[k][TheGlobal_N_col - 1 - i];
        ENDFOR
        pop_float(&DelayNEndBuf[k].buffer_out);
        push_float(&BranchBuf[k].buffer_out, sum);
    ENDFOR
}

void fb8s_down_samp(uint32_t k) {
    push_float(&fb8s_up_sampBuf[k].buffer_in,pop_float(&fb8s_down_sampBuf[k].buffer_in));
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp-1, i++)
        pop_float(&fb8s_down_sampBuf[k].buffer_in);
    ENDFOR
}

void fb8s_up_samp(uint32_t k) {
    push_float(&DelayNEndBuf[k].buffer_in, pop_float(&fb8s_up_sampBuf[k].buffer_in));
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp-1, i++)
        push_float(&DelayNEndBuf[k].buffer_in, 0);
    ENDFOR
}

void fb8s_combine() {
    FOR(uint32_t, j, 0, <, TheGlobal_N_samp, j++)
        float sum = 0;
        FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
            sum += pop_float(&fb8s_combineBuf.buffer_in);
        ENDFOR
        push_float(&SinkBuf.buffer_in, sum);
    ENDFOR
}

void fb8s_filterbank_init() {
    FOR(uint32_t, i, 0, <, TheGlobal_N_col, i++)
        FOR(uint32_t, j, 0, <, TheGlobal_N_samp, j++)
            TheGlobal.H[j][i] = i * TheGlobal_N_col + j * TheGlobal_N_samp + j + i + j + 1;
            TheGlobal.F[j][i] = i * j + j * j + j + i;
        ENDFOR
    ENDFOR
        
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
        init_buffer_float(&DelayNStartBuf[i].buffer_in);
        init_buffer_float(&DelayNStartBuf[i].buffer_out);
        init_buffer_float(&DelayNEndBuf[i].buffer_in);
        init_buffer_float(&DelayNEndBuf[i].buffer_out);
        init_buffer_float(&fb8s_down_sampBuf[i].buffer_in);
        init_buffer_float(&BranchBuf[i].buffer_out);
        init_buffer_float(&fb8s_up_sampBuf[i].buffer_in);
    ENDFOR
    init_buffer_float(&SourceBuf.buffer_out);
    init_buffer_float(&SinkBuf.buffer_in);
    init_buffer_float(&fb8s_combineBuf.buffer_in);

    //Delay_N(int N) -- prework
    FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
        FOR(uint32_t, j, 0, <, TheGlobal_N_col - 1, j++)
            push_float(&DelayNStartBuf[i].buffer_out, 0.0);
            push_float(&DelayNEndBuf[i].buffer_out, 0.0);
        ENDFOR
    ENDFOR
}

void fb8s_split_duplicate() {
    FOR(uint32_t, j, 0, <, TheGlobal_N_samp, j++)
        float val = pop_float(&SourceBuf.buffer_out);
        FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
            push_float(&DelayNStartBuf[i].buffer_in, val);
        ENDFOR
    ENDFOR
}
void fb8s_join_round_robin() {
    FOR(uint32_t, k, 0, <, TheGlobal_N_samp, k++)
        FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
            push_float(&fb8s_combineBuf.buffer_in, pop_float(&BranchBuf[i].buffer_out));
        ENDFOR
    ENDFOR
}

int main(int argc, char** argv) {
    fb8s_filterbank_init();

    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        fb8s_source();
        fb8s_split_duplicate();
        FOR(uint32_t, i, 0, <, TheGlobal_N_samp, i++)
            fb8s_delay_n_start(i);
            fb8s_fir_filter_h(i);
            fb8s_down_samp(i);
            fb8s_up_samp(i);
            fb8s_delay_n_end(i);
            fb8s_fir_filter_f(i);
        ENDFOR
        fb8s_join_round_robin();
        fb8s_combine();
        fb8s_sink();
    ENDFOR
    return EXIT_SUCCESS;
}
