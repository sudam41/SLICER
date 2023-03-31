#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=4485 on the compile command line
#else
#if BUF_SIZEMAX < 4485
#error BUF_SIZEMAX too small, it must be at least 4485
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float x;
} FloatOneSource_103_t;

typedef struct {
	float coeff[64];
} LowPassFilter_105_t;
void FloatOneSource(buffer_float_t *chanout);
void FloatOneSource_103();
void LowPassFilter(buffer_float_t *chanin, buffer_float_t *chanout);
void LowPassFilter_105();
void FMDemodulator(buffer_float_t *chanin, buffer_float_t *chanout);
void FMDemodulator_106();
void DUPLICATE_Splitter_180();
void DUPLICATE_Splitter_182();
void LowPassFilter_111();
void LowPassFilter_112();
void WEIGHTED_ROUND_ROBIN_Joiner_183();
void Subtracter(buffer_float_t *chanin, buffer_float_t *chanout);
void Subtracter_113();
void Amplify(buffer_float_t *chanin, buffer_float_t *chanout);
void Amplify_114();
void DUPLICATE_Splitter_184();
void LowPassFilter_118();
void LowPassFilter_119();
void WEIGHTED_ROUND_ROBIN_Joiner_185();
void Subtracter_120();
void Amplify_121();
void DUPLICATE_Splitter_186();
void LowPassFilter_125();
void LowPassFilter_126();
void WEIGHTED_ROUND_ROBIN_Joiner_187();
void Subtracter_127();
void Amplify_128();
void DUPLICATE_Splitter_188();
void LowPassFilter_132();
void LowPassFilter_133();
void WEIGHTED_ROUND_ROBIN_Joiner_189();
void Subtracter_134();
void Amplify_135();
void DUPLICATE_Splitter_190();
void LowPassFilter_139();
void LowPassFilter_140();
void WEIGHTED_ROUND_ROBIN_Joiner_191();
void Subtracter_141();
void Amplify_142();
void DUPLICATE_Splitter_192();
void LowPassFilter_146();
void LowPassFilter_147();
void WEIGHTED_ROUND_ROBIN_Joiner_193();
void Subtracter_148();
void Amplify_149();
void DUPLICATE_Splitter_194();
void LowPassFilter_153();
void LowPassFilter_154();
void WEIGHTED_ROUND_ROBIN_Joiner_195();
void Subtracter_155();
void Amplify_156();
void DUPLICATE_Splitter_196();
void LowPassFilter_160();
void LowPassFilter_161();
void WEIGHTED_ROUND_ROBIN_Joiner_197();
void Subtracter_162();
void Amplify_163();
void DUPLICATE_Splitter_198();
void LowPassFilter_167();
void LowPassFilter_168();
void WEIGHTED_ROUND_ROBIN_Joiner_199();
void Subtracter_169();
void Amplify_170();
void DUPLICATE_Splitter_200();
void LowPassFilter_174();
void LowPassFilter_175();
void WEIGHTED_ROUND_ROBIN_Joiner_201();
void Subtracter_176();
void Amplify_177();
void WEIGHTED_ROUND_ROBIN_Joiner_181();
void AnonFilter_a0(buffer_float_t *chanin, buffer_float_t *chanout);
void AnonFilter_a0_178();
void FloatPrinter(buffer_float_t *chanin);
void FloatPrinter_179();

#ifdef __cplusplus
}
#endif
#endif
