#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=512 on the compile command line
#else
#if BUF_SIZEMAX < 512
#error BUF_SIZEMAX too small, it must be at least 512
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float w[2];
} CombineDFT_47_t;

typedef struct {
	float w[4];
} CombineDFT_48_t;

typedef struct {
	float w[8];
} CombineDFT_49_t;

typedef struct {
	float w[16];
} CombineDFT_50_t;

typedef struct {
	float w[32];
} CombineDFT_51_t;

typedef struct {
	float w[64];
} CombineDFT_52_t;
void FFTTestSource(buffer_float_t *chanout);
void FFTTestSource_41();
void WEIGHTED_ROUND_ROBIN_Splitter_65();
void FFTReorderSimple(buffer_float_t *chanin, buffer_float_t *chanout);
void FFTReorderSimple_42();
void FFTReorderSimple_43();
void FFTReorderSimple_44();
void FFTReorderSimple_45();
void FFTReorderSimple_46();
void CombineDFT(buffer_float_t *chanin, buffer_float_t *chanout);
void CombineDFT_47();
void CombineDFT_48();
void CombineDFT_49();
void CombineDFT_50();
void CombineDFT_51();
void CombineDFT_52();
void FFTReorderSimple_53();
void FFTReorderSimple_54();
void FFTReorderSimple_55();
void FFTReorderSimple_56();
void FFTReorderSimple_57();
void CombineDFT_58();
void CombineDFT_59();
void CombineDFT_60();
void CombineDFT_61();
void CombineDFT_62();
void CombineDFT_63();
void WEIGHTED_ROUND_ROBIN_Joiner_66();
void FloatPrinter(buffer_float_t *chanin);
void FloatPrinter_64();

#ifdef __cplusplus
}
#endif
#endif
