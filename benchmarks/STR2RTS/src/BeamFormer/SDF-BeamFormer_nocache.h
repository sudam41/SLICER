#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=48 on the compile command line
#else
#if BUF_SIZEMAX < 48
#error BUF_SIZEMAX too small, it must be at least 48
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	int curSample;
} InputGenerate_59_t;

typedef struct {
	float real_weight[64];
	float imag_weight[64];
	float realBuffer[64];
	float imagBuffer[64];
	int count;
	int pos;
} BeamFirFilter_60_t;

typedef struct {
	float real_weight[12];
	float imag_weight[12];
} BeamForm_107_t;

typedef struct {
	float real_weight[512];
	float imag_weight[512];
	float realBuffer[512];
	float imagBuffer[512];
	int count;
	int pos;
} BeamFirFilter_108_t;
void WEIGHTED_ROUND_ROBIN_Splitter_126();
void InputGenerate_59();
void BeamFirFilter_60();
void BeamFirFilter_61();
void InputGenerate_63();
void BeamFirFilter_64();
void BeamFirFilter_65();
void InputGenerate_67();
void BeamFirFilter_68();
void BeamFirFilter_69();
void InputGenerate_71();
void BeamFirFilter_72();
void BeamFirFilter_73();
void InputGenerate_75();
void BeamFirFilter_76();
void BeamFirFilter_77();
void InputGenerate_79();
void BeamFirFilter_80();
void BeamFirFilter_81();
void InputGenerate_83();
void BeamFirFilter_84();
void BeamFirFilter_85();
void InputGenerate_87();
void BeamFirFilter_88();
void BeamFirFilter_89();
void InputGenerate_91();
void BeamFirFilter_92();
void BeamFirFilter_93();
void InputGenerate_95();
void BeamFirFilter_96();
void BeamFirFilter_97();
void InputGenerate_99();
void BeamFirFilter_100();
void BeamFirFilter_101();
void InputGenerate_103();
void BeamFirFilter_104();
void BeamFirFilter_105();
void WEIGHTED_ROUND_ROBIN_Joiner_127();
void DUPLICATE_Splitter_128();
void BeamForm_107();
void BeamFirFilter_108();
float Magnitude_109_mag(float real, float imag);
void Magnitude_109();
void FloatPrinter_110();
void BeamForm_112();
void BeamFirFilter_113();
float Magnitude_114_mag(float real, float imag);
void Magnitude_114();
void FloatPrinter_115();
void BeamForm_117();
void BeamFirFilter_118();
float Magnitude_119_mag(float real, float imag);
void Magnitude_119();
void FloatPrinter_120();
void BeamForm_122();
void BeamFirFilter_123();
float Magnitude_124_mag(float real, float imag);
void Magnitude_124();
void FloatPrinter_125();
void WEIGHTED_ROUND_ROBIN_Joiner_129();

#ifdef __cplusplus
}
#endif
#endif
