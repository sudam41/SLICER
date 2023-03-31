#include "SDF-Audiobeam_nocache.h"

#include "sim_api.h"

buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[15];
buffer_float_t Average_100Printer_101;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_103Average_100;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[15];


Interpolate_85_t Interpolate_85_s;
Interpolate_85_t Interpolate_86_s;
Interpolate_85_t Interpolate_87_s;
Interpolate_85_t Interpolate_88_s;
Interpolate_85_t Interpolate_89_s;
Interpolate_85_t Interpolate_90_s;
Interpolate_85_t Interpolate_91_s;
Interpolate_85_t Interpolate_92_s;
Interpolate_85_t Interpolate_93_s;
Interpolate_85_t Interpolate_94_s;
Interpolate_85_t Interpolate_95_s;
Interpolate_85_t Interpolate_96_s;
Interpolate_85_t Interpolate_97_s;
Interpolate_85_t Interpolate_98_s;
Interpolate_85_t Interpolate_99_s;
Printer_101_t Printer_101_s;

void FileReader_81(){
	SimNamedMarker(5, __func__);
	FileReader(15);
}

void Interpolate_85() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[0], 0) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[0], 1) ; 
	value = (((high_sample - low_sample) * 0.2536888) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[0], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[0]) ; 
}


void Interpolate_86() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[1], 0) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[1], 1) ; 
	value = (((high_sample - low_sample) * 0.979969) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[1], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[1]) ; 
}


void Interpolate_87() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[2], 1) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[2], 2) ; 
	value = (((high_sample - low_sample) * 0.73080826) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[2], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[2]) ; 
}


void Interpolate_88() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[3], 2) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[3], 3) ; 
	value = (((high_sample - low_sample) * 0.50528336) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[3], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[3]) ; 
}


void Interpolate_89() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[4], 3) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[4], 4) ; 
	value = (((high_sample - low_sample) * 0.30248642) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[4], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[4]) ; 
}


void Interpolate_90() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[5], 4) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[5], 5) ; 
	value = (((high_sample - low_sample) * 0.12152481) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[5], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[5]) ; 
}


void Interpolate_91() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[6], 4) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[6], 5) ; 
	value = (((high_sample - low_sample) * 0.96152496) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[6], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[6]) ; 
}


void Interpolate_92() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[7], 5) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[7], 6) ; 
	value = (((high_sample - low_sample) * 0.8216553) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[7], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[7]) ; 
}


void Interpolate_93() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[8], 6) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[8], 7) ; 
	value = (((high_sample - low_sample) * 0.70109177) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[8], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[8]) ; 
}


void Interpolate_94() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[9], 7) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[9], 8) ; 
	value = (((high_sample - low_sample) * 0.5990677) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[9], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[9]) ; 
}


void Interpolate_95() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[10], 8) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[10], 9) ; 
	value = (((high_sample - low_sample) * 0.51478577) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[10], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[10]) ; 
}


void Interpolate_96() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[11], 9) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[11], 10) ; 
	value = (((high_sample - low_sample) * 0.44754028) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[11], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[11]) ; 
}


void Interpolate_97() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[12], 10) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[12], 11) ; 
	value = (((high_sample - low_sample) * 0.3966217) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[12], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[12]) ; 
}


void Interpolate_98() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[13], 11) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[13], 12) ; 
	value = (((high_sample - low_sample) * 0.36133575) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[13], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[13]) ; 
}


void Interpolate_99() {
	SimNamedMarker(5, __func__);
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[14], 12) ; 
	high_sample = peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[14], 13) ; 
	value = (((high_sample - low_sample) * 0.3410492) + low_sample) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[14], (value * 1.0)) ; 
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[14]) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_102() {
	SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_, 0, <, 15, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[__iter_], pop_float(&FileReaderBufFloat));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_103() {
	SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_, 0, <, 15, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_103Average_100, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[__iter_]));
	ENDFOR
}

void Average_100() {
	SimNamedMarker(5, __func__);
	float sum = 0.0;
	FOR(int, i, 0,  < , 15, i++) {
		float val = 0.0;
		val = pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_103Average_100) ; 
		sum = (sum + val) ; 
	}
	ENDFOR
	push_float(&Average_100Printer_101, (sum / 15.0)) ; 
}


void Printer_101() {
	SimNamedMarker(5, __func__);
	printf("%.10f", Printer_101_s.time_index);
	FOR(int, i, 0,  < , 1, i++) {
		printf("%s", " ");
		printf("%.10f", pop_float(&Average_100Printer_101));
	}
	ENDFOR
	printf("%s", "");
	printf("\n");
	Printer_101_s.time_index = (Printer_101_s.time_index + 6.25E-5) ; 
}


void __stream_init__() {
	FOR(int, __iter_init_0_, 0, <, 15, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&Average_100Printer_101);
	FileReader_init(READDATAFILE, "float");
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_103Average_100);
	FOR(int, __iter_init_1_, 0, <, 15, __iter_init_1_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[__iter_init_1_]);
	ENDFOR
	FileReader(195);
// --- init: WEIGHTED_ROUND_ROBIN_Splitter_102
	FOR(uint32_t, __iter_init_, 0, <, 13, __iter_init_++)
		FOR(uint32_t, __iter_, 0, <, 15, __iter_++)
			push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[__iter_], pop_float(&FileReaderBufFloat));
		ENDFOR
	ENDFOR
//--------------------------------
// --- init: Printer_101
	 {
	Printer_101_s.time_index = 0.0 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		FileReader_81();
		WEIGHTED_ROUND_ROBIN_Splitter_102();
			Interpolate_85();
			Interpolate_86();
			Interpolate_87();
			Interpolate_88();
			Interpolate_89();
			Interpolate_90();
			Interpolate_91();
			Interpolate_92();
			Interpolate_93();
			Interpolate_94();
			Interpolate_95();
			Interpolate_96();
			Interpolate_97();
			Interpolate_98();
			Interpolate_99();
		WEIGHTED_ROUND_ROBIN_Joiner_103();
		Average_100();
		Printer_101();
	ENDFOR
	FileReader_close();
	return EXIT_SUCCESS;
}
