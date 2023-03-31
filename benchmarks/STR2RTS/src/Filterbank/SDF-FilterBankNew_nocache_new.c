#include "sim_api.h"
#include "SDF-FilterBankNew_nocache.h"

buffer_float_t UpSamp_67Delay_N_68;
buffer_float_t Delay_N_89FirFilter_90;
buffer_float_t DownSamp_80UpSamp_81;
buffer_float_t FirFilter_72DownSamp_73;
buffer_float_t UpSamp_88Delay_N_89;
buffer_float_t FirFilter_107DownSamp_108;
buffer_float_t DownSamp_73UpSamp_74;
buffer_float_t FirFilter_114DownSamp_115;
buffer_float_t Delay_N_64FirFilter_65;
buffer_float_t Delay_N_85FirFilter_86;
buffer_float_t Delay_N_71FirFilter_72;
buffer_float_t FirFilter_86DownSamp_87;
buffer_float_t UpSamp_109Delay_N_110;
buffer_float_t FirFilter_100DownSamp_101;
buffer_float_t UpSamp_102Delay_N_103;
buffer_float_t Delay_N_68FirFilter_69;
buffer_float_t Delay_N_92FirFilter_93;
buffer_float_t FirFilter_93DownSamp_94;
buffer_float_t Delay_N_113FirFilter_114;
buffer_float_t Delay_N_106FirFilter_107;
buffer_float_t DownSamp_115UpSamp_116;
buffer_float_t source_61DUPLICATE_Splitter_121;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[8];
buffer_float_t Combine_119sink_120;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_122Combine_119;
buffer_float_t Delay_N_110FirFilter_111;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[8];
buffer_float_t Delay_N_99FirFilter_100;
buffer_float_t DownSamp_101UpSamp_102;
buffer_float_t Delay_N_103FirFilter_104;
buffer_float_t DownSamp_94UpSamp_95;
buffer_float_t Delay_N_82FirFilter_83;
buffer_float_t Delay_N_96FirFilter_97;
buffer_float_t FirFilter_79DownSamp_80;
buffer_float_t Delay_N_78FirFilter_79;
buffer_float_t DownSamp_66UpSamp_67;
buffer_float_t Delay_N_75FirFilter_76;
buffer_float_t UpSamp_95Delay_N_96;
buffer_float_t UpSamp_81Delay_N_82;
buffer_float_t DownSamp_87UpSamp_88;
buffer_float_t FirFilter_65DownSamp_66;
buffer_float_t UpSamp_116Delay_N_117;
buffer_float_t Delay_N_117FirFilter_118;
buffer_float_t UpSamp_74Delay_N_75;
buffer_float_t DownSamp_108UpSamp_109;


source_61_t source_61_s;
FirFilter_65_t FirFilter_65_s;
FirFilter_65_t FirFilter_69_s;
FirFilter_65_t FirFilter_72_s;
FirFilter_65_t FirFilter_76_s;
FirFilter_65_t FirFilter_79_s;
FirFilter_65_t FirFilter_83_s;
FirFilter_65_t FirFilter_86_s;
FirFilter_65_t FirFilter_90_s;
FirFilter_65_t FirFilter_93_s;
FirFilter_65_t FirFilter_97_s;
FirFilter_65_t FirFilter_100_s;
FirFilter_65_t FirFilter_104_s;
FirFilter_65_t FirFilter_107_s;
FirFilter_65_t FirFilter_111_s;
FirFilter_65_t FirFilter_114_s;
FirFilter_65_t FirFilter_118_s;

void source_61(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&source_61DUPLICATE_Splitter_121, source_61_s.current) ; 
		if((source_61_s.current > 1000.0)) {
			source_61_s.current = 0.0 ; 
		}
		else {
			source_61_s.current = (source_61_s.current + 1.0) ; 
		}
	}
	ENDFOR
}

void Delay_N_64(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_64FirFilter_65, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[0])) ; 
	}
	ENDFOR
}

void FirFilter_65(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_64FirFilter_65, i) * FirFilter_65_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_64FirFilter_65) ; 
		push_float(&FirFilter_65DownSamp_66, sum) ; 
	}
	ENDFOR
}

void DownSamp_66() {
	push_float(&DownSamp_66UpSamp_67, pop_float(&FirFilter_65DownSamp_66)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_65DownSamp_66) ; 
	}
	ENDFOR
}


void UpSamp_67() {
	push_float(&UpSamp_67Delay_N_68, pop_float(&DownSamp_66UpSamp_67)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_67Delay_N_68, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_68(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_68FirFilter_69, pop_float(&UpSamp_67Delay_N_68)) ; 
	}
	ENDFOR
}

void FirFilter_69(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_68FirFilter_69, i) * FirFilter_69_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_68FirFilter_69) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[0], sum) ; 
	}
	ENDFOR
}

void Delay_N_71(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_71FirFilter_72, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[1])) ; 
	}
	ENDFOR
}

void FirFilter_72(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_71FirFilter_72, i) * FirFilter_72_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_71FirFilter_72) ; 
		push_float(&FirFilter_72DownSamp_73, sum) ; 
	}
	ENDFOR
}

void DownSamp_73() {
	push_float(&DownSamp_73UpSamp_74, pop_float(&FirFilter_72DownSamp_73)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_72DownSamp_73) ; 
	}
	ENDFOR
}


void UpSamp_74() {
	push_float(&UpSamp_74Delay_N_75, pop_float(&DownSamp_73UpSamp_74)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_74Delay_N_75, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_75(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_75FirFilter_76, pop_float(&UpSamp_74Delay_N_75)) ; 
	}
	ENDFOR
}

void FirFilter_76(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_75FirFilter_76, i) * FirFilter_76_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_75FirFilter_76) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[1], sum) ; 
	}
	ENDFOR
}

void Delay_N_78(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_78FirFilter_79, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[2])) ; 
	}
	ENDFOR
}

void FirFilter_79(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_78FirFilter_79, i) * FirFilter_79_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_78FirFilter_79) ; 
		push_float(&FirFilter_79DownSamp_80, sum) ; 
	}
	ENDFOR
}

void DownSamp_80() {
	push_float(&DownSamp_80UpSamp_81, pop_float(&FirFilter_79DownSamp_80)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_79DownSamp_80) ; 
	}
	ENDFOR
}


void UpSamp_81() {
	push_float(&UpSamp_81Delay_N_82, pop_float(&DownSamp_80UpSamp_81)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_81Delay_N_82, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_82(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_82FirFilter_83, pop_float(&UpSamp_81Delay_N_82)) ; 
	}
	ENDFOR
}

void FirFilter_83(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_82FirFilter_83, i) * FirFilter_83_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_82FirFilter_83) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[2], sum) ; 
	}
	ENDFOR
}

void Delay_N_85(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_85FirFilter_86, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[3])) ; 
	}
	ENDFOR
}

void FirFilter_86(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_85FirFilter_86, i) * FirFilter_86_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_85FirFilter_86) ; 
		push_float(&FirFilter_86DownSamp_87, sum) ; 
	}
	ENDFOR
}

void DownSamp_87() {
	push_float(&DownSamp_87UpSamp_88, pop_float(&FirFilter_86DownSamp_87)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_86DownSamp_87) ; 
	}
	ENDFOR
}


void UpSamp_88() {
	push_float(&UpSamp_88Delay_N_89, pop_float(&DownSamp_87UpSamp_88)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_88Delay_N_89, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_89(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_89FirFilter_90, pop_float(&UpSamp_88Delay_N_89)) ; 
	}
	ENDFOR
}

void FirFilter_90(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_89FirFilter_90, i) * FirFilter_90_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_89FirFilter_90) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[3], sum) ; 
	}
	ENDFOR
}

void Delay_N_92(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_92FirFilter_93, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[4])) ; 
	}
	ENDFOR
}

void FirFilter_93(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_92FirFilter_93, i) * FirFilter_93_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_92FirFilter_93) ; 
		push_float(&FirFilter_93DownSamp_94, sum) ; 
	}
	ENDFOR
}

void DownSamp_94() {
	push_float(&DownSamp_94UpSamp_95, pop_float(&FirFilter_93DownSamp_94)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_93DownSamp_94) ; 
	}
	ENDFOR
}


void UpSamp_95() {
	push_float(&UpSamp_95Delay_N_96, pop_float(&DownSamp_94UpSamp_95)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_95Delay_N_96, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_96(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_96FirFilter_97, pop_float(&UpSamp_95Delay_N_96)) ; 
	}
	ENDFOR
}

void FirFilter_97(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_96FirFilter_97, i) * FirFilter_97_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_96FirFilter_97) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[4], sum) ; 
	}
	ENDFOR
}

void Delay_N_99(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_99FirFilter_100, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[5])) ; 
	}
	ENDFOR
}

void FirFilter_100(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_99FirFilter_100, i) * FirFilter_100_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_99FirFilter_100) ; 
		push_float(&FirFilter_100DownSamp_101, sum) ; 
	}
	ENDFOR
}

void DownSamp_101() {
	push_float(&DownSamp_101UpSamp_102, pop_float(&FirFilter_100DownSamp_101)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_100DownSamp_101) ; 
	}
	ENDFOR
}


void UpSamp_102() {
	push_float(&UpSamp_102Delay_N_103, pop_float(&DownSamp_101UpSamp_102)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_102Delay_N_103, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_103(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_103FirFilter_104, pop_float(&UpSamp_102Delay_N_103)) ; 
	}
	ENDFOR
}

void FirFilter_104(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_103FirFilter_104, i) * FirFilter_104_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_103FirFilter_104) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[5], sum) ; 
	}
	ENDFOR
}

void Delay_N_106(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_106FirFilter_107, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[6])) ; 
	}
	ENDFOR
}

void FirFilter_107(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_106FirFilter_107, i) * FirFilter_107_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_106FirFilter_107) ; 
		push_float(&FirFilter_107DownSamp_108, sum) ; 
	}
	ENDFOR
}

void DownSamp_108() {
	push_float(&DownSamp_108UpSamp_109, pop_float(&FirFilter_107DownSamp_108)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_107DownSamp_108) ; 
	}
	ENDFOR
}


void UpSamp_109() {
	push_float(&UpSamp_109Delay_N_110, pop_float(&DownSamp_108UpSamp_109)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_109Delay_N_110, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_110(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_110FirFilter_111, pop_float(&UpSamp_109Delay_N_110)) ; 
	}
	ENDFOR
}

void FirFilter_111(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_110FirFilter_111, i) * FirFilter_111_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_110FirFilter_111) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[6], sum) ; 
	}
	ENDFOR
}

void Delay_N_113(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_113FirFilter_114, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[7])) ; 
	}
	ENDFOR
}

void FirFilter_114(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_113FirFilter_114, i) * FirFilter_114_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_113FirFilter_114) ; 
		push_float(&FirFilter_114DownSamp_115, sum) ; 
	}
	ENDFOR
}

void DownSamp_115() {
	push_float(&DownSamp_115UpSamp_116, pop_float(&FirFilter_114DownSamp_115)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&FirFilter_114DownSamp_115) ; 
	}
	ENDFOR
}


void UpSamp_116() {
	push_float(&UpSamp_116Delay_N_117, pop_float(&DownSamp_115UpSamp_116)) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&UpSamp_116Delay_N_117, 0.0) ; 
	}
	ENDFOR
}


void Delay_N_117(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		push_float(&Delay_N_117FirFilter_118, pop_float(&UpSamp_116Delay_N_117)) ; 
	}
	ENDFOR
}

void FirFilter_118(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&Delay_N_117FirFilter_118, i) * FirFilter_118_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&Delay_N_117FirFilter_118) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[7], sum) ; 
	}
	ENDFOR
}

void DUPLICATE_Splitter_121() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		float __token_ = pop_float(&source_61DUPLICATE_Splitter_121);
		FOR(uint32_t, __iter_dup_, 0, <, 8, __iter_dup_++)
			push_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_122() {
SimNamedMarker(5, __func__);
{
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FOR(uint32_t, __iter_, 0, <, 8, __iter_++)
			push_float(&WEIGHTED_ROUND_ROBIN_Joiner_122Combine_119, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[__iter_]));
		ENDFOR
	ENDFOR
}}

void Combine_119(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 8, i++) {
			sum = (sum + pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_122Combine_119)) ; 
		}
		ENDFOR
		push_float(&Combine_119sink_120, sum) ; 
	}
	ENDFOR
}

void sink_120(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		printf("%.10f", pop_float(&Combine_119sink_120));
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&UpSamp_67Delay_N_68);
	init_buffer_float(&Delay_N_89FirFilter_90);
	init_buffer_float(&DownSamp_80UpSamp_81);
	init_buffer_float(&FirFilter_72DownSamp_73);
	init_buffer_float(&UpSamp_88Delay_N_89);
	init_buffer_float(&FirFilter_107DownSamp_108);
	init_buffer_float(&DownSamp_73UpSamp_74);
	init_buffer_float(&FirFilter_114DownSamp_115);
	init_buffer_float(&Delay_N_64FirFilter_65);
	init_buffer_float(&Delay_N_85FirFilter_86);
	init_buffer_float(&Delay_N_71FirFilter_72);
	init_buffer_float(&FirFilter_86DownSamp_87);
	init_buffer_float(&UpSamp_109Delay_N_110);
	init_buffer_float(&FirFilter_100DownSamp_101);
	init_buffer_float(&UpSamp_102Delay_N_103);
	init_buffer_float(&Delay_N_68FirFilter_69);
	init_buffer_float(&Delay_N_92FirFilter_93);
	init_buffer_float(&FirFilter_93DownSamp_94);
	init_buffer_float(&Delay_N_113FirFilter_114);
	init_buffer_float(&Delay_N_106FirFilter_107);
	init_buffer_float(&DownSamp_115UpSamp_116);
	init_buffer_float(&source_61DUPLICATE_Splitter_121);
	FOR(int, __iter_init_0_, 0, <, 8, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&Combine_119sink_120);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_122Combine_119);
	init_buffer_float(&Delay_N_110FirFilter_111);
	FOR(int, __iter_init_1_, 0, <, 8, __iter_init_1_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[__iter_init_1_]);
	ENDFOR
	init_buffer_float(&Delay_N_99FirFilter_100);
	init_buffer_float(&DownSamp_101UpSamp_102);
	init_buffer_float(&Delay_N_103FirFilter_104);
	init_buffer_float(&DownSamp_94UpSamp_95);
	init_buffer_float(&Delay_N_82FirFilter_83);
	init_buffer_float(&Delay_N_96FirFilter_97);
	init_buffer_float(&FirFilter_79DownSamp_80);
	init_buffer_float(&Delay_N_78FirFilter_79);
	init_buffer_float(&DownSamp_66UpSamp_67);
	init_buffer_float(&Delay_N_75FirFilter_76);
	init_buffer_float(&UpSamp_95Delay_N_96);
	init_buffer_float(&UpSamp_81Delay_N_82);
	init_buffer_float(&DownSamp_87UpSamp_88);
	init_buffer_float(&FirFilter_65DownSamp_66);
	init_buffer_float(&UpSamp_116Delay_N_117);
	init_buffer_float(&Delay_N_117FirFilter_118);
	init_buffer_float(&UpSamp_74Delay_N_75);
	init_buffer_float(&DownSamp_108UpSamp_109);
// --- init: source_61
	 {
	source_61_s.current = 0.0 ; 
}
//--------------------------------
// --- prework: Delay_N_64
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_64FirFilter_65, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_65
	 {
	FirFilter_65_s.COEFF[0] = 1.0 ; 
	FirFilter_65_s.COEFF[1] = 34.0 ; 
	FirFilter_65_s.COEFF[2] = 67.0 ; 
	FirFilter_65_s.COEFF[3] = 100.0 ; 
	FirFilter_65_s.COEFF[4] = 133.0 ; 
	FirFilter_65_s.COEFF[5] = 166.0 ; 
	FirFilter_65_s.COEFF[6] = 199.0 ; 
	FirFilter_65_s.COEFF[7] = 232.0 ; 
	FirFilter_65_s.COEFF[8] = 265.0 ; 
	FirFilter_65_s.COEFF[9] = 298.0 ; 
	FirFilter_65_s.COEFF[10] = 331.0 ; 
	FirFilter_65_s.COEFF[11] = 364.0 ; 
	FirFilter_65_s.COEFF[12] = 397.0 ; 
	FirFilter_65_s.COEFF[13] = 430.0 ; 
	FirFilter_65_s.COEFF[14] = 463.0 ; 
	FirFilter_65_s.COEFF[15] = 496.0 ; 
	FirFilter_65_s.COEFF[16] = 529.0 ; 
	FirFilter_65_s.COEFF[17] = 562.0 ; 
	FirFilter_65_s.COEFF[18] = 595.0 ; 
	FirFilter_65_s.COEFF[19] = 628.0 ; 
	FirFilter_65_s.COEFF[20] = 661.0 ; 
	FirFilter_65_s.COEFF[21] = 694.0 ; 
	FirFilter_65_s.COEFF[22] = 727.0 ; 
	FirFilter_65_s.COEFF[23] = 760.0 ; 
	FirFilter_65_s.COEFF[24] = 793.0 ; 
	FirFilter_65_s.COEFF[25] = 826.0 ; 
	FirFilter_65_s.COEFF[26] = 859.0 ; 
	FirFilter_65_s.COEFF[27] = 892.0 ; 
	FirFilter_65_s.COEFF[28] = 925.0 ; 
	FirFilter_65_s.COEFF[29] = 958.0 ; 
	FirFilter_65_s.COEFF[30] = 991.0 ; 
	FirFilter_65_s.COEFF[31] = 1024.0 ; 
}
//--------------------------------
// --- prework: Delay_N_68
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_68FirFilter_69, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_69
	 {
	FirFilter_69_s.COEFF[0] = 0.0 ; 
	FirFilter_69_s.COEFF[1] = 1.0 ; 
	FirFilter_69_s.COEFF[2] = 2.0 ; 
	FirFilter_69_s.COEFF[3] = 3.0 ; 
	FirFilter_69_s.COEFF[4] = 4.0 ; 
	FirFilter_69_s.COEFF[5] = 5.0 ; 
	FirFilter_69_s.COEFF[6] = 6.0 ; 
	FirFilter_69_s.COEFF[7] = 7.0 ; 
	FirFilter_69_s.COEFF[8] = 8.0 ; 
	FirFilter_69_s.COEFF[9] = 9.0 ; 
	FirFilter_69_s.COEFF[10] = 10.0 ; 
	FirFilter_69_s.COEFF[11] = 11.0 ; 
	FirFilter_69_s.COEFF[12] = 12.0 ; 
	FirFilter_69_s.COEFF[13] = 13.0 ; 
	FirFilter_69_s.COEFF[14] = 14.0 ; 
	FirFilter_69_s.COEFF[15] = 15.0 ; 
	FirFilter_69_s.COEFF[16] = 16.0 ; 
	FirFilter_69_s.COEFF[17] = 17.0 ; 
	FirFilter_69_s.COEFF[18] = 18.0 ; 
	FirFilter_69_s.COEFF[19] = 19.0 ; 
	FirFilter_69_s.COEFF[20] = 20.0 ; 
	FirFilter_69_s.COEFF[21] = 21.0 ; 
	FirFilter_69_s.COEFF[22] = 22.0 ; 
	FirFilter_69_s.COEFF[23] = 23.0 ; 
	FirFilter_69_s.COEFF[24] = 24.0 ; 
	FirFilter_69_s.COEFF[25] = 25.0 ; 
	FirFilter_69_s.COEFF[26] = 26.0 ; 
	FirFilter_69_s.COEFF[27] = 27.0 ; 
	FirFilter_69_s.COEFF[28] = 28.0 ; 
	FirFilter_69_s.COEFF[29] = 29.0 ; 
	FirFilter_69_s.COEFF[30] = 30.0 ; 
	FirFilter_69_s.COEFF[31] = 31.0 ; 
}
//--------------------------------
// --- prework: Delay_N_71
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_71FirFilter_72, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_72
	 {
	FirFilter_72_s.COEFF[0] = 11.0 ; 
	FirFilter_72_s.COEFF[1] = 44.0 ; 
	FirFilter_72_s.COEFF[2] = 77.0 ; 
	FirFilter_72_s.COEFF[3] = 110.0 ; 
	FirFilter_72_s.COEFF[4] = 143.0 ; 
	FirFilter_72_s.COEFF[5] = 176.0 ; 
	FirFilter_72_s.COEFF[6] = 209.0 ; 
	FirFilter_72_s.COEFF[7] = 242.0 ; 
	FirFilter_72_s.COEFF[8] = 275.0 ; 
	FirFilter_72_s.COEFF[9] = 308.0 ; 
	FirFilter_72_s.COEFF[10] = 341.0 ; 
	FirFilter_72_s.COEFF[11] = 374.0 ; 
	FirFilter_72_s.COEFF[12] = 407.0 ; 
	FirFilter_72_s.COEFF[13] = 440.0 ; 
	FirFilter_72_s.COEFF[14] = 473.0 ; 
	FirFilter_72_s.COEFF[15] = 506.0 ; 
	FirFilter_72_s.COEFF[16] = 539.0 ; 
	FirFilter_72_s.COEFF[17] = 572.0 ; 
	FirFilter_72_s.COEFF[18] = 605.0 ; 
	FirFilter_72_s.COEFF[19] = 638.0 ; 
	FirFilter_72_s.COEFF[20] = 671.0 ; 
	FirFilter_72_s.COEFF[21] = 704.0 ; 
	FirFilter_72_s.COEFF[22] = 737.0 ; 
	FirFilter_72_s.COEFF[23] = 770.0 ; 
	FirFilter_72_s.COEFF[24] = 803.0 ; 
	FirFilter_72_s.COEFF[25] = 836.0 ; 
	FirFilter_72_s.COEFF[26] = 869.0 ; 
	FirFilter_72_s.COEFF[27] = 902.0 ; 
	FirFilter_72_s.COEFF[28] = 935.0 ; 
	FirFilter_72_s.COEFF[29] = 968.0 ; 
	FirFilter_72_s.COEFF[30] = 1001.0 ; 
	FirFilter_72_s.COEFF[31] = 1034.0 ; 
}
//--------------------------------
// --- prework: Delay_N_75
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_75FirFilter_76, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_76
	 {
	FirFilter_76_s.COEFF[0] = 2.0 ; 
	FirFilter_76_s.COEFF[1] = 4.0 ; 
	FirFilter_76_s.COEFF[2] = 6.0 ; 
	FirFilter_76_s.COEFF[3] = 8.0 ; 
	FirFilter_76_s.COEFF[4] = 10.0 ; 
	FirFilter_76_s.COEFF[5] = 12.0 ; 
	FirFilter_76_s.COEFF[6] = 14.0 ; 
	FirFilter_76_s.COEFF[7] = 16.0 ; 
	FirFilter_76_s.COEFF[8] = 18.0 ; 
	FirFilter_76_s.COEFF[9] = 20.0 ; 
	FirFilter_76_s.COEFF[10] = 22.0 ; 
	FirFilter_76_s.COEFF[11] = 24.0 ; 
	FirFilter_76_s.COEFF[12] = 26.0 ; 
	FirFilter_76_s.COEFF[13] = 28.0 ; 
	FirFilter_76_s.COEFF[14] = 30.0 ; 
	FirFilter_76_s.COEFF[15] = 32.0 ; 
	FirFilter_76_s.COEFF[16] = 34.0 ; 
	FirFilter_76_s.COEFF[17] = 36.0 ; 
	FirFilter_76_s.COEFF[18] = 38.0 ; 
	FirFilter_76_s.COEFF[19] = 40.0 ; 
	FirFilter_76_s.COEFF[20] = 42.0 ; 
	FirFilter_76_s.COEFF[21] = 44.0 ; 
	FirFilter_76_s.COEFF[22] = 46.0 ; 
	FirFilter_76_s.COEFF[23] = 48.0 ; 
	FirFilter_76_s.COEFF[24] = 50.0 ; 
	FirFilter_76_s.COEFF[25] = 52.0 ; 
	FirFilter_76_s.COEFF[26] = 54.0 ; 
	FirFilter_76_s.COEFF[27] = 56.0 ; 
	FirFilter_76_s.COEFF[28] = 58.0 ; 
	FirFilter_76_s.COEFF[29] = 60.0 ; 
	FirFilter_76_s.COEFF[30] = 62.0 ; 
	FirFilter_76_s.COEFF[31] = 64.0 ; 
}
//--------------------------------
// --- prework: Delay_N_78
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_78FirFilter_79, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_79
	 {
	FirFilter_79_s.COEFF[0] = 21.0 ; 
	FirFilter_79_s.COEFF[1] = 54.0 ; 
	FirFilter_79_s.COEFF[2] = 87.0 ; 
	FirFilter_79_s.COEFF[3] = 120.0 ; 
	FirFilter_79_s.COEFF[4] = 153.0 ; 
	FirFilter_79_s.COEFF[5] = 186.0 ; 
	FirFilter_79_s.COEFF[6] = 219.0 ; 
	FirFilter_79_s.COEFF[7] = 252.0 ; 
	FirFilter_79_s.COEFF[8] = 285.0 ; 
	FirFilter_79_s.COEFF[9] = 318.0 ; 
	FirFilter_79_s.COEFF[10] = 351.0 ; 
	FirFilter_79_s.COEFF[11] = 384.0 ; 
	FirFilter_79_s.COEFF[12] = 417.0 ; 
	FirFilter_79_s.COEFF[13] = 450.0 ; 
	FirFilter_79_s.COEFF[14] = 483.0 ; 
	FirFilter_79_s.COEFF[15] = 516.0 ; 
	FirFilter_79_s.COEFF[16] = 549.0 ; 
	FirFilter_79_s.COEFF[17] = 582.0 ; 
	FirFilter_79_s.COEFF[18] = 615.0 ; 
	FirFilter_79_s.COEFF[19] = 648.0 ; 
	FirFilter_79_s.COEFF[20] = 681.0 ; 
	FirFilter_79_s.COEFF[21] = 714.0 ; 
	FirFilter_79_s.COEFF[22] = 747.0 ; 
	FirFilter_79_s.COEFF[23] = 780.0 ; 
	FirFilter_79_s.COEFF[24] = 813.0 ; 
	FirFilter_79_s.COEFF[25] = 846.0 ; 
	FirFilter_79_s.COEFF[26] = 879.0 ; 
	FirFilter_79_s.COEFF[27] = 912.0 ; 
	FirFilter_79_s.COEFF[28] = 945.0 ; 
	FirFilter_79_s.COEFF[29] = 978.0 ; 
	FirFilter_79_s.COEFF[30] = 1011.0 ; 
	FirFilter_79_s.COEFF[31] = 1044.0 ; 
}
//--------------------------------
// --- prework: Delay_N_82
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_82FirFilter_83, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_83
	 {
	FirFilter_83_s.COEFF[0] = 6.0 ; 
	FirFilter_83_s.COEFF[1] = 9.0 ; 
	FirFilter_83_s.COEFF[2] = 12.0 ; 
	FirFilter_83_s.COEFF[3] = 15.0 ; 
	FirFilter_83_s.COEFF[4] = 18.0 ; 
	FirFilter_83_s.COEFF[5] = 21.0 ; 
	FirFilter_83_s.COEFF[6] = 24.0 ; 
	FirFilter_83_s.COEFF[7] = 27.0 ; 
	FirFilter_83_s.COEFF[8] = 30.0 ; 
	FirFilter_83_s.COEFF[9] = 33.0 ; 
	FirFilter_83_s.COEFF[10] = 36.0 ; 
	FirFilter_83_s.COEFF[11] = 39.0 ; 
	FirFilter_83_s.COEFF[12] = 42.0 ; 
	FirFilter_83_s.COEFF[13] = 45.0 ; 
	FirFilter_83_s.COEFF[14] = 48.0 ; 
	FirFilter_83_s.COEFF[15] = 51.0 ; 
	FirFilter_83_s.COEFF[16] = 54.0 ; 
	FirFilter_83_s.COEFF[17] = 57.0 ; 
	FirFilter_83_s.COEFF[18] = 60.0 ; 
	FirFilter_83_s.COEFF[19] = 63.0 ; 
	FirFilter_83_s.COEFF[20] = 66.0 ; 
	FirFilter_83_s.COEFF[21] = 69.0 ; 
	FirFilter_83_s.COEFF[22] = 72.0 ; 
	FirFilter_83_s.COEFF[23] = 75.0 ; 
	FirFilter_83_s.COEFF[24] = 78.0 ; 
	FirFilter_83_s.COEFF[25] = 81.0 ; 
	FirFilter_83_s.COEFF[26] = 84.0 ; 
	FirFilter_83_s.COEFF[27] = 87.0 ; 
	FirFilter_83_s.COEFF[28] = 90.0 ; 
	FirFilter_83_s.COEFF[29] = 93.0 ; 
	FirFilter_83_s.COEFF[30] = 96.0 ; 
	FirFilter_83_s.COEFF[31] = 99.0 ; 
}
//--------------------------------
// --- prework: Delay_N_85
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_85FirFilter_86, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_86
	 {
	FirFilter_86_s.COEFF[0] = 31.0 ; 
	FirFilter_86_s.COEFF[1] = 64.0 ; 
	FirFilter_86_s.COEFF[2] = 97.0 ; 
	FirFilter_86_s.COEFF[3] = 130.0 ; 
	FirFilter_86_s.COEFF[4] = 163.0 ; 
	FirFilter_86_s.COEFF[5] = 196.0 ; 
	FirFilter_86_s.COEFF[6] = 229.0 ; 
	FirFilter_86_s.COEFF[7] = 262.0 ; 
	FirFilter_86_s.COEFF[8] = 295.0 ; 
	FirFilter_86_s.COEFF[9] = 328.0 ; 
	FirFilter_86_s.COEFF[10] = 361.0 ; 
	FirFilter_86_s.COEFF[11] = 394.0 ; 
	FirFilter_86_s.COEFF[12] = 427.0 ; 
	FirFilter_86_s.COEFF[13] = 460.0 ; 
	FirFilter_86_s.COEFF[14] = 493.0 ; 
	FirFilter_86_s.COEFF[15] = 526.0 ; 
	FirFilter_86_s.COEFF[16] = 559.0 ; 
	FirFilter_86_s.COEFF[17] = 592.0 ; 
	FirFilter_86_s.COEFF[18] = 625.0 ; 
	FirFilter_86_s.COEFF[19] = 658.0 ; 
	FirFilter_86_s.COEFF[20] = 691.0 ; 
	FirFilter_86_s.COEFF[21] = 724.0 ; 
	FirFilter_86_s.COEFF[22] = 757.0 ; 
	FirFilter_86_s.COEFF[23] = 790.0 ; 
	FirFilter_86_s.COEFF[24] = 823.0 ; 
	FirFilter_86_s.COEFF[25] = 856.0 ; 
	FirFilter_86_s.COEFF[26] = 889.0 ; 
	FirFilter_86_s.COEFF[27] = 922.0 ; 
	FirFilter_86_s.COEFF[28] = 955.0 ; 
	FirFilter_86_s.COEFF[29] = 988.0 ; 
	FirFilter_86_s.COEFF[30] = 1021.0 ; 
	FirFilter_86_s.COEFF[31] = 1054.0 ; 
}
//--------------------------------
// --- prework: Delay_N_89
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_89FirFilter_90, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_90
	 {
	FirFilter_90_s.COEFF[0] = 12.0 ; 
	FirFilter_90_s.COEFF[1] = 16.0 ; 
	FirFilter_90_s.COEFF[2] = 20.0 ; 
	FirFilter_90_s.COEFF[3] = 24.0 ; 
	FirFilter_90_s.COEFF[4] = 28.0 ; 
	FirFilter_90_s.COEFF[5] = 32.0 ; 
	FirFilter_90_s.COEFF[6] = 36.0 ; 
	FirFilter_90_s.COEFF[7] = 40.0 ; 
	FirFilter_90_s.COEFF[8] = 44.0 ; 
	FirFilter_90_s.COEFF[9] = 48.0 ; 
	FirFilter_90_s.COEFF[10] = 52.0 ; 
	FirFilter_90_s.COEFF[11] = 56.0 ; 
	FirFilter_90_s.COEFF[12] = 60.0 ; 
	FirFilter_90_s.COEFF[13] = 64.0 ; 
	FirFilter_90_s.COEFF[14] = 68.0 ; 
	FirFilter_90_s.COEFF[15] = 72.0 ; 
	FirFilter_90_s.COEFF[16] = 76.0 ; 
	FirFilter_90_s.COEFF[17] = 80.0 ; 
	FirFilter_90_s.COEFF[18] = 84.0 ; 
	FirFilter_90_s.COEFF[19] = 88.0 ; 
	FirFilter_90_s.COEFF[20] = 92.0 ; 
	FirFilter_90_s.COEFF[21] = 96.0 ; 
	FirFilter_90_s.COEFF[22] = 100.0 ; 
	FirFilter_90_s.COEFF[23] = 104.0 ; 
	FirFilter_90_s.COEFF[24] = 108.0 ; 
	FirFilter_90_s.COEFF[25] = 112.0 ; 
	FirFilter_90_s.COEFF[26] = 116.0 ; 
	FirFilter_90_s.COEFF[27] = 120.0 ; 
	FirFilter_90_s.COEFF[28] = 124.0 ; 
	FirFilter_90_s.COEFF[29] = 128.0 ; 
	FirFilter_90_s.COEFF[30] = 132.0 ; 
	FirFilter_90_s.COEFF[31] = 136.0 ; 
}
//--------------------------------
// --- prework: Delay_N_92
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_92FirFilter_93, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_93
	 {
	FirFilter_93_s.COEFF[0] = 41.0 ; 
	FirFilter_93_s.COEFF[1] = 74.0 ; 
	FirFilter_93_s.COEFF[2] = 107.0 ; 
	FirFilter_93_s.COEFF[3] = 140.0 ; 
	FirFilter_93_s.COEFF[4] = 173.0 ; 
	FirFilter_93_s.COEFF[5] = 206.0 ; 
	FirFilter_93_s.COEFF[6] = 239.0 ; 
	FirFilter_93_s.COEFF[7] = 272.0 ; 
	FirFilter_93_s.COEFF[8] = 305.0 ; 
	FirFilter_93_s.COEFF[9] = 338.0 ; 
	FirFilter_93_s.COEFF[10] = 371.0 ; 
	FirFilter_93_s.COEFF[11] = 404.0 ; 
	FirFilter_93_s.COEFF[12] = 437.0 ; 
	FirFilter_93_s.COEFF[13] = 470.0 ; 
	FirFilter_93_s.COEFF[14] = 503.0 ; 
	FirFilter_93_s.COEFF[15] = 536.0 ; 
	FirFilter_93_s.COEFF[16] = 569.0 ; 
	FirFilter_93_s.COEFF[17] = 602.0 ; 
	FirFilter_93_s.COEFF[18] = 635.0 ; 
	FirFilter_93_s.COEFF[19] = 668.0 ; 
	FirFilter_93_s.COEFF[20] = 701.0 ; 
	FirFilter_93_s.COEFF[21] = 734.0 ; 
	FirFilter_93_s.COEFF[22] = 767.0 ; 
	FirFilter_93_s.COEFF[23] = 800.0 ; 
	FirFilter_93_s.COEFF[24] = 833.0 ; 
	FirFilter_93_s.COEFF[25] = 866.0 ; 
	FirFilter_93_s.COEFF[26] = 899.0 ; 
	FirFilter_93_s.COEFF[27] = 932.0 ; 
	FirFilter_93_s.COEFF[28] = 965.0 ; 
	FirFilter_93_s.COEFF[29] = 998.0 ; 
	FirFilter_93_s.COEFF[30] = 1031.0 ; 
	FirFilter_93_s.COEFF[31] = 1064.0 ; 
}
//--------------------------------
// --- prework: Delay_N_96
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_96FirFilter_97, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_97
	 {
	FirFilter_97_s.COEFF[0] = 20.0 ; 
	FirFilter_97_s.COEFF[1] = 25.0 ; 
	FirFilter_97_s.COEFF[2] = 30.0 ; 
	FirFilter_97_s.COEFF[3] = 35.0 ; 
	FirFilter_97_s.COEFF[4] = 40.0 ; 
	FirFilter_97_s.COEFF[5] = 45.0 ; 
	FirFilter_97_s.COEFF[6] = 50.0 ; 
	FirFilter_97_s.COEFF[7] = 55.0 ; 
	FirFilter_97_s.COEFF[8] = 60.0 ; 
	FirFilter_97_s.COEFF[9] = 65.0 ; 
	FirFilter_97_s.COEFF[10] = 70.0 ; 
	FirFilter_97_s.COEFF[11] = 75.0 ; 
	FirFilter_97_s.COEFF[12] = 80.0 ; 
	FirFilter_97_s.COEFF[13] = 85.0 ; 
	FirFilter_97_s.COEFF[14] = 90.0 ; 
	FirFilter_97_s.COEFF[15] = 95.0 ; 
	FirFilter_97_s.COEFF[16] = 100.0 ; 
	FirFilter_97_s.COEFF[17] = 105.0 ; 
	FirFilter_97_s.COEFF[18] = 110.0 ; 
	FirFilter_97_s.COEFF[19] = 115.0 ; 
	FirFilter_97_s.COEFF[20] = 120.0 ; 
	FirFilter_97_s.COEFF[21] = 125.0 ; 
	FirFilter_97_s.COEFF[22] = 130.0 ; 
	FirFilter_97_s.COEFF[23] = 135.0 ; 
	FirFilter_97_s.COEFF[24] = 140.0 ; 
	FirFilter_97_s.COEFF[25] = 145.0 ; 
	FirFilter_97_s.COEFF[26] = 150.0 ; 
	FirFilter_97_s.COEFF[27] = 155.0 ; 
	FirFilter_97_s.COEFF[28] = 160.0 ; 
	FirFilter_97_s.COEFF[29] = 165.0 ; 
	FirFilter_97_s.COEFF[30] = 170.0 ; 
	FirFilter_97_s.COEFF[31] = 175.0 ; 
}
//--------------------------------
// --- prework: Delay_N_99
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_99FirFilter_100, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_100
	 {
	FirFilter_100_s.COEFF[0] = 51.0 ; 
	FirFilter_100_s.COEFF[1] = 84.0 ; 
	FirFilter_100_s.COEFF[2] = 117.0 ; 
	FirFilter_100_s.COEFF[3] = 150.0 ; 
	FirFilter_100_s.COEFF[4] = 183.0 ; 
	FirFilter_100_s.COEFF[5] = 216.0 ; 
	FirFilter_100_s.COEFF[6] = 249.0 ; 
	FirFilter_100_s.COEFF[7] = 282.0 ; 
	FirFilter_100_s.COEFF[8] = 315.0 ; 
	FirFilter_100_s.COEFF[9] = 348.0 ; 
	FirFilter_100_s.COEFF[10] = 381.0 ; 
	FirFilter_100_s.COEFF[11] = 414.0 ; 
	FirFilter_100_s.COEFF[12] = 447.0 ; 
	FirFilter_100_s.COEFF[13] = 480.0 ; 
	FirFilter_100_s.COEFF[14] = 513.0 ; 
	FirFilter_100_s.COEFF[15] = 546.0 ; 
	FirFilter_100_s.COEFF[16] = 579.0 ; 
	FirFilter_100_s.COEFF[17] = 612.0 ; 
	FirFilter_100_s.COEFF[18] = 645.0 ; 
	FirFilter_100_s.COEFF[19] = 678.0 ; 
	FirFilter_100_s.COEFF[20] = 711.0 ; 
	FirFilter_100_s.COEFF[21] = 744.0 ; 
	FirFilter_100_s.COEFF[22] = 777.0 ; 
	FirFilter_100_s.COEFF[23] = 810.0 ; 
	FirFilter_100_s.COEFF[24] = 843.0 ; 
	FirFilter_100_s.COEFF[25] = 876.0 ; 
	FirFilter_100_s.COEFF[26] = 909.0 ; 
	FirFilter_100_s.COEFF[27] = 942.0 ; 
	FirFilter_100_s.COEFF[28] = 975.0 ; 
	FirFilter_100_s.COEFF[29] = 1008.0 ; 
	FirFilter_100_s.COEFF[30] = 1041.0 ; 
	FirFilter_100_s.COEFF[31] = 1074.0 ; 
}
//--------------------------------
// --- prework: Delay_N_103
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_103FirFilter_104, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_104
	 {
	FirFilter_104_s.COEFF[0] = 30.0 ; 
	FirFilter_104_s.COEFF[1] = 36.0 ; 
	FirFilter_104_s.COEFF[2] = 42.0 ; 
	FirFilter_104_s.COEFF[3] = 48.0 ; 
	FirFilter_104_s.COEFF[4] = 54.0 ; 
	FirFilter_104_s.COEFF[5] = 60.0 ; 
	FirFilter_104_s.COEFF[6] = 66.0 ; 
	FirFilter_104_s.COEFF[7] = 72.0 ; 
	FirFilter_104_s.COEFF[8] = 78.0 ; 
	FirFilter_104_s.COEFF[9] = 84.0 ; 
	FirFilter_104_s.COEFF[10] = 90.0 ; 
	FirFilter_104_s.COEFF[11] = 96.0 ; 
	FirFilter_104_s.COEFF[12] = 102.0 ; 
	FirFilter_104_s.COEFF[13] = 108.0 ; 
	FirFilter_104_s.COEFF[14] = 114.0 ; 
	FirFilter_104_s.COEFF[15] = 120.0 ; 
	FirFilter_104_s.COEFF[16] = 126.0 ; 
	FirFilter_104_s.COEFF[17] = 132.0 ; 
	FirFilter_104_s.COEFF[18] = 138.0 ; 
	FirFilter_104_s.COEFF[19] = 144.0 ; 
	FirFilter_104_s.COEFF[20] = 150.0 ; 
	FirFilter_104_s.COEFF[21] = 156.0 ; 
	FirFilter_104_s.COEFF[22] = 162.0 ; 
	FirFilter_104_s.COEFF[23] = 168.0 ; 
	FirFilter_104_s.COEFF[24] = 174.0 ; 
	FirFilter_104_s.COEFF[25] = 180.0 ; 
	FirFilter_104_s.COEFF[26] = 186.0 ; 
	FirFilter_104_s.COEFF[27] = 192.0 ; 
	FirFilter_104_s.COEFF[28] = 198.0 ; 
	FirFilter_104_s.COEFF[29] = 204.0 ; 
	FirFilter_104_s.COEFF[30] = 210.0 ; 
	FirFilter_104_s.COEFF[31] = 216.0 ; 
}
//--------------------------------
// --- prework: Delay_N_106
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_106FirFilter_107, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_107
	 {
	FirFilter_107_s.COEFF[0] = 61.0 ; 
	FirFilter_107_s.COEFF[1] = 94.0 ; 
	FirFilter_107_s.COEFF[2] = 127.0 ; 
	FirFilter_107_s.COEFF[3] = 160.0 ; 
	FirFilter_107_s.COEFF[4] = 193.0 ; 
	FirFilter_107_s.COEFF[5] = 226.0 ; 
	FirFilter_107_s.COEFF[6] = 259.0 ; 
	FirFilter_107_s.COEFF[7] = 292.0 ; 
	FirFilter_107_s.COEFF[8] = 325.0 ; 
	FirFilter_107_s.COEFF[9] = 358.0 ; 
	FirFilter_107_s.COEFF[10] = 391.0 ; 
	FirFilter_107_s.COEFF[11] = 424.0 ; 
	FirFilter_107_s.COEFF[12] = 457.0 ; 
	FirFilter_107_s.COEFF[13] = 490.0 ; 
	FirFilter_107_s.COEFF[14] = 523.0 ; 
	FirFilter_107_s.COEFF[15] = 556.0 ; 
	FirFilter_107_s.COEFF[16] = 589.0 ; 
	FirFilter_107_s.COEFF[17] = 622.0 ; 
	FirFilter_107_s.COEFF[18] = 655.0 ; 
	FirFilter_107_s.COEFF[19] = 688.0 ; 
	FirFilter_107_s.COEFF[20] = 721.0 ; 
	FirFilter_107_s.COEFF[21] = 754.0 ; 
	FirFilter_107_s.COEFF[22] = 787.0 ; 
	FirFilter_107_s.COEFF[23] = 820.0 ; 
	FirFilter_107_s.COEFF[24] = 853.0 ; 
	FirFilter_107_s.COEFF[25] = 886.0 ; 
	FirFilter_107_s.COEFF[26] = 919.0 ; 
	FirFilter_107_s.COEFF[27] = 952.0 ; 
	FirFilter_107_s.COEFF[28] = 985.0 ; 
	FirFilter_107_s.COEFF[29] = 1018.0 ; 
	FirFilter_107_s.COEFF[30] = 1051.0 ; 
	FirFilter_107_s.COEFF[31] = 1084.0 ; 
}
//--------------------------------
// --- prework: Delay_N_110
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_110FirFilter_111, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_111
	 {
	FirFilter_111_s.COEFF[0] = 42.0 ; 
	FirFilter_111_s.COEFF[1] = 49.0 ; 
	FirFilter_111_s.COEFF[2] = 56.0 ; 
	FirFilter_111_s.COEFF[3] = 63.0 ; 
	FirFilter_111_s.COEFF[4] = 70.0 ; 
	FirFilter_111_s.COEFF[5] = 77.0 ; 
	FirFilter_111_s.COEFF[6] = 84.0 ; 
	FirFilter_111_s.COEFF[7] = 91.0 ; 
	FirFilter_111_s.COEFF[8] = 98.0 ; 
	FirFilter_111_s.COEFF[9] = 105.0 ; 
	FirFilter_111_s.COEFF[10] = 112.0 ; 
	FirFilter_111_s.COEFF[11] = 119.0 ; 
	FirFilter_111_s.COEFF[12] = 126.0 ; 
	FirFilter_111_s.COEFF[13] = 133.0 ; 
	FirFilter_111_s.COEFF[14] = 140.0 ; 
	FirFilter_111_s.COEFF[15] = 147.0 ; 
	FirFilter_111_s.COEFF[16] = 154.0 ; 
	FirFilter_111_s.COEFF[17] = 161.0 ; 
	FirFilter_111_s.COEFF[18] = 168.0 ; 
	FirFilter_111_s.COEFF[19] = 175.0 ; 
	FirFilter_111_s.COEFF[20] = 182.0 ; 
	FirFilter_111_s.COEFF[21] = 189.0 ; 
	FirFilter_111_s.COEFF[22] = 196.0 ; 
	FirFilter_111_s.COEFF[23] = 203.0 ; 
	FirFilter_111_s.COEFF[24] = 210.0 ; 
	FirFilter_111_s.COEFF[25] = 217.0 ; 
	FirFilter_111_s.COEFF[26] = 224.0 ; 
	FirFilter_111_s.COEFF[27] = 231.0 ; 
	FirFilter_111_s.COEFF[28] = 238.0 ; 
	FirFilter_111_s.COEFF[29] = 245.0 ; 
	FirFilter_111_s.COEFF[30] = 252.0 ; 
	FirFilter_111_s.COEFF[31] = 259.0 ; 
}
//--------------------------------
// --- prework: Delay_N_113
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_113FirFilter_114, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_114
	 {
	FirFilter_114_s.COEFF[0] = 71.0 ; 
	FirFilter_114_s.COEFF[1] = 104.0 ; 
	FirFilter_114_s.COEFF[2] = 137.0 ; 
	FirFilter_114_s.COEFF[3] = 170.0 ; 
	FirFilter_114_s.COEFF[4] = 203.0 ; 
	FirFilter_114_s.COEFF[5] = 236.0 ; 
	FirFilter_114_s.COEFF[6] = 269.0 ; 
	FirFilter_114_s.COEFF[7] = 302.0 ; 
	FirFilter_114_s.COEFF[8] = 335.0 ; 
	FirFilter_114_s.COEFF[9] = 368.0 ; 
	FirFilter_114_s.COEFF[10] = 401.0 ; 
	FirFilter_114_s.COEFF[11] = 434.0 ; 
	FirFilter_114_s.COEFF[12] = 467.0 ; 
	FirFilter_114_s.COEFF[13] = 500.0 ; 
	FirFilter_114_s.COEFF[14] = 533.0 ; 
	FirFilter_114_s.COEFF[15] = 566.0 ; 
	FirFilter_114_s.COEFF[16] = 599.0 ; 
	FirFilter_114_s.COEFF[17] = 632.0 ; 
	FirFilter_114_s.COEFF[18] = 665.0 ; 
	FirFilter_114_s.COEFF[19] = 698.0 ; 
	FirFilter_114_s.COEFF[20] = 731.0 ; 
	FirFilter_114_s.COEFF[21] = 764.0 ; 
	FirFilter_114_s.COEFF[22] = 797.0 ; 
	FirFilter_114_s.COEFF[23] = 830.0 ; 
	FirFilter_114_s.COEFF[24] = 863.0 ; 
	FirFilter_114_s.COEFF[25] = 896.0 ; 
	FirFilter_114_s.COEFF[26] = 929.0 ; 
	FirFilter_114_s.COEFF[27] = 962.0 ; 
	FirFilter_114_s.COEFF[28] = 995.0 ; 
	FirFilter_114_s.COEFF[29] = 1028.0 ; 
	FirFilter_114_s.COEFF[30] = 1061.0 ; 
	FirFilter_114_s.COEFF[31] = 1094.0 ; 
}
//--------------------------------
// --- prework: Delay_N_117
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_117FirFilter_118, 0.0) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: FirFilter_118
	 {
	FirFilter_118_s.COEFF[0] = 56.0 ; 
	FirFilter_118_s.COEFF[1] = 64.0 ; 
	FirFilter_118_s.COEFF[2] = 72.0 ; 
	FirFilter_118_s.COEFF[3] = 80.0 ; 
	FirFilter_118_s.COEFF[4] = 88.0 ; 
	FirFilter_118_s.COEFF[5] = 96.0 ; 
	FirFilter_118_s.COEFF[6] = 104.0 ; 
	FirFilter_118_s.COEFF[7] = 112.0 ; 
	FirFilter_118_s.COEFF[8] = 120.0 ; 
	FirFilter_118_s.COEFF[9] = 128.0 ; 
	FirFilter_118_s.COEFF[10] = 136.0 ; 
	FirFilter_118_s.COEFF[11] = 144.0 ; 
	FirFilter_118_s.COEFF[12] = 152.0 ; 
	FirFilter_118_s.COEFF[13] = 160.0 ; 
	FirFilter_118_s.COEFF[14] = 168.0 ; 
	FirFilter_118_s.COEFF[15] = 176.0 ; 
	FirFilter_118_s.COEFF[16] = 184.0 ; 
	FirFilter_118_s.COEFF[17] = 192.0 ; 
	FirFilter_118_s.COEFF[18] = 200.0 ; 
	FirFilter_118_s.COEFF[19] = 208.0 ; 
	FirFilter_118_s.COEFF[20] = 216.0 ; 
	FirFilter_118_s.COEFF[21] = 224.0 ; 
	FirFilter_118_s.COEFF[22] = 232.0 ; 
	FirFilter_118_s.COEFF[23] = 240.0 ; 
	FirFilter_118_s.COEFF[24] = 248.0 ; 
	FirFilter_118_s.COEFF[25] = 256.0 ; 
	FirFilter_118_s.COEFF[26] = 264.0 ; 
	FirFilter_118_s.COEFF[27] = 272.0 ; 
	FirFilter_118_s.COEFF[28] = 280.0 ; 
	FirFilter_118_s.COEFF[29] = 288.0 ; 
	FirFilter_118_s.COEFF[30] = 296.0 ; 
	FirFilter_118_s.COEFF[31] = 304.0 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();
	unsigned long freq = SimGetOwnFreqMHz();
	printf("Current Freq = %lu MHz\n", freq);

	freq = 1000;
	printf("Setting frequency to %lu MHz\n", freq);
	SimSetOwnFreqMHz(freq);
	freq = SimGetOwnFreqMHz();
	printf("Current Freq = %lu MHz\n", freq);
	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		source_61();
		DUPLICATE_Splitter_121();
			Delay_N_64();
			FirFilter_65();
			DownSamp_66();
			UpSamp_67();
			Delay_N_68();
			FirFilter_69();
			Delay_N_71();
			FirFilter_72();
			DownSamp_73();
			UpSamp_74();
			Delay_N_75();
			FirFilter_76();
			Delay_N_78();
			FirFilter_79();
			DownSamp_80();
			UpSamp_81();
			Delay_N_82();
			FirFilter_83();
			Delay_N_85();
			FirFilter_86();
			DownSamp_87();
			UpSamp_88();
			Delay_N_89();
			FirFilter_90();
			Delay_N_92();
			FirFilter_93();
			DownSamp_94();
			UpSamp_95();
			Delay_N_96();
			FirFilter_97();
			Delay_N_99();
			FirFilter_100();
			DownSamp_101();
			UpSamp_102();
			Delay_N_103();
			FirFilter_104();
			Delay_N_106();
			FirFilter_107();
			DownSamp_108();
			UpSamp_109();
			Delay_N_110();
			FirFilter_111();
			Delay_N_113();
			FirFilter_114();
			DownSamp_115();
			UpSamp_116();
			Delay_N_117();
			FirFilter_118();
		WEIGHTED_ROUND_ROBIN_Joiner_122();
		Combine_119();
		sink_120();
	ENDFOR
	return EXIT_SUCCESS;
}
