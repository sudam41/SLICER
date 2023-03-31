#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=128 on the compile command line
#else
#if BUF_SIZEMAX < 128
#error BUF_SIZEMAX too small, it must be at least 128
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	complex_t wn;
} CombineDFT_28_t;
void FFTTestSource_22();
void FFTReorderSimple_23();
void FFTReorderSimple_24();
void FFTReorderSimple_25();
void FFTReorderSimple_26();
void FFTReorderSimple_27();
void CombineDFT_28();
void CombineDFT_29();
void CombineDFT_30();
void CombineDFT_31();
void CombineDFT_32();
void CombineDFT_33();
void CPrinter_34();

#ifdef __cplusplus
}
#endif
#endif
