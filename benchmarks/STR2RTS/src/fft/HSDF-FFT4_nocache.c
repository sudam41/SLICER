#include "HSDF-FFT4_nocache.h"

buffer_float_t SplitJoin0_OneSource_Fiss_166_170_split[2];
buffer_float_t SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_join[2];
buffer_float_t SplitJoin0_OneSource_Fiss_166_170_join[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_148DUPLICATE_Splitter_149;
buffer_float_t SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_join[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_150FloatPrinter_146;
buffer_float_t SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_163WEIGHTED_ROUND_ROBIN_Splitter_147;
buffer_float_t SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_split[2];



void OneSource_164() {
	push_float(&SplitJoin0_OneSource_Fiss_166_170_join[0], 1.0) ; 
}


void OneSource_165() {
	push_float(&SplitJoin0_OneSource_Fiss_166_170_join[1], 1.0) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_162() {
}

void WEIGHTED_ROUND_ROBIN_Joiner_163() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_163WEIGHTED_ROUND_ROBIN_Splitter_147, pop_float(&SplitJoin0_OneSource_Fiss_166_170_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_163WEIGHTED_ROUND_ROBIN_Splitter_147, pop_float(&SplitJoin0_OneSource_Fiss_166_170_join[1]));
}

void Identity_141() {
	float __tmp3 = 0.0;
	__tmp3 = pop_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_split[0]) ; 
	push_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_join[0], __tmp3) ; 
}


void Multiply_142() {
	push_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_join[1], (2.0 * pop_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_split[1]))) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_147() {
	push_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_split[0], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_163WEIGHTED_ROUND_ROBIN_Splitter_147));
	push_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_split[1], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_163WEIGHTED_ROUND_ROBIN_Splitter_147));
}

void WEIGHTED_ROUND_ROBIN_Joiner_148() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_148DUPLICATE_Splitter_149, pop_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_148DUPLICATE_Splitter_149, pop_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_join[1]));
}

void Add_144() {
	push_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_join[0], (peek_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[0], 0) + peek_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[0], 1))) ; 
	pop_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[0]) ; 
	pop_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[0]) ; 
}


void Subtract_145() {
	push_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_join[1], (peek_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[1], 0) - peek_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[1], 1))) ; 
	pop_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[1]) ; 
	pop_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[1]) ; 
}


void DUPLICATE_Splitter_149() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++)
		float __token_ = pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_148DUPLICATE_Splitter_149);
		FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
			push_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_150() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_150FloatPrinter_146, pop_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_150FloatPrinter_146, pop_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_join[1]));
}

void FloatPrinter_146(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		printf("%.10f", pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_150FloatPrinter_146));
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	FOR(int, __iter_init_0_, 0, <, 2, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_OneSource_Fiss_166_170_split[__iter_init_0_]);
	ENDFOR
	FOR(int, __iter_init_1_, 0, <, 2, __iter_init_1_++)
		init_buffer_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_join[__iter_init_1_]);
	ENDFOR
	FOR(int, __iter_init_2_, 0, <, 2, __iter_init_2_++)
		init_buffer_float(&SplitJoin0_OneSource_Fiss_166_170_join[__iter_init_2_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_148DUPLICATE_Splitter_149);
	FOR(int, __iter_init_3_, 0, <, 2, __iter_init_3_++)
		init_buffer_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_join[__iter_init_3_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_150FloatPrinter_146);
	FOR(int, __iter_init_4_, 0, <, 2, __iter_init_4_++)
		init_buffer_float(&SplitJoin4_SplitJoin2_SplitJoin2_AnonFilter_a1_143_153_168_172_split[__iter_init_4_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_163WEIGHTED_ROUND_ROBIN_Splitter_147);
	FOR(int, __iter_init_5_, 0, <, 2, __iter_init_5_++)
		init_buffer_float(&SplitJoin2_SplitJoin0_SplitJoin0_AnonFilter_a0_140_151_167_171_split[__iter_init_5_]);
	ENDFOR
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		WEIGHTED_ROUND_ROBIN_Splitter_162();
			OneSource_164();
			OneSource_165();
		WEIGHTED_ROUND_ROBIN_Joiner_163();
		WEIGHTED_ROUND_ROBIN_Splitter_147();
			Identity_141();
			Multiply_142();
		WEIGHTED_ROUND_ROBIN_Joiner_148();
		DUPLICATE_Splitter_149();
			Add_144();
			Subtract_145();
		WEIGHTED_ROUND_ROBIN_Joiner_150();
		FloatPrinter_146();
	ENDFOR
	return EXIT_SUCCESS;
}
