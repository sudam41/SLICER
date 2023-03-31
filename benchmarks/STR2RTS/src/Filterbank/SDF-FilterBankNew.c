#include "SDF-FilterBankNew.h"

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

void source(buffer_float_t *chanout) {
		push_float(&(*chanout), source_61_s.current) ; 
		if((source_61_s.current > 1000.0)) {
			source_61_s.current = 0.0 ; 
		}
		else {
			source_61_s.current = (source_61_s.current + 1.0) ; 
		}
	}


void source_61() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		source(&(source_61DUPLICATE_Splitter_121));
	ENDFOR
}

void Delay_N(buffer_float_t *chanin, buffer_float_t *chanout) {
	}


void Delay_N_64() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[0]), &(Delay_N_64FirFilter_65));
	ENDFOR
}

void FirFilter(buffer_float_t *chanin, buffer_float_t *chanout) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 32, i++) {
			sum = (sum + (peek_float(&(*chanin), i) * FirFilter_65_s.COEFF[(31 - i)])) ; 
		}
		ENDFOR
		pop_float(&(*chanin)) ; 
		push_float(&(*chanout), sum) ; 
	}


void FirFilter_65() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_64FirFilter_65), &(FirFilter_65DownSamp_66));
	ENDFOR
}

void DownSamp(buffer_float_t *chanin, buffer_float_t *chanout) {
	push_float(&(*chanout), pop_float(&(*chanin))) ; 
	FOR(int, i, 0,  < , 7, i++) {
		pop_float(&(*chanin)) ; 
	}
	ENDFOR
}


void DownSamp_66() {
	DownSamp(&(FirFilter_65DownSamp_66), &(DownSamp_66UpSamp_67));
}

void UpSamp(buffer_float_t *chanin, buffer_float_t *chanout) {
	push_float(&(*chanout), pop_float(&(*chanin))) ; 
	FOR(int, i, 0,  < , 7, i++) {
		push_float(&(*chanout), 0.0) ; 
	}
	ENDFOR
}


void UpSamp_67() {
	UpSamp(&(DownSamp_66UpSamp_67), &(UpSamp_67Delay_N_68));
}

void Delay_N_68() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_67Delay_N_68), &(Delay_N_68FirFilter_69));
	ENDFOR
}

void FirFilter_69() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_68FirFilter_69), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[0]));
	ENDFOR
}

void Delay_N_71() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[1]), &(Delay_N_71FirFilter_72));
	ENDFOR
}

void FirFilter_72() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_71FirFilter_72), &(FirFilter_72DownSamp_73));
	ENDFOR
}

void DownSamp_73() {
	DownSamp(&(FirFilter_72DownSamp_73), &(DownSamp_73UpSamp_74));
}

void UpSamp_74() {
	UpSamp(&(DownSamp_73UpSamp_74), &(UpSamp_74Delay_N_75));
}

void Delay_N_75() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_74Delay_N_75), &(Delay_N_75FirFilter_76));
	ENDFOR
}

void FirFilter_76() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_75FirFilter_76), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[1]));
	ENDFOR
}

void Delay_N_78() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[2]), &(Delay_N_78FirFilter_79));
	ENDFOR
}

void FirFilter_79() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_78FirFilter_79), &(FirFilter_79DownSamp_80));
	ENDFOR
}

void DownSamp_80() {
	DownSamp(&(FirFilter_79DownSamp_80), &(DownSamp_80UpSamp_81));
}

void UpSamp_81() {
	UpSamp(&(DownSamp_80UpSamp_81), &(UpSamp_81Delay_N_82));
}

void Delay_N_82() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_81Delay_N_82), &(Delay_N_82FirFilter_83));
	ENDFOR
}

void FirFilter_83() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_82FirFilter_83), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[2]));
	ENDFOR
}

void Delay_N_85() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[3]), &(Delay_N_85FirFilter_86));
	ENDFOR
}

void FirFilter_86() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_85FirFilter_86), &(FirFilter_86DownSamp_87));
	ENDFOR
}

void DownSamp_87() {
	DownSamp(&(FirFilter_86DownSamp_87), &(DownSamp_87UpSamp_88));
}

void UpSamp_88() {
	UpSamp(&(DownSamp_87UpSamp_88), &(UpSamp_88Delay_N_89));
}

void Delay_N_89() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_88Delay_N_89), &(Delay_N_89FirFilter_90));
	ENDFOR
}

void FirFilter_90() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_89FirFilter_90), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[3]));
	ENDFOR
}

void Delay_N_92() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[4]), &(Delay_N_92FirFilter_93));
	ENDFOR
}

void FirFilter_93() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_92FirFilter_93), &(FirFilter_93DownSamp_94));
	ENDFOR
}

void DownSamp_94() {
	DownSamp(&(FirFilter_93DownSamp_94), &(DownSamp_94UpSamp_95));
}

void UpSamp_95() {
	UpSamp(&(DownSamp_94UpSamp_95), &(UpSamp_95Delay_N_96));
}

void Delay_N_96() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_95Delay_N_96), &(Delay_N_96FirFilter_97));
	ENDFOR
}

void FirFilter_97() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_96FirFilter_97), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[4]));
	ENDFOR
}

void Delay_N_99() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[5]), &(Delay_N_99FirFilter_100));
	ENDFOR
}

void FirFilter_100() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_99FirFilter_100), &(FirFilter_100DownSamp_101));
	ENDFOR
}

void DownSamp_101() {
	DownSamp(&(FirFilter_100DownSamp_101), &(DownSamp_101UpSamp_102));
}

void UpSamp_102() {
	UpSamp(&(DownSamp_101UpSamp_102), &(UpSamp_102Delay_N_103));
}

void Delay_N_103() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_102Delay_N_103), &(Delay_N_103FirFilter_104));
	ENDFOR
}

void FirFilter_104() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_103FirFilter_104), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[5]));
	ENDFOR
}

void Delay_N_106() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[6]), &(Delay_N_106FirFilter_107));
	ENDFOR
}

void FirFilter_107() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_106FirFilter_107), &(FirFilter_107DownSamp_108));
	ENDFOR
}

void DownSamp_108() {
	DownSamp(&(FirFilter_107DownSamp_108), &(DownSamp_108UpSamp_109));
}

void UpSamp_109() {
	UpSamp(&(DownSamp_108UpSamp_109), &(UpSamp_109Delay_N_110));
}

void Delay_N_110() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_109Delay_N_110), &(Delay_N_110FirFilter_111));
	ENDFOR
}

void FirFilter_111() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_110FirFilter_111), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[6]));
	ENDFOR
}

void Delay_N_113() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_split[7]), &(Delay_N_113FirFilter_114));
	ENDFOR
}

void FirFilter_114() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_113FirFilter_114), &(FirFilter_114DownSamp_115));
	ENDFOR
}

void DownSamp_115() {
	DownSamp(&(FirFilter_114DownSamp_115), &(DownSamp_115UpSamp_116));
}

void UpSamp_116() {
	UpSamp(&(DownSamp_115UpSamp_116), &(UpSamp_116Delay_N_117));
}

void Delay_N_117() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Delay_N(&(UpSamp_116Delay_N_117), &(Delay_N_117FirFilter_118));
	ENDFOR
}

void FirFilter_118() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FirFilter(&(Delay_N_117FirFilter_118), &(SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[7]));
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
{
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		FOR(uint32_t, __iter_, 0, <, 8, __iter_++)
			push_float(&WEIGHTED_ROUND_ROBIN_Joiner_122Combine_119, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_Branches_59_123_132_142_join[__iter_]));
		ENDFOR
	ENDFOR
}}

void Combine(buffer_float_t *chanin, buffer_float_t *chanout) {
		float sum = 0.0;
		FOR(int, i, 0,  < , 8, i++) {
			sum = (sum + pop_float(&(*chanin))) ; 
		}
		ENDFOR
		push_float(&(*chanout), sum) ; 
	}


void Combine_119() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		Combine(&(WEIGHTED_ROUND_ROBIN_Joiner_122Combine_119), &(Combine_119sink_120));
	ENDFOR
}

void sink(buffer_float_t *chanin) {
		printf("%.10f", pop_float(&(*chanin)));
		printf("\n");
	}


void sink_120() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		sink(&(Combine_119sink_120));
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
// --- prework: Delay_N_71
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_71FirFilter_72, 0.0) ; 
	}
	ENDFOR
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
// --- prework: Delay_N_78
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_78FirFilter_79, 0.0) ; 
	}
	ENDFOR
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
// --- prework: Delay_N_85
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_85FirFilter_86, 0.0) ; 
	}
	ENDFOR
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
// --- prework: Delay_N_92
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_92FirFilter_93, 0.0) ; 
	}
	ENDFOR
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
// --- prework: Delay_N_99
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_99FirFilter_100, 0.0) ; 
	}
	ENDFOR
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
// --- prework: Delay_N_106
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_106FirFilter_107, 0.0) ; 
	}
	ENDFOR
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
// --- prework: Delay_N_113
	 {
	FOR(int, i, 0,  < , 31, i++) {
		push_float(&Delay_N_113FirFilter_114, 0.0) ; 
	}
	ENDFOR
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
