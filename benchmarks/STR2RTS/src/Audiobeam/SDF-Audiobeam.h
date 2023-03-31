#define MAX_DATAREAD_IN_FILE 195
#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=30 on the compile command line
#else
#if BUF_SIZEMAX < 30
#error BUF_SIZEMAX too small, it must be at least 30
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif

#define READDATAFILE "/Users/brouxel/SharedVMs/share/Projects/Benchmarks/streamit-git/streams/apps/benchmarks/audiobeam/data/str-data/near-field/data2.bin"


typedef struct {
	float time_index;
} Printer_101_t;
void FileReader_81();
void WEIGHTED_ROUND_ROBIN_Splitter_102();
void Interpolate(buffer_float_t *chanin, buffer_float_t *chanout);
void Interpolate_85();
void Interpolate_86();
void Interpolate_87();
void Interpolate_88();
void Interpolate_89();
void Interpolate_90();
void Interpolate_91();
void Interpolate_92();
void Interpolate_93();
void Interpolate_94();
void Interpolate_95();
void Interpolate_96();
void Interpolate_97();
void Interpolate_98();
void Interpolate_99();
void WEIGHTED_ROUND_ROBIN_Joiner_103();
void Average(buffer_float_t *chanin, buffer_float_t *chanout);
void Average_100();
void Printer(buffer_float_t *chanin);
void Printer_101();

#ifdef __cplusplus
}
#endif
#endif
