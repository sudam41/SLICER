#ifndef FFT2_H
#define FFT2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "globals.h"

#define TheGlobal_N 64
    
typedef struct {
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} channel_t;

void fft2_combine_dft(int iter, buffer_float_t *in, buffer_float_t *out);
void fft2_reorder_simple(int iter, buffer_float_t *in, buffer_float_t *out);
void fft2_test_source();
void fft2_init();
void fft2_join1_round_robin();
void fft2_split1_round_robin() ;
void fft2_float_printer();
void fft2_combine_dft_1(int branch);
void fft2_combine_dft_2(int branch);
void fft2_combine_dft_4(int branch);
void fft2_combine_dft_8(int branch);
void fft2_combine_dft_16(int branch);
void fft2_combine_dft_32(int branch);
void fft2_reorder_simple_1(int branch);
void fft2_reorder_simple_2(int branch);
void fft2_reorder_simple_4(int branch);
void fft2_reorder_simple_8(int branch);
void fft2_reorder_simple_16(int branch);

#ifdef __cplusplus
}
#endif

#endif /* FFT2_H */

