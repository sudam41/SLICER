#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=34 on the compile command line
#else
#if BUF_SIZEMAX < 34
#error BUF_SIZEMAX too small, it must be at least 34
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float input[2048];
	int i;
} Input_8_t;

typedef struct {
	float coeff_real[16];
	float coeff_imag[16];
} FIR_9_t;
void Input_8();
void FIR_9();
void Printer_10();

#ifdef __cplusplus
}
#endif
#endif
