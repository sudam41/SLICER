#ifndef DCT2_H
#define DCT2_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "globals.h"
    
#define TheGlobal_FILEIN "/home/sudam/STR2RTS/dct/idct-input.bin"
#define TheGlobal_FILEOUT "/home/sudam/STR2RTS/dct/idct-output2.bin"
#define TheGlobal_SIZE 16
    
typedef struct {  // DCT2.str:331
    float coeff [TheGlobal_SIZE][TheGlobal_SIZE];	// DCT2.str:332
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} iDCT_1D_reference_fine_t;

typedef struct {  // DCT2.str:95
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} channel_t;

void dct2_init();
void dct2_idct_1d_reference_fine(int);
void dct2_printer();
void dct2_writer();
void dct2_split_round_robin_y();
void dct2_join_round_robin_y();
void dct2_split_round_robin_x();
void dct2_join_round_robin_x();
#ifdef __cplusplus
}
#endif

#endif /* DCT2_H */

