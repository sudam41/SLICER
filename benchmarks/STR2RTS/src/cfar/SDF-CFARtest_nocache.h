#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=1309 on the compile command line
#else
#if BUF_SIZEMAX < 1309
#error BUF_SIZEMAX too small, it must be at least 1309
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float theta;
} ComplexSource_14_t;

typedef struct {
	int pos;
	float poke[9];
} CFAR_gather_17_t;
void ComplexSource_14();
void SquareAndScale_16();
void CFAR_gather_17();
void AnonFilter_a0_18();
#define __DEFLOOPBOUND__0__ -1

#define __DEFLOOPBOUND__1__ -1

#define __DEFLOOPBOUND__2__ -1

#define __DEFLOOPBOUND__3__ -1

#define __DEFLOOPBOUND__4__ -1

#define __DEFLOOPBOUND__5__ -1


#ifdef __cplusplus
}
#endif
#endif
