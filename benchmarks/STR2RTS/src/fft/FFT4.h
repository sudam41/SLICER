#ifndef FFT4_H
#define FFT4_H

#include "globals.h"

#define TheGlobal_N 32

#ifdef __cplusplus
extern "C" {
#endif

typedef struct { 
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} channel_t;

void fft4_init();
void fft4_source();
void fft4_multiply();
void fft4_identity();
void fft4_add();
void fft4_subtract();
void fft4_float_printer();
void fft4_split_weighted_round_robin_1();
void fft4_split_weighted_round_robin_2();
void fft4_split_weighted_round_robin_4();
void fft4_split_weighted_round_robin_8();
void fft4_split_weighted_round_robin_16();
void fft4_join_round_robin();
void fft4_split_duplicate();
void fft4_join_weighted_round_robin_1();
void fft4_join_weighted_round_robin_2();
void fft4_join_weighted_round_robin_4();
void fft4_join_weighted_round_robin_8();
void fft4_join_weighted_round_robin_16();

#ifdef __cplusplus
}
#endif

#endif /* FFT4_H */

