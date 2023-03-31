#include "SDF-DCTverify.h"

buffer_int_t AnonFilter_a0_239DUPLICATE_Splitter_248;
buffer_int_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_split[2];
buffer_int_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_join[2];
buffer_int_t WEIGHTED_ROUND_ROBIN_Joiner_249AnonFilter_a3_247;
buffer_int_t DCT_2D_reference_coarse_243iDCT_2D_reference_coarse_245;


DCT_2D_reference_coarse_243_t DCT_2D_reference_coarse_243_s;
DCT_2D_reference_coarse_243_t iDCT_2D_reference_coarse_245_s;
AnonFilter_a3_247_t AnonFilter_a3_247_s;

void AnonFilter_a0(buffer_int_t *chanout) {
	FOR(int, i, 0,  < , 64, i++) {
		push_int(&(*chanout), (((int) pow(3.0, i)) % 75)) ; 
	}
	ENDFOR
}


void AnonFilter_a0_239() {
	AnonFilter_a0(&(AnonFilter_a0_239DUPLICATE_Splitter_248));
}

void DCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout) {
	float block_x[8][8];
	FOR(int, i, 0,  < , 8, i++) {
		FOR(int, j, 0,  < , 8, j++) {
			block_x[i][j] = 0.0 ; 
			FOR(int, k, 0,  < , 8, k++) {
				block_x[i][j] = (block_x[i][j] + (DCT_2D_reference_coarse_243_s.coeff[j][k] * peek_int(&(*chanin), ((8 * i) + k)))) ; 
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
				block_y = (block_y + (DCT_2D_reference_coarse_243_s.coeff[i][k] * block_x[k][j])) ; 
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


void DCT_2D_reference_coarse_243() {
	DCT_2D_reference_coarse(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_split[0]), &(DCT_2D_reference_coarse_243iDCT_2D_reference_coarse_245));
}

void iDCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout) {
	float block_x[8][8];
	FOR(int, i, 0,  < , 8, i++) {
		FOR(int, j, 0,  < , 8, j++) {
			block_x[i][j] = 0.0 ; 
			FOR(int, k, 0,  < , 8, k++) {
				block_x[i][j] = (block_x[i][j] + (iDCT_2D_reference_coarse_245_s.coeff[k][j] * peek_int(&(*chanin), ((8 * i) + k)))) ; 
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
				block_y = (block_y + (iDCT_2D_reference_coarse_245_s.coeff[k][i] * block_x[k][j])) ; 
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


void iDCT_2D_reference_coarse_245() {
	iDCT_2D_reference_coarse(&(DCT_2D_reference_coarse_243iDCT_2D_reference_coarse_245), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_join[0]));
}

void Identity(buffer_int_t *chanin, buffer_int_t *chanout) {
		int __tmp3 = 0;
		__tmp3 = pop_int(&(*chanin)) ; 
		push_int(&(*chanout), __tmp3) ; 
	}


void Identity_246() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		Identity(&(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_split[1]), &(SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_join[1]));
	ENDFOR
}

void DUPLICATE_Splitter_248() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		int __token_ = pop_int(&AnonFilter_a0_239DUPLICATE_Splitter_248);
		FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
			push_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_249() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		push_int(&WEIGHTED_ROUND_ROBIN_Joiner_249AnonFilter_a3_247, pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_join[0]));
		push_int(&WEIGHTED_ROUND_ROBIN_Joiner_249AnonFilter_a3_247, pop_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_join[1]));
	ENDFOR
}}

void AnonFilter_a3(buffer_int_t *chanin) {
		int a = 0;
		int b = 0;
		a = pop_int(&(*chanin)) ; 
		b = pop_int(&(*chanin)) ; 
		AnonFilter_a3_247_s.count = (AnonFilter_a3_247_s.count + 1.0) ; 
		if(a != b) {
			float errorRate = 0.0;
			AnonFilter_a3_247_s.errors = (AnonFilter_a3_247_s.errors + 1.0) ; 
			if((((a - b) > 1) || ((a - b) < -1))) {
				printf("%s", "Serious Error  - iDCT output off by more than 1 from DCT input.");
				printf("\n");
			}
			else {
				printf("%s", "Possible Error - iDCT output off by 1 from DCT input.");
				printf("\n");
			}
			printf("%s", "                 input: ");
			printf("%d", b);
			printf("%s", ", output: ");
			printf("%d", a);
			printf("\n");
			errorRate = (AnonFilter_a3_247_s.errors / AnonFilter_a3_247_s.count) ; 
			printf("%s", "                 Error Rate: ");
			printf("%.10f", errorRate);
			printf("\n");
		}
	}


void AnonFilter_a3_247() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		AnonFilter_a3(&(WEIGHTED_ROUND_ROBIN_Joiner_249AnonFilter_a3_247));
	ENDFOR
}

void __stream_init__() {
	init_buffer_int(&AnonFilter_a0_239DUPLICATE_Splitter_248);
	FOR(int, __iter_init_0_, 0, <, 2, __iter_init_0_++)
		init_buffer_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_split[__iter_init_0_]);
	ENDFOR
	FOR(int, __iter_init_1_, 0, <, 2, __iter_init_1_++)
		init_buffer_int(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a2_240_250_253_256_join[__iter_init_1_]);
	ENDFOR
	init_buffer_int(&WEIGHTED_ROUND_ROBIN_Joiner_249AnonFilter_a3_247);
	init_buffer_int(&DCT_2D_reference_coarse_243iDCT_2D_reference_coarse_245);
// --- init: DCT_2D_reference_coarse_243
	 {
	FOR(int, i, 0,  < , 8, i++) {
		float s = 0.0;
		s = i == 0 ? (0.35355338) : (0.5) ; 
		FOR(int, j, 0,  < , 8, j++) {
			DCT_2D_reference_coarse_243_s.coeff[i][j] = (s * ((float) cos(((0.3926991 * i) * (j + 0.5))))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: iDCT_2D_reference_coarse_245
	 {
	FOR(int, freq, 0,  < , 8, freq++) {
		float scale = 0.0;
		scale = freq == 0 ? (0.35355338) : (0.5) ; 
		FOR(int, time, 0,  < , 8, time++) {
			iDCT_2D_reference_coarse_245_s.coeff[freq][time] = (scale * ((float) cos(((0.3926991 * freq) * (time + 0.5))))) ; 
		}
		ENDFOR
	}
	ENDFOR
}
//--------------------------------
// --- init: AnonFilter_a3_247
	 {
	AnonFilter_a3_247_s.count = 0.0 ; 
	AnonFilter_a3_247_s.errors = 0.0 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		AnonFilter_a0_239();
		DUPLICATE_Splitter_248();
			DCT_2D_reference_coarse_243();
			iDCT_2D_reference_coarse_245();
			Identity_246();
		WEIGHTED_ROUND_ROBIN_Joiner_249();
		AnonFilter_a3_247();
	ENDFOR
	return EXIT_SUCCESS;
}
