#include "HSDF-CFARtest_nocache.h"

buffer_float_t CFAR_gather_30AnonFilter_a0_31;
buffer_complex_t ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30;
buffer_float_t SplitJoin0_SquareAndScale_Fiss_99_101_join[64];
buffer_complex_t SplitJoin0_SquareAndScale_Fiss_99_101_split[64];


ComplexSource_27_t ComplexSource_27_s;
CFAR_gather_30_t CFAR_gather_30_s;

void ComplexSource_27() {
	FOR(int, i, 0,  < , 64, i++) {
		complex_t c = {
			.real = 0,
			.imag = 0
		};
		ComplexSource_27_s.theta = (ComplexSource_27_s.theta + 0.19634955) ; 
		c.real = ((((float) sin(ComplexSource_27_s.theta)) * (((float) cos(ComplexSource_27_s.theta)) + ((0.0 * ((float) sin(ComplexSource_27_s.theta))) - 0.0))) - (0.0 * (0.0 + (1.0 * ((float) sin(ComplexSource_27_s.theta)))))) ; 
		c.imag = ((((float) sin(ComplexSource_27_s.theta)) * (0.0 + (1.0 * ((float) sin(ComplexSource_27_s.theta))))) + (0.0 * (((float) cos(ComplexSource_27_s.theta)) + ((0.0 * ((float) sin(ComplexSource_27_s.theta))) - 0.0)))) ; 
		push_complex(&ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33, c) ; 
	}
	ENDFOR
}


void SquareAndScale_35() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[0]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[0], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_36() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[1]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[1], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_37() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[2]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[2], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_38() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[3]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[3], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_39() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[4]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[4], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_40() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[5]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[5], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_41() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[6]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[6], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_42() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[7]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[7], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_43() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[8]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[8], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_44() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[9]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[9], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_45() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[10]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[10], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_46() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[11]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[11], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_47() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[12]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[12], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_48() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[13]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[13], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_49() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[14]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[14], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_50() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[15]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[15], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_51() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[16]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[16], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_52() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[17]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[17], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_53() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[18]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[18], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_54() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[19]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[19], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_55() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[20]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[20], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_56() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[21]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[21], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_57() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[22]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[22], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_58() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[23]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[23], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_59() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[24]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[24], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_60() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[25]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[25], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_61() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[26]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[26], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_62() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[27]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[27], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_63() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[28]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[28], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_64() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[29]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[29], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_65() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[30]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[30], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_66() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[31]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[31], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_67() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[32]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[32], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_68() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[33]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[33], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_69() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[34]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[34], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_70() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[35]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[35], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_71() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[36]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[36], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_72() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[37]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[37], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_73() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[38]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[38], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_74() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[39]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[39], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_75() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[40]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[40], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_76() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[41]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[41], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_77() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[42]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[42], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_78() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[43]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[43], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_79() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[44]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[44], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_80() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[45]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[45], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_81() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[46]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[46], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_82() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[47]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[47], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_83() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[48]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[48], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_84() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[49]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[49], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_85() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[50]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[50], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_86() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[51]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[51], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_87() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[52]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[52], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_88() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[53]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[53], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_89() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[54]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[54], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_90() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[55]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[55], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_91() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[56]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[56], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_92() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[57]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[57], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_93() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[58]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[58], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_94() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[59]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[59], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_95() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[60]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[60], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_96() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[61]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[61], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_97() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[62]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[62], ((mag * mag) / 10.0)) ; 
}


void SquareAndScale_98() {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[63]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[63], ((mag * mag) / 10.0)) ; 
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

void CFAR_gather_30(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		float sum = 0.0;
		FOR4(int, i__conflict__1, 0, ((i__conflict__1 < 5) && (((i__conflict__1 + CFAR_gather_30_s.pos) - 5) >= 0)), __DEFLOOPBOUND__8__, i__conflict__1++) {
			sum = (sum + CFAR_gather_30_s.poke[((5 - i__conflict__1) - 1)]) ; 
		}
		ENDFOR
		FOR4(int, i__conflict__0, 5, ((i__conflict__0 <= 9) && ((i__conflict__0 + CFAR_gather_30_s.pos) < 64)), __DEFLOOPBOUND__9__, i__conflict__0++) {
			sum = (sum + peek_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30, i__conflict__0)) ; 
		}
		ENDFOR
		push_float(&CFAR_gather_30AnonFilter_a0_31, sum) ; 
		FOR(int, i, 1,  < , 9, i++) {
			CFAR_gather_30_s.poke[(i - 1)] = CFAR_gather_30_s.poke[i] ; 
		}
		ENDFOR
		CFAR_gather_30_s.poke[8] = pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30) ; 
		CFAR_gather_30_s.pos++ ; 
		if(CFAR_gather_30_s.pos == 64) {
			CFAR_gather_30_s.pos = 0 ; 
		}
	}
	ENDFOR
}

void AnonFilter_a0_31(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		printf("%.10f", pop_float(&CFAR_gather_30AnonFilter_a0_31));
		printf("\n");
	}
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
	 {
	FOR(int, i, 0,  < , 64, i++) {
		complex_t c = {
			.real = 0,
			.imag = 0
		};
		ComplexSource_27_s.theta = (ComplexSource_27_s.theta + 0.19634955) ; 
		c.real = ((((float) sin(ComplexSource_27_s.theta)) * (((float) cos(ComplexSource_27_s.theta)) + ((0.0 * ((float) sin(ComplexSource_27_s.theta))) - 0.0))) - (0.0 * (0.0 + (1.0 * ((float) sin(ComplexSource_27_s.theta)))))) ; 
		c.imag = ((((float) sin(ComplexSource_27_s.theta)) * (0.0 + (1.0 * ((float) sin(ComplexSource_27_s.theta))))) + (0.0 * (((float) cos(ComplexSource_27_s.theta)) + ((0.0 * ((float) sin(ComplexSource_27_s.theta))) - 0.0)))) ; 
		push_complex(&ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33, c) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: WEIGHTED_ROUND_ROBIN_Splitter_33
	
	FOR(uint32_t, __iter_, 0, <, 64, __iter_++)
		push_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[__iter_], pop_complex(&ComplexSource_27WEIGHTED_ROUND_ROBIN_Splitter_33));
	ENDFOR
//--------------------------------
// --- init: SquareAndScale_35
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[0]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[0], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_36
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[1]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[1], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_37
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[2]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[2], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_38
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[3]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[3], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_39
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[4]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[4], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_40
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[5]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[5], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_41
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[6]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[6], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_42
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[7]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[7], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_43
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[8]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[8], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_44
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[9]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[9], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_45
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[10]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[10], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_46
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[11]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[11], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_47
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[12]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[12], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_48
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[13]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[13], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_49
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[14]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[14], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_50
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[15]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[15], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_51
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[16]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[16], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_52
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[17]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[17], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_53
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[18]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[18], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_54
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[19]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[19], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_55
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[20]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[20], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_56
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[21]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[21], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_57
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[22]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[22], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_58
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[23]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[23], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_59
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[24]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[24], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_60
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[25]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[25], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_61
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[26]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[26], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_62
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[27]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[27], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_63
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[28]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[28], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_64
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[29]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[29], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_65
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[30]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[30], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_66
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[31]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[31], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_67
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[32]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[32], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_68
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[33]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[33], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_69
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[34]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[34], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_70
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[35]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[35], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_71
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[36]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[36], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_72
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[37]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[37], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_73
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[38]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[38], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_74
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[39]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[39], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_75
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[40]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[40], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_76
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[41]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[41], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_77
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[42]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[42], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_78
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[43]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[43], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_79
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[44]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[44], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_80
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[45]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[45], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_81
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[46]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[46], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_82
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[47]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[47], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_83
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[48]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[48], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_84
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[49]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[49], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_85
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[50]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[50], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_86
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[51]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[51], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_87
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[52]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[52], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_88
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[53]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[53], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_89
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[54]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[54], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_90
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[55]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[55], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_91
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[56]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[56], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_92
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[57]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[57], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_93
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[58]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[58], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_94
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[59]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[59], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_95
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[60]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[60], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_96
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[61]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[61], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_97
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[62]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[62], ((mag * mag) / 10.0)) ; 
}
//--------------------------------
// --- init: SquareAndScale_98
	 {
	complex_t c = ((complex_t) pop_complex(&SplitJoin0_SquareAndScale_Fiss_99_101_split[63]));
	float mag = 0.0;
	mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
	push_float(&SplitJoin0_SquareAndScale_Fiss_99_101_join[63], ((mag * mag) / 10.0)) ; 
}
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
	FOR(uint32_t, __iter_init_, 0, <, 55, __iter_init_++) {
		float sum = 0.0;
		FOR4(int, i__conflict__1, 0, ((i__conflict__1 < 5) && (((i__conflict__1 + CFAR_gather_30_s.pos) - 5) >= 0)), __DEFLOOPBOUND__10__, i__conflict__1++) {
			sum = (sum + CFAR_gather_30_s.poke[((5 - i__conflict__1) - 1)]) ; 
		}
		ENDFOR
		FOR4(int, i__conflict__0, 5, ((i__conflict__0 <= 9) && ((i__conflict__0 + CFAR_gather_30_s.pos) < 64)), __DEFLOOPBOUND__11__, i__conflict__0++) {
			sum = (sum + peek_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30, i__conflict__0)) ; 
		}
		ENDFOR
		push_float(&CFAR_gather_30AnonFilter_a0_31, sum) ; 
		FOR(int, i, 1,  < , 9, i++) {
			CFAR_gather_30_s.poke[(i - 1)] = CFAR_gather_30_s.poke[i] ; 
		}
		ENDFOR
		CFAR_gather_30_s.poke[8] = pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_34CFAR_gather_30) ; 
		CFAR_gather_30_s.pos++ ; 
		if(CFAR_gather_30_s.pos == 64) {
			CFAR_gather_30_s.pos = 0 ; 
		}
	}
	ENDFOR
//--------------------------------
// --- init: AnonFilter_a0_31
	FOR(uint32_t, __iter_init_, 0, <, 55, __iter_init_++) {
		printf("%.10f", pop_float(&CFAR_gather_30AnonFilter_a0_31));
		printf("\n");
	}
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
