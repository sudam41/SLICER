#include "HSDF-iDCTcompare.h"

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

void AnonFilter_a0(buffer_int_t *chanout) {
	FOR(int, i, 0,  < , 64, i++) {
		push_int(&(*chanout), (((int) pow(3.0, i)) % 75)) ; 
	}
	ENDFOR
}


void AnonFilter_a0_371() {
	AnonFilter_a0(&(AnonFilter_a0_371DUPLICATE_Splitter_446));
}

void iDCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout) {
	float block_x[8][8];
	FOR(int, i, 0,  < , 8, i++) {
		FOR(int, j, 0,  < , 8, j++) {
			block_x[i][j] = 0.0 ; 
			FOR(int, k, 0,  < , 8, k++) {
				block_x[i][j] = (block_x[i][j] + (iDCT_2D_reference_coarse_374_s.coeff[k][j] * peek_int(&(*chanin), ((8 * i) + k)))) ; 
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
			push_int(&(*chanout), ((int) block_y)) ; 
		}
		ENDFOR
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_int(&(*chanin)) ; 
	}
	ENDFOR
}


void iDCT_2D_reference_coarse_374() {
	iDCT_2D_reference_coarse(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_split[0]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[0]));
}

void AnonFilter_a3(buffer_int_t *chanin, buffer_float_t *chanout) {
	push_float(&(*chanout), pop_int(&(*chanin))) ; 
}


void AnonFilter_a3_456() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[0]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[0]));
}

void AnonFilter_a3_457() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[1]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[1]));
}

void AnonFilter_a3_458() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[2]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[2]));
}

void AnonFilter_a3_459() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[3]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[3]));
}

void AnonFilter_a3_460() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[4]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[4]));
}

void AnonFilter_a3_461() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[5]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[5]));
}

void AnonFilter_a3_462() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[6]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[6]));
}

void AnonFilter_a3_463() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[7]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[7]));
}

void AnonFilter_a3_464() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[8]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[8]));
}

void AnonFilter_a3_465() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[9]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[9]));
}

void AnonFilter_a3_466() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[10]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[10]));
}

void AnonFilter_a3_467() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[11]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[11]));
}

void AnonFilter_a3_468() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[12]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[12]));
}

void AnonFilter_a3_469() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[13]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[13]));
}

void AnonFilter_a3_470() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[14]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[14]));
}

void AnonFilter_a3_471() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[15]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[15]));
}

void AnonFilter_a3_472() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[16]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[16]));
}

void AnonFilter_a3_473() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[17]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[17]));
}

void AnonFilter_a3_474() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[18]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[18]));
}

void AnonFilter_a3_475() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[19]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[19]));
}

void AnonFilter_a3_476() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[20]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[20]));
}

void AnonFilter_a3_477() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[21]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[21]));
}

void AnonFilter_a3_478() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[22]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[22]));
}

void AnonFilter_a3_479() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[23]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[23]));
}

void AnonFilter_a3_480() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[24]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[24]));
}

void AnonFilter_a3_481() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[25]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[25]));
}

void AnonFilter_a3_482() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[26]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[26]));
}

void AnonFilter_a3_483() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[27]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[27]));
}

void AnonFilter_a3_484() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[28]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[28]));
}

void AnonFilter_a3_485() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[29]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[29]));
}

void AnonFilter_a3_486() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[30]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[30]));
}

void AnonFilter_a3_487() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[31]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[31]));
}

void AnonFilter_a3_488() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[32]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[32]));
}

void AnonFilter_a3_489() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[33]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[33]));
}

void AnonFilter_a3_490() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[34]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[34]));
}

void AnonFilter_a3_491() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[35]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[35]));
}

void AnonFilter_a3_492() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[36]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[36]));
}

void AnonFilter_a3_493() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[37]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[37]));
}

void AnonFilter_a3_494() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[38]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[38]));
}

void AnonFilter_a3_495() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[39]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[39]));
}

void AnonFilter_a3_496() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[40]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[40]));
}

void AnonFilter_a3_497() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[41]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[41]));
}

void AnonFilter_a3_498() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[42]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[42]));
}

void AnonFilter_a3_499() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[43]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[43]));
}

void AnonFilter_a3_500() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[44]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[44]));
}

void AnonFilter_a3_501() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[45]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[45]));
}

void AnonFilter_a3_502() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[46]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[46]));
}

void AnonFilter_a3_503() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[47]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[47]));
}

void AnonFilter_a3_504() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[48]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[48]));
}

void AnonFilter_a3_505() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[49]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[49]));
}

void AnonFilter_a3_506() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[50]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[50]));
}

void AnonFilter_a3_507() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[51]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[51]));
}

void AnonFilter_a3_508() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[52]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[52]));
}

void AnonFilter_a3_509() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[53]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[53]));
}

void AnonFilter_a3_510() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[54]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[54]));
}

void AnonFilter_a3_511() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[55]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[55]));
}

void AnonFilter_a3_512() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[56]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[56]));
}

void AnonFilter_a3_513() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[57]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[57]));
}

void AnonFilter_a3_514() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[58]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[58]));
}

void AnonFilter_a3_515() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[59]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[59]));
}

void AnonFilter_a3_516() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[60]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[60]));
}

void AnonFilter_a3_517() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[61]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[61]));
}

void AnonFilter_a3_518() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[62]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[62]));
}

void AnonFilter_a3_519() {
	AnonFilter_a3(&(SplitJoin3_AnonFilter_a3_Fiss_617_624_split[63]), &(SplitJoin3_AnonFilter_a3_Fiss_617_624_join[63]));
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

void Pre_CollapsedDataParallel_1(buffer_float_t *chanin, buffer_float_t *chanout) {
 {
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = 0;
		iTimesSumOfWeights_Plus_PartialSum_k = _k ; 
 {
		FOR(int, _i, 0,  < , 8, _i++) {
			push_float(&(*chanout), peek_float(&(*chanin), (iTimesSumOfWeights_Plus_PartialSum_k + 0))) ; 
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 8) ; 
		}
		ENDFOR
	}
	}
	ENDFOR
}
}
	pop_float(&(*chanin)) ; 
}


void Pre_CollapsedDataParallel_1_444() {
	Pre_CollapsedDataParallel_1(&(WEIGHTED_ROUND_ROBIN_Joiner_455Pre_CollapsedDataParallel_1_444), &(Pre_CollapsedDataParallel_1_444WEIGHTED_ROUND_ROBIN_Splitter_520));
}

void iDCT_1D_reference_fine(buffer_float_t *chanin, buffer_float_t *chanout) {
	FOR(int, x, 0,  < , 8, x++) {
		float tempsum = 0.0;
		FOR(int, u, 0,  < , 8, u++) {
			tempsum = (tempsum + (iDCT_1D_reference_fine_522_s.coeff[x][u] * peek_float(&(*chanin), u))) ; 
		}
		ENDFOR
		push_float(&(*chanout), tempsum) ; 
	}
	ENDFOR
	FOR(int, u, 0,  < , 8, u++) {
		pop_float(&(*chanin)) ; 
	}
	ENDFOR
}


void iDCT_1D_reference_fine_522() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[0]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[0]));
}

void iDCT_1D_reference_fine_523() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[1]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[1]));
}

void iDCT_1D_reference_fine_524() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[2]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[2]));
}

void iDCT_1D_reference_fine_525() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[3]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[3]));
}

void iDCT_1D_reference_fine_526() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[4]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[4]));
}

void iDCT_1D_reference_fine_527() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[5]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[5]));
}

void iDCT_1D_reference_fine_528() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[6]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[6]));
}

void iDCT_1D_reference_fine_529() {
	iDCT_1D_reference_fine(&(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_split[7]), &(SplitJoin5_iDCT_1D_reference_fine_Fiss_618_625_join[7]));
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

void Post_CollapsedDataParallel_2(buffer_float_t *chanin, buffer_float_t *chanout) {
 {
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 8, _i++) {
			push_float(&(*chanout), peek_float(&(*chanin), (_k + (partialSum_i + 0)))) ; 
			partialSum_i = (partialSum_i + 8) ; 
		}
		ENDFOR
	}
	}
	ENDFOR
}
}
	pop_float(&(*chanin)) ; 
}


void Post_CollapsedDataParallel_2_445() {
	Post_CollapsedDataParallel_2(&(WEIGHTED_ROUND_ROBIN_Joiner_521Post_CollapsedDataParallel_2_445), &(Post_CollapsedDataParallel_2_445WEIGHTED_ROUND_ROBIN_Splitter_530));
}

void iDCT_1D_reference_fine_532() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[0]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[0]));
}

void iDCT_1D_reference_fine_533() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[1]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[1]));
}

void iDCT_1D_reference_fine_534() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[2]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[2]));
}

void iDCT_1D_reference_fine_535() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[3]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[3]));
}

void iDCT_1D_reference_fine_536() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[4]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[4]));
}

void iDCT_1D_reference_fine_537() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[5]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[5]));
}

void iDCT_1D_reference_fine_538() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[6]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[6]));
}

void iDCT_1D_reference_fine_539() {
	iDCT_1D_reference_fine(&(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_split[7]), &(SplitJoin7_iDCT_1D_reference_fine_Fiss_619_626_join[7]));
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

void AnonFilter_a4(buffer_float_t *chanin, buffer_int_t *chanout) {
	push_int(&(*chanout), ((int) floor((pop_float(&(*chanin)) + 0.5)))) ; 
}


void AnonFilter_a4_542() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[0]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[0]));
}

void AnonFilter_a4_543() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[1]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[1]));
}

void AnonFilter_a4_544() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[2]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[2]));
}

void AnonFilter_a4_545() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[3]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[3]));
}

void AnonFilter_a4_546() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[4]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[4]));
}

void AnonFilter_a4_547() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[5]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[5]));
}

void AnonFilter_a4_548() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[6]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[6]));
}

void AnonFilter_a4_549() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[7]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[7]));
}

void AnonFilter_a4_550() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[8]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[8]));
}

void AnonFilter_a4_551() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[9]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[9]));
}

void AnonFilter_a4_552() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[10]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[10]));
}

void AnonFilter_a4_553() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[11]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[11]));
}

void AnonFilter_a4_554() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[12]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[12]));
}

void AnonFilter_a4_555() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[13]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[13]));
}

void AnonFilter_a4_556() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[14]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[14]));
}

void AnonFilter_a4_557() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[15]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[15]));
}

void AnonFilter_a4_558() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[16]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[16]));
}

void AnonFilter_a4_559() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[17]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[17]));
}

void AnonFilter_a4_560() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[18]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[18]));
}

void AnonFilter_a4_561() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[19]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[19]));
}

void AnonFilter_a4_562() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[20]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[20]));
}

void AnonFilter_a4_563() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[21]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[21]));
}

void AnonFilter_a4_564() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[22]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[22]));
}

void AnonFilter_a4_565() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[23]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[23]));
}

void AnonFilter_a4_566() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[24]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[24]));
}

void AnonFilter_a4_567() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[25]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[25]));
}

void AnonFilter_a4_568() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[26]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[26]));
}

void AnonFilter_a4_569() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[27]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[27]));
}

void AnonFilter_a4_570() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[28]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[28]));
}

void AnonFilter_a4_571() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[29]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[29]));
}

void AnonFilter_a4_572() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[30]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[30]));
}

void AnonFilter_a4_573() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[31]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[31]));
}

void AnonFilter_a4_574() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[32]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[32]));
}

void AnonFilter_a4_575() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[33]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[33]));
}

void AnonFilter_a4_576() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[34]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[34]));
}

void AnonFilter_a4_577() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[35]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[35]));
}

void AnonFilter_a4_578() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[36]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[36]));
}

void AnonFilter_a4_579() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[37]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[37]));
}

void AnonFilter_a4_580() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[38]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[38]));
}

void AnonFilter_a4_581() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[39]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[39]));
}

void AnonFilter_a4_582() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[40]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[40]));
}

void AnonFilter_a4_583() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[41]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[41]));
}

void AnonFilter_a4_584() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[42]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[42]));
}

void AnonFilter_a4_585() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[43]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[43]));
}

void AnonFilter_a4_586() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[44]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[44]));
}

void AnonFilter_a4_587() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[45]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[45]));
}

void AnonFilter_a4_588() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[46]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[46]));
}

void AnonFilter_a4_589() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[47]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[47]));
}

void AnonFilter_a4_590() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[48]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[48]));
}

void AnonFilter_a4_591() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[49]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[49]));
}

void AnonFilter_a4_592() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[50]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[50]));
}

void AnonFilter_a4_593() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[51]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[51]));
}

void AnonFilter_a4_594() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[52]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[52]));
}

void AnonFilter_a4_595() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[53]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[53]));
}

void AnonFilter_a4_596() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[54]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[54]));
}

void AnonFilter_a4_597() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[55]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[55]));
}

void AnonFilter_a4_598() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[56]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[56]));
}

void AnonFilter_a4_599() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[57]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[57]));
}

void AnonFilter_a4_600() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[58]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[58]));
}

void AnonFilter_a4_601() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[59]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[59]));
}

void AnonFilter_a4_602() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[60]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[60]));
}

void AnonFilter_a4_603() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[61]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[61]));
}

void AnonFilter_a4_604() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[62]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[62]));
}

void AnonFilter_a4_605() {
	AnonFilter_a4(&(SplitJoin9_AnonFilter_a4_Fiss_620_627_split[63]), &(SplitJoin9_AnonFilter_a4_Fiss_620_627_join[63]));
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

void iDCT8x8_1D_row_fast(buffer_int_t *chanin, buffer_int_t *chanout) {
	int x0 = 0;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;
	int x5 = 0;
	int x6 = 0;
	int x7 = 0;
	int x8 = 0;
	x0 = peek_int(&(*chanin), 0) ; 
	x1 = (peek_int(&(*chanin), 4) << 11) ; 
	x2 = peek_int(&(*chanin), 6) ; 
	x3 = peek_int(&(*chanin), 2) ; 
	x4 = peek_int(&(*chanin), 1) ; 
	x5 = peek_int(&(*chanin), 7) ; 
	x6 = peek_int(&(*chanin), 5) ; 
	x7 = peek_int(&(*chanin), 3) ; 
	if(((((((x1 == 0 && x2 == 0) && x3 == 0) && x4 == 0) && x5 == 0) && x6 == 0) && x7 == 0)) {
		x0 = (x0 << 3) ; 
		FOR(int, i, 0,  < , 8, i++) {
			push_int(&(*chanout), x0) ; 
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
		push_int(&(*chanout), ((x7 + x1) >> 8)) ; 
		push_int(&(*chanout), ((x3 + x2) >> 8)) ; 
		push_int(&(*chanout), ((x0 + x4) >> 8)) ; 
		push_int(&(*chanout), ((x8 + x6) >> 8)) ; 
		push_int(&(*chanout), ((x8 - x6) >> 8)) ; 
		push_int(&(*chanout), ((x0 - x4) >> 8)) ; 
		push_int(&(*chanout), ((x3 - x2) >> 8)) ; 
		push_int(&(*chanout), ((x7 - x1) >> 8)) ; 
	}
	FOR(int, i, 0,  < , 8, i++) {
		pop_int(&(*chanin)) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_row_fast_608() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[0]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[0]));
}

void iDCT8x8_1D_row_fast_609() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[1]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[1]));
}

void iDCT8x8_1D_row_fast_610() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[2]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[2]));
}

void iDCT8x8_1D_row_fast_611() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[3]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[3]));
}

void iDCT8x8_1D_row_fast_612() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[4]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[4]));
}

void iDCT8x8_1D_row_fast_613() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[5]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[5]));
}

void iDCT8x8_1D_row_fast_614() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[6]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[6]));
}

void iDCT8x8_1D_row_fast_615() {
	iDCT8x8_1D_row_fast(&(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_split[7]), &(SplitJoin152_iDCT8x8_1D_row_fast_Fiss_621_628_join[7]));
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

void iDCT8x8_1D_col_fast(buffer_int_t *chanin, buffer_int_t *chanout) {
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
		x0 = peek_int(&(*chanin), (c + 0)) ; 
		x1 = (peek_int(&(*chanin), (c + 32)) << 8) ; 
		x2 = peek_int(&(*chanin), (c + 48)) ; 
		x3 = peek_int(&(*chanin), (c + 16)) ; 
		x4 = peek_int(&(*chanin), (c + 8)) ; 
		x5 = peek_int(&(*chanin), (c + 56)) ; 
		x6 = peek_int(&(*chanin), (c + 40)) ; 
		x7 = peek_int(&(*chanin), (c + 24)) ; 
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
		pop_int(&(*chanin)) ; 
		push_int(&(*chanout), iDCT8x8_1D_col_fast_398_s.buffer[i]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_col_fast_398() {
	iDCT8x8_1D_col_fast(&(WEIGHTED_ROUND_ROBIN_Joiner_607iDCT8x8_1D_col_fast_398), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_372_448_616_623_join[2]));
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

void AnonFilter_a2(buffer_int_t *chanin) {
		int refcoarse = 0;
		int reffine = 0;
		int fastfine = 0;
		refcoarse = pop_int(&(*chanin)) ; 
		reffine = pop_int(&(*chanin)) ; 
		fastfine = pop_int(&(*chanin)) ; 
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


void AnonFilter_a2_399() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		AnonFilter_a2(&(WEIGHTED_ROUND_ROBIN_Joiner_447AnonFilter_a2_399));
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
