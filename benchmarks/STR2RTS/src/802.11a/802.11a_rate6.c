#include "802.11a_rate6.h"

bit_generator_t scramble_seqBuf;
complex_generator_t pilot_generatorBuf;
channel_complex_t short_seqBuf;
channel_complex_t long_seqBuf;

FFT_t add_seqs_FFT;
FFT_t HD_FFT;
halve_t add_seqs_halve;
halve_t hd_halve;

channel_complex_t add_seqs;
channel_complex_t header_and_data;
channel_complex_t AnonFilter_a5Buf;
channel_complex_t AnonFilter_a5Buf_id[2];
channel_complex_t AnonFilter_a5Buf_halve;
channel_complex_t output_cBuf;
channel_bit_t gen_headerBuf;
channel_bit_t conv_code_headerBuf;
channel_bit_t conv_code_dataBuf;
channel_bit_t permute_1[48/16];
channel_b2c_t BPSKBuf;
channel_b2c_t DataModulationBuf;
channel_complex_t header_pilotBuf[2];
channel_complex_t header_insert_pilotBuf;
channel_complex_t header_genZero[5];
channel_bit_t data_init[3]; 
channel_bit_t scrambleBuf;
channel_bit_t idScrambleBuf;
channel_bit_t data_tails;
channel_bit_t permute_1_dataBuf;
channel_bit_t permute_1_dataIdBuf[TheGlobal_BITS_PER_SYM/16];
channel_bit_t permute_2Buf;
channel_bit_t permute_2_swapBuf[2];
channel_complex_t data_pilotBuf;
channel_complex_t AnonFilter_a20Buf;
channel_complex_t data_genZero[5];
header_data_t header_data_splitBuf;
channel_complex_t AnonFilter_a7Buf[3];
channel_complex_t append_symbIdBuf;

void _80211_r6_halve_as() {
    _80211_r6_halve(&add_seqs_halve.halve_in, &add_seqs_halve.halve_out);
}
void _80211_r6_halve_hd() {
    _80211_r6_halve(&hd_halve.halve_in, &hd_halve.halve_out);
}
void _80211_r6_halve(buffer_complex_t *in, buffer_complex_t *out) {
    complex_t numerator = pop_complex(in);
    complex_t denominator = {.real= 2.0f , .imag= 0.0f};
    complex_t val = {
        .real = (((numerator.real * denominator.real) + (numerator.imag * denominator.imag)) / 
                ((denominator.real * denominator.real) + (denominator.imag * denominator.imag))),
        .imag = (((numerator.imag * denominator.real) - (numerator.real * denominator.imag)) / 
                ((denominator.real * denominator.real) + (denominator.imag * denominator.imag)))
    };
    push_complex(out, val);
}

void _80211_r6_halve_and_combine_as() {
    _80211_r6_halve_and_combine(&add_seqs_halve.halve_comb_in, &add_seqs_halve.halve_comb_out);
}
void _80211_r6_halve_and_combine_hd() {
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS , i++)
        _80211_r6_halve_and_combine(&hd_halve.halve_comb_in, &hd_halve.halve_comb_out);
    ENDFOR
    }
void _80211_r6_halve_and_combine_final() {
    _80211_r6_halve_and_combine(&AnonFilter_a5Buf_halve.buffer_in, &AnonFilter_a5Buf_halve.buffer_out);
}
void _80211_r6_halve_and_combine(buffer_complex_t *in, buffer_complex_t *out) {
    complex_t val1 = pop_complex(in);
    complex_t val2 = pop_complex(in);
    complex_t numerator = {
        .real = val1.real + val2.real,
        .imag = val1.imag + val2.imag
    };
    complex_t denominator = {.real= 2.0f , .imag= 0.0f};
    complex_t res = {
        .real = (((numerator.real * denominator.real) + (numerator.imag * denominator.imag)) / 
                ((denominator.real * denominator.real) + (denominator.imag * denominator.imag))),
        .imag = (((numerator.imag * denominator.real) - (numerator.real * denominator.imag)) / 
                ((denominator.real * denominator.real) + (denominator.imag * denominator.imag)))
    };
    push_complex(out, res);
}

// size: 128, 159, 1, 48, 26, TheGlobal_MODULED_DATA, 26*TheGlobal_TOTAL_OUT_SYMBS, 448, 79*TheGlobal_TOTAL_OUT_SYMBS, 79, 320, 80*(TheGlobal_TOTAL_OUT_SYMBS+1)
void _80211_r6_identity(uint32_t size, buffer_complex_t *in, buffer_complex_t *out) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX , i++)
        push_complex(out, pop_complex(in));
    ENDFOR
}

// size: 16, TheGlobal_TOTAL_IN_BITS, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS, TheGlobal_ENCODED_DATA/(TheGlobal_BITS_PER_SYM/16), TheGlobal_ENCODED_DATA, TheGlobal_ENCODED_DATA/2
void _80211_r6_identity_bit(uint32_t size, buffer_bit_t *in, buffer_bit_t *out) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX , i++)
        push_bit(out, pop_bit(in));
    ENDFOR
}

void _80211_r6_remove_first_as() {
    FOR(uint32_t, i, 0, <, 4 , i++)
        _80211_r6_remove_first(32, &add_seqs_FFT.rem_f_buffer_in, &add_seqs_FFT.rem_f_buffer_out);
    ENDFOR
}
void _80211_r6_remove_first_hd() {
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS+1 , i++)
        _80211_r6_remove_first(16, &HD_FFT.rem_f_buffer_in, &HD_FFT.rem_f_buffer_out);
    ENDFOR
}

void _80211_r6_remove_first(int post_total, buffer_complex_t *in, buffer_complex_t *out) { //min 16 - max 32
    int stop = 64 - post_total;

    FOR2(uint32_t, i, 0, <, stop, 48, i++)
        pop_complex(in);
    ENDFOR

    FOR2(uint32_t, i, 0, <, post_total, 32, i++)
      push_complex(out, pop_complex(in));
    ENDFOR
}

void _80211_r6_remove_last_as() {
    FOR(uint32_t, i, 0, <, 4 , i++)
        _80211_r6_remove_last(&add_seqs_FFT.rem_l_buffer_in, &add_seqs_FFT.rem_l_buffer_out);
    ENDFOR
}
void _80211_r6_remove_last_hd() {
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS+1 , i++)
        _80211_r6_remove_last(&HD_FFT.rem_l_buffer_in, &HD_FFT.rem_l_buffer_out);
    ENDFOR
}

void _80211_r6_remove_last(buffer_complex_t *in, buffer_complex_t *out) {
    //for(int i=0; i<1; i++)
    push_complex(out, pop_complex(in));

    FOR(uint32_t, i, 1, <, 64, i++)
        pop_complex(in);
    ENDFOR
}

void _80211_r6_zero_tail_bits() { // transmit.str:360
    FOR(uint32_t, i, 0, <, 16+TheGlobal_LENGTH*8, i++)
      push_bit(&data_tails.buffer_out, pop_bit(&data_tails.buffer_in));
    ENDFOR

    FOR(uint32_t, i, 0, <, 6, i++)
      push_bit(&data_tails.buffer_out, 0);
      pop_bit(&data_tails.buffer_in);
    ENDFOR

    FOR2(uint32_t, i, 16+TheGlobal_LENGTH*8+6, <, TheGlobal_TOTAL_OUT_BITS, TheGlobal_TOTAL_OUT_BITS-(16+TheGlobal_LENGTH*8+6), i++)
      push_bit(&data_tails.buffer_out, pop_bit(&data_tails.buffer_in));
    ENDFOR
}

void _80211_r6_scramble_seq() {
    BIT out;
    FOR(uint32_t, i, 0, <, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS , i++)
        out = scramble_seqBuf.temp[6]^scramble_seqBuf.temp[3];

        FOR3(uint32_t, i, 6, >, 0, i--)
          scramble_seqBuf.temp[i] = scramble_seqBuf.temp[i-1];
        ENDFOR

        scramble_seqBuf.temp[0] = out;
        push_bit(&scramble_seqBuf.buffer_out, out);
    ENDFOR
}
void _80211_r6_xor_pair() {
    FOR(uint32_t, i, 0, <, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS , i++)
        push_bit(&data_tails.buffer_in, pop_bit(&scrambleBuf.buffer_out)^pop_bit(&scrambleBuf.buffer_out));
    ENDFOR
}

void _80211_r6_pilot_generator() { // transmit.str:787
    int factor;
    BIT out;
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        out = pilot_generatorBuf.temp[6]^pilot_generatorBuf.temp[3];

        FOR3(uint32_t, i, 7-1, >, 0, i--)
          pilot_generatorBuf.temp[i] = pilot_generatorBuf.temp[i-1];
        ENDFOR

        pilot_generatorBuf.temp[0] = out;

        if(out==0)
          factor = 1;
        else
          factor = -1;

        complex_t val = {
            .real = factor,
            .imag = 0
        };
        complex_t neg_val = {
            .real = factor*-1,
            .imag = 0
        };

        push_complex(&pilot_generatorBuf.buffer_out, val); 
        push_complex(&pilot_generatorBuf.buffer_out, val); 
        push_complex(&pilot_generatorBuf.buffer_out, val); 
        push_complex(&pilot_generatorBuf.buffer_out, neg_val);
    ENDFOR
}

void _80211_r6_fftshift_1d(buffer_complex_t *in, buffer_complex_t *out) { // transmit.str:891
    FOR(uint32_t, i, 32, <, 64, i++)// transmit.str:900
        push_complex(out, peek_complex(in, i));
    ENDFOR

    FOR(uint32_t, i, 0, <, 32 , i++)
        push_complex(out, pop_complex(in));
    ENDFOR

    FOR2(uint32_t, i, 32, <, 64, 32 , i++)
        pop_complex(in);
    ENDFOR
}

void _80211_r6_fftshift_1d_as() {
    _80211_r6_fftshift_1d(&add_seqs_FFT.buffer_in, &add_seqs_FFT.shift_1d_buffer_out);
    _80211_r6_fftshift_1d(&add_seqs_FFT.buffer_in, &add_seqs_FFT.shift_1d_buffer_out);
}
void _80211_r6_fftshift_1d_hd() {
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS+1 , i++)
        _80211_r6_fftshift_1d(&HD_FFT.buffer_in, &HD_FFT.shift_1d_buffer_out);
    ENDFOR
}

void _80211_r6_short_seq() {
    complex_t zero = { .real = 0.0f, .imag = 0.0f }; // transmit.str:946
    complex_t pos = { .real = ((sqrt((13.0f / 6.0f)) * 1.0f) - (0.0f * 1.0f)),
                      .imag = ((sqrt((13.0f / 6.0f)) * 1.0f) + (0.0f * 1.0f)) }; // transmit.str:947
    complex_t neg = { .real = ((sqrt((13.0f / 6.0f)) * -(1.0f)) - (0.0f * -(1.0f))),
                      .imag = ((sqrt((13.0f / 6.0f)) * -(1.0f)) + (0.0f * -(1.0f))) }; // transmit.str:948
    
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, neg);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, neg);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, neg);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, neg);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, neg);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, pos);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero);
    push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero); push_complex(&short_seqBuf.buffer_out, zero);
}
void _80211_r6_long_seq() { // transmit.str:978
    complex_t zero = { .real = 0.0f, .imag = 0.0f }; // transmit.str:979
    complex_t pos = { .real = 1.0f, .imag = 0 }; // transmit.str:980
    complex_t neg = { .real = -(1.0f), .imag = 0 }; // transmit.str:981
    
    push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero);
    push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, neg);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg);
    push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, zero);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, neg);
    push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, neg); push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, pos); push_complex(&long_seqBuf.buffer_out, pos);
    push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero); push_complex(&long_seqBuf.buffer_out, zero);
}

void _80211_r6_fft_reorder_simple_as1() {
    _80211_r6_fft_reorder_simple(64, &add_seqs_FFT.shift_1d_buffer_out, &add_seqs_FFT.reorder_buffer_out[0]);
    _80211_r6_fft_reorder_simple(64, &add_seqs_FFT.shift_1d_buffer_out, &add_seqs_FFT.reorder_buffer_out[0]);
}
void _80211_r6_fft_reorder_simple_as2() {
    FOR(uint32_t, i, 0, <, 4 , i++)
        _80211_r6_fft_reorder_simple(32, &add_seqs_FFT.reorder_buffer_out[0], &add_seqs_FFT.reorder_buffer_out[1]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_as3() {
    FOR(uint32_t, i, 0, <, 8 , i++)
        _80211_r6_fft_reorder_simple(16, &add_seqs_FFT.reorder_buffer_out[1], &add_seqs_FFT.reorder_buffer_out[2]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_as4() {
    FOR(uint32_t, i, 0, <, 16 , i++)
        _80211_r6_fft_reorder_simple(8, &add_seqs_FFT.reorder_buffer_out[2], &add_seqs_FFT.reorder_buffer_out[3]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_as5() {
    FOR(uint32_t, i, 0, <, 32 , i++)
        _80211_r6_fft_reorder_simple(4, &add_seqs_FFT.reorder_buffer_out[3], &add_seqs_FFT.reorder_buffer_out[4]);
    ENDFOR
}

void _80211_r6_fft_reorder_simple_hd1() {
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS+1 , i++)
        _80211_r6_fft_reorder_simple(64, &HD_FFT.shift_1d_buffer_out, &HD_FFT.reorder_buffer_out[0]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_hd2() {
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*2 , i++)
        _80211_r6_fft_reorder_simple(32, &HD_FFT.reorder_buffer_out[0], &HD_FFT.reorder_buffer_out[1]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_hd3() {
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*4 , i++)
        _80211_r6_fft_reorder_simple(16, &HD_FFT.reorder_buffer_out[1], &HD_FFT.reorder_buffer_out[2]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_hd4() {
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*8 , i++)
        _80211_r6_fft_reorder_simple(8, &HD_FFT.reorder_buffer_out[2], &HD_FFT.reorder_buffer_out[3]);
    ENDFOR
}
void _80211_r6_fft_reorder_simple_hd5() {
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*16 , i++)
        _80211_r6_fft_reorder_simple(4, &HD_FFT.reorder_buffer_out[3], &HD_FFT.reorder_buffer_out[4]);
    ENDFOR
}

void _80211_r6_fft_reorder_simple(int iter, buffer_complex_t *in, buffer_complex_t *out) { //min 4 max 64
    FOR2(uint32_t, i, 0, <, iter, 64, i+=2)
        push_complex(out, peek_complex(in, i));
    ENDFOR

    FOR2(uint32_t, i, 1, <, iter, 32, i+=2)
        push_complex(out, peek_complex(in, i));
    ENDFOR

    FOR2(uint32_t, i, 0, <, iter, 64 , i++)
        pop_complex(in);
    ENDFOR
}

void _80211_r6_combine_idft_as1() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, 64 , i++)
        _80211_r6_combine_idft(2, w_init_real, &add_seqs_FFT.reorder_buffer_out[4], &add_seqs_FFT.IDFT_buffer_out[0]);
    ENDFOR
}
void _80211_r6_combine_idft_as2() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, 32 , i++)
        _80211_r6_combine_idft(4, w_init_real, &add_seqs_FFT.IDFT_buffer_out[0], &add_seqs_FFT.IDFT_buffer_out[1]);
    ENDFOR
}
void _80211_r6_combine_idft_as3() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, 16 , i++)
        _80211_r6_combine_idft(8, w_init_real, &add_seqs_FFT.IDFT_buffer_out[1], &add_seqs_FFT.IDFT_buffer_out[2]);
    ENDFOR
}
void _80211_r6_combine_idft_as4() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, 8 , i++)
        _80211_r6_combine_idft(16, w_init_real, &add_seqs_FFT.IDFT_buffer_out[2], &add_seqs_FFT.IDFT_buffer_out[3]);
    ENDFOR
}
void _80211_r6_combine_idft_as5() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, 4 , i++)
        _80211_r6_combine_idft(32, w_init_real, &add_seqs_FFT.IDFT_buffer_out[3], &add_seqs_FFT.IDFT_buffer_out[4]);
    ENDFOR
}
void _80211_r6_combine_idft_final_as() {
    float w_init_real = 1.0 / ((float)64.0f); // FFT6.str:82
    _80211_r6_combine_idft(64, w_init_real, &add_seqs_FFT.IDFT_buffer_out[4], &add_seqs_FFT.IDFTF_buffer_out);
    _80211_r6_combine_idft(64, w_init_real, &add_seqs_FFT.IDFT_buffer_out[4], &add_seqs_FFT.IDFTF_buffer_out);
}

void _80211_r6_combine_idft_hd1() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*32 , i++)
        _80211_r6_combine_idft(2, w_init_real, &HD_FFT.reorder_buffer_out[4], &HD_FFT.IDFT_buffer_out[0]);
    ENDFOR
}
void _80211_r6_combine_idft_hd2() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*16 , i++)
        _80211_r6_combine_idft(4, w_init_real, &HD_FFT.IDFT_buffer_out[0], &HD_FFT.IDFT_buffer_out[1]);
    ENDFOR
}
void _80211_r6_combine_idft_hd3() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*8 , i++)
        _80211_r6_combine_idft(8, w_init_real, &HD_FFT.IDFT_buffer_out[1], &HD_FFT.IDFT_buffer_out[2]);
    ENDFOR
}
void _80211_r6_combine_idft_hd4() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*4 , i++)
        _80211_r6_combine_idft(16, w_init_real, &HD_FFT.IDFT_buffer_out[2], &HD_FFT.IDFT_buffer_out[3]);
    ENDFOR
}
void _80211_r6_combine_idft_hd5() {// FFT6.str:169
    float w_init_real = 1.0;
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*2 , i++)
        _80211_r6_combine_idft(32, w_init_real, &HD_FFT.IDFT_buffer_out[3], &HD_FFT.IDFT_buffer_out[4]);
    ENDFOR
}
void _80211_r6_combine_idft_final_hd() {
    float w_init_real = 1.0 / ((float)64.0f); // FFT6.str:82
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS+1 , i++)
        _80211_r6_combine_idft(64, w_init_real, &HD_FFT.IDFT_buffer_out[4], &HD_FFT.IDFTF_buffer_out);
    ENDFOR
}

void _80211_r6_combine_idft(int n, float w_init_real, buffer_complex_t *in, buffer_complex_t *out) { //min 2 max 64
    complex_t wn = {
        .real = cos(((2 * 3.141592653589793f) / n)), // FFT6.str:44
        .imag = sin(((2 * 3.141592653589793f) / n)) // FFT6.str:45
    };
    
    complex_t w, y0, y1, y1w, w_next;
    w.real = w_init_real;
    w.imag = 0.0;
    complex_t results[n];

    FOR2(uint32_t, i, 0, <, n/2, 32, i++)
        complex_t val = peek_complex(in, i);
        y0.real = w_init_real * val.real;
        y0.imag = w_init_real * val.imag;

        y1 = peek_complex(in, n/2 + i);
        y1w.real = (y1.real * w.real) - (y1.imag * w.imag);
        y1w.imag = (y1.real * w.imag) + (y1.imag * w.real);

        results[i].real = y0.real + y1w.real;
        results[i].imag = y0.imag + y1w.imag;

        results[n/2 + i].real = y0.real - y1w.real;
        results[n/2 + i].imag = y0.imag - y1w.imag;

        w_next.real = (w.real * wn.real) - (w.imag * wn.imag);
        w_next.imag = (w.real * wn.imag) + (w.imag * wn.real);
        
        w.real = w_next.real;
        w.imag = w_next.imag;
    ENDFOR

    FOR2(uint32_t, i, 0, <, n, 64, i++)
        pop_complex(in);
        push_complex(out, results[i]);
    ENDFOR
}

void _80211_r6_generate_header() {
    int temp = 1;
    boolean odd = FALSE; // for parity bit

// first push the 4 bit code for data rate
    push_bit(&gen_headerBuf.buffer_out, 1); 
    push_bit(&gen_headerBuf.buffer_out, 1); 
    push_bit(&gen_headerBuf.buffer_out, 0); 
    push_bit(&gen_headerBuf.buffer_out, 1); 
    odd = TRUE;

    push_bit(&gen_headerBuf.buffer_out, 0); // reserved bit

   // push length (number of octets) as a 12 bit number, LSB first
    FOR(uint32_t, i, 0, <, 12, i++)
      if((temp & TheGlobal_LENGTH) == 0) {
        push_bit(&gen_headerBuf.buffer_out, 0);
      }
      else {
        push_bit(&gen_headerBuf.buffer_out, 1);
        odd = !odd;
      }
      temp *= 2;
    ENDFOR


    // parity bit
    if(odd)
      push_bit(&gen_headerBuf.buffer_out, 1);
    else
      push_bit(&gen_headerBuf.buffer_out, 0);

    // tail bits
    FOR(uint32_t, i, 0, <, 6, i++)
      push_bit(&gen_headerBuf.buffer_out, 0);
    ENDFOR
}

void _80211_r6_anon_filter_a8_header(){
    FOR(uint32_t, i, 0, <, 24, i++)
        push_bit(&conv_code_headerBuf.buffer_in, pop_bit(&gen_headerBuf.buffer_out));
    ENDFOR
}
void _80211_r6_anon_filter_a8_data(){
    FOR(uint32_t, i, 0, <, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS , i++)
        push_bit(&conv_code_dataBuf.buffer_in, pop_bit(&data_tails.buffer_out));
    ENDFOR
}

void _80211_r6_conv_code_header() {
    FOR(uint32_t, i, 0, <, 24 , i++)
        _80211_r6_conv_code_filter(&conv_code_headerBuf.buffer_in, &conv_code_headerBuf.buffer_out);
    ENDFOR
}
void _80211_r6_conv_code_data() {
    FOR(uint32_t, i, 0, <, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS , i++)
        _80211_r6_conv_code_filter(&conv_code_dataBuf.buffer_in, &permute_1_dataBuf.buffer_in);
    ENDFOR
}

void _80211_r6_conv_code_filter(buffer_bit_t *in, buffer_bit_t *out) {
    BIT out_a, out_b;

    out_a = peek_bit(in, 6)^peek_bit(in, 4)^peek_bit(in, 3)^peek_bit(in, 1)^peek_bit(in, 0);
    out_b = peek_bit(in, 6)^peek_bit(in, 5)^peek_bit(in, 4)^peek_bit(in, 3)^peek_bit(in, 0);
    pop_bit(in);

    push_bit(out, out_a);
    push_bit(out, out_b);
}

void _80211_r6_bpsk_header() {
    BIT b;
    complex_t c;
    FOR(uint32_t, i, 0, <, 48 , i++)
        b = pop_bit(&BPSKBuf.buffer_in);
        c.imag = 0.0;
        if(b==0)
          c.real = -1.0; 
        else
          c.real = 1.0;

        push_complex(&BPSKBuf.buffer_out, c);
    ENDFOR
}
void _80211_r6_bpsk_data() {
    BIT b;
    complex_t c;
    FOR(uint32_t, i, 0, <, TheGlobal_ENCODED_DATA , i++)
        b = pop_bit(&permute_2Buf.buffer_out);
        c.imag = 0.0;
        if(b==0)
          c.real = -1.0; 
        else
          c.real = 1.0;

        push_complex(&DataModulationBuf.buffer_out, c);
    ENDFOR
}

void _80211_r6_header_pilot_generator() {
    complex_t one = {
        .real = 1.0,
        .imag = 0.0
    };
    complex_t neg_one = {
        .real = -1.0,
        .imag = 0.0
    };

    push_complex(&header_pilotBuf[1].buffer_out, one); 
    push_complex(&header_pilotBuf[1].buffer_out, one); 
    push_complex(&header_pilotBuf[1].buffer_out, one); 
    push_complex(&header_pilotBuf[1].buffer_out, neg_one);
}

void _80211_r6_insert_pilots(buffer_complex_t *in, buffer_complex_t *out) {
    complex_t p1,p2,p3,p4;
    p1 = peek_complex(in, 48); p2 = peek_complex(in, 49); p3 = peek_complex(in, 50); p4 = peek_complex(in, 51);

    FOR(uint32_t, i, 0, <, 5, i++)
      push_complex(out, pop_complex(in));
    ENDFOR

    push_complex(out, p1);

    FOR(uint32_t, i, 0, <, 13, i++)
      push_complex(out, pop_complex(in));
    ENDFOR

    push_complex(out, p2);

    FOR(uint32_t, i, 0, <, 12, i++) // no zero value
      push_complex(out, pop_complex(in));
    ENDFOR

    push_complex(out, p3);

    FOR(uint32_t, i, 0, <, 13, i++)
      push_complex(out, pop_complex(in));
    ENDFOR

    push_complex(out, p4);

    FOR(uint32_t, i, 0, <, 5, i++)
      push_complex(out, pop_complex(in));
    ENDFOR

    pop_complex(in); pop_complex(in); pop_complex(in); pop_complex(in);
}

void _80211_r6_header_insert_pilots() {
    _80211_r6_insert_pilots(&header_insert_pilotBuf.buffer_in, &header_insert_pilotBuf.buffer_out);
}

// reps: 1, 5, 6, 6*TheGlobal_TOTAL_OUT_SYMBS, TheGlobal_TOTAL_OUT_SYMBS, 5*TheGlobal_TOTAL_OUT_SYMBS
void _80211_r6_zero_gen_complex(uint32_t reps, buffer_complex_t *out) {
    complex_t c = {
        .real = 0.0,
        .imag = 0.0
    };
    FOR2(uint32_t, i, 0, <, reps, 6*TheGlobal_TOTAL_OUT_SYMBS , i++)
        push_complex(out, c);
    ENDFOR
}

// reps: 16, 6+TheGlobal_EXTRA_BITS
void _80211_r6_zero_gen(uint32_t reps, buffer_bit_t *out) {
    FOR2(uint32_t, i, 0, <, reps, 6+TheGlobal_EXTRA_BITS , i++)
        push_bit(out, 0);
    ENDFOR
}

void _80211_r6_printer() {
    FOR(uint32_t, i, 0, <, 320+1+80*(TheGlobal_TOTAL_OUT_SYMBS+1) , i++)
        complex_t c = pop_complex(&output_cBuf.buffer_in);
        printf("%.12f\n",c.real);
        printf("%.12f\n",c.imag);
    ENDFOR
}

void _80211_r6_anon_filter_a20() {
    complex_t p1,p2,p3,p4;
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        p1 = peek_complex(&AnonFilter_a20Buf.buffer_in, 48); 
        p2 = peek_complex(&AnonFilter_a20Buf.buffer_in, 49); 
        p3 = peek_complex(&AnonFilter_a20Buf.buffer_in, 50); 
        p4 = peek_complex(&AnonFilter_a20Buf.buffer_in, 51);

        FOR(uint32_t, i, 0, <, 5, i++)
          push_complex(&AnonFilter_a20Buf.buffer_out, pop_complex(&AnonFilter_a20Buf.buffer_in));
        ENDFOR

        push_complex(&AnonFilter_a20Buf.buffer_out, p1);

        FOR(uint32_t, i, 0, <, 13, i++)
          push_complex(&AnonFilter_a20Buf.buffer_out, pop_complex(&AnonFilter_a20Buf.buffer_in));
        ENDFOR

        push_complex(&AnonFilter_a20Buf.buffer_out, p2);

        FOR(uint32_t, i, 0, <, 12, i++) // no zero value
          push_complex(&AnonFilter_a20Buf.buffer_out, pop_complex(&AnonFilter_a20Buf.buffer_in));
        ENDFOR

        push_complex(&AnonFilter_a20Buf.buffer_out, p3);

        FOR(uint32_t, i, 0, <, 13, i++)
          push_complex(&AnonFilter_a20Buf.buffer_out, pop_complex(&AnonFilter_a20Buf.buffer_in));
        ENDFOR

        push_complex(&AnonFilter_a20Buf.buffer_out, p4);

        FOR(uint32_t, i, 0, <, 5, i++)
          push_complex(&AnonFilter_a20Buf.buffer_out, pop_complex(&AnonFilter_a20Buf.buffer_in));
        ENDFOR

        pop_complex(&AnonFilter_a20Buf.buffer_in); 
        pop_complex(&AnonFilter_a20Buf.buffer_in); 
        pop_complex(&AnonFilter_a20Buf.buffer_in); 
        pop_complex(&AnonFilter_a20Buf.buffer_in);
    }
}

void _80211_r6_transmit_init() {
    FileReader_init(TheGlobal_FILEIN, "bit");
    
    FOR(uint32_t, i, 1, <=, 6, i++) // transmit.str:790
        pilot_generatorBuf.temp[i] = 1; // transmit.str:790
    ENDFOR
    pilot_generatorBuf.temp[0] = 0; // transmit.str:791
    init_buffer_complex(&pilot_generatorBuf.buffer_out);
    
    scramble_seqBuf.temp[6] = 1; // transmit.str:417
    scramble_seqBuf.temp[5] = 0; // transmit.str:418
    scramble_seqBuf.temp[4] = 1; // transmit.str:419
    scramble_seqBuf.temp[3] = 1; // transmit.str:420
    scramble_seqBuf.temp[2] = 1; // transmit.str:421
    scramble_seqBuf.temp[1] = 0; // transmit.str:422
    scramble_seqBuf.temp[0] = 1; // transmit.str:423
    init_buffer_bit(&scramble_seqBuf.buffer_out);
    
    init_buffer_complex(&short_seqBuf.buffer_out);
    init_buffer_complex(&long_seqBuf.buffer_out);

    init_buffer_complex(&add_seqs_FFT.buffer_in);
    init_buffer_complex(&add_seqs_FFT.shift_1d_buffer_out);
    FOR(uint32_t, i, 0, <, 5 , i++)
        init_buffer_complex(&add_seqs_FFT.reorder_buffer_out[i]);
        init_buffer_complex(&add_seqs_FFT.IDFT_buffer_out[i]);
    ENDFOR
    init_buffer_complex(&add_seqs_FFT.IDFTF_buffer_out);
    init_buffer_complex(&add_seqs_FFT.rem_f_buffer_in);
    init_buffer_complex(&add_seqs_FFT.rem_f_buffer_out);
    init_buffer_complex(&add_seqs_FFT.rem_l_buffer_in);
    init_buffer_complex(&add_seqs_FFT.rem_l_buffer_out);
    FOR(uint32_t, i, 0, <, 2 , i++)
        init_buffer_complex(&add_seqs_FFT.id_buffer_in[i]);
        init_buffer_complex(&add_seqs_FFT.id_buffer_out[i]);
    ENDFOR
    init_buffer_complex(&add_seqs_FFT.buffer_out);
    
    init_buffer_complex(&HD_FFT.buffer_in);
    init_buffer_complex(&HD_FFT.shift_1d_buffer_out);
    FOR(uint32_t, i, 0, <, 5 , i++)
        init_buffer_complex(&HD_FFT.reorder_buffer_out[i]);
        init_buffer_complex(&HD_FFT.IDFT_buffer_out[i]);
    ENDFOR
    init_buffer_complex(&HD_FFT.IDFTF_buffer_out);
    init_buffer_complex(&HD_FFT.rem_f_buffer_in);
    init_buffer_complex(&HD_FFT.rem_f_buffer_out);
    init_buffer_complex(&HD_FFT.rem_l_buffer_in);
    init_buffer_complex(&HD_FFT.rem_l_buffer_out);
    FOR(uint32_t, i, 0, <, 2 , i++)
        init_buffer_complex(&HD_FFT.id_buffer_in[i]);
        init_buffer_complex(&HD_FFT.id_buffer_out[i]);
    ENDFOR
    init_buffer_complex(&HD_FFT.buffer_out);
    
    init_buffer_complex(&add_seqs_halve.halve_in);
    init_buffer_complex(&add_seqs_halve.halve_out);
    FOR(uint32_t, i, 0, <, 3 , i++)
        init_buffer_complex(&add_seqs_halve.id_in[i]);
        init_buffer_complex(&add_seqs_halve.id_out[i]);
    ENDFOR
    init_buffer_complex(&add_seqs_halve.halve_comb_in);
    init_buffer_complex(&add_seqs_halve.halve_comb_out);
    
    init_buffer_complex(&hd_halve.halve_in);
    init_buffer_complex(&hd_halve.halve_out);
    FOR(uint32_t, i, 0, <, 3 , i++)
        init_buffer_complex(&hd_halve.id_in[i]);
        init_buffer_complex(&hd_halve.id_out[i]);
    ENDFOR
    init_buffer_complex(&hd_halve.halve_comb_in);
    init_buffer_complex(&hd_halve.halve_comb_out);

    init_buffer_complex(&add_seqs.buffer_in);
    init_buffer_complex(&add_seqs.buffer_out);
    init_buffer_complex(&header_and_data.buffer_in);
    init_buffer_complex(&header_and_data.buffer_out);
    init_buffer_complex(&AnonFilter_a5Buf.buffer_in);
    init_buffer_complex(&AnonFilter_a5Buf.buffer_out);
    FOR(uint32_t, i, 0, <, 2 , i++)
        init_buffer_complex(&AnonFilter_a5Buf_id[i].buffer_in);
        init_buffer_complex(&AnonFilter_a5Buf_id[i].buffer_out);
    ENDFOR
    init_buffer_complex(&AnonFilter_a5Buf_halve.buffer_in);
    init_buffer_complex(&AnonFilter_a5Buf_halve.buffer_out);
    init_buffer_complex(&output_cBuf.buffer_in);
    
    init_buffer_bit(&gen_headerBuf.buffer_in);
    init_buffer_bit(&gen_headerBuf.buffer_out);
    
    init_buffer_bit(&conv_code_headerBuf.buffer_in);
    init_buffer_bit(&conv_code_headerBuf.buffer_out);
    //-- AnonFilter_a8_header_init pre_work // transmit.str:460
    FOR(uint32_t, i, 0, <, 6, i++)
        push_bit(&conv_code_headerBuf.buffer_in, 0);
    ENDFOR
    init_buffer_bit(&conv_code_dataBuf.buffer_in);
    init_buffer_bit(&conv_code_dataBuf.buffer_out);
    //-- AnonFilter_a8_data_init pre_work // transmit.str:460
    FOR(uint32_t, i, 0, <, 6, i++)
        push_bit(&conv_code_dataBuf.buffer_in, 0);
    ENDFOR
    
    FOR(uint32_t, i, 0, <, 48/16 , i++)
        init_buffer_bit(&permute_1[i].buffer_in);
        init_buffer_bit(&permute_1[i].buffer_out);
    ENDFOR
    init_buffer_bit(&BPSKBuf.buffer_in);
    init_buffer_complex(&BPSKBuf.buffer_out);
    
    FOR(uint32_t, i, 0, <, 2 , i++)
        init_buffer_complex(&header_pilotBuf[i].buffer_in);
        init_buffer_complex(&header_pilotBuf[i].buffer_out);
    ENDFOR
    
    init_buffer_complex(&header_insert_pilotBuf.buffer_in);
    init_buffer_complex(&header_insert_pilotBuf.buffer_out);
    
    FOR(uint32_t, i, 0, <, 5 , i++)
        init_buffer_complex(&header_genZero[i].buffer_in);
        init_buffer_complex(&header_genZero[i].buffer_out);
    ENDFOR
    
    FOR(uint32_t, i, 0, <, 3 , i++)
        init_buffer_bit(&data_init[i].buffer_in);
        init_buffer_bit(&data_init[i].buffer_out);
    ENDFOR
    init_buffer_bit(&DataModulationBuf.buffer_in);
    init_buffer_complex(&DataModulationBuf.buffer_out);
    
    init_buffer_bit(&scrambleBuf.buffer_in);
    init_buffer_bit(&scrambleBuf.buffer_out);
    init_buffer_bit(&idScrambleBuf.buffer_in);
    init_buffer_bit(&idScrambleBuf.buffer_out);
    init_buffer_bit(&data_tails.buffer_in);
    init_buffer_bit(&data_tails.buffer_out);
    
    FOR(uint32_t, i, 0, <, TheGlobal_BITS_PER_SYM/16 , i++)
        init_buffer_bit(&permute_1_dataIdBuf[i].buffer_in);
        init_buffer_bit(&permute_1_dataIdBuf[i].buffer_out);
    ENDFOR
    init_buffer_bit(&permute_1_dataBuf.buffer_in);
    init_buffer_bit(&permute_1_dataBuf.buffer_out);
    init_buffer_bit(&permute_2Buf.buffer_in);
    init_buffer_bit(&permute_2Buf.buffer_out);
    FOR(uint32_t, i, 0, <, 2 , i++)
        init_buffer_bit(&permute_2_swapBuf[i].buffer_in);
        init_buffer_bit(&permute_2_swapBuf[i].buffer_out);
    ENDFOR
    init_buffer_complex(&data_pilotBuf.buffer_in);
    init_buffer_complex(&data_pilotBuf.buffer_out);
    init_buffer_complex(&AnonFilter_a20Buf.buffer_in);
    init_buffer_complex(&AnonFilter_a20Buf.buffer_out);
    
    FOR(uint32_t, i, 0, <, 5 , i++)
        init_buffer_complex(&data_genZero[i].buffer_in);
        init_buffer_complex(&data_genZero[i].buffer_out);
    ENDFOR
    init_buffer_bit(&header_data_splitBuf.buffer_in);
    init_buffer_complex(&header_data_splitBuf.buffer_header_out);
    init_buffer_complex(&header_data_splitBuf.buffer_data_out);
    
    FOR(uint32_t, i, 0, <, 3 , i++)
        init_buffer_complex(&AnonFilter_a7Buf[i].buffer_in);
        init_buffer_complex(&AnonFilter_a7Buf[i].buffer_out);
    ENDFOR
    init_buffer_complex(&append_symbIdBuf.buffer_in);
    init_buffer_complex(&append_symbIdBuf.buffer_out);
    
}

void _80211_r6_split1_round_robin() {}
void _80211_r6_join1_weighted_round_robin() { // transmit.str:144
    FOR(uint32_t, i, 0, <, 321 , i++)
        push_complex(&AnonFilter_a5Buf.buffer_in, pop_complex(&add_seqs.buffer_out));
    ENDFOR
    
    FOR(uint32_t, i, 0, <, ((80 * (TheGlobal_TOTAL_OUT_SYMBS + 1)) + 1) , i++)
        push_complex(&AnonFilter_a5Buf.buffer_in, pop_complex(&header_and_data.buffer_out));
    ENDFOR
}

void _80211_r6_split14_round_robin() {}
void _80211_r6_join14_weighted_round_robin() { // transmit.str:1014
    FOR(uint32_t, i, 0, <, 64 , i++)
        push_complex(&add_seqs_FFT.buffer_in, pop_complex(&short_seqBuf.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 64 , i++)
        push_complex(&add_seqs_FFT.buffer_in, pop_complex(&long_seqBuf.buffer_out));
    ENDFOR
}
void _80211_r6_split13_addseq_duplicate() {
    FOR(uint32_t, i, 0, <, 128 , i++)
        complex_t tmp = pop_complex(&add_seqs_FFT.IDFTF_buffer_out);
        push_complex(&add_seqs_FFT.rem_f_buffer_in, tmp);
        push_complex(&add_seqs_FFT.id_buffer_in[0], tmp);
        push_complex(&add_seqs_FFT.id_buffer_in[1], tmp);
        push_complex(&add_seqs_FFT.rem_l_buffer_in, tmp);
    ENDFOR
}
void _80211_r6_join13_addseq_weighted_round_robin() { // transmit.str:844
    FOR(uint32_t, i, 0, <, 2 , i++)
        FOR(uint32_t, j, 0, <, 32 , j++)
            push_complex(&add_seqs_FFT.buffer_out, pop_complex(&add_seqs_FFT.rem_f_buffer_out));
        ENDFOR
        FOR(uint32_t, j, 0, <, 64 , j++)
            push_complex(&add_seqs_FFT.buffer_out, pop_complex(&add_seqs_FFT.id_buffer_out[0]));
        ENDFOR
        FOR(uint32_t, j, 0, <, 64 , j++)
            push_complex(&add_seqs_FFT.buffer_out, pop_complex(&add_seqs_FFT.id_buffer_out[1]));
        ENDFOR
        push_complex(&add_seqs_FFT.buffer_out, pop_complex(&add_seqs_FFT.rem_l_buffer_out));
    ENDFOR
}
void _80211_r6_split13_hd_duplicate() {
    FOR(uint32_t, i, 0, <, (TheGlobal_TOTAL_OUT_SYMBS+1)*64 , i++)
        complex_t tmp = pop_complex(&HD_FFT.IDFTF_buffer_out);
        push_complex(&HD_FFT.rem_f_buffer_in, tmp);
        push_complex(&HD_FFT.id_buffer_in[0], tmp);
        push_complex(&HD_FFT.rem_l_buffer_in, tmp);
    ENDFOR
}
void _80211_r6_join13_hd_weighted_round_robin() { // transmit.str:844
    //ou push_complex .buffer_out
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_SYMBS+1 , i++)
        FOR(uint32_t, j, 0, <, 16 , j++)
            push_complex(&HD_FFT.buffer_out, pop_complex(&HD_FFT.rem_f_buffer_out));
        ENDFOR
        FOR(uint32_t, j, 0, <, 64 , j++)
            push_complex(&HD_FFT.buffer_out, pop_complex(&HD_FFT.id_buffer_out[0]));
        ENDFOR
        push_complex(&HD_FFT.buffer_out, pop_complex(&HD_FFT.rem_l_buffer_out));
    ENDFOR
}

void _80211_r6_split15_weighted_round_robin(){ // transmit.str:1020  AnonFilter_a14
    push_complex(&add_seqs_halve.halve_in, pop_complex(&add_seqs_FFT.buffer_out));
    FOR(uint32_t, i, 0, <, 159 , i++)
        push_complex(&add_seqs_halve.id_in[0], pop_complex(&add_seqs_FFT.buffer_out));
    ENDFOR
    push_complex(&add_seqs_halve.halve_comb_in, pop_complex(&add_seqs_FFT.buffer_out));
    push_complex(&add_seqs_halve.halve_comb_in, pop_complex(&add_seqs_FFT.buffer_out));
    FOR(uint32_t, i, 0, <, 159 , i++)
        push_complex(&add_seqs_halve.id_in[1], pop_complex(&add_seqs_FFT.buffer_out));
    ENDFOR
    push_complex(&add_seqs_halve.id_in[2], pop_complex(&add_seqs_FFT.buffer_out));
}
void _80211_r6_join15_weighted_round_robin() { // transmit.str:1026
    push_complex(&add_seqs.buffer_out, pop_complex(&add_seqs_halve.halve_out));
    FOR(uint32_t, i, 0, <, 159 , i++)
        push_complex(&add_seqs.buffer_out, pop_complex(&add_seqs_halve.id_out[0]));
    ENDFOR
    push_complex(&add_seqs.buffer_out, pop_complex(&add_seqs_halve.halve_comb_out));
    FOR(uint32_t, i, 0, <, 159 , i++)
        push_complex(&add_seqs.buffer_out, pop_complex(&add_seqs_halve.id_out[1]));
    ENDFOR
    push_complex(&add_seqs.buffer_out, pop_complex(&add_seqs_halve.id_out[2]));
}

void _80211_r6_split8_weighted_round_robin() { //AnonFilter_a5
    FOR(uint32_t, i, 0, <, 320 , i++)
        push_complex(&AnonFilter_a5Buf_id[0].buffer_in, pop_complex(&AnonFilter_a5Buf.buffer_in));
    ENDFOR
    push_complex(&AnonFilter_a5Buf_halve.buffer_in, pop_complex(&AnonFilter_a5Buf.buffer_in));
    push_complex(&AnonFilter_a5Buf_halve.buffer_in, pop_complex(&AnonFilter_a5Buf.buffer_in));
    FOR(uint32_t, i, 0, <, 80*(TheGlobal_TOTAL_OUT_SYMBS+1) , i++)
        push_complex(&AnonFilter_a5Buf_id[1].buffer_in, pop_complex(&AnonFilter_a5Buf.buffer_in));
    ENDFOR
}

void _80211_r6_join8_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, 320 , i++)
        push_complex(&output_cBuf.buffer_in, pop_complex(&AnonFilter_a5Buf_id[0].buffer_out));
    ENDFOR
    push_complex(&output_cBuf.buffer_in, pop_complex(&AnonFilter_a5Buf_halve.buffer_out));
    FOR(uint32_t, i, 0, <, 80*(TheGlobal_TOTAL_OUT_SYMBS+1) , i++)
        push_complex(&output_cBuf.buffer_in, pop_complex(&AnonFilter_a5Buf_id[1].buffer_out));
    ENDFOR
}

void _80211_r6_split4_round_robin() {
    FOR(uint32_t, i, 0, <, 16 , i++)
        push_bit(&permute_1[0].buffer_in, pop_bit(&conv_code_headerBuf.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 16 , i++)
        push_bit(&permute_1[1].buffer_in, pop_bit(&conv_code_headerBuf.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 16 , i++)
        push_bit(&permute_1[2].buffer_in, pop_bit(&conv_code_headerBuf.buffer_out));
    ENDFOR
}

void _80211_r6_join4_round_robin() {
    FOR(uint32_t, i, 0, <, 16 , i++)
        push_bit(&BPSKBuf.buffer_in, pop_bit(&permute_1[0].buffer_out));
        push_bit(&BPSKBuf.buffer_in, pop_bit(&permute_1[1].buffer_out));
        push_bit(&BPSKBuf.buffer_in, pop_bit(&permute_1[2].buffer_out));
    ENDFOR
}

void _80211_r6_split11_weighted_round_robin() { //AnonFilter_a9
    FOR(uint32_t, i, 0, <, 48 , i++)
        push_complex(&header_pilotBuf[0].buffer_in, pop_complex(&BPSKBuf.buffer_out));
    ENDFOR
}
void _80211_r6_join11_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, 48 , i++)
        push_complex(&header_insert_pilotBuf.buffer_in, pop_complex(&header_pilotBuf[0].buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 4 , i++)
        push_complex(&header_insert_pilotBuf.buffer_in, pop_complex(&header_pilotBuf[1].buffer_out));
    ENDFOR
}

void _80211_r6_split2_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, 26 , i++)
        push_complex(&header_genZero[1].buffer_in, pop_complex(&header_insert_pilotBuf.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 26 , i++)
        push_complex(&header_genZero[3].buffer_in, pop_complex(&header_insert_pilotBuf.buffer_out));
    ENDFOR
}
void _80211_r6_join2_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, 6 , i++)
        push_complex(&header_data_splitBuf.buffer_header_out, pop_complex(&header_genZero[0].buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 26 , i++)
        push_complex(&header_data_splitBuf.buffer_header_out, pop_complex(&header_genZero[1].buffer_out));
    ENDFOR
    push_complex(&header_data_splitBuf.buffer_header_out, pop_complex(&header_genZero[2].buffer_out));
    FOR(uint32_t, i, 0, <, 26 , i++)
        push_complex(&header_data_splitBuf.buffer_header_out, pop_complex(&header_genZero[3].buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 5 , i++)
        push_complex(&header_data_splitBuf.buffer_header_out, pop_complex(&header_genZero[4].buffer_out));
    ENDFOR
}

void _80211_r6_split16_weighted_round_robin() {  // transmit.str:318
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_IN_BITS , i++)
        push_bit(&data_init[1].buffer_in, pop_bit(&header_data_splitBuf.buffer_in));
    ENDFOR
}

void _80211_r6_join16_weighted_round_robin() {  // transmit.str:322
    FOR(uint32_t, i, 0, <, 16 , i++)
        push_bit(&scrambleBuf.buffer_in, pop_bit(&data_init[0].buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_IN_BITS , i++)
        push_bit(&scrambleBuf.buffer_in, pop_bit(&data_init[1].buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 6+TheGlobal_EXTRA_BITS , i++)
        push_bit(&scrambleBuf.buffer_in, pop_bit(&data_init[2].buffer_out));
    ENDFOR
}

void _80211_r6_split3_weighted_round_robin(){ // transmit.str:400 interleave_scramble_seq();
    FOR(uint32_t, i, 0, <, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS , i++)
        push_bit(&idScrambleBuf.buffer_in, pop_bit(&scrambleBuf.buffer_in));
    ENDFOR
}
void _80211_r6_join3_round_robin() {
    FOR(uint32_t, i, 0, <, 16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS , i++)
        push_bit(&scrambleBuf.buffer_out, pop_bit(&idScrambleBuf.buffer_out));
        push_bit(&scrambleBuf.buffer_out, pop_bit(&scramble_seqBuf.buffer_out));
    ENDFOR
}

void _80211_r6_split17_round_robin() {
    FOR(uint32_t, k, 0, <, (TheGlobal_ENCODED_DATA/16)/(TheGlobal_BITS_PER_SYM/16) , k++)
        FOR(uint32_t, i, 0, <, TheGlobal_BITS_PER_SYM/16, i++)
            FOR(uint32_t, j, 0, <, 16 , j++)
                push_bit(&permute_1_dataIdBuf[i].buffer_in, pop_bit(&permute_1_dataBuf.buffer_in));
            ENDFOR
        ENDFOR
    ENDFOR
}
void _80211_r6_join17_round_robin() {
    FOR(uint32_t, k, 0, <, (TheGlobal_ENCODED_DATA/16)/(TheGlobal_BITS_PER_SYM/16) , k++)
        FOR(uint32_t, j, 0, <, 16 , j++)
            FOR(uint32_t, i, 0, <, TheGlobal_BITS_PER_SYM/16, i++)
                push_bit(&permute_2Buf.buffer_in, pop_bit(&permute_1_dataIdBuf[i].buffer_out));
            ENDFOR
        ENDFOR
    ENDFOR
}

void _80211_r6_split19_weighted_round_robin() { //AnonFilter_a9
    FOR(uint32_t, i, 0, <, TheGlobal_MODULED_DATA , i++)
        push_complex(&data_pilotBuf.buffer_in, pop_complex(&DataModulationBuf.buffer_out));
    ENDFOR
}
void _80211_r6_join19_weighted_round_robin() {
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        FOR(uint32_t, i, 0, <, 48 , i++)
            push_complex(&AnonFilter_a20Buf.buffer_in, pop_complex(&data_pilotBuf.buffer_out));
        ENDFOR
        FOR(uint32_t, i, 0, <, 4 , i++)
            push_complex(&AnonFilter_a20Buf.buffer_in, pop_complex(&pilot_generatorBuf.buffer_out));
        ENDFOR
    ENDFOR
}

void _80211_r6_split20_weighted_round_robin() {
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        FOR(uint32_t, i, 0, <, 26 , i++)
            push_complex(&data_genZero[1].buffer_in, pop_complex(&AnonFilter_a20Buf.buffer_out));
        ENDFOR
        FOR(uint32_t, i, 0, <, 26 , i++)
            push_complex(&data_genZero[3].buffer_in, pop_complex(&AnonFilter_a20Buf.buffer_out));
        ENDFOR
    ENDFOR
}
void _80211_r6_join20_weighted_round_robin() {
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        FOR(uint32_t, i, 0, <, 6 , i++)
            push_complex(&header_data_splitBuf.buffer_data_out, pop_complex(&data_genZero[0].buffer_out));
        ENDFOR
        FOR(uint32_t, i, 0, <, 26 , i++)
            push_complex(&header_data_splitBuf.buffer_data_out, pop_complex(&data_genZero[1].buffer_out));
        ENDFOR
        push_complex(&header_data_splitBuf.buffer_data_out, pop_complex(&data_genZero[2].buffer_out));
        FOR(uint32_t, i, 0, <, 26 , i++)
            push_complex(&header_data_splitBuf.buffer_data_out, pop_complex(&data_genZero[3].buffer_out));
        ENDFOR
        FOR(uint32_t, i, 0, <, 5 , i++)
            push_complex(&header_data_splitBuf.buffer_data_out, pop_complex(&data_genZero[4].buffer_out));
        ENDFOR
    ENDFOR
}

void _80211_r6_split9_weighted_round_robin() { //AnonFilter_a6
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_IN_BITS , i++)
        push_bit(&header_data_splitBuf.buffer_in, pop_bit(&FileReaderBufBit));
    ENDFOR
}

void _80211_r6_join9_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, 64 , i++)
        push_complex(&HD_FFT.buffer_in, pop_complex(&header_data_splitBuf.buffer_header_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_TOTAL_OUT_COMPLEX , i++)
        push_complex(&HD_FFT.buffer_in, pop_complex(&header_data_splitBuf.buffer_data_out));
    ENDFOR
}

void _80211_r6_split10_weighted_round_robin() { // AnonFilter_a7
    push_complex(&AnonFilter_a7Buf[0].buffer_in, pop_complex(&HD_FFT.buffer_out));
    FOR(uint32_t, i, 0, <, 81*TheGlobal_TOTAL_OUT_SYMBS , i++)
        push_complex(&AnonFilter_a7Buf[1].buffer_in, pop_complex(&HD_FFT.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 79 , i++)
        push_complex(&AnonFilter_a7Buf[2].buffer_in, pop_complex(&HD_FFT.buffer_out));
    ENDFOR
    push_complex(&hd_halve.halve_in, pop_complex(&HD_FFT.buffer_out));
}
void _80211_r6_join10_weighted_round_robin() {
    push_complex(&header_and_data.buffer_out, pop_complex(&AnonFilter_a7Buf[0].buffer_out));
    FOR(uint32_t, i, 0, <, 80*TheGlobal_TOTAL_OUT_SYMBS , i++)
        push_complex(&header_and_data.buffer_out, pop_complex(&AnonFilter_a7Buf[1].buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, 79 , i++)
        push_complex(&header_and_data.buffer_out, pop_complex(&AnonFilter_a7Buf[2].buffer_out));
    ENDFOR
    push_complex(&header_and_data.buffer_out, pop_complex(&hd_halve.halve_out));
}

void _80211_r6_split6_weighted_round_robin() { //append_symbols
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        FOR(uint32_t, i, 0, <, 79 , i++)
            push_complex(&append_symbIdBuf.buffer_in, pop_complex(&AnonFilter_a7Buf[1].buffer_in));
        ENDFOR
        push_complex(&hd_halve.halve_comb_in, pop_complex(&AnonFilter_a7Buf[1].buffer_in));
        push_complex(&hd_halve.halve_comb_in, pop_complex(&AnonFilter_a7Buf[1].buffer_in));
    ENDFOR
}
void _80211_r6_join6_weighted_round_robin() {
    FOR(uint32_t, k, 0, <, TheGlobal_TOTAL_OUT_SYMBS , k++)
        FOR(uint32_t, i, 0, <, 79 , i++)
            push_complex(&AnonFilter_a7Buf[1].buffer_out, pop_complex(&append_symbIdBuf.buffer_out));
        ENDFOR
        push_complex(&AnonFilter_a7Buf[1].buffer_out, pop_complex(&hd_halve.halve_comb_out));
    ENDFOR
}

int main(int argv, char** argc) {
    _80211_r6_transmit_init();

    FOR(uint32_t, i, 0, <, MAX_ITERATION , i++)
    	_80211_r6_split1_round_robin(); // transmit.str:141 //AnnonFilter_a4
            _80211_r6_split14_round_robin(); // transmit.str:1011 //add_seq(); //AnonFilter_a13
                _80211_r6_short_seq();
                _80211_r6_long_seq();
            _80211_r6_join14_weighted_round_robin(64, 64); // transmit.str:1014
            //cyclicIFFT2
            _80211_r6_fftshift_1d_as();
            _80211_r6_fft_reorder_simple_as1();
            _80211_r6_fft_reorder_simple_as2();
            _80211_r6_fft_reorder_simple_as3();
            _80211_r6_fft_reorder_simple_as4();
            _80211_r6_fft_reorder_simple_as5();
            _80211_r6_combine_idft_as1(); // FFT6.str:169
            _80211_r6_combine_idft_as2(); // FFT6.str:169
            _80211_r6_combine_idft_as3(); // FFT6.str:169
            _80211_r6_combine_idft_as4(); // FFT6.str:169
            _80211_r6_combine_idft_as5(); // FFT6.str:169
            _80211_r6_combine_idft_final_as();
            _80211_r6_split13_addseq_duplicate();  // transmit.str:839 AnonFilter_a12
                _80211_r6_remove_first_as();
                _80211_r6_identity(128, &add_seqs_FFT.id_buffer_in[0], &add_seqs_FFT.id_buffer_out[0]);
                _80211_r6_identity(128, &add_seqs_FFT.id_buffer_in[1], &add_seqs_FFT.id_buffer_out[1]);
                _80211_r6_remove_last_as();
            _80211_r6_join13_addseq_weighted_round_robin(); // transmit.str:844
           
            _80211_r6_split15_weighted_round_robin(); // transmit.str:1020  AnonFilter_a14
                _80211_r6_halve_as();
                _80211_r6_identity(159, &add_seqs_halve.id_in[0], &add_seqs_halve.id_out[0]);
                _80211_r6_halve_and_combine_as();
                _80211_r6_identity(159, &add_seqs_halve.id_in[1], &add_seqs_halve.id_out[1]);
                _80211_r6_identity(1, &add_seqs_halve.id_in[2], &add_seqs_halve.id_out[2]);
            _80211_r6_join15_weighted_round_robin(); // transmit.str:1026
                
            //header_and_data(); 
                FileReader(TheGlobal_TOTAL_IN_BITS);
                _80211_r6_split9_weighted_round_robin(); //AnonFilter_a6
                    //encoded_header
                    _80211_r6_generate_header();
                    //conv_code
                    //conv_code_pipeline
                        _80211_r6_anon_filter_a8_header();
                        _80211_r6_conv_code_header();
                    //permute_1();
                    _80211_r6_split4_round_robin();
                    FOR(uint32_t, j, 0, <, 48/16, j++)
                        _80211_r6_identity_bit(16, &permute_1[j].buffer_in, &permute_1[j].buffer_out); 
                    ENDFOR
                    _80211_r6_join4_round_robin();
                    _80211_r6_bpsk_header();
                    
                    //insert_pilots
                    _80211_r6_split11_weighted_round_robin(); //AnonFilter_a9 
                        _80211_r6_identity(48, &header_pilotBuf[0].buffer_in, &header_pilotBuf[0].buffer_out);
                        _80211_r6_header_pilot_generator();
                    _80211_r6_join11_weighted_round_robin();
                    _80211_r6_header_insert_pilots();
                    //insert_zeros_complex();
                    _80211_r6_split2_weighted_round_robin();
                        _80211_r6_zero_gen_complex(6, &header_genZero[0].buffer_out); 
                        _80211_r6_identity(26, &header_genZero[1].buffer_in, &header_genZero[1].buffer_out);
                        _80211_r6_zero_gen_complex(1, &header_genZero[2].buffer_out);
                        _80211_r6_identity(26, &header_genZero[3].buffer_in, &header_genZero[3].buffer_out);
                        _80211_r6_zero_gen_complex(5, &header_genZero[4].buffer_out);
                    _80211_r6_join2_weighted_round_robin();
                    
                    //encoded_data();
                    //insert_zeros();
                    _80211_r6_split16_weighted_round_robin(); // transmit.str:318
                        _80211_r6_zero_gen(16, &data_init[0].buffer_out); 
                        _80211_r6_identity_bit(TheGlobal_TOTAL_IN_BITS, &data_init[1].buffer_in, &data_init[1].buffer_out); 
                        _80211_r6_zero_gen(6+TheGlobal_EXTRA_BITS, &data_init[2].buffer_out);
                    _80211_r6_join16_weighted_round_robin(); // transmit.str:322
                    _80211_r6_split3_weighted_round_robin(); // transmit.str:400 interleave_scramble_seq();
                        _80211_r6_identity_bit(16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS, &idScrambleBuf.buffer_in, &idScrambleBuf.buffer_out);
                        _80211_r6_scramble_seq();
                    _80211_r6_join3_round_robin();
                    _80211_r6_xor_pair();
                    _80211_r6_zero_tail_bits();
                    //conv_code
                    //conv_code_pipeline
                    _80211_r6_anon_filter_a8_data();
                    _80211_r6_conv_code_data();
                    
                    //permute_1();
                    _80211_r6_split17_round_robin();
                    FOR(uint32_t, j, 0, <, TheGlobal_BITS_PER_SYM/16, j++)
                        _80211_r6_identity_bit(TheGlobal_ENCODED_DATA/(TheGlobal_BITS_PER_SYM/16), &permute_1_dataIdBuf[j].buffer_in, &permute_1_dataIdBuf[j].buffer_out);
                    ENDFOR
                    _80211_r6_join17_round_robin();
                    //permute_2()
                    _80211_r6_identity_bit(TheGlobal_ENCODED_DATA, &permute_2Buf.buffer_in, &permute_2Buf.buffer_out);
                    
                    _80211_r6_bpsk_data();
                    
                    //insert_pilots
                    _80211_r6_split19_weighted_round_robin(); //AnonFilter_a9 
                        _80211_r6_identity(TheGlobal_MODULED_DATA, &data_pilotBuf.buffer_in, &data_pilotBuf.buffer_out);
                        _80211_r6_pilot_generator();
                    _80211_r6_join19_weighted_round_robin();
                    _80211_r6_anon_filter_a20();
                    //insert_zeros_complex();
                    _80211_r6_split20_weighted_round_robin();
                        _80211_r6_zero_gen_complex(6*TheGlobal_TOTAL_OUT_SYMBS, &data_genZero[0].buffer_out);
                        _80211_r6_identity(26*TheGlobal_TOTAL_OUT_SYMBS, &data_genZero[1].buffer_in, &data_genZero[1].buffer_out);
                        _80211_r6_zero_gen_complex(TheGlobal_TOTAL_OUT_SYMBS, &data_genZero[2].buffer_out);
                        _80211_r6_identity(26*TheGlobal_TOTAL_OUT_SYMBS, &data_genZero[3].buffer_in, &data_genZero[3].buffer_out);
                        _80211_r6_zero_gen_complex(5*TheGlobal_TOTAL_OUT_SYMBS, &data_genZero[4].buffer_out);
                    _80211_r6_join20_weighted_round_robin();
                _80211_r6_join9_weighted_round_robin();
 
                //cyclicIFFT
                _80211_r6_fftshift_1d_hd();
                _80211_r6_fft_reorder_simple_hd1();
                _80211_r6_fft_reorder_simple_hd2();
                _80211_r6_fft_reorder_simple_hd3();
                _80211_r6_fft_reorder_simple_hd4();
                _80211_r6_fft_reorder_simple_hd5();
                _80211_r6_combine_idft_hd1(); // FFT6.str:169
                _80211_r6_combine_idft_hd2(); // FFT6.str:169
                _80211_r6_combine_idft_hd3(); // FFT6.str:169
                _80211_r6_combine_idft_hd4(); // FFT6.str:169
                _80211_r6_combine_idft_hd5(); // FFT6.str:169
                _80211_r6_combine_idft_final_hd();
                _80211_r6_split13_hd_duplicate();  // transmit.str:839 AnonFilter_a12
                    _80211_r6_remove_first_hd();
                    _80211_r6_identity((TheGlobal_TOTAL_OUT_SYMBS+1)*64, &HD_FFT.id_buffer_in[0], &HD_FFT.id_buffer_out[0]);
                    _80211_r6_remove_last_hd();
                _80211_r6_join13_hd_weighted_round_robin(); // transmit.str:844
                
                _80211_r6_split10_weighted_round_robin(); // AnonFilter_a7
                    _80211_r6_identity(1, &AnonFilter_a7Buf[0].buffer_in, &AnonFilter_a7Buf[0].buffer_out);
                    _80211_r6_split6_weighted_round_robin(); //append_symbols
                        _80211_r6_identity(79*TheGlobal_TOTAL_OUT_SYMBS,&append_symbIdBuf.buffer_in, &append_symbIdBuf.buffer_out);
                        _80211_r6_halve_and_combine_hd();
                    _80211_r6_join6_weighted_round_robin();  
                    _80211_r6_identity(79, &AnonFilter_a7Buf[2].buffer_in, &AnonFilter_a7Buf[2].buffer_out);
                    _80211_r6_halve_hd(); 
                _80211_r6_join10_weighted_round_robin();

        _80211_r6_join1_weighted_round_robin(); // transmit.str:144
    	
        _80211_r6_split8_weighted_round_robin(); //AnonFilter_a5
            _80211_r6_identity(320, &AnonFilter_a5Buf_id[0].buffer_in, &AnonFilter_a5Buf_id[0].buffer_out);
            _80211_r6_halve_and_combine_final();
            _80211_r6_identity(80*(TheGlobal_TOTAL_OUT_SYMBS+1), &AnonFilter_a5Buf_id[1].buffer_in, &AnonFilter_a5Buf_id[1].buffer_out);
        _80211_r6_join8_weighted_round_robin();
        _80211_r6_printer();
    ENDFOR
    
    return EXIT_SUCCESS;
} 
