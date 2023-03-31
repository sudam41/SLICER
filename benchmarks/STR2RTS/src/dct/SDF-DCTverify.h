#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=256 on the compile command line
#else
#if BUF_SIZEMAX < 256
#error BUF_SIZEMAX too small, it must be at least 256
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
} DCT_2D_reference_coarse_243_t;

typedef struct {
	float count;
	float errors;
} AnonFilter_a3_247_t;
void AnonFilter_a0(buffer_int_t *chanout);
void AnonFilter_a0_239();
void DUPLICATE_Splitter_248();
void DCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout);
void DCT_2D_reference_coarse_243();
void iDCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT_2D_reference_coarse_245();
void Identity(buffer_int_t *chanin, buffer_int_t *chanout);
void Identity_246();
void WEIGHTED_ROUND_ROBIN_Joiner_249();
void AnonFilter_a3(buffer_int_t *chanin);
void AnonFilter_a3_247();

#ifdef __cplusplus
}
#endif
#endif
