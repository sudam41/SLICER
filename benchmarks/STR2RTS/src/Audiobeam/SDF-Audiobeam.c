#include "SDF-Audiobeam.h"

#include "sim_api.h"

buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[15];
buffer_float_t Average_100Printer_101;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_103Average_100;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[15];


Printer_101_t Printer_101_s;

void FileReader_81() {
	SimNamedMarker(5, __func__);
	FileReader(15);
}

void Interpolate(buffer_float_t *chanin, buffer_float_t *chanout) {
	float low_sample = 0.0;
	float high_sample = 0.0;
	float value = 0.0;
	low_sample = peek_float(&(*chanin), 0) ; 
	high_sample = peek_float(&(*chanin), 1) ; 
	value = (((high_sample - low_sample) * 0.2536888) + low_sample) ; 
	push_float(&(*chanout), (value * 1.0)) ; 
	pop_float(&(*chanin)) ; 
}


void Interpolate_85() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[0]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[0]));
}

void Interpolate_86() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[1]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[1]));
}

void Interpolate_87() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[2]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[2]));
}

void Interpolate_88() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[3]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[3]));
}

void Interpolate_89() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[4]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[4]));
}

void Interpolate_90() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[5]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[5]));
}

void Interpolate_91() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[6]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[6]));
}

void Interpolate_92() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[7]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[7]));
}

void Interpolate_93() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[8]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[8]));
}

void Interpolate_94() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[9]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[9]));
}

void Interpolate_95() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[10]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[10]));
}

void Interpolate_96() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[11]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[11]));
}

void Interpolate_97() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[12]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[12]));
}

void Interpolate_98() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[13]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[13]));
}

void Interpolate_99() {
	SimNamedMarker(5, __func__);
	Interpolate(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[14]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_join[14]));
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

void Average(buffer_float_t *chanin, buffer_float_t *chanout) {
	float sum = 0.0;
	FOR(int, i, 0,  < , 15, i++) {
		float val = 0.0;
		val = pop_float(&(*chanin)) ; 
		sum = (sum + val) ; 
	}
	ENDFOR
	push_float(&(*chanout), (sum / 15.0)) ; 
}


void Average_100() {
	SimNamedMarker(5, __func__);
	Average(&(WEIGHTED_ROUND_ROBIN_Joiner_103Average_100), &(Average_100Printer_101));
}

void Printer(buffer_float_t *chanin) {
	printf("%.10f", Printer_101_s.time_index);
	FOR(int, i, 0,  < , 1, i++) {
		printf("%s", " ");
		printf("%.10f", pop_float(&(*chanin)));
	}
	ENDFOR
	printf("%s", "");
	printf("\n");
	Printer_101_s.time_index = (Printer_101_s.time_index + 6.25E-5) ; 
}


void Printer_101() {
	SimNamedMarker(5, __func__);
	Printer(&(Average_100Printer_101));
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
		WEIGHTED_ROUND_ROBIN_Splitter(&(FileReaderBufFloat), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_79_104_120_122_split[Need Human for iter var]));
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
