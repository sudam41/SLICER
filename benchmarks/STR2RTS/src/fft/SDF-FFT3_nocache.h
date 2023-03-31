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
	float A_re[32];
	float A_im[32];
	int idx;
} FloatSource_113_t;
void FloatSource_113();
void Pre_CollapsedDataParallel_1_414();
void Butterfly_114();
void Post_CollapsedDataParallel_2_415();
void WEIGHTED_ROUND_ROBIN_Splitter_458();
void Pre_CollapsedDataParallel_1_417();
void Butterfly_130();
void Post_CollapsedDataParallel_2_418();
void WEIGHTED_ROUND_ROBIN_Splitter_539();
void Pre_CollapsedDataParallel_1_423();
void Butterfly_146();
void Post_CollapsedDataParallel_2_424();
void Pre_CollapsedDataParallel_1_426();
void Butterfly_150();
void Post_CollapsedDataParallel_2_427();
void WEIGHTED_ROUND_ROBIN_Joiner_540();
void Pre_CollapsedDataParallel_1_420();
void Butterfly_138();
void Post_CollapsedDataParallel_2_421();
void WEIGHTED_ROUND_ROBIN_Splitter_541();
void Pre_CollapsedDataParallel_1_429();
void Butterfly_154();
void Post_CollapsedDataParallel_2_430();
void Pre_CollapsedDataParallel_1_432();
void Butterfly_158();
void Post_CollapsedDataParallel_2_433();
void WEIGHTED_ROUND_ROBIN_Joiner_542();
void WEIGHTED_ROUND_ROBIN_Joiner_538();
void WEIGHTED_ROUND_ROBIN_Splitter_543();
void WEIGHTED_ROUND_ROBIN_Splitter_545();
void Pre_CollapsedDataParallel_1_435();
void Butterfly_162();
void Post_CollapsedDataParallel_2_436();
void Pre_CollapsedDataParallel_1_438();
void Butterfly_164();
void Post_CollapsedDataParallel_2_439();
void Pre_CollapsedDataParallel_1_441();
void Butterfly_166();
void Post_CollapsedDataParallel_2_442();
void Pre_CollapsedDataParallel_1_444();
void Butterfly_168();
void Post_CollapsedDataParallel_2_445();
void WEIGHTED_ROUND_ROBIN_Joiner_546();
void WEIGHTED_ROUND_ROBIN_Splitter_547();
void Pre_CollapsedDataParallel_1_447();
void Butterfly_170();
void Post_CollapsedDataParallel_2_448();
void Pre_CollapsedDataParallel_1_450();
void Butterfly_172();
void Post_CollapsedDataParallel_2_451();
void Pre_CollapsedDataParallel_1_453();
void Butterfly_174();
void Post_CollapsedDataParallel_2_454();
void Pre_CollapsedDataParallel_1_456();
void Butterfly_176();
void Post_CollapsedDataParallel_2_457();
void WEIGHTED_ROUND_ROBIN_Joiner_548();
void WEIGHTED_ROUND_ROBIN_Joiner_544();
void WEIGHTED_ROUND_ROBIN_Splitter_549();
void WEIGHTED_ROUND_ROBIN_Splitter_551();
void Butterfly_178();
void Butterfly_179();
void Butterfly_180();
void Butterfly_181();
void Butterfly_182();
void Butterfly_183();
void Butterfly_184();
void Butterfly_185();
void WEIGHTED_ROUND_ROBIN_Joiner_552();
void WEIGHTED_ROUND_ROBIN_Splitter_553();
void Butterfly_186();
void Butterfly_187();
void Butterfly_188();
void Butterfly_189();
void Butterfly_190();
void Butterfly_191();
void Butterfly_192();
void Butterfly_193();
void WEIGHTED_ROUND_ROBIN_Joiner_554();
void WEIGHTED_ROUND_ROBIN_Joiner_550();
int BitReverse_194_bitrev(int inp);
void BitReverse_194();
void FloatPrinter_195();

#ifdef __cplusplus
}
#endif
#endif
