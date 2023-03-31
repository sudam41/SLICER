#define MAX_DATAREAD_IN_FILE 800
#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=6912 on the compile command line
#else
#if BUF_SIZEMAX < 6912
#error BUF_SIZEMAX too small, it must be at least 6912
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif

#define READDATAFILE "/home/sudam/STR2RTS/_802_11a/data1.bin"


typedef struct {
	complex_t pos;
	complex_t neg;
	complex_t zero;
} short_seq_817_t;

typedef struct {
	complex_t wn;
} CombineIDFT_826_t;

typedef struct {
	int temp[7];
} scramble_seq_875_t;

typedef struct {
	complex_t c1;
	complex_t c2;
	complex_t c3;
	complex_t c4;
	int temp[7];
} pilot_generator_903_t;
void WEIGHTED_ROUND_ROBIN_Splitter_984();
void WEIGHTED_ROUND_ROBIN_Splitter_986();
void short_seq_817();
void long_seq_818();
void WEIGHTED_ROUND_ROBIN_Joiner_987();
void fftshift_1d_820();
void FFTReorderSimple_821();
void FFTReorderSimple_822();
void FFTReorderSimple_823();
void FFTReorderSimple_824();
void FFTReorderSimple_825();
void CombineIDFT_826();
void CombineIDFT_827();
void CombineIDFT_828();
void CombineIDFT_829();
void CombineIDFT_830();
void CombineIDFTFinal_831();
void DUPLICATE_Splitter_988();
void remove_first_833();
void Identity_834();
void Identity_835();
void remove_last_836();
void WEIGHTED_ROUND_ROBIN_Joiner_989();
void WEIGHTED_ROUND_ROBIN_Splitter_990();
void halve_838();
void Identity_839();
void halve_and_combine_840();
void Identity_841();
void Identity_842();
void WEIGHTED_ROUND_ROBIN_Joiner_991();
void FileReader_844();
void WEIGHTED_ROUND_ROBIN_Splitter_992();
void generate_header_847();
void AnonFilter_a8_850();
void conv_code_filter_851();
void Post_CollapsedDataParallel_1_982();
void Identity_852();
void BPSK_855();
void WEIGHTED_ROUND_ROBIN_Splitter_994();
void Identity_858();
void header_pilot_generator_859();
void WEIGHTED_ROUND_ROBIN_Joiner_995();
void AnonFilter_a10_860();
void WEIGHTED_ROUND_ROBIN_Splitter_996();
void zero_gen_complex_862();
void Identity_863();
void zero_gen_complex_864();
void Identity_865();
void zero_gen_complex_866();
void WEIGHTED_ROUND_ROBIN_Joiner_997();
void WEIGHTED_ROUND_ROBIN_Splitter_998();
void zero_gen_869();
void Identity_870();
void zero_gen_871();
void WEIGHTED_ROUND_ROBIN_Joiner_999();
void WEIGHTED_ROUND_ROBIN_Splitter_1000();
void Identity_874();
void scramble_seq_875();
void WEIGHTED_ROUND_ROBIN_Joiner_1001();
void xor_pair_876();
void zero_tail_bits_877();
void AnonFilter_a8_880();
void conv_code_filter_881();
void puncture_1_882();
void Post_CollapsedDataParallel_1_983();
void Identity_883();
void WEIGHTED_ROUND_ROBIN_Splitter_1002();
void Identity_897();
void swap_898();
void WEIGHTED_ROUND_ROBIN_Joiner_1003();
void QAM16_899();
void WEIGHTED_ROUND_ROBIN_Splitter_1004();
void Identity_902();
void pilot_generator_903();
void WEIGHTED_ROUND_ROBIN_Joiner_1005();
void AnonFilter_a10_904();
void WEIGHTED_ROUND_ROBIN_Splitter_1006();
void zero_gen_complex_906();
void Identity_907();
void zero_gen_complex_908();
void Identity_909();
void zero_gen_complex_910();
void WEIGHTED_ROUND_ROBIN_Joiner_1007();
void WEIGHTED_ROUND_ROBIN_Joiner_993();
void fftshift_1d_912();
void FFTReorderSimple_913();
void FFTReorderSimple_914();
void FFTReorderSimple_915();
void FFTReorderSimple_916();
void FFTReorderSimple_917();
void CombineIDFT_918();
void CombineIDFT_919();
void CombineIDFT_920();
void CombineIDFT_921();
void CombineIDFT_922();
void CombineIDFTFinal_923();
void DUPLICATE_Splitter_1008();
void remove_first_925();
void Identity_926();
void remove_last_927();
void WEIGHTED_ROUND_ROBIN_Joiner_1009();
void WEIGHTED_ROUND_ROBIN_Splitter_1010();
void Identity_929();
void WEIGHTED_ROUND_ROBIN_Splitter_1012();
void Identity_931();
void halve_and_combine_932();
void WEIGHTED_ROUND_ROBIN_Joiner_1013();
void Identity_933();
void halve_934();
void WEIGHTED_ROUND_ROBIN_Joiner_1011();
void WEIGHTED_ROUND_ROBIN_Joiner_985();
void WEIGHTED_ROUND_ROBIN_Splitter_1014();
void Identity_936();
void halve_and_combine_937();
void Identity_938();
void WEIGHTED_ROUND_ROBIN_Joiner_1015();
void output_c_939();

#ifdef __cplusplus
}
#endif
#endif
