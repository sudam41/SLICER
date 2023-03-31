#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=264 on the compile command line
#else
#if BUF_SIZEMAX < 264
#error BUF_SIZEMAX too small, it must be at least 264
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float current;
} source_61_t;

typedef struct {
	float COEFF[32];
} FirFilter_65_t;
void source_61();
void DUPLICATE_Splitter_121();
void Delay_N_64();
void FirFilter_65();
void DownSamp_66();
void UpSamp_67();
void Delay_N_68();
void FirFilter_69();
void Delay_N_71();
void FirFilter_72();
void DownSamp_73();
void UpSamp_74();
void Delay_N_75();
void FirFilter_76();
void Delay_N_78();
void FirFilter_79();
void DownSamp_80();
void UpSamp_81();
void Delay_N_82();
void FirFilter_83();
void Delay_N_85();
void FirFilter_86();
void DownSamp_87();
void UpSamp_88();
void Delay_N_89();
void FirFilter_90();
void Delay_N_92();
void FirFilter_93();
void DownSamp_94();
void UpSamp_95();
void Delay_N_96();
void FirFilter_97();
void Delay_N_99();
void FirFilter_100();
void DownSamp_101();
void UpSamp_102();
void Delay_N_103();
void FirFilter_104();
void Delay_N_106();
void FirFilter_107();
void DownSamp_108();
void UpSamp_109();
void Delay_N_110();
void FirFilter_111();
void Delay_N_113();
void FirFilter_114();
void DownSamp_115();
void UpSamp_116();
void Delay_N_117();
void FirFilter_118();
void WEIGHTED_ROUND_ROBIN_Joiner_122();
void Combine_119();
void sink_120();

#ifdef __cplusplus
}
#endif
#endif
