#include "HSDF-iDCTcompare_nocache.h"

buffer_int_t AnonFilter_a0_371DUPLICATE_Splitter_446;
buffer_int_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[3];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_531WEIGHTED_ROUND_ROBIN_Splitter_540;
buffer_float_t SplitJoin9_AnonFilter_a4_Fiss_620_627_split[64];
buffer_int_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[3];
buffer_int_t SplitJoin9_AnonFilter_a4_Fiss_620_627_join[64];
buffer_float_t SplitJoin3_AnonFilter_a3_Fiss_617_624_join[64];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_521Post_CollapsedDataParallel_2_445;
buffer_int_t SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[8];
buffer_float_t Pre_CollapsedDataParallel_1_444WEIGHTED_ROUND_ROBIN_Splitter_520;
buffer_float_t Post_CollapsedDataParallel_2_445WEIGHTED_ROUND_ROBIN_Splitter_530;
buffer_float_t SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[8];
buffer_float_t SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[8];
buffer_int_t SplitJoin3_AnonFilter_a3_Fiss_617_624_split[64];
buffer_int_t WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_455Pre_CollapsedDataParallel_1_444;
buffer_float_t SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[8];
buffer_float_t SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[8];
buffer_int_t SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[8];
buffer_int_t WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399;


iDCT_2D_reference_coarse_374_t iDCT_2D_reference_coarse_374_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_522_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_523_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_524_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_525_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_526_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_527_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_528_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_529_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_532_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_533_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_534_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_535_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_536_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_537_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_538_s;
iDCT_2D_reference_coarse_374_t iDCT_1D_reference_fine_539_s;
iDCT8x8_1D_col_fast_398_t iDCT8x8_1D_col_fast_398_s;
AnonFilter_a2_399_t AnonFilter_a2_399_s;

void AnonFilter_a0_371() {
	FOR(int, i, 0,  < , 64, i++) {
		push_int(&AnonFilter_a0_371DUPLICATE_Splitter_446, (((int) pow(3.0, i)) % 75)) ; 
	}
	ENDFOR
}


void iDCT_2D_reference_coarse_374() {
	float block_x[8][8];
	FOR(int, i, 0,  < , 8, i++) {
		FOR(int, j, 0,  < , 8, j++) {
			block_x[i][j] = 0.0 ; 
			FOR(int, k, 0,  < , 8, k++) {
				block_x[i][j] = (block_x[i][j] + (iDCT_2D_reference_coarse_374_s.coeff[k][j] * peek_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[0], ((8 * i) + k)))) ; 
			}
			ENDFOR
		}
		ENDFOR
	}
	ENDFOR
	FOR(int, i, 0,  < , 8, i++) {
		FOR(int, j, 0,  < , 8, j++) {
			float block_y = 0.0;
			FOR(int, k, 0,  < , 8, k++) {
				block_y = (block_y + (iDCT_2D_reference_coarse_374_s.coeff[k][i] * block_x[k][j])) ; 
			}
			ENDFOR
			block_y = ((float) floor((block_y + 0.5))) ; 
			push_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[0], ((int) block_y)) ; 
		}
		ENDFOR
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[0]) ; 
	}
	ENDFOR
}


void AnonFilter_a3_456() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[0], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[0])) ; 
}


void AnonFilter_a3_457() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[1], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[1])) ; 
}


void AnonFilter_a3_458() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[2], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[2])) ; 
}


void AnonFilter_a3_459() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[3], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[3])) ; 
}


void AnonFilter_a3_460() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[4], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[4])) ; 
}


void AnonFilter_a3_461() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[5], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[5])) ; 
}


void AnonFilter_a3_462() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[6], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[6])) ; 
}


void AnonFilter_a3_463() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[7], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[7])) ; 
}


void AnonFilter_a3_464() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[8], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[8])) ; 
}


void AnonFilter_a3_465() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[9], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[9])) ; 
}


void AnonFilter_a3_466() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[10], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[10])) ; 
}


void AnonFilter_a3_467() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[11], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[11])) ; 
}


void AnonFilter_a3_468() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[12], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[12])) ; 
}


void AnonFilter_a3_469() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[13], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[13])) ; 
}


void AnonFilter_a3_470() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[14], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[14])) ; 
}


void AnonFilter_a3_471() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[15], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[15])) ; 
}


void AnonFilter_a3_472() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[16], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[16])) ; 
}


void AnonFilter_a3_473() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[17], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[17])) ; 
}


void AnonFilter_a3_474() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[18], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[18])) ; 
}


void AnonFilter_a3_475() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[19], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[19])) ; 
}


void AnonFilter_a3_476() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[20], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[20])) ; 
}


void AnonFilter_a3_477() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[21], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[21])) ; 
}


void AnonFilter_a3_478() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[22], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[22])) ; 
}


void AnonFilter_a3_479() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[23], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[23])) ; 
}


void AnonFilter_a3_480() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[24], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[24])) ; 
}


void AnonFilter_a3_481() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[25], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[25])) ; 
}


void AnonFilter_a3_482() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[26], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[26])) ; 
}


void AnonFilter_a3_483() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[27], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[27])) ; 
}


void AnonFilter_a3_484() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[28], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[28])) ; 
}


void AnonFilter_a3_485() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[29], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[29])) ; 
}


void AnonFilter_a3_486() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[30], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[30])) ; 
}


void AnonFilter_a3_487() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[31], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[31])) ; 
}


void AnonFilter_a3_488() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[32], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[32])) ; 
}


void AnonFilter_a3_489() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[33], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[33])) ; 
}


void AnonFilter_a3_490() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[34], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[34])) ; 
}


void AnonFilter_a3_491() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[35], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[35])) ; 
}


void AnonFilter_a3_492() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[36], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[36])) ; 
}


void AnonFilter_a3_493() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[37], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[37])) ; 
}


void AnonFilter_a3_494() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[38], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[38])) ; 
}


void AnonFilter_a3_495() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[39], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[39])) ; 
}


void AnonFilter_a3_496() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[40], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[40])) ; 
}


void AnonFilter_a3_497() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[41], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[41])) ; 
}


void AnonFilter_a3_498() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[42], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[42])) ; 
}


void AnonFilter_a3_499() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[43], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[43])) ; 
}


void AnonFilter_a3_500() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[44], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[44])) ; 
}


void AnonFilter_a3_501() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[45], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[45])) ; 
}


void AnonFilter_a3_502() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[46], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[46])) ; 
}


void AnonFilter_a3_503() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[47], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[47])) ; 
}


void AnonFilter_a3_504() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[48], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[48])) ; 
}


void AnonFilter_a3_505() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[49], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[49])) ; 
}


void AnonFilter_a3_506() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[50], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[50])) ; 
}


void AnonFilter_a3_507() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[51], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[51])) ; 
}


void AnonFilter_a3_508() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[52], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[52])) ; 
}


void AnonFilter_a3_509() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[53], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[53])) ; 
}


void AnonFilter_a3_510() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[54], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[54])) ; 
}


void AnonFilter_a3_511() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[55], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[55])) ; 
}


void AnonFilter_a3_512() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[56], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[56])) ; 
}


void AnonFilter_a3_513() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[57], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[57])) ; 
}


void AnonFilter_a3_514() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[58], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[58])) ; 
}


void AnonFilter_a3_515() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[59], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[59])) ; 
}


void AnonFilter_a3_516() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[60], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[60])) ; 
}


void AnonFilter_a3_517() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[61], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[61])) ; 
}


void AnonFilter_a3_518() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[62], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[62])) ; 
}


void AnonFilter_a3_519() {
	push_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[63], pop_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[63])) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_454() {
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[__iter_], pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[1]));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_455() {
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_455Pre_CollapsedDataParallel_1_444, pop_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[__iter_]));
	ENDFOR
}

void Pre_CollapsedDataParallel_1_444() {
 {
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = 0;
		iTimesSumOfWeights_Plus_PartialSum_k = 0 ; 
		iTimesSumOfWeights_Plus_PartialSum_k = _k ; 
 {
		FOR(int, _i, 0,  < , 8, _i++) {
			push_float(&Pre_CollapsedDataParallel_1_444WEIGHTED_ROUND_ROBIN_Splitter_520, peek_float(&WEIGHTED_ROUND_ROBIN_Joiner_455Pre_CollapsedDataParallel_1_444, (iTimesSumOfWeights_Plus_PartialSum_k + 0))) ; 
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 8) ; 
		}
		ENDFOR
	}
	}
	ENDFOR
}
}
	pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_455Pre_CollapsedDataParallel_1_444) ; 
}


void iDCT_1D_reference_fine_522() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_522_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[0], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[0], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[0]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_523() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_523_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[1], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[1], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[1]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_524() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_524_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[2], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[2], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[2]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_525() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_525_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[3], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[3], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[3]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_526() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_526_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[4], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[4], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[4]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_527() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_527_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[5], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[5], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[5]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_528() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_528_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[6], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[6], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[6]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_529() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_529_s.coeff[x][u] * peek_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[7], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[7], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[7]) ; 
	}
	ENDFOR
}


void WEIGHTED_ROUND_ROBIN_Splitter_520() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[__iter_dec_], pop_float(&Pre_CollapsedDataParallel_1_444WEIGHTED_ROUND_ROBIN_Splitter_520));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_521() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&WEIGHTED_ROUND_ROBIN_Joiner_521Post_CollapsedDataParallel_2_445, pop_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void Post_CollapsedDataParallel_2_445() {
 {
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int partialSum_i = 0;
		partialSum_i = 0 ; 
		partialSum_i = 0 ; 
 {
		FOR(int, _i, 0,  < , 8, _i++) {
			push_float(&Post_CollapsedDataParallel_2_445WEIGHTED_ROUND_ROBIN_Splitter_530, peek_float(&WEIGHTED_ROUND_ROBIN_Joiner_521Post_CollapsedDataParallel_2_445, (_k + (partialSum_i + 0)))) ; 
			partialSum_i = (partialSum_i + 8) ; 
		}
		ENDFOR
	}
	}
	ENDFOR
}
}
	pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_521Post_CollapsedDataParallel_2_445) ; 
}


void iDCT_1D_reference_fine_532() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_532_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[0], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[0], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[0]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_533() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_533_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[1], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[1], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[1]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_534() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_534_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[2], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[2], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[2]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_535() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_535_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[3], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[3], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[3]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_536() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_536_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[4], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[4], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[4]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_537() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_537_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[5], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[5], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[5]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_538() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_538_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[6], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[6], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[6]) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_539() {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		tempsum = 0.0 ; 
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_539_s.coeff[x][u] * peek_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[7], u))) ; 
		}
		ENDFOR
		push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[7], tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[7]) ; 
	}
	ENDFOR
}


void WEIGHTED_ROUND_ROBIN_Splitter_530() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[__iter_dec_], pop_float(&Post_CollapsedDataParallel_2_445WEIGHTED_ROUND_ROBIN_Splitter_530));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_531() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&WEIGHTED_ROUND_ROBIN_Joiner_531WEIGHTED_ROUND_ROBIN_Splitter_540, pop_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void AnonFilter_a4_542() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[0], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[0]) + 0.5)))) ; 
}


void AnonFilter_a4_543() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[1], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[1]) + 0.5)))) ; 
}


void AnonFilter_a4_544() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[2], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[2]) + 0.5)))) ; 
}


void AnonFilter_a4_545() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[3], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[3]) + 0.5)))) ; 
}


void AnonFilter_a4_546() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[4], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[4]) + 0.5)))) ; 
}


void AnonFilter_a4_547() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[5], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[5]) + 0.5)))) ; 
}


void AnonFilter_a4_548() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[6], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[6]) + 0.5)))) ; 
}


void AnonFilter_a4_549() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[7], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[7]) + 0.5)))) ; 
}


void AnonFilter_a4_550() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[8], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[8]) + 0.5)))) ; 
}


void AnonFilter_a4_551() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[9], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[9]) + 0.5)))) ; 
}


void AnonFilter_a4_552() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[10], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[10]) + 0.5)))) ; 
}


void AnonFilter_a4_553() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[11], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[11]) + 0.5)))) ; 
}


void AnonFilter_a4_554() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[12], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[12]) + 0.5)))) ; 
}


void AnonFilter_a4_555() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[13], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[13]) + 0.5)))) ; 
}


void AnonFilter_a4_556() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[14], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[14]) + 0.5)))) ; 
}


void AnonFilter_a4_557() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[15], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[15]) + 0.5)))) ; 
}


void AnonFilter_a4_558() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[16], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[16]) + 0.5)))) ; 
}


void AnonFilter_a4_559() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[17], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[17]) + 0.5)))) ; 
}


void AnonFilter_a4_560() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[18], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[18]) + 0.5)))) ; 
}


void AnonFilter_a4_561() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[19], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[19]) + 0.5)))) ; 
}


void AnonFilter_a4_562() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[20], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[20]) + 0.5)))) ; 
}


void AnonFilter_a4_563() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[21], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[21]) + 0.5)))) ; 
}


void AnonFilter_a4_564() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[22], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[22]) + 0.5)))) ; 
}


void AnonFilter_a4_565() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[23], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[23]) + 0.5)))) ; 
}


void AnonFilter_a4_566() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[24], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[24]) + 0.5)))) ; 
}


void AnonFilter_a4_567() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[25], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[25]) + 0.5)))) ; 
}


void AnonFilter_a4_568() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[26], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[26]) + 0.5)))) ; 
}


void AnonFilter_a4_569() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[27], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[27]) + 0.5)))) ; 
}


void AnonFilter_a4_570() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[28], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[28]) + 0.5)))) ; 
}


void AnonFilter_a4_571() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[29], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[29]) + 0.5)))) ; 
}


void AnonFilter_a4_572() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[30], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[30]) + 0.5)))) ; 
}


void AnonFilter_a4_573() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[31], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[31]) + 0.5)))) ; 
}


void AnonFilter_a4_574() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[32], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[32]) + 0.5)))) ; 
}


void AnonFilter_a4_575() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[33], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[33]) + 0.5)))) ; 
}


void AnonFilter_a4_576() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[34], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[34]) + 0.5)))) ; 
}


void AnonFilter_a4_577() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[35], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[35]) + 0.5)))) ; 
}


void AnonFilter_a4_578() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[36], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[36]) + 0.5)))) ; 
}


void AnonFilter_a4_579() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[37], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[37]) + 0.5)))) ; 
}


void AnonFilter_a4_580() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[38], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[38]) + 0.5)))) ; 
}


void AnonFilter_a4_581() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[39], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[39]) + 0.5)))) ; 
}


void AnonFilter_a4_582() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[40], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[40]) + 0.5)))) ; 
}


void AnonFilter_a4_583() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[41], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[41]) + 0.5)))) ; 
}


void AnonFilter_a4_584() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[42], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[42]) + 0.5)))) ; 
}


void AnonFilter_a4_585() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[43], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[43]) + 0.5)))) ; 
}


void AnonFilter_a4_586() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[44], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[44]) + 0.5)))) ; 
}


void AnonFilter_a4_587() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[45], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[45]) + 0.5)))) ; 
}


void AnonFilter_a4_588() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[46], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[46]) + 0.5)))) ; 
}


void AnonFilter_a4_589() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[47], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[47]) + 0.5)))) ; 
}


void AnonFilter_a4_590() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[48], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[48]) + 0.5)))) ; 
}


void AnonFilter_a4_591() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[49], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[49]) + 0.5)))) ; 
}


void AnonFilter_a4_592() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[50], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[50]) + 0.5)))) ; 
}


void AnonFilter_a4_593() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[51], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[51]) + 0.5)))) ; 
}


void AnonFilter_a4_594() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[52], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[52]) + 0.5)))) ; 
}


void AnonFilter_a4_595() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[53], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[53]) + 0.5)))) ; 
}


void AnonFilter_a4_596() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[54], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[54]) + 0.5)))) ; 
}


void AnonFilter_a4_597() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[55], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[55]) + 0.5)))) ; 
}


void AnonFilter_a4_598() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[56], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[56]) + 0.5)))) ; 
}


void AnonFilter_a4_599() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[57], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[57]) + 0.5)))) ; 
}


void AnonFilter_a4_600() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[58], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[58]) + 0.5)))) ; 
}


void AnonFilter_a4_601() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[59], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[59]) + 0.5)))) ; 
}


void AnonFilter_a4_602() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[60], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[60]) + 0.5)))) ; 
}


void AnonFilter_a4_603() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[61], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[61]) + 0.5)))) ; 
}


void AnonFilter_a4_604() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[62], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[62]) + 0.5)))) ; 
}


void AnonFilter_a4_605() {
	push_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[63], ((int) floor((pop_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[63]) + 0.5)))) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_540() {
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[__iter_], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_531WEIGHTED_ROUND_ROBIN_Splitter_540));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_541() {
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[1], pop_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[__iter_]));
	ENDFOR
}

void iDCT8x8_1D_row_fast_608() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_609() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_610() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_611() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_612() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_613() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_614() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_615() {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 0) ; 
	x1 = (peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 4) << 11) ; 
	x2 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 6) ; 
	x3 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 2) ; 
	x4 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 1) ; 
	x5 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 7) ; 
	x6 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 5) ; 
	x7 = peek_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7], 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], x0) ; 
		}
		ENDFOR
	}
	else {
		x0 = ((x0 << 11) + 128) ; 
		x8 = (565 * (x4 + x5)) ; 
		x4 = (x8 + (2276 * x4)) ; 
		x5 = (x8 - (3406 * x5)) ; 
		x8 = (2408 * (x6 + x7)) ; 
		x6 = (x8 - (799 * x6)) ; 
		x7 = (x8 - (4017 * x7)) ; 
		x8 = (x0 + x1) ; 
		x0 = (x0 - x1) ; 
		x1 = (1108 * (x3 + x2)) ; 
		x2 = (x1 - (3784 * x2)) ; 
		x3 = (x1 + (1568 * x3)) ; 
		x1 = (x4 + x6) ; 
		x4 = (x4 - x6) ; 
		x6 = (x5 + x7) ; 
		x5 = (x5 - x7) ; 
		x7 = (x8 + x3) ; 
		x8 = (x8 - x3) ; 
		x3 = (x0 + x2) ; 
		x0 = (x0 - x2) ; 
		x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
		x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x7 + x1) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x3 + x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x0 + x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x8 + x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x8 - x6) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x0 - x4) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x3 - x2) >> 8)) ; 
		push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7], ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7]) ; 
	}
	ENDFOR
}


void WEIGHTED_ROUND_ROBIN_Splitter_606() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[__iter_dec_], pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[2]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_607() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, pop_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void iDCT8x8_1D_col_fast_398() {
	FOR(int, c, 0,  < , 8, c++) {
		int x0 = 0;
		int x1 = 0;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int x6 = 0;
		int x7 = 0;
		int x8 = 0;
		x0 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 0)) ; 
		x1 = (peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 32)) << 8) ; 
		x2 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 48)) ; 
		x3 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 16)) ; 
		x4 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 8)) ; 
		x5 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 56)) ; 
		x6 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 40)) ; 
		x7 = peek_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398, (c + 24)) ; 
		if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
			x0 = ((x0 + 32) >> 6) ; 
			FOR(int, i, 0,  < , 8, i++) {
				iDCT8x8_1D_col_fast_398_s.buffer[(c + (8 * i))] = x0 ; 
			}
			ENDFOR
		}
		else {
			x0 = ((x0 << 8) + 8192) ; 
			x8 = ((565 * (x4 + x5)) + 4) ; 
			x4 = ((x8 + (2276 * x4)) >> 3) ; 
			x5 = ((x8 - (3406 * x5)) >> 3) ; 
			x8 = ((2408 * (x6 + x7)) + 4) ; 
			x6 = ((x8 - (799 * x6)) >> 3) ; 
			x7 = ((x8 - (4017 * x7)) >> 3) ; 
			x8 = (x0 + x1) ; 
			x0 = (x0 - x1) ; 
			x1 = ((1108 * (x3 + x2)) + 4) ; 
			x2 = ((x1 - (3784 * x2)) >> 3) ; 
			x3 = ((x1 + (1568 * x3)) >> 3) ; 
			x1 = (x4 + x6) ; 
			x4 = (x4 - x6) ; 
			x6 = (x5 + x7) ; 
			x5 = (x5 - x7) ; 
			x7 = (x8 + x3) ; 
			x8 = (x8 - x3) ; 
			x3 = (x0 + x2) ; 
			x0 = (x0 - x2) ; 
			x2 = (((181 * (x4 + x5)) + 128) >> 8) ; 
			x4 = (((181 * (x4 - x5)) + 128) >> 8) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 0)] = ((x7 + x1) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 8)] = ((x3 + x2) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 16)] = ((x0 + x4) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 24)] = ((x8 + x6) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 32)] = ((x8 - x6) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 40)] = ((x0 - x4) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 48)] = ((x3 - x2) >> 14) ; 
			iDCT8x8_1D_col_fast_398_s.buffer[(c + 56)] = ((x7 - x1) >> 14) ; 
		}
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398) ; 
		push_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[2], iDCT8x8_1D_col_fast_398_s.buffer[i]) ; 
	}
	ENDFOR
}


void DUPLICATE_Splitter_446() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		int __token_ = pop_int(&AnonFilter_a0_371DUPLICATE_Splitter_446);
		FOR(uint32_t, __iter_dup_, 0, <, 3, __iter_dup_++)
			push_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_447() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		FOR(uint32_t, __iter_, 0, <, 3, __iter_++)
			push_int(&WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399, pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[__iter_]));
		ENDFOR
	ENDFOR
}}

void AnonFilter_a2_399(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		int refcoarse = 0;
		int reffine = 0;
		int fastfine = 0;
		refcoarse = pop_int(&WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399) ; 
		reffine = pop_int(&WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399) ; 
		fastfine = pop_int(&WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399) ; 
		AnonFilter_a2_399_s.count = (AnonFilter_a2_399_s.count + 1.0) ; 
		if(refcoarse != reffine) {
			float errorRate = 0.0;
			printf("%s", "Error - Discrepancy between reference iDCT coarse and fine");
			printf("\n");
			printf("%s", "        coarse iDCT gives ");
			printf("%d", refcoarse);
			printf("%s", " and fine iDCT gives ");
			printf("%d", reffine);
			printf("\n");
			AnonFilter_a2_399_s.errors = (AnonFilter_a2_399_s.errors + 1.0) ; 
			errorRate = (AnonFilter_a2_399_s.errors / AnonFilter_a2_399_s.count) ; 
			printf("%s", "        Error Rate is ");
			printf("%.10f", errorRate);
			printf("\n");
		}
		if(fastfine != reffine) {
			float errorRate = 0.0;
			printf("%s", "Error - Discrepancy between reference iDCT and fast iDCT");
			printf("\n");
			printf("%s", "        reference iDCT gives ");
			printf("%d", reffine);
			printf("%s", " and fast iDCT gives ");
			printf("%d", fastfine);
			printf("\n");
			AnonFilter_a2_399_s.errors = (AnonFilter_a2_399_s.errors + 1.0) ; 
			errorRate = (AnonFilter_a2_399_s.errors / AnonFilter_a2_399_s.count) ; 
			printf("%s", "        Error Rate is ");
			printf("%.10f", errorRate);
			printf("\n");
		}
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_int(&AnonFilter_a0_371DUPLICATE_Splitter_446);
	FOR(int, __iter_init_0_, 0, <, 3, __iter_init_0_++)
		init_buffer_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_531WEIGHTED_ROUND_ROBIN_Splitter_540);
	FOR(int, __iter_init_1_, 0, <, 64, __iter_init_1_++)
		init_buffer_float(&SplitJoin9_AnonFilter_a4_Fiss_620_627_split[__iter_init_1_]);
	ENDFOR
	FOR(int, __iter_init_2_, 0, <, 3, __iter_init_2_++)
		init_buffer_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[__iter_init_2_]);
	ENDFOR
	FOR(int, __iter_init_3_, 0, <, 64, __iter_init_3_++)
		init_buffer_int(&SplitJoin9_AnonFilter_a4_Fiss_620_627_join[__iter_init_3_]);
	ENDFOR
	FOR(int, __iter_init_4_, 0, <, 64, __iter_init_4_++)
		init_buffer_float(&SplitJoin3_AnonFilter_a3_Fiss_617_624_join[__iter_init_4_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_521Post_CollapsedDataParallel_2_445);
	FOR(int, __iter_init_5_, 0, <, 8, __iter_init_5_++)
		init_buffer_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[__iter_init_5_]);
	ENDFOR
	init_buffer_float(&Pre_CollapsedDataParallel_1_444WEIGHTED_ROUND_ROBIN_Splitter_520);
	init_buffer_float(&Post_CollapsedDataParallel_2_445WEIGHTED_ROUND_ROBIN_Splitter_530);
	FOR(int, __iter_init_6_, 0, <, 8, __iter_init_6_++)
		init_buffer_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[__iter_init_6_]);
	ENDFOR
	FOR(int, __iter_init_7_, 0, <, 8, __iter_init_7_++)
		init_buffer_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[__iter_init_7_]);
	ENDFOR
	FOR(int, __iter_init_8_, 0, <, 64, __iter_init_8_++)
		init_buffer_int(&SplitJoin3_AnonFilter_a3_Fiss_617_624_split[__iter_init_8_]);
	ENDFOR
	init_buffer_int(&WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_455Pre_CollapsedDataParallel_1_444);
	FOR(int, __iter_init_9_, 0, <, 8, __iter_init_9_++)
		init_buffer_float(&SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[__iter_init_9_]);
	ENDFOR
	FOR(int, __iter_init_10_, 0, <, 8, __iter_init_10_++)
		init_buffer_float(&SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[__iter_init_10_]);
	ENDFOR
	FOR(int, __iter_init_11_, 0, <, 8, __iter_init_11_++)
		init_buffer_int(&SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[__iter_init_11_]);
	ENDFOR
	init_buffer_int(&WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399);
// --- init: iDCT_2D_reference_coarse_374
	 {
	FOR(int, freq, 0,  < , 8, freq++) {
		float scale = 0.0;
		scale = freq == 0 ? (0.35355338) : (0.5) ; 
		FOR(int, time, 0,  < , 8, time++) {
			iDCT_2D_reference_coarse_374_s.coeff[freq][time] = (scale * ((float) cos(((0.3926991 * freq) * (time + 0.5))))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_522
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_522_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_523
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_523_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_524
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_524_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_525
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_525_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_526
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_526_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_527
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_527_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_528
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_528_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_529
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_529_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_532
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_532_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_533
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_533_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_534
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_534_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_535
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_535_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_536
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_536_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_537
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_537_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_538
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_538_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_539
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 0.0 ; 
			Cu = 0.0 ; 
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_539_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: AnonFilter_a2_399
	 {
	AnonFilter_a2_399_s.count = 0.0 ; 
	AnonFilter_a2_399_s.errors = 0.0 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		AnonFilter_a0_371();
		DUPLICATE_Splitter_446();
			iDCT_2D_reference_coarse_374();
			WEIGHTED_ROUND_ROBIN_Splitter_454();
				AnonFilter_a3_456();
				AnonFilter_a3_457();
				AnonFilter_a3_458();
				AnonFilter_a3_459();
				AnonFilter_a3_460();
				AnonFilter_a3_461();
				AnonFilter_a3_462();
				AnonFilter_a3_463();
				AnonFilter_a3_464();
				AnonFilter_a3_465();
				AnonFilter_a3_466();
				AnonFilter_a3_467();
				AnonFilter_a3_468();
				AnonFilter_a3_469();
				AnonFilter_a3_470();
				AnonFilter_a3_471();
				AnonFilter_a3_472();
				AnonFilter_a3_473();
				AnonFilter_a3_474();
				AnonFilter_a3_475();
				AnonFilter_a3_476();
				AnonFilter_a3_477();
				AnonFilter_a3_478();
				AnonFilter_a3_479();
				AnonFilter_a3_480();
				AnonFilter_a3_481();
				AnonFilter_a3_482();
				AnonFilter_a3_483();
				AnonFilter_a3_484();
				AnonFilter_a3_485();
				AnonFilter_a3_486();
				AnonFilter_a3_487();
				AnonFilter_a3_488();
				AnonFilter_a3_489();
				AnonFilter_a3_490();
				AnonFilter_a3_491();
				AnonFilter_a3_492();
				AnonFilter_a3_493();
				AnonFilter_a3_494();
				AnonFilter_a3_495();
				AnonFilter_a3_496();
				AnonFilter_a3_497();
				AnonFilter_a3_498();
				AnonFilter_a3_499();
				AnonFilter_a3_500();
				AnonFilter_a3_501();
				AnonFilter_a3_502();
				AnonFilter_a3_503();
				AnonFilter_a3_504();
				AnonFilter_a3_505();
				AnonFilter_a3_506();
				AnonFilter_a3_507();
				AnonFilter_a3_508();
				AnonFilter_a3_509();
				AnonFilter_a3_510();
				AnonFilter_a3_511();
				AnonFilter_a3_512();
				AnonFilter_a3_513();
				AnonFilter_a3_514();
				AnonFilter_a3_515();
				AnonFilter_a3_516();
				AnonFilter_a3_517();
				AnonFilter_a3_518();
				AnonFilter_a3_519();
			WEIGHTED_ROUND_ROBIN_Joiner_455();
			Pre_CollapsedDataParallel_1_444();
			WEIGHTED_ROUND_ROBIN_Splitter_520();
				iDCT_1D_reference_fine_522();
				iDCT_1D_reference_fine_523();
				iDCT_1D_reference_fine_524();
				iDCT_1D_reference_fine_525();
				iDCT_1D_reference_fine_526();
				iDCT_1D_reference_fine_527();
				iDCT_1D_reference_fine_528();
				iDCT_1D_reference_fine_529();
			WEIGHTED_ROUND_ROBIN_Joiner_521();
			Post_CollapsedDataParallel_2_445();
			WEIGHTED_ROUND_ROBIN_Splitter_530();
				iDCT_1D_reference_fine_532();
				iDCT_1D_reference_fine_533();
				iDCT_1D_reference_fine_534();
				iDCT_1D_reference_fine_535();
				iDCT_1D_reference_fine_536();
				iDCT_1D_reference_fine_537();
				iDCT_1D_reference_fine_538();
				iDCT_1D_reference_fine_539();
			WEIGHTED_ROUND_ROBIN_Joiner_531();
			WEIGHTED_ROUND_ROBIN_Splitter_540();
				AnonFilter_a4_542();
				AnonFilter_a4_543();
				AnonFilter_a4_544();
				AnonFilter_a4_545();
				AnonFilter_a4_546();
				AnonFilter_a4_547();
				AnonFilter_a4_548();
				AnonFilter_a4_549();
				AnonFilter_a4_550();
				AnonFilter_a4_551();
				AnonFilter_a4_552();
				AnonFilter_a4_553();
				AnonFilter_a4_554();
				AnonFilter_a4_555();
				AnonFilter_a4_556();
				AnonFilter_a4_557();
				AnonFilter_a4_558();
				AnonFilter_a4_559();
				AnonFilter_a4_560();
				AnonFilter_a4_561();
				AnonFilter_a4_562();
				AnonFilter_a4_563();
				AnonFilter_a4_564();
				AnonFilter_a4_565();
				AnonFilter_a4_566();
				AnonFilter_a4_567();
				AnonFilter_a4_568();
				AnonFilter_a4_569();
				AnonFilter_a4_570();
				AnonFilter_a4_571();
				AnonFilter_a4_572();
				AnonFilter_a4_573();
				AnonFilter_a4_574();
				AnonFilter_a4_575();
				AnonFilter_a4_576();
				AnonFilter_a4_577();
				AnonFilter_a4_578();
				AnonFilter_a4_579();
				AnonFilter_a4_580();
				AnonFilter_a4_581();
				AnonFilter_a4_582();
				AnonFilter_a4_583();
				AnonFilter_a4_584();
				AnonFilter_a4_585();
				AnonFilter_a4_586();
				AnonFilter_a4_587();
				AnonFilter_a4_588();
				AnonFilter_a4_589();
				AnonFilter_a4_590();
				AnonFilter_a4_591();
				AnonFilter_a4_592();
				AnonFilter_a4_593();
				AnonFilter_a4_594();
				AnonFilter_a4_595();
				AnonFilter_a4_596();
				AnonFilter_a4_597();
				AnonFilter_a4_598();
				AnonFilter_a4_599();
				AnonFilter_a4_600();
				AnonFilter_a4_601();
				AnonFilter_a4_602();
				AnonFilter_a4_603();
				AnonFilter_a4_604();
				AnonFilter_a4_605();
			WEIGHTED_ROUND_ROBIN_Joiner_541();
			WEIGHTED_ROUND_ROBIN_Splitter_606();
				iDCT8x8_1D_row_fast_608();
				iDCT8x8_1D_row_fast_609();
				iDCT8x8_1D_row_fast_610();
				iDCT8x8_1D_row_fast_611();
				iDCT8x8_1D_row_fast_612();
				iDCT8x8_1D_row_fast_613();
				iDCT8x8_1D_row_fast_614();
				iDCT8x8_1D_row_fast_615();
			WEIGHTED_ROUND_ROBIN_Joiner_607();
			iDCT8x8_1D_col_fast_398();
		WEIGHTED_ROUND_ROBIN_Joiner_447();
		AnonFilter_a2_399();
	ENDFOR
	return EXIT_SUCCESS;
}
