#include "HSDF-CFARtest.h"

buffer_float_t CFAR_gather_30AnonFilter_a0_31;
buffer_complex_t ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30;
buffer_float_t SplitJoin0_SquareAndScale_Fiss_99_101_join[64];
buffer_complex_t SplitJoin0_SquareAndScale_Fiss_99_101_split[64];


ComplexSource_27_t ComplexSource_27_s;
CFAR_gather_30_t CFAR_gather_30_s;

void ComplexSource(buffer_complex_t *chanout) {
	FOR(int, i, 0,  < , 64, i++) {
		complex_t c = {
			.real = 0,
			.imag = 0
		};
		ComplexSource_27_s.theta = (ComplexSource_27_s.theta + 0.19634955) ; 
		c.real = ((((float) sin(ComplexSource_27_s.theta)) * (((float) cos(ComplexSource_27_s.theta)) + ((0.0 * ((float) sin(ComplexSource_27_s.theta))) - 0.0))) - (0.0 * (0.0 + (1.0 * ((float) sin(ComplexSource_27_s.theta)))))) ; 
		c.imag = ((((float) sin(ComplexSource_27_s.theta)) * (0.0 + (1.0 * ((float) sin(ComplexSource_27_s.theta))))) + (0.0 * (((float) cos(ComplexSource_27_s.theta)) + ((0.0 * ((float) sin(ComplexSource_27_s.theta))) - 0.0)))) ; 
		push_complex(&(*chanout), c) ; 
	}
	ENDFOR
}


void ComplexSource_27() {
	ComplexSource(&(ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33));
}

void SquareAndScale(buffer_complex_t *chanin, buffer_float_t *chanout) {
	complex_t c = ((complex_t) pop_complex(&(*chanin)));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&(*chanout), ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_35() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[0]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[0]));
}

void SquareAndScale_36() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[1]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[1]));
}

void SquareAndScale_37() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[2]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[2]));
}

void SquareAndScale_38() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[3]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[3]));
}

void SquareAndScale_39() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[4]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[4]));
}

void SquareAndScale_40() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[5]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[5]));
}

void SquareAndScale_41() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[6]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[6]));
}

void SquareAndScale_42() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[7]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[7]));
}

void SquareAndScale_43() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[8]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[8]));
}

void SquareAndScale_44() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[9]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[9]));
}

void SquareAndScale_45() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[10]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[10]));
}

void SquareAndScale_46() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[11]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[11]));
}

void SquareAndScale_47() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[12]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[12]));
}

void SquareAndScale_48() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[13]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[13]));
}

void SquareAndScale_49() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[14]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[14]));
}

void SquareAndScale_50() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[15]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[15]));
}

void SquareAndScale_51() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[16]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[16]));
}

void SquareAndScale_52() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[17]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[17]));
}

void SquareAndScale_53() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[18]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[18]));
}

void SquareAndScale_54() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[19]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[19]));
}

void SquareAndScale_55() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[20]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[20]));
}

void SquareAndScale_56() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[21]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[21]));
}

void SquareAndScale_57() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[22]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[22]));
}

void SquareAndScale_58() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[23]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[23]));
}

void SquareAndScale_59() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[24]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[24]));
}

void SquareAndScale_60() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[25]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[25]));
}

void SquareAndScale_61() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[26]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[26]));
}

void SquareAndScale_62() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[27]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[27]));
}

void SquareAndScale_63() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[28]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[28]));
}

void SquareAndScale_64() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[29]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[29]));
}

void SquareAndScale_65() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[30]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[30]));
}

void SquareAndScale_66() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[31]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[31]));
}

void SquareAndScale_67() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[32]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[32]));
}

void SquareAndScale_68() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[33]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[33]));
}

void SquareAndScale_69() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[34]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[34]));
}

void SquareAndScale_70() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[35]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[35]));
}

void SquareAndScale_71() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[36]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[36]));
}

void SquareAndScale_72() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[37]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[37]));
}

void SquareAndScale_73() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[38]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[38]));
}

void SquareAndScale_74() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[39]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[39]));
}

void SquareAndScale_75() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[40]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[40]));
}

void SquareAndScale_76() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[41]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[41]));
}

void SquareAndScale_77() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[42]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[42]));
}

void SquareAndScale_78() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[43]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[43]));
}

void SquareAndScale_79() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[44]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[44]));
}

void SquareAndScale_80() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[45]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[45]));
}

void SquareAndScale_81() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[46]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[46]));
}

void SquareAndScale_82() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[47]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[47]));
}

void SquareAndScale_83() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[48]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[48]));
}

void SquareAndScale_84() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[49]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[49]));
}

void SquareAndScale_85() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[50]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[50]));
}

void SquareAndScale_86() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[51]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[51]));
}

void SquareAndScale_87() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[52]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[52]));
}

void SquareAndScale_88() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[53]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[53]));
}

void SquareAndScale_89() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[54]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[54]));
}

void SquareAndScale_90() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[55]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[55]));
}

void SquareAndScale_91() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[56]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[56]));
}

void SquareAndScale_92() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[57]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[57]));
}

void SquareAndScale_93() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[58]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[58]));
}

void SquareAndScale_94() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[59]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[59]));
}

void SquareAndScale_95() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[60]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[60]));
}

void SquareAndScale_96() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[61]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[61]));
}

void SquareAndScale_97() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[62]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[62]));
}

void SquareAndScale_98() {
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[63]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[63]));
}

void WEIGHTED_ROUND_ROBIN_Splitter_33() {
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[__iter_], pop_complex(&ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_34() {
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30, pop_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[__iter_]));
	ENDFOR
}

void CFAR_gather(buffer_float_t *chanin, buffer_float_t *chanout) {
		float sum = 0.0;
		FOR4(int, i__conflict__1, 0, ((i__conflict__1 < 5) && (((i__conflict__1 + CFAR_gather_30_s.pos) - 5) >= 0)), __DEFLOOPBOUND__8__, i__conflict__1++) {
			sum = (sum + CFAR_gather_30_s.poke[((5 - i__conflict__1) - 1)]) ; 
		}
		ENDFOR
		FOR4(int, i__conflict__0, 5, ((i__conflict__0 <= 9) && ((i__conflict__0 + CFAR_gather_30_s.pos) < 64)), __DEFLOOPBOUND__9__, i__conflict__0++) {
			sum = (sum + peek_float(&(*chanin), i__conflict__0)) ; 
		}
		ENDFOR
		push_float(&(*chanout), sum) ; 
		FOR(int, i, 1,  < , 9, i++) {
			CFAR_gather_30_s.poke[(i - 1)] = CFAR_gather_30_s.poke[i] ; 
		}
		ENDFOR
		CFAR_gather_30_s.poke[8] = pop_float(&(*chanin)) ; 
		CFAR_gather_30_s.pos++ ; 
		if(CFAR_gather_30_s.pos == 64) {
			CFAR_gather_30_s.pos = 0 ; 
		}
	}


void CFAR_gather_30() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		CFAR_gather(&(WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30), &(CFAR_gather_30AnonFilter_a0_31));
	ENDFOR
}

void AnonFilter_a0(buffer_float_t *chanin) {
		printf("%.10f", pop_float(&(*chanin)));
		printf("\n");
	}


void AnonFilter_a0_31() {
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++)
		AnonFilter_a0(&(CFAR_gather_30AnonFilter_a0_31));
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&CFAR_gather_30AnonFilter_a0_31);
	init_buffer_complex(&ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30);
	FOR(int, __iter_init_0_, 0, <, 64, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[__iter_init_0_]);
	ENDFOR
	FOR(int, __iter_init_1_, 0, <, 64, __iter_init_1_++)
		init_buffer_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[__iter_init_1_]);
	ENDFOR
// --- init: ComplexSource_27
	 {
	ComplexSource_27_s.theta = 0.0 ; 
}
	ComplexSource(&(ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33));
//--------------------------------
// --- init: WEIGHTED_ROUND_ROBIN_Splitter_33
	
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[__iter_], pop_complex(&ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33));
	ENDFOR
//--------------------------------
// --- init: SquareAndScale_35
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[0]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[0]));
//--------------------------------
// --- init: SquareAndScale_36
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[1]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[1]));
//--------------------------------
// --- init: SquareAndScale_37
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[2]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[2]));
//--------------------------------
// --- init: SquareAndScale_38
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[3]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[3]));
//--------------------------------
// --- init: SquareAndScale_39
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[4]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[4]));
//--------------------------------
// --- init: SquareAndScale_40
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[5]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[5]));
//--------------------------------
// --- init: SquareAndScale_41
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[6]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[6]));
//--------------------------------
// --- init: SquareAndScale_42
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[7]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[7]));
//--------------------------------
// --- init: SquareAndScale_43
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[8]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[8]));
//--------------------------------
// --- init: SquareAndScale_44
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[9]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[9]));
//--------------------------------
// --- init: SquareAndScale_45
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[10]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[10]));
//--------------------------------
// --- init: SquareAndScale_46
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[11]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[11]));
//--------------------------------
// --- init: SquareAndScale_47
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[12]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[12]));
//--------------------------------
// --- init: SquareAndScale_48
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[13]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[13]));
//--------------------------------
// --- init: SquareAndScale_49
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[14]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[14]));
//--------------------------------
// --- init: SquareAndScale_50
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[15]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[15]));
//--------------------------------
// --- init: SquareAndScale_51
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[16]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[16]));
//--------------------------------
// --- init: SquareAndScale_52
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[17]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[17]));
//--------------------------------
// --- init: SquareAndScale_53
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[18]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[18]));
//--------------------------------
// --- init: SquareAndScale_54
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[19]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[19]));
//--------------------------------
// --- init: SquareAndScale_55
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[20]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[20]));
//--------------------------------
// --- init: SquareAndScale_56
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[21]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[21]));
//--------------------------------
// --- init: SquareAndScale_57
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[22]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[22]));
//--------------------------------
// --- init: SquareAndScale_58
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[23]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[23]));
//--------------------------------
// --- init: SquareAndScale_59
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[24]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[24]));
//--------------------------------
// --- init: SquareAndScale_60
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[25]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[25]));
//--------------------------------
// --- init: SquareAndScale_61
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[26]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[26]));
//--------------------------------
// --- init: SquareAndScale_62
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[27]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[27]));
//--------------------------------
// --- init: SquareAndScale_63
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[28]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[28]));
//--------------------------------
// --- init: SquareAndScale_64
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[29]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[29]));
//--------------------------------
// --- init: SquareAndScale_65
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[30]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[30]));
//--------------------------------
// --- init: SquareAndScale_66
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[31]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[31]));
//--------------------------------
// --- init: SquareAndScale_67
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[32]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[32]));
//--------------------------------
// --- init: SquareAndScale_68
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[33]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[33]));
//--------------------------------
// --- init: SquareAndScale_69
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[34]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[34]));
//--------------------------------
// --- init: SquareAndScale_70
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[35]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[35]));
//--------------------------------
// --- init: SquareAndScale_71
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[36]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[36]));
//--------------------------------
// --- init: SquareAndScale_72
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[37]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[37]));
//--------------------------------
// --- init: SquareAndScale_73
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[38]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[38]));
//--------------------------------
// --- init: SquareAndScale_74
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[39]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[39]));
//--------------------------------
// --- init: SquareAndScale_75
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[40]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[40]));
//--------------------------------
// --- init: SquareAndScale_76
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[41]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[41]));
//--------------------------------
// --- init: SquareAndScale_77
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[42]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[42]));
//--------------------------------
// --- init: SquareAndScale_78
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[43]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[43]));
//--------------------------------
// --- init: SquareAndScale_79
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[44]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[44]));
//--------------------------------
// --- init: SquareAndScale_80
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[45]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[45]));
//--------------------------------
// --- init: SquareAndScale_81
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[46]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[46]));
//--------------------------------
// --- init: SquareAndScale_82
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[47]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[47]));
//--------------------------------
// --- init: SquareAndScale_83
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[48]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[48]));
//--------------------------------
// --- init: SquareAndScale_84
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[49]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[49]));
//--------------------------------
// --- init: SquareAndScale_85
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[50]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[50]));
//--------------------------------
// --- init: SquareAndScale_86
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[51]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[51]));
//--------------------------------
// --- init: SquareAndScale_87
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[52]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[52]));
//--------------------------------
// --- init: SquareAndScale_88
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[53]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[53]));
//--------------------------------
// --- init: SquareAndScale_89
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[54]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[54]));
//--------------------------------
// --- init: SquareAndScale_90
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[55]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[55]));
//--------------------------------
// --- init: SquareAndScale_91
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[56]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[56]));
//--------------------------------
// --- init: SquareAndScale_92
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[57]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[57]));
//--------------------------------
// --- init: SquareAndScale_93
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[58]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[58]));
//--------------------------------
// --- init: SquareAndScale_94
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[59]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[59]));
//--------------------------------
// --- init: SquareAndScale_95
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[60]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[60]));
//--------------------------------
// --- init: SquareAndScale_96
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[61]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[61]));
//--------------------------------
// --- init: SquareAndScale_97
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[62]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[62]));
//--------------------------------
// --- init: SquareAndScale_98
	SquareAndScale(&(SplitJoin0_SquareAndScale_Fiss_99_101_split[63]), &(SplitJoin0_SquareAndScale_Fiss_99_101_join[63]));
//--------------------------------
// --- init: WEIGHTED_ROUND_ROBIN_Joiner_34
	
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30, pop_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[__iter_]));
	ENDFOR
//--------------------------------
// --- init: CFAR_gather_30
	 {
	CFAR_gather_30_s.pos = 0 ; 
}
	FOR(uint32_t, __iter_init_, 0, <, 55, __iter_init_++)
		CFAR_gather(&(WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30), &(CFAR_gather_30AnonFilter_a0_31));
	ENDFOR
//--------------------------------
// --- init: AnonFilter_a0_31
	FOR(uint32_t, __iter_init_, 0, <, 55, __iter_init_++)
		AnonFilter_a0(&(CFAR_gather_30AnonFilter_a0_31));
	ENDFOR
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		ComplexSource_27();
		WEIGHTED_ROUND_ROBIN_Splitter_33();
			SquareAndScale_35();
			SquareAndScale_36();
			SquareAndScale_37();
			SquareAndScale_38();
			SquareAndScale_39();
			SquareAndScale_40();
			SquareAndScale_41();
			SquareAndScale_42();
			SquareAndScale_43();
			SquareAndScale_44();
			SquareAndScale_45();
			SquareAndScale_46();
			SquareAndScale_47();
			SquareAndScale_48();
			SquareAndScale_49();
			SquareAndScale_50();
			SquareAndScale_51();
			SquareAndScale_52();
			SquareAndScale_53();
			SquareAndScale_54();
			SquareAndScale_55();
			SquareAndScale_56();
			SquareAndScale_57();
			SquareAndScale_58();
			SquareAndScale_59();
			SquareAndScale_60();
			SquareAndScale_61();
			SquareAndScale_62();
			SquareAndScale_63();
			SquareAndScale_64();
			SquareAndScale_65();
			SquareAndScale_66();
			SquareAndScale_67();
			SquareAndScale_68();
			SquareAndScale_69();
			SquareAndScale_70();
			SquareAndScale_71();
			SquareAndScale_72();
			SquareAndScale_73();
			SquareAndScale_74();
			SquareAndScale_75();
			SquareAndScale_76();
			SquareAndScale_77();
			SquareAndScale_78();
			SquareAndScale_79();
			SquareAndScale_80();
			SquareAndScale_81();
			SquareAndScale_82();
			SquareAndScale_83();
			SquareAndScale_84();
			SquareAndScale_85();
			SquareAndScale_86();
			SquareAndScale_87();
			SquareAndScale_88();
			SquareAndScale_89();
			SquareAndScale_90();
			SquareAndScale_91();
			SquareAndScale_92();
			SquareAndScale_93();
			SquareAndScale_94();
			SquareAndScale_95();
			SquareAndScale_96();
			SquareAndScale_97();
			SquareAndScale_98();
		WEIGHTED_ROUND_ROBIN_Joiner_34();
		CFAR_gather_30();
		AnonFilter_a0_31();
	ENDFOR
	return EXIT_SUCCESS;
}
