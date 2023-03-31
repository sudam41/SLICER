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


void OneSource_67();
void WEIGHTED_ROUND_ROBIN_Splitter_76();
void Identity_70();
void Multiply_71();
void WEIGHTED_ROUND_ROBIN_Joiner_77();
void DUPLICATE_Splitter_78();
void Add_73();
void Subtract_74();
void WEIGHTED_ROUND_ROBIN_Joiner_79();
void FloatPrinter_75();

#ifdef __cplusplus
}
#endif
#endif
