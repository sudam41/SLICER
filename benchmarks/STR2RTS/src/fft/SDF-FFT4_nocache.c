#include "SDF-FFT4_nocache.h"

buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_79FloatPrinter_75;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_split[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_77DUPLICATE_Splitter_78;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_join[2];
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_join[2];
buffer_float_t OneSource_67WEIGHTED_ROUND_ROBIN_Splitter_76;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[2];



void OneSource_67(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		push_float(&OneSource_67WEIGHTED_ROUND_ROBIN_Splitter_76, 1.0) ; 
	}
	ENDFOR
}

void Identity_70() {
	float __tmp3 = 0.0;
	__tmp3 = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_split[0]) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_join[0], __tmp3) ; 
}


void Multiply_71() {
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_join[1], (2.0 * pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_split[1]))) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_76() {
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_split[0], pop_float(&OneSource_67WEIGHTED_ROUND_ROBIN_Splitter_76));
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_split[1], pop_float(&OneSource_67WEIGHTED_ROUND_ROBIN_Splitter_76));
}

void WEIGHTED_ROUND_ROBIN_Joiner_77() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_77DUPLICATE_Splitter_78, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_77DUPLICATE_Splitter_78, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_join[1]));
}

void Add_73() {
	push_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_join[0], (peek_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[0], 0) + peek_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[0], 1))) ; 
	pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[0]) ; 
	pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[0]) ; 
}


void Subtract_74() {
	push_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_join[1], (peek_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[1], 0) - peek_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[1], 1))) ; 
	pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[1]) ; 
	pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[1]) ; 
}


void DUPLICATE_Splitter_78() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++)
		float __token_ = pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_77DUPLICATE_Splitter_78);
		FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
			push_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_79() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_79FloatPrinter_75, pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_79FloatPrinter_75, pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_join[1]));
}

void FloatPrinter_75(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		printf("%.10f", pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_79FloatPrinter_75));
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_79FloatPrinter_75);
	FOR(int, __iter_init_0_, 0, <, 2, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_split[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_77DUPLICATE_Splitter_78);
	FOR(int, __iter_init_1_, 0, <, 2, __iter_init_1_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_join[__iter_init_1_]);
	ENDFOR
	FOR(int, __iter_init_2_, 0, <, 2, __iter_init_2_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a0_69_80_90_93_join[__iter_init_2_]);
	ENDFOR
	init_buffer_float(&OneSource_67WEIGHTED_ROUND_ROBIN_Splitter_76);
	FOR(int, __iter_init_3_, 0, <, 2, __iter_init_3_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a1_72_82_91_94_split[__iter_init_3_]);
	ENDFOR
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		OneSource_67();
		WEIGHTED_ROUND_ROBIN_Splitter_76();
			Identity_70();
			Multiply_71();
		WEIGHTED_ROUND_ROBIN_Joiner_77();
		DUPLICATE_Splitter_78();
			Add_73();
			Subtract_74();
		WEIGHTED_ROUND_ROBIN_Joiner_79();
		FloatPrinter_75();
	ENDFOR
	return EXIT_SUCCESS;
}
