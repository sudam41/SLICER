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


void OneSource(buffer_float_t *chanout);
void OneSource_67();
void WEIGHTED_ROUND_ROBIN_Splitter_76();
void Identity(buffer_float_t *chanin, buffer_float_t *chanout);
void Identity_70();
void Multiply(buffer_float_t *chanin, buffer_float_t *chanout);
void Multiply_71();
void WEIGHTED_ROUND_ROBIN_Joiner_77();
void DUPLICATE_Splitter_78();
void Add(buffer_float_t *chanin, buffer_float_t *chanout);
void Add_73();
void Subtract(buffer_float_t *chanin, buffer_float_t *chanout);
void Subtract_74();
void WEIGHTED_ROUND_ROBIN_Joiner_79();
void FloatPrinter(buffer_float_t *chanin);
void FloatPrinter_75();

#ifdef __cplusplus
}
#endif
#endif
