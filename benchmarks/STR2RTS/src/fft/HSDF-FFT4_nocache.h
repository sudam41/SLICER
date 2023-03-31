#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=4 on the compile command line
#else
#if BUF_SIZEMAX < 4
#error BUF_SIZEMAX too small, it must be at least 4
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif


void WEIGHTED_ROUND_ROBIN_Splitter_162();
void OneSource_164();
void OneSource_165();
void WEIGHTED_ROUND_ROBIN_Joiner_163();
void WEIGHTED_ROUND_ROBIN_Splitter_147();
void Identity_141();
void Multiply_142();
void WEIGHTED_ROUND_ROBIN_Joiner_148();
void DUPLICATE_Splitter_149();
void Add_144();
void Subtract_145();
void WEIGHTED_ROUND_ROBIN_Joiner_150();
void FloatPrinter_146();

#ifdef __cplusplus
}
#endif
#endif
