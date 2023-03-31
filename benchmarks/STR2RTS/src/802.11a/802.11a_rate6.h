#ifndef _802_11A_H
#define _802_11A_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TheGlobal_LENGTH 100 // transmit.str:65

#define TheGlobal_MODULATION 0 // transmit.str:75
#define TheGlobal_CODING_RATE 0 // transmit.str:76
#define TheGlobal_BITS_PER_SUB 1 // transmit.str:77
#define TheGlobal_BITS_PER_SYM  48 // transmit.str:78
#define TheGlobal_DATA_BITS_PER_SYM 24 // transmit.str:79


#define TheGlobal_TOTAL_IN_BITS (8 * TheGlobal_LENGTH) // transmit.str:131
#define TheGlobal_SUBTOTAL_OUT_BITS (TheGlobal_TOTAL_IN_BITS + 22) // transmit.str:132
#define TheGlobal_TOTAL_OUT_SYMBS_tmp (TheGlobal_SUBTOTAL_OUT_BITS / TheGlobal_DATA_BITS_PER_SYM) // transmit.str:134
#if (TheGlobal_DATA_BITS_PER_SYM * TheGlobal_TOTAL_OUT_SYMBS_tmp) != TheGlobal_SUBTOTAL_OUT_BITS // transmit.str:137
    #define TheGlobal_TOTAL_OUT_SYMBS (TheGlobal_TOTAL_OUT_SYMBS_tmp + 1) // transmit.str:137
#else
    #define TheGlobal_TOTAL_OUT_SYMBS (TheGlobal_TOTAL_OUT_SYMBS_tmp)
#endif
#define TheGlobal_TOTAL_OUT_COMPLEX (64 * TheGlobal_TOTAL_OUT_SYMBS) // transmit.str:178
#if (TheGlobal_SUBTOTAL_OUT_BITS % TheGlobal_DATA_BITS_PER_SYM) == 0  // transmit.str:282
    #define TheGlobal_EXTRA_BITS 0 // transmit.str:282
#else 
    #define TheGlobal_EXTRA_BITS (TheGlobal_DATA_BITS_PER_SYM - ((TheGlobal_SUBTOTAL_OUT_BITS) % TheGlobal_DATA_BITS_PER_SYM)) // transmit.str:284
#endif
#define TheGlobal_TOTAL_OUT_BITS (TheGlobal_SUBTOTAL_OUT_BITS + TheGlobal_EXTRA_BITS) // transmit.str:285

#define TheGlobal_TMP_ENCODED_DATA (2*(16+TheGlobal_TOTAL_IN_BITS+6+TheGlobal_EXTRA_BITS))

#define TheGlobal_ENCODED_DATA (TheGlobal_TMP_ENCODED_DATA)

#define TheGlobal_MODULED_DATA TheGlobal_ENCODED_DATA

#define TheGlobal_FILEIN "/home/brouxel/Projects/Benchmarks/streamit-git/streams/apps/applications/802.11a/streamit/data1.bin"
#define TheGlobal_MAX_DATAREAD_IN_FILE TheGlobal_TOTAL_IN_BITS
    
typedef struct {  // transmit.str:407
    BIT temp[7];	// transmit.str:411
    buffer_bit_t buffer_out;
} bit_generator_t;

typedef struct {  // transmit.str:407
    BIT temp[7];	// transmit.str:411
    buffer_complex_t buffer_out;
} complex_generator_t;

typedef struct {
    buffer_complex_t buffer_in;
    buffer_complex_t shift_1d_buffer_out;
    buffer_complex_t reorder_buffer_out[5];
    buffer_complex_t IDFT_buffer_out[5];
    buffer_complex_t IDFTF_buffer_out;
    buffer_complex_t rem_f_buffer_in;
    buffer_complex_t rem_f_buffer_out;
    buffer_complex_t rem_l_buffer_in;
    buffer_complex_t rem_l_buffer_out;
    buffer_complex_t id_buffer_in[2];
    buffer_complex_t id_buffer_out[2];
    buffer_complex_t buffer_out;
} FFT_t;

typedef struct {
    buffer_complex_t halve_in;
    buffer_complex_t halve_out;
    buffer_complex_t id_in[3];
    buffer_complex_t id_out[3];
    buffer_complex_t halve_comb_in;
    buffer_complex_t halve_comb_out;
} halve_t;

typedef struct {
    buffer_bit_t buffer_in;
    buffer_complex_t buffer_header_out;
    buffer_complex_t buffer_data_out;
} header_data_t;

void _80211_r6_halve_as();
void _80211_r6_halve_hd();
void _80211_r6_halve();
void _80211_r6_halve_and_combine_as();
void _80211_r6_halve_and_combine_hd();
void _80211_r6_halve_and_combine_final();
void _80211_r6_halve_and_combine(buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_identity(uint32_t size, buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_identity_bit(uint32_t size, buffer_bit_t *in, buffer_bit_t *out);
void _80211_r6_remove_first_as();
void _80211_r6_remove_first_hd();
void _80211_r6_remove_first(int post_total, buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_remove_last_as();
void _80211_r6_remove_last_hd();
void _80211_r6_remove_last(buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_zero_tail_bits();
void _80211_r6_scramble_seq();
void _80211_r6_xor_pair();
void _80211_r6_pilot_generator();
void _80211_r6_fftshift_1d(buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_fftshift_1d_as();
void _80211_r6_fftshift_1d_hd();
void _80211_r6_short_seq();
void _80211_r6_long_seq();
void _80211_r6_fft_reorder_simple_as1();
void _80211_r6_fft_reorder_simple_as2();
void _80211_r6_fft_reorder_simple_as3();
void _80211_r6_fft_reorder_simple_as4();
void _80211_r6_fft_reorder_simple_as5();
void _80211_r6_fft_reorder_simple_hd1();
void _80211_r6_fft_reorder_simple_hd2();
void _80211_r6_fft_reorder_simple_hd3();
void _80211_r6_fft_reorder_simple_hd4();
void _80211_r6_fft_reorder_simple_hd5();
void _80211_r6_fft_reorder_simple(int iter, buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_combine_idft_as1();
void _80211_r6_combine_idft_as2();
void _80211_r6_combine_idft_as3();
void _80211_r6_combine_idft_as4();
void _80211_r6_combine_idft_as5();
void _80211_r6_combine_idft_final_as();
void _80211_r6_combine_idft_hd1();
void _80211_r6_combine_idft_hd2();
void _80211_r6_combine_idft_hd3();
void _80211_r6_combine_idft_hd4();
void _80211_r6_combine_idft_hd5();
void _80211_r6_combine_idft_final_hd();
void _80211_r6_combine_idft(int n, float w_init_real, buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_generate_header();
void _80211_r6_anon_filter_a8_header();
void _80211_r6_anon_filter_a8_data();
void _80211_r6_conv_code_header();
void _80211_r6_conv_code_data();
void _80211_r6_conv_code_filter(buffer_bit_t *in, buffer_bit_t *out);
void _80211_r6_bpsk_header();
void _80211_r6_bpsk_data();
void _80211_r6_header_pilot_generator();
void _80211_r6_insert_pilots(buffer_complex_t *in, buffer_complex_t *out);
void _80211_r6_header_insert_pilots();
void _80211_r6_zero_gen_complex(uint32_t reps, buffer_complex_t *out);
void _80211_r6_zero_gen(uint32_t reps, buffer_bit_t *out);
void _80211_r6_printer();
void _80211_r6_anon_filter_a20();
void _80211_r6_transmit_init();
void _80211_r6_split1_round_robin();
void _80211_r6_join1_weighted_round_robin();
void _80211_r6_split14_round_robin();
void _80211_r6_join14_weighted_round_robin();
void _80211_r6_split13_addseq_duplicate();
void _80211_r6_join13_addseq_weighted_round_robin();
void _80211_r6_split13_hd_duplicate();
void _80211_r6_join13_hd_weighted_round_robin();
void _80211_r6_split15_weighted_round_robin();
void _80211_r6_join15_weighted_round_robin();
void _80211_r6_split8_weighted_round_robin();
void _80211_r6_join8_weighted_round_robin();
void _80211_r6_split4_round_robin();
void _80211_r6_join4_round_robin();
void _80211_r6_split11_weighted_round_robin();
void _80211_r6_join11_weighted_round_robin();
void _80211_r6_split2_weighted_round_robin();
void _80211_r6_join2_weighted_round_robin();
void _80211_r6_split16_weighted_round_robin();
void _80211_r6_join16_weighted_round_robin();
void _80211_r6_split3_weighted_round_robin();
void _80211_r6_join3_round_robin();
void _80211_r6_split17_round_robin();
void _80211_r6_join17_round_robin();
void _80211_r6_split19_weighted_round_robin();
void _80211_r6_join19_weighted_round_robin();
void _80211_r6_split20_weighted_round_robin();
void _80211_r6_join20_weighted_round_robin();
void _80211_r6_split9_weighted_round_robin();
void _80211_r6_join9_weighted_round_robin();
void _80211_r6_split10_weighted_round_robin();
void _80211_r6_join10_weighted_round_robin();
void _80211_r6_split6_weighted_round_robin();
void _80211_r6_join6_weighted_round_robin();

#ifdef __cplusplus
}
#endif

#endif /* _802_11A_H */

