#include "SDF-iDCTcompare.h"

buffer_float_t AnonFilter_a3_243Pre_CollapsedDataParallel_1_310;
buffer_int_t WEIGHTED_ROUND_ROBIN_Joiner_313AnonFilter_a2_265;
buffer_int_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_join[3];
buffer_float_t iDCT_1D_reference_fine_244Post_CollapsedDataParallel_2_311;
buffer_float_t Post_CollapsedDataParallel_2_311iDCT_1D_reference_fine_252;
buffer_int_t iDCT8x8_1D_row_fast_263iDCT8x8_1D_col_fast_264;
buffer_int_t AnonFilter_a0_237DUPLICATE_Splitter_312;
buffer_float_t Pre_CollapsedDataParallel_1_310iDCT_1D_reference_fine_244;
buffer_int_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_split[3];
buffer_float_t iDCT_1D_reference_fine_252AnonFilter_a4_260;


iDCT_2D_reference_coarse_240_t iDCT_2D_reference_coarse_240_s;
iDCT_2D_reference_coarse_240_t iDCT_1D_reference_fine_244_s;
iDCT_2D_reference_coarse_240_t iDCT_1D_reference_fine_252_s;
iDCT8x8_1D_col_fast_264_t iDCT8x8_1D_col_fast_264_s;
AnonFilter_a2_265_t AnonFilter_a2_265_s;

void AnonFilter_a0(buffer_int_t *chanout) {
	FOR(int, i, 0,  < , 64, i++) {
		push_int(&(*chanout), (((int) pow(3.0, i)) % 75)) ; 
	}
	ENDFOR
}


void AnonFilter_a0_237() {
	AnonFilter_a0(&(AnonFilter_a0_237DUPLICATE_Splitter_312));
}

void iDCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout) {
	float block_x[8][8];
	FOR(int, i, 0,  < , 8, i++) {
		FOR(int, j, 0,  < , 8, j++) {
			block_x[i][j] = 0.0 ; 
			FOR(int, k, 0,  < , 8, k++) {
				block_x[i][j] = (block_x[i][j] + (iDCT_2D_reference_coarse_240_s.coeff[k][j] * peek_int(&(*chanin), ((8 * i) + k)))) ; 
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
				block_y = (block_y + (iDCT_2D_reference_coarse_240_s.coeff[k][i] * block_x[k][j])) ; 
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


void iDCT_2D_reference_coarse_240() {
	iDCT_2D_reference_coarse(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_split[0]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_join[0]));
}

void AnonFilter_a3(buffer_int_t *chanin, buffer_float_t *chanout) {
		push_float(&(*chanout), pop_int(&(*chanin))) ; 
	}


void AnonFilter_a3_243() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		AnonFilter_a3(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_split[1]), &(AnonFilter_a3_243Pre_CollapsedDataParallel_1_310));
	ENDFOR
}

void Pre_CollapsedDataParallel_1(buffer_float_t *chanin, buffer_float_t *chanout) {
 {
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = _k;
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


void Pre_CollapsedDataParallel_1_310() {
	Pre_CollapsedDataParallel_1(&(AnonFilter_a3_243Pre_CollapsedDataParallel_1_310), &(Pre_CollapsedDataParallel_1_310iDCT_1D_reference_fine_244));
}

void iDCT_1D_reference_fine(buffer_float_t *chanin, buffer_float_t *chanout) {
		FOR(int, x, 0,  < , 8, x++) {
			float tempsum = 0.0;
			FOR(int, u, 0,  < , 8, u++) {
				tempsum = (tempsum + (iDCT_1D_reference_fine_244_s.coeff[x][u] * peek_float(&(*chanin), u))) ; 
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


void iDCT_1D_reference_fine_244() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		iDCT_1D_reference_fine(&(Pre_CollapsedDataParallel_1_310iDCT_1D_reference_fine_244), &(iDCT_1D_reference_fine_244Post_CollapsedDataParallel_2_311));
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


void Post_CollapsedDataParallel_2_311() {
	Post_CollapsedDataParallel_2(&(iDCT_1D_reference_fine_244Post_CollapsedDataParallel_2_311), &(Post_CollapsedDataParallel_2_311iDCT_1D_reference_fine_252));
}

void iDCT_1D_reference_fine_252() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		iDCT_1D_reference_fine(&(Post_CollapsedDataParallel_2_311iDCT_1D_reference_fine_252), &(iDCT_1D_reference_fine_252AnonFilter_a4_260));
	ENDFOR
}

void AnonFilter_a4(buffer_float_t *chanin, buffer_int_t *chanout) {
		push_int(&(*chanout), ((int) floor((pop_float(&(*chanin)) + 0.5)))) ; 
	}


void AnonFilter_a4_260() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		AnonFilter_a4(&(iDCT_1D_reference_fine_252AnonFilter_a4_260), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_join[1]));
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


void iDCT8x8_1D_row_fast_263() {
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++)
		iDCT8x8_1D_row_fast(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_split[2]), &(iDCT8x8_1D_row_fast_263iDCT8x8_1D_col_fast_264));
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
				iDCT8x8_1D_col_fast_264_s.buffer[(c + (8 * i))] = x0 ; 
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
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 0)] = ((x7 + x1) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 8)] = ((x3 + x2) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 16)] = ((x0 + x4) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 24)] = ((x8 + x6) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 32)] = ((x8 - x6) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 40)] = ((x0 - x4) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 48)] = ((x3 - x2) >> 14) ; 
			iDCT8x8_1D_col_fast_264_s.buffer[(c + 56)] = ((x7 - x1) >> 14) ; 
		}
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_int(&(*chanin)) ; 
		push_int(&(*chanout), iDCT8x8_1D_col_fast_264_s.buffer[i]) ; 
	}
	ENDFOR
}


void iDCT8x8_1D_col_fast_264() {
	iDCT8x8_1D_col_fast(&(iDCT8x8_1D_row_fast_263iDCT8x8_1D_col_fast_264), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_join[2]));
}

void DUPLICATE_Splitter_312() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		int __token_ = pop_int(&AnonFilter_a0_237DUPLICATE_Splitter_312);
		FOR(uint32_t, __iter_dup_, 0, <, 3, __iter_dup_++)
			push_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_313() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		FOR(uint32_t, __iter_, 0, <, 3, __iter_++)
			push_int(&WEIGHTED_ROUND_ROBIN_Joiner_313AnonFilter_a2_265, pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_join[__iter_]));
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
		AnonFilter_a2_265_s.count = (AnonFilter_a2_265_s.count + 1.0) ; 
		if(refcoarse != reffine) {
			float errorRate = 0.0;
			printf("%s", "Error - Discrepancy between reference iDCT coarse and fine");
			printf("\n");
			printf("%s", "        coarse iDCT gives ");
			printf("%d", refcoarse);
			printf("%s", " and fine iDCT gives ");
			printf("%d", reffine);
			printf("\n");
			AnonFilter_a2_265_s.errors = (AnonFilter_a2_265_s.errors + 1.0) ; 
			errorRate = (AnonFilter_a2_265_s.errors / AnonFilter_a2_265_s.count) ; 
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
			AnonFilter_a2_265_s.errors = (AnonFilter_a2_265_s.errors + 1.0) ; 
			errorRate = (AnonFilter_a2_265_s.errors / AnonFilter_a2_265_s.count) ; 
			printf("%s", "        Error Rate is ");
			printf("%.10f", errorRate);
			printf("\n");
		}
	}


void AnonFilter_a2_265() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		AnonFilter_a2(&(WEIGHTED_ROUND_ROBIN_Joiner_313AnonFilter_a2_265));
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&AnonFilter_a3_243Pre_CollapsedDataParallel_1_310);
	init_buffer_int(&WEIGHTED_ROUND_ROBIN_Joiner_313AnonFilter_a2_265);
	FOR(int, __iter_init_0_, 0, <, 3, __iter_init_0_++)
		init_buffer_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_join[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&iDCT_1D_reference_fine_244Post_CollapsedDataParallel_2_311);
	init_buffer_float(&Post_CollapsedDataParallel_2_311iDCT_1D_reference_fine_252);
	init_buffer_int(&iDCT8x8_1D_row_fast_263iDCT8x8_1D_col_fast_264);
	init_buffer_int(&AnonFilter_a0_237DUPLICATE_Splitter_312);
	init_buffer_float(&Pre_CollapsedDataParallel_1_310iDCT_1D_reference_fine_244);
	FOR(int, __iter_init_1_, 0, <, 3, __iter_init_1_++)
		init_buffer_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_238_314_318_322_split[__iter_init_1_]);
	ENDFOR
	init_buffer_float(&iDCT_1D_reference_fine_252AnonFilter_a4_260);
// --- init: iDCT_2D_reference_coarse_240
	 {
	FOR(int, freq, 0,  < , 8, freq++) {
		float scale = 0.0;
		scale = freq == 0 ? (0.35355338) : (0.5) ; 
		FOR(int, time, 0,  < , 8, time++) {
			iDCT_2D_reference_coarse_240_s.coeff[freq][time] = (scale * ((float) cos(((0.3926991 * freq) * (time + 0.5))))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_244
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_244_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_1D_reference_fine_252
	 {
	FOR(int, x, 0,  < , 8, x++) {
		FOR(int, u, 0,  < , 8, u++) {
			float Cu = 0.0;
			Cu = 1.0 ; 
			if(u == 0) {
				Cu = 0.70710677 ; 
			}
			iDCT_1D_reference_fine_252_s.coeff[x][u] = ((0.5 * Cu) * ((float) cos((((u * 3.1415927) * ((2.0 * x) + 1.0)) / 16.0)))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: AnonFilter_a2_265
	 {
	AnonFilter_a2_265_s.count = 0.0 ; 
	AnonFilter_a2_265_s.errors = 0.0 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		AnonFilter_a0_237();
		DUPLICATE_Splitter_312();
			iDCT_2D_reference_coarse_240();
			AnonFilter_a3_243();
			Pre_CollapsedDataParallel_1_310();
			iDCT_1D_reference_fine_244();
			Post_CollapsedDataParallel_2_311();
			iDCT_1D_reference_fine_252();
			AnonFilter_a4_260();
			iDCT8x8_1D_row_fast_263();
			iDCT8x8_1D_col_fast_264();
		WEIGHTED_ROUND_ROBIN_Joiner_313();
		AnonFilter_a2_265();
	ENDFOR
	return EXIT_SUCCESS;
}
