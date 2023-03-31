#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=384 on the compile command line
#else
#if BUF_SIZEMAX < 384
#error BUF_SIZEMAX too small, it must be at least 384
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float coeff[8][8];
} iDCT_2D_reference_coarse_240_t;

typedef struct {
	int buffer[64];
} iDCT8x8_1D_col_fast_264_t;

typedef struct {
	float count;
	float errors;
} AnonFilter_a2_265_t;
void AnonFilter_a0(buffer_int_t *chanout);
void AnonFilter_a0_237();
void DUPLICATE_Splitter_312();
void iDCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT_2D_reference_coarse_240();
void AnonFilter_a3(buffer_int_t *chanin, buffer_float_t *chanout);
void AnonFilter_a3_243();
void Pre_CollapsedDataParallel_1(buffer_float_t *chanin, buffer_float_t *chanout);
void Pre_CollapsedDataParallel_1_310();
void iDCT_1D_reference_fine(buffer_float_t *chanin, buffer_float_t *chanout);
void iDCT_1D_reference_fine_244();
void Post_CollapsedDataParallel_2(buffer_float_t *chanin, buffer_float_t *chanout);
void Post_CollapsedDataParallel_2_311();
void iDCT_1D_reference_fine_252();
void AnonFilter_a4(buffer_float_t *chanin, buffer_int_t *chanout);
void AnonFilter_a4_260();
void iDCT8x8_1D_row_fast(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT8x8_1D_row_fast_263();
void iDCT8x8_1D_col_fast(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT8x8_1D_col_fast_264();
void WEIGHTED_ROUND_ROBIN_Joiner_313();
void AnonFilter_a2(buffer_int_t *chanin);
void AnonFilter_a2_265();

#ifdef __cplusplus
}
#endif
#endif
