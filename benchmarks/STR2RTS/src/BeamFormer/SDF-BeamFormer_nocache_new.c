#include "sim_api.h"
#include "SDF-BeamFormer_nocache.h"

buffer_float_t Magnitude_109FloatPrinter_110;
buffer_float_t BeamFirFilter_60BeamFirFilter_61;
buffer_float_t BeamFirFilter_100BeamFirFilter_101;
buffer_float_t BeamFirFilter_68BeamFirFilter_69;
buffer_float_t InputGenerate_67BeamFirFilter_68;
buffer_float_t BeamFirFilter_104BeamFirFilter_105;
buffer_float_t InputGenerate_75BeamFirFilter_76;
buffer_float_t BeamForm_107BeamFirFilter_108;
buffer_float_t BeamFirFilter_92BeamFirFilter_93;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_join[4];
buffer_float_t InputGenerate_99BeamFirFilter_100;
buffer_float_t InputGenerate_79BeamFirFilter_80;
buffer_float_t BeamFirFilter_80BeamFirFilter_81;
buffer_float_t BeamFirFilter_84BeamFirFilter_85;
buffer_float_t BeamFirFilter_123Magnitude_124;
buffer_float_t BeamFirFilter_76BeamFirFilter_77;
buffer_float_t BeamFirFilter_113Magnitude_114;
buffer_float_t Magnitude_124FloatPrinter_125;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_127DUPLICATE_Splitter_128;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[4];
buffer_float_t InputGenerate_71BeamFirFilter_72;
buffer_float_t BeamForm_112BeamFirFilter_113;
buffer_float_t Magnitude_114FloatPrinter_115;
buffer_float_t BeamFirFilter_118Magnitude_119;
buffer_float_t BeamFirFilter_64BeamFirFilter_65;
buffer_float_t BeamFirFilter_108Magnitude_109;
buffer_float_t BeamForm_117BeamFirFilter_118;
buffer_float_t InputGenerate_63BeamFirFilter_64;
buffer_float_t InputGenerate_103BeamFirFilter_104;
buffer_float_t BeamFirFilter_72BeamFirFilter_73;
buffer_float_t InputGenerate_59BeamFirFilter_60;
buffer_float_t InputGenerate_95BeamFirFilter_96;
buffer_float_t Magnitude_119FloatPrinter_120;
buffer_float_t InputGenerate_87BeamFirFilter_88;
buffer_float_t BeamFirFilter_88BeamFirFilter_89;
buffer_float_t InputGenerate_83BeamFirFilter_84;
buffer_float_t BeamForm_122BeamFirFilter_123;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_split[12];
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[12];
buffer_float_t BeamFirFilter_96BeamFirFilter_97;
buffer_float_t InputGenerate_91BeamFirFilter_92;


InputGenerate_59_t InputGenerate_59_s;
BeamFirFilter_60_t BeamFirFilter_60_s;
BeamFirFilter_60_t BeamFirFilter_61_s;
InputGenerate_59_t InputGenerate_63_s;
BeamFirFilter_60_t BeamFirFilter_64_s;
BeamFirFilter_60_t BeamFirFilter_65_s;
InputGenerate_59_t InputGenerate_67_s;
BeamFirFilter_60_t BeamFirFilter_68_s;
BeamFirFilter_60_t BeamFirFilter_69_s;
InputGenerate_59_t InputGenerate_71_s;
BeamFirFilter_60_t BeamFirFilter_72_s;
BeamFirFilter_60_t BeamFirFilter_73_s;
InputGenerate_59_t InputGenerate_75_s;
BeamFirFilter_60_t BeamFirFilter_76_s;
BeamFirFilter_60_t BeamFirFilter_77_s;
InputGenerate_59_t InputGenerate_79_s;
BeamFirFilter_60_t BeamFirFilter_80_s;
BeamFirFilter_60_t BeamFirFilter_81_s;
InputGenerate_59_t InputGenerate_83_s;
BeamFirFilter_60_t BeamFirFilter_84_s;
BeamFirFilter_60_t BeamFirFilter_85_s;
InputGenerate_59_t InputGenerate_87_s;
BeamFirFilter_60_t BeamFirFilter_88_s;
BeamFirFilter_60_t BeamFirFilter_89_s;
InputGenerate_59_t InputGenerate_91_s;
BeamFirFilter_60_t BeamFirFilter_92_s;
BeamFirFilter_60_t BeamFirFilter_93_s;
InputGenerate_59_t InputGenerate_95_s;
BeamFirFilter_60_t BeamFirFilter_96_s;
BeamFirFilter_60_t BeamFirFilter_97_s;
InputGenerate_59_t InputGenerate_99_s;
BeamFirFilter_60_t BeamFirFilter_100_s;
BeamFirFilter_60_t BeamFirFilter_101_s;
InputGenerate_59_t InputGenerate_103_s;
BeamFirFilter_60_t BeamFirFilter_104_s;
BeamFirFilter_60_t BeamFirFilter_105_s;
BeamForm_107_t BeamForm_107_s;
BeamFirFilter_108_t BeamFirFilter_108_s;
BeamForm_107_t BeamForm_112_s;
BeamFirFilter_108_t BeamFirFilter_113_s;
BeamForm_107_t BeamForm_117_s;
BeamFirFilter_108_t BeamFirFilter_118_s;
BeamForm_107_t BeamForm_122_s;
BeamFirFilter_108_t BeamFirFilter_123_s;

void InputGenerate_59(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_59_s.curSample == 256)) {
			push_float(&InputGenerate_59BeamFirFilter_60, ((float) sqrt((InputGenerate_59_s.curSample * 0)))) ; 
			push_float(&InputGenerate_59BeamFirFilter_60, (((float) sqrt((InputGenerate_59_s.curSample * 0))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_59BeamFirFilter_60, -((float) sqrt((InputGenerate_59_s.curSample * 0)))) ; 
			push_float(&InputGenerate_59BeamFirFilter_60, -(((float) sqrt((InputGenerate_59_s.curSample * 0))) + 1.0)) ; 
		}
		InputGenerate_59_s.curSample++ ; 
		if((InputGenerate_59_s.curSample >= 1024)) {
			InputGenerate_59_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_60(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_60_s.realBuffer[(63 - BeamFirFilter_60_s.pos)] = pop_float(&InputGenerate_59BeamFirFilter_60) ; 
		BeamFirFilter_60_s.imagBuffer[(63 - BeamFirFilter_60_s.pos)] = pop_float(&InputGenerate_59BeamFirFilter_60) ; 
		modPos = (63 - BeamFirFilter_60_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_60_s.realBuffer[modPos] * BeamFirFilter_60_s.real_weight[i]) + (BeamFirFilter_60_s.imagBuffer[modPos] * BeamFirFilter_60_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_60_s.imagBuffer[modPos] * BeamFirFilter_60_s.real_weight[i]) + (BeamFirFilter_60_s.realBuffer[modPos] * BeamFirFilter_60_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_60_s.pos = ((BeamFirFilter_60_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_60BeamFirFilter_61, real_curr) ; 
		push_float(&BeamFirFilter_60BeamFirFilter_61, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_59BeamFirFilter_60) ; 
		}
		ENDFOR
		BeamFirFilter_60_s.count = (BeamFirFilter_60_s.count + 1) ; 
		if(BeamFirFilter_60_s.count == 1024) {
			BeamFirFilter_60_s.count = 0 ; 
			BeamFirFilter_60_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_60_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_60_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_61() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_61_s.realBuffer[(63 - BeamFirFilter_61_s.pos)] = pop_float(&BeamFirFilter_60BeamFirFilter_61) ; 
	BeamFirFilter_61_s.imagBuffer[(63 - BeamFirFilter_61_s.pos)] = pop_float(&BeamFirFilter_60BeamFirFilter_61) ; 
	modPos = (63 - BeamFirFilter_61_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_61_s.realBuffer[modPos] * BeamFirFilter_61_s.real_weight[i]) + (BeamFirFilter_61_s.imagBuffer[modPos] * BeamFirFilter_61_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_61_s.imagBuffer[modPos] * BeamFirFilter_61_s.real_weight[i]) + (BeamFirFilter_61_s.realBuffer[modPos] * BeamFirFilter_61_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_61_s.pos = ((BeamFirFilter_61_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[0], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[0], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_60BeamFirFilter_61) ; 
	}
	ENDFOR
	BeamFirFilter_61_s.count = (BeamFirFilter_61_s.count + 2) ; 
	if(BeamFirFilter_61_s.count == 1024) {
		BeamFirFilter_61_s.count = 0 ; 
		BeamFirFilter_61_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_61_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_61_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_63(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((TRUE && InputGenerate_63_s.curSample == 256)) {
			push_float(&InputGenerate_63BeamFirFilter_64, ((float) sqrt((InputGenerate_63_s.curSample * 1)))) ; 
			push_float(&InputGenerate_63BeamFirFilter_64, (((float) sqrt((InputGenerate_63_s.curSample * 1))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_63BeamFirFilter_64, -((float) sqrt((InputGenerate_63_s.curSample * 1)))) ; 
			push_float(&InputGenerate_63BeamFirFilter_64, -(((float) sqrt((InputGenerate_63_s.curSample * 1))) + 1.0)) ; 
		}
		InputGenerate_63_s.curSample++ ; 
		if((InputGenerate_63_s.curSample >= 1024)) {
			InputGenerate_63_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_64(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_64_s.realBuffer[(63 - BeamFirFilter_64_s.pos)] = pop_float(&InputGenerate_63BeamFirFilter_64) ; 
		BeamFirFilter_64_s.imagBuffer[(63 - BeamFirFilter_64_s.pos)] = pop_float(&InputGenerate_63BeamFirFilter_64) ; 
		modPos = (63 - BeamFirFilter_64_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_64_s.realBuffer[modPos] * BeamFirFilter_64_s.real_weight[i]) + (BeamFirFilter_64_s.imagBuffer[modPos] * BeamFirFilter_64_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_64_s.imagBuffer[modPos] * BeamFirFilter_64_s.real_weight[i]) + (BeamFirFilter_64_s.realBuffer[modPos] * BeamFirFilter_64_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_64_s.pos = ((BeamFirFilter_64_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_64BeamFirFilter_65, real_curr) ; 
		push_float(&BeamFirFilter_64BeamFirFilter_65, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_63BeamFirFilter_64) ; 
		}
		ENDFOR
		BeamFirFilter_64_s.count = (BeamFirFilter_64_s.count + 1) ; 
		if(BeamFirFilter_64_s.count == 1024) {
			BeamFirFilter_64_s.count = 0 ; 
			BeamFirFilter_64_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_64_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_64_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_65() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_65_s.realBuffer[(63 - BeamFirFilter_65_s.pos)] = pop_float(&BeamFirFilter_64BeamFirFilter_65) ; 
	BeamFirFilter_65_s.imagBuffer[(63 - BeamFirFilter_65_s.pos)] = pop_float(&BeamFirFilter_64BeamFirFilter_65) ; 
	modPos = (63 - BeamFirFilter_65_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_65_s.realBuffer[modPos] * BeamFirFilter_65_s.real_weight[i]) + (BeamFirFilter_65_s.imagBuffer[modPos] * BeamFirFilter_65_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_65_s.imagBuffer[modPos] * BeamFirFilter_65_s.real_weight[i]) + (BeamFirFilter_65_s.realBuffer[modPos] * BeamFirFilter_65_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_65_s.pos = ((BeamFirFilter_65_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[1], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[1], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_64BeamFirFilter_65) ; 
	}
	ENDFOR
	BeamFirFilter_65_s.count = (BeamFirFilter_65_s.count + 2) ; 
	if(BeamFirFilter_65_s.count == 1024) {
		BeamFirFilter_65_s.count = 0 ; 
		BeamFirFilter_65_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_65_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_65_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_67(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_67_s.curSample == 256)) {
			push_float(&InputGenerate_67BeamFirFilter_68, ((float) sqrt((InputGenerate_67_s.curSample * 2)))) ; 
			push_float(&InputGenerate_67BeamFirFilter_68, (((float) sqrt((InputGenerate_67_s.curSample * 2))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_67BeamFirFilter_68, -((float) sqrt((InputGenerate_67_s.curSample * 2)))) ; 
			push_float(&InputGenerate_67BeamFirFilter_68, -(((float) sqrt((InputGenerate_67_s.curSample * 2))) + 1.0)) ; 
		}
		InputGenerate_67_s.curSample++ ; 
		if((InputGenerate_67_s.curSample >= 1024)) {
			InputGenerate_67_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_68(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_68_s.realBuffer[(63 - BeamFirFilter_68_s.pos)] = pop_float(&InputGenerate_67BeamFirFilter_68) ; 
		BeamFirFilter_68_s.imagBuffer[(63 - BeamFirFilter_68_s.pos)] = pop_float(&InputGenerate_67BeamFirFilter_68) ; 
		modPos = (63 - BeamFirFilter_68_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_68_s.realBuffer[modPos] * BeamFirFilter_68_s.real_weight[i]) + (BeamFirFilter_68_s.imagBuffer[modPos] * BeamFirFilter_68_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_68_s.imagBuffer[modPos] * BeamFirFilter_68_s.real_weight[i]) + (BeamFirFilter_68_s.realBuffer[modPos] * BeamFirFilter_68_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_68_s.pos = ((BeamFirFilter_68_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_68BeamFirFilter_69, real_curr) ; 
		push_float(&BeamFirFilter_68BeamFirFilter_69, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_67BeamFirFilter_68) ; 
		}
		ENDFOR
		BeamFirFilter_68_s.count = (BeamFirFilter_68_s.count + 1) ; 
		if(BeamFirFilter_68_s.count == 1024) {
			BeamFirFilter_68_s.count = 0 ; 
			BeamFirFilter_68_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_68_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_68_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_69() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_69_s.realBuffer[(63 - BeamFirFilter_69_s.pos)] = pop_float(&BeamFirFilter_68BeamFirFilter_69) ; 
	BeamFirFilter_69_s.imagBuffer[(63 - BeamFirFilter_69_s.pos)] = pop_float(&BeamFirFilter_68BeamFirFilter_69) ; 
	modPos = (63 - BeamFirFilter_69_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_69_s.realBuffer[modPos] * BeamFirFilter_69_s.real_weight[i]) + (BeamFirFilter_69_s.imagBuffer[modPos] * BeamFirFilter_69_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_69_s.imagBuffer[modPos] * BeamFirFilter_69_s.real_weight[i]) + (BeamFirFilter_69_s.realBuffer[modPos] * BeamFirFilter_69_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_69_s.pos = ((BeamFirFilter_69_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[2], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[2], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_68BeamFirFilter_69) ; 
	}
	ENDFOR
	BeamFirFilter_69_s.count = (BeamFirFilter_69_s.count + 2) ; 
	if(BeamFirFilter_69_s.count == 1024) {
		BeamFirFilter_69_s.count = 0 ; 
		BeamFirFilter_69_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_69_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_69_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_71(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_71_s.curSample == 256)) {
			push_float(&InputGenerate_71BeamFirFilter_72, ((float) sqrt((InputGenerate_71_s.curSample * 3)))) ; 
			push_float(&InputGenerate_71BeamFirFilter_72, (((float) sqrt((InputGenerate_71_s.curSample * 3))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_71BeamFirFilter_72, -((float) sqrt((InputGenerate_71_s.curSample * 3)))) ; 
			push_float(&InputGenerate_71BeamFirFilter_72, -(((float) sqrt((InputGenerate_71_s.curSample * 3))) + 1.0)) ; 
		}
		InputGenerate_71_s.curSample++ ; 
		if((InputGenerate_71_s.curSample >= 1024)) {
			InputGenerate_71_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_72(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_72_s.realBuffer[(63 - BeamFirFilter_72_s.pos)] = pop_float(&InputGenerate_71BeamFirFilter_72) ; 
		BeamFirFilter_72_s.imagBuffer[(63 - BeamFirFilter_72_s.pos)] = pop_float(&InputGenerate_71BeamFirFilter_72) ; 
		modPos = (63 - BeamFirFilter_72_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_72_s.realBuffer[modPos] * BeamFirFilter_72_s.real_weight[i]) + (BeamFirFilter_72_s.imagBuffer[modPos] * BeamFirFilter_72_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_72_s.imagBuffer[modPos] * BeamFirFilter_72_s.real_weight[i]) + (BeamFirFilter_72_s.realBuffer[modPos] * BeamFirFilter_72_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_72_s.pos = ((BeamFirFilter_72_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_72BeamFirFilter_73, real_curr) ; 
		push_float(&BeamFirFilter_72BeamFirFilter_73, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_71BeamFirFilter_72) ; 
		}
		ENDFOR
		BeamFirFilter_72_s.count = (BeamFirFilter_72_s.count + 1) ; 
		if(BeamFirFilter_72_s.count == 1024) {
			BeamFirFilter_72_s.count = 0 ; 
			BeamFirFilter_72_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_72_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_72_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_73() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_73_s.realBuffer[(63 - BeamFirFilter_73_s.pos)] = pop_float(&BeamFirFilter_72BeamFirFilter_73) ; 
	BeamFirFilter_73_s.imagBuffer[(63 - BeamFirFilter_73_s.pos)] = pop_float(&BeamFirFilter_72BeamFirFilter_73) ; 
	modPos = (63 - BeamFirFilter_73_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_73_s.realBuffer[modPos] * BeamFirFilter_73_s.real_weight[i]) + (BeamFirFilter_73_s.imagBuffer[modPos] * BeamFirFilter_73_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_73_s.imagBuffer[modPos] * BeamFirFilter_73_s.real_weight[i]) + (BeamFirFilter_73_s.realBuffer[modPos] * BeamFirFilter_73_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_73_s.pos = ((BeamFirFilter_73_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[3], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[3], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_72BeamFirFilter_73) ; 
	}
	ENDFOR
	BeamFirFilter_73_s.count = (BeamFirFilter_73_s.count + 2) ; 
	if(BeamFirFilter_73_s.count == 1024) {
		BeamFirFilter_73_s.count = 0 ; 
		BeamFirFilter_73_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_73_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_73_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_75(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_75_s.curSample == 256)) {
			push_float(&InputGenerate_75BeamFirFilter_76, ((float) sqrt((InputGenerate_75_s.curSample * 4)))) ; 
			push_float(&InputGenerate_75BeamFirFilter_76, (((float) sqrt((InputGenerate_75_s.curSample * 4))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_75BeamFirFilter_76, -((float) sqrt((InputGenerate_75_s.curSample * 4)))) ; 
			push_float(&InputGenerate_75BeamFirFilter_76, -(((float) sqrt((InputGenerate_75_s.curSample * 4))) + 1.0)) ; 
		}
		InputGenerate_75_s.curSample++ ; 
		if((InputGenerate_75_s.curSample >= 1024)) {
			InputGenerate_75_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_76(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_76_s.realBuffer[(63 - BeamFirFilter_76_s.pos)] = pop_float(&InputGenerate_75BeamFirFilter_76) ; 
		BeamFirFilter_76_s.imagBuffer[(63 - BeamFirFilter_76_s.pos)] = pop_float(&InputGenerate_75BeamFirFilter_76) ; 
		modPos = (63 - BeamFirFilter_76_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_76_s.realBuffer[modPos] * BeamFirFilter_76_s.real_weight[i]) + (BeamFirFilter_76_s.imagBuffer[modPos] * BeamFirFilter_76_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_76_s.imagBuffer[modPos] * BeamFirFilter_76_s.real_weight[i]) + (BeamFirFilter_76_s.realBuffer[modPos] * BeamFirFilter_76_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_76_s.pos = ((BeamFirFilter_76_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_76BeamFirFilter_77, real_curr) ; 
		push_float(&BeamFirFilter_76BeamFirFilter_77, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_75BeamFirFilter_76) ; 
		}
		ENDFOR
		BeamFirFilter_76_s.count = (BeamFirFilter_76_s.count + 1) ; 
		if(BeamFirFilter_76_s.count == 1024) {
			BeamFirFilter_76_s.count = 0 ; 
			BeamFirFilter_76_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_76_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_76_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_77() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_77_s.realBuffer[(63 - BeamFirFilter_77_s.pos)] = pop_float(&BeamFirFilter_76BeamFirFilter_77) ; 
	BeamFirFilter_77_s.imagBuffer[(63 - BeamFirFilter_77_s.pos)] = pop_float(&BeamFirFilter_76BeamFirFilter_77) ; 
	modPos = (63 - BeamFirFilter_77_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_77_s.realBuffer[modPos] * BeamFirFilter_77_s.real_weight[i]) + (BeamFirFilter_77_s.imagBuffer[modPos] * BeamFirFilter_77_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_77_s.imagBuffer[modPos] * BeamFirFilter_77_s.real_weight[i]) + (BeamFirFilter_77_s.realBuffer[modPos] * BeamFirFilter_77_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_77_s.pos = ((BeamFirFilter_77_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[4], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[4], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_76BeamFirFilter_77) ; 
	}
	ENDFOR
	BeamFirFilter_77_s.count = (BeamFirFilter_77_s.count + 2) ; 
	if(BeamFirFilter_77_s.count == 1024) {
		BeamFirFilter_77_s.count = 0 ; 
		BeamFirFilter_77_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_77_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_77_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_79(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_79_s.curSample == 256)) {
			push_float(&InputGenerate_79BeamFirFilter_80, ((float) sqrt((InputGenerate_79_s.curSample * 5)))) ; 
			push_float(&InputGenerate_79BeamFirFilter_80, (((float) sqrt((InputGenerate_79_s.curSample * 5))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_79BeamFirFilter_80, -((float) sqrt((InputGenerate_79_s.curSample * 5)))) ; 
			push_float(&InputGenerate_79BeamFirFilter_80, -(((float) sqrt((InputGenerate_79_s.curSample * 5))) + 1.0)) ; 
		}
		InputGenerate_79_s.curSample++ ; 
		if((InputGenerate_79_s.curSample >= 1024)) {
			InputGenerate_79_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_80(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_80_s.realBuffer[(63 - BeamFirFilter_80_s.pos)] = pop_float(&InputGenerate_79BeamFirFilter_80) ; 
		BeamFirFilter_80_s.imagBuffer[(63 - BeamFirFilter_80_s.pos)] = pop_float(&InputGenerate_79BeamFirFilter_80) ; 
		modPos = (63 - BeamFirFilter_80_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_80_s.realBuffer[modPos] * BeamFirFilter_80_s.real_weight[i]) + (BeamFirFilter_80_s.imagBuffer[modPos] * BeamFirFilter_80_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_80_s.imagBuffer[modPos] * BeamFirFilter_80_s.real_weight[i]) + (BeamFirFilter_80_s.realBuffer[modPos] * BeamFirFilter_80_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_80_s.pos = ((BeamFirFilter_80_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_80BeamFirFilter_81, real_curr) ; 
		push_float(&BeamFirFilter_80BeamFirFilter_81, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_79BeamFirFilter_80) ; 
		}
		ENDFOR
		BeamFirFilter_80_s.count = (BeamFirFilter_80_s.count + 1) ; 
		if(BeamFirFilter_80_s.count == 1024) {
			BeamFirFilter_80_s.count = 0 ; 
			BeamFirFilter_80_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_80_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_80_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_81() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_81_s.realBuffer[(63 - BeamFirFilter_81_s.pos)] = pop_float(&BeamFirFilter_80BeamFirFilter_81) ; 
	BeamFirFilter_81_s.imagBuffer[(63 - BeamFirFilter_81_s.pos)] = pop_float(&BeamFirFilter_80BeamFirFilter_81) ; 
	modPos = (63 - BeamFirFilter_81_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_81_s.realBuffer[modPos] * BeamFirFilter_81_s.real_weight[i]) + (BeamFirFilter_81_s.imagBuffer[modPos] * BeamFirFilter_81_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_81_s.imagBuffer[modPos] * BeamFirFilter_81_s.real_weight[i]) + (BeamFirFilter_81_s.realBuffer[modPos] * BeamFirFilter_81_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_81_s.pos = ((BeamFirFilter_81_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[5], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[5], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_80BeamFirFilter_81) ; 
	}
	ENDFOR
	BeamFirFilter_81_s.count = (BeamFirFilter_81_s.count + 2) ; 
	if(BeamFirFilter_81_s.count == 1024) {
		BeamFirFilter_81_s.count = 0 ; 
		BeamFirFilter_81_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_81_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_81_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_83(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_83_s.curSample == 256)) {
			push_float(&InputGenerate_83BeamFirFilter_84, ((float) sqrt((InputGenerate_83_s.curSample * 6)))) ; 
			push_float(&InputGenerate_83BeamFirFilter_84, (((float) sqrt((InputGenerate_83_s.curSample * 6))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_83BeamFirFilter_84, -((float) sqrt((InputGenerate_83_s.curSample * 6)))) ; 
			push_float(&InputGenerate_83BeamFirFilter_84, -(((float) sqrt((InputGenerate_83_s.curSample * 6))) + 1.0)) ; 
		}
		InputGenerate_83_s.curSample++ ; 
		if((InputGenerate_83_s.curSample >= 1024)) {
			InputGenerate_83_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_84(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_84_s.realBuffer[(63 - BeamFirFilter_84_s.pos)] = pop_float(&InputGenerate_83BeamFirFilter_84) ; 
		BeamFirFilter_84_s.imagBuffer[(63 - BeamFirFilter_84_s.pos)] = pop_float(&InputGenerate_83BeamFirFilter_84) ; 
		modPos = (63 - BeamFirFilter_84_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_84_s.realBuffer[modPos] * BeamFirFilter_84_s.real_weight[i]) + (BeamFirFilter_84_s.imagBuffer[modPos] * BeamFirFilter_84_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_84_s.imagBuffer[modPos] * BeamFirFilter_84_s.real_weight[i]) + (BeamFirFilter_84_s.realBuffer[modPos] * BeamFirFilter_84_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_84_s.pos = ((BeamFirFilter_84_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_84BeamFirFilter_85, real_curr) ; 
		push_float(&BeamFirFilter_84BeamFirFilter_85, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_83BeamFirFilter_84) ; 
		}
		ENDFOR
		BeamFirFilter_84_s.count = (BeamFirFilter_84_s.count + 1) ; 
		if(BeamFirFilter_84_s.count == 1024) {
			BeamFirFilter_84_s.count = 0 ; 
			BeamFirFilter_84_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_84_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_84_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_85() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_85_s.realBuffer[(63 - BeamFirFilter_85_s.pos)] = pop_float(&BeamFirFilter_84BeamFirFilter_85) ; 
	BeamFirFilter_85_s.imagBuffer[(63 - BeamFirFilter_85_s.pos)] = pop_float(&BeamFirFilter_84BeamFirFilter_85) ; 
	modPos = (63 - BeamFirFilter_85_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_85_s.realBuffer[modPos] * BeamFirFilter_85_s.real_weight[i]) + (BeamFirFilter_85_s.imagBuffer[modPos] * BeamFirFilter_85_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_85_s.imagBuffer[modPos] * BeamFirFilter_85_s.real_weight[i]) + (BeamFirFilter_85_s.realBuffer[modPos] * BeamFirFilter_85_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_85_s.pos = ((BeamFirFilter_85_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[6], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[6], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_84BeamFirFilter_85) ; 
	}
	ENDFOR
	BeamFirFilter_85_s.count = (BeamFirFilter_85_s.count + 2) ; 
	if(BeamFirFilter_85_s.count == 1024) {
		BeamFirFilter_85_s.count = 0 ; 
		BeamFirFilter_85_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_85_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_85_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_87(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_87_s.curSample == 256)) {
			push_float(&InputGenerate_87BeamFirFilter_88, ((float) sqrt((InputGenerate_87_s.curSample * 7)))) ; 
			push_float(&InputGenerate_87BeamFirFilter_88, (((float) sqrt((InputGenerate_87_s.curSample * 7))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_87BeamFirFilter_88, -((float) sqrt((InputGenerate_87_s.curSample * 7)))) ; 
			push_float(&InputGenerate_87BeamFirFilter_88, -(((float) sqrt((InputGenerate_87_s.curSample * 7))) + 1.0)) ; 
		}
		InputGenerate_87_s.curSample++ ; 
		if((InputGenerate_87_s.curSample >= 1024)) {
			InputGenerate_87_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_88(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_88_s.realBuffer[(63 - BeamFirFilter_88_s.pos)] = pop_float(&InputGenerate_87BeamFirFilter_88) ; 
		BeamFirFilter_88_s.imagBuffer[(63 - BeamFirFilter_88_s.pos)] = pop_float(&InputGenerate_87BeamFirFilter_88) ; 
		modPos = (63 - BeamFirFilter_88_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_88_s.realBuffer[modPos] * BeamFirFilter_88_s.real_weight[i]) + (BeamFirFilter_88_s.imagBuffer[modPos] * BeamFirFilter_88_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_88_s.imagBuffer[modPos] * BeamFirFilter_88_s.real_weight[i]) + (BeamFirFilter_88_s.realBuffer[modPos] * BeamFirFilter_88_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_88_s.pos = ((BeamFirFilter_88_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_88BeamFirFilter_89, real_curr) ; 
		push_float(&BeamFirFilter_88BeamFirFilter_89, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_87BeamFirFilter_88) ; 
		}
		ENDFOR
		BeamFirFilter_88_s.count = (BeamFirFilter_88_s.count + 1) ; 
		if(BeamFirFilter_88_s.count == 1024) {
			BeamFirFilter_88_s.count = 0 ; 
			BeamFirFilter_88_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_88_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_88_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_89() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_89_s.realBuffer[(63 - BeamFirFilter_89_s.pos)] = pop_float(&BeamFirFilter_88BeamFirFilter_89) ; 
	BeamFirFilter_89_s.imagBuffer[(63 - BeamFirFilter_89_s.pos)] = pop_float(&BeamFirFilter_88BeamFirFilter_89) ; 
	modPos = (63 - BeamFirFilter_89_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_89_s.realBuffer[modPos] * BeamFirFilter_89_s.real_weight[i]) + (BeamFirFilter_89_s.imagBuffer[modPos] * BeamFirFilter_89_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_89_s.imagBuffer[modPos] * BeamFirFilter_89_s.real_weight[i]) + (BeamFirFilter_89_s.realBuffer[modPos] * BeamFirFilter_89_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_89_s.pos = ((BeamFirFilter_89_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[7], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[7], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_88BeamFirFilter_89) ; 
	}
	ENDFOR
	BeamFirFilter_89_s.count = (BeamFirFilter_89_s.count + 2) ; 
	if(BeamFirFilter_89_s.count == 1024) {
		BeamFirFilter_89_s.count = 0 ; 
		BeamFirFilter_89_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_89_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_89_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_91(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_91_s.curSample == 256)) {
			push_float(&InputGenerate_91BeamFirFilter_92, ((float) sqrt((InputGenerate_91_s.curSample * 8)))) ; 
			push_float(&InputGenerate_91BeamFirFilter_92, (((float) sqrt((InputGenerate_91_s.curSample * 8))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_91BeamFirFilter_92, -((float) sqrt((InputGenerate_91_s.curSample * 8)))) ; 
			push_float(&InputGenerate_91BeamFirFilter_92, -(((float) sqrt((InputGenerate_91_s.curSample * 8))) + 1.0)) ; 
		}
		InputGenerate_91_s.curSample++ ; 
		if((InputGenerate_91_s.curSample >= 1024)) {
			InputGenerate_91_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_92(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_92_s.realBuffer[(63 - BeamFirFilter_92_s.pos)] = pop_float(&InputGenerate_91BeamFirFilter_92) ; 
		BeamFirFilter_92_s.imagBuffer[(63 - BeamFirFilter_92_s.pos)] = pop_float(&InputGenerate_91BeamFirFilter_92) ; 
		modPos = (63 - BeamFirFilter_92_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_92_s.realBuffer[modPos] * BeamFirFilter_92_s.real_weight[i]) + (BeamFirFilter_92_s.imagBuffer[modPos] * BeamFirFilter_92_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_92_s.imagBuffer[modPos] * BeamFirFilter_92_s.real_weight[i]) + (BeamFirFilter_92_s.realBuffer[modPos] * BeamFirFilter_92_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_92_s.pos = ((BeamFirFilter_92_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_92BeamFirFilter_93, real_curr) ; 
		push_float(&BeamFirFilter_92BeamFirFilter_93, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_91BeamFirFilter_92) ; 
		}
		ENDFOR
		BeamFirFilter_92_s.count = (BeamFirFilter_92_s.count + 1) ; 
		if(BeamFirFilter_92_s.count == 1024) {
			BeamFirFilter_92_s.count = 0 ; 
			BeamFirFilter_92_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_92_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_92_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_93() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_93_s.realBuffer[(63 - BeamFirFilter_93_s.pos)] = pop_float(&BeamFirFilter_92BeamFirFilter_93) ; 
	BeamFirFilter_93_s.imagBuffer[(63 - BeamFirFilter_93_s.pos)] = pop_float(&BeamFirFilter_92BeamFirFilter_93) ; 
	modPos = (63 - BeamFirFilter_93_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_93_s.realBuffer[modPos] * BeamFirFilter_93_s.real_weight[i]) + (BeamFirFilter_93_s.imagBuffer[modPos] * BeamFirFilter_93_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_93_s.imagBuffer[modPos] * BeamFirFilter_93_s.real_weight[i]) + (BeamFirFilter_93_s.realBuffer[modPos] * BeamFirFilter_93_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_93_s.pos = ((BeamFirFilter_93_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[8], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[8], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_92BeamFirFilter_93) ; 
	}
	ENDFOR
	BeamFirFilter_93_s.count = (BeamFirFilter_93_s.count + 2) ; 
	if(BeamFirFilter_93_s.count == 1024) {
		BeamFirFilter_93_s.count = 0 ; 
		BeamFirFilter_93_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_93_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_93_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_95(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_95_s.curSample == 256)) {
			push_float(&InputGenerate_95BeamFirFilter_96, ((float) sqrt((InputGenerate_95_s.curSample * 9)))) ; 
			push_float(&InputGenerate_95BeamFirFilter_96, (((float) sqrt((InputGenerate_95_s.curSample * 9))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_95BeamFirFilter_96, -((float) sqrt((InputGenerate_95_s.curSample * 9)))) ; 
			push_float(&InputGenerate_95BeamFirFilter_96, -(((float) sqrt((InputGenerate_95_s.curSample * 9))) + 1.0)) ; 
		}
		InputGenerate_95_s.curSample++ ; 
		if((InputGenerate_95_s.curSample >= 1024)) {
			InputGenerate_95_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_96(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_96_s.realBuffer[(63 - BeamFirFilter_96_s.pos)] = pop_float(&InputGenerate_95BeamFirFilter_96) ; 
		BeamFirFilter_96_s.imagBuffer[(63 - BeamFirFilter_96_s.pos)] = pop_float(&InputGenerate_95BeamFirFilter_96) ; 
		modPos = (63 - BeamFirFilter_96_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_96_s.realBuffer[modPos] * BeamFirFilter_96_s.real_weight[i]) + (BeamFirFilter_96_s.imagBuffer[modPos] * BeamFirFilter_96_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_96_s.imagBuffer[modPos] * BeamFirFilter_96_s.real_weight[i]) + (BeamFirFilter_96_s.realBuffer[modPos] * BeamFirFilter_96_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_96_s.pos = ((BeamFirFilter_96_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_96BeamFirFilter_97, real_curr) ; 
		push_float(&BeamFirFilter_96BeamFirFilter_97, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_95BeamFirFilter_96) ; 
		}
		ENDFOR
		BeamFirFilter_96_s.count = (BeamFirFilter_96_s.count + 1) ; 
		if(BeamFirFilter_96_s.count == 1024) {
			BeamFirFilter_96_s.count = 0 ; 
			BeamFirFilter_96_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_96_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_96_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_97() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_97_s.realBuffer[(63 - BeamFirFilter_97_s.pos)] = pop_float(&BeamFirFilter_96BeamFirFilter_97) ; 
	BeamFirFilter_97_s.imagBuffer[(63 - BeamFirFilter_97_s.pos)] = pop_float(&BeamFirFilter_96BeamFirFilter_97) ; 
	modPos = (63 - BeamFirFilter_97_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_97_s.realBuffer[modPos] * BeamFirFilter_97_s.real_weight[i]) + (BeamFirFilter_97_s.imagBuffer[modPos] * BeamFirFilter_97_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_97_s.imagBuffer[modPos] * BeamFirFilter_97_s.real_weight[i]) + (BeamFirFilter_97_s.realBuffer[modPos] * BeamFirFilter_97_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_97_s.pos = ((BeamFirFilter_97_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[9], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[9], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_96BeamFirFilter_97) ; 
	}
	ENDFOR
	BeamFirFilter_97_s.count = (BeamFirFilter_97_s.count + 2) ; 
	if(BeamFirFilter_97_s.count == 1024) {
		BeamFirFilter_97_s.count = 0 ; 
		BeamFirFilter_97_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_97_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_97_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_99(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_99_s.curSample == 256)) {
			push_float(&InputGenerate_99BeamFirFilter_100, ((float) sqrt((InputGenerate_99_s.curSample * 10)))) ; 
			push_float(&InputGenerate_99BeamFirFilter_100, (((float) sqrt((InputGenerate_99_s.curSample * 10))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_99BeamFirFilter_100, -((float) sqrt((InputGenerate_99_s.curSample * 10)))) ; 
			push_float(&InputGenerate_99BeamFirFilter_100, -(((float) sqrt((InputGenerate_99_s.curSample * 10))) + 1.0)) ; 
		}
		InputGenerate_99_s.curSample++ ; 
		if((InputGenerate_99_s.curSample >= 1024)) {
			InputGenerate_99_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_100(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_100_s.realBuffer[(63 - BeamFirFilter_100_s.pos)] = pop_float(&InputGenerate_99BeamFirFilter_100) ; 
		BeamFirFilter_100_s.imagBuffer[(63 - BeamFirFilter_100_s.pos)] = pop_float(&InputGenerate_99BeamFirFilter_100) ; 
		modPos = (63 - BeamFirFilter_100_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_100_s.realBuffer[modPos] * BeamFirFilter_100_s.real_weight[i]) + (BeamFirFilter_100_s.imagBuffer[modPos] * BeamFirFilter_100_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_100_s.imagBuffer[modPos] * BeamFirFilter_100_s.real_weight[i]) + (BeamFirFilter_100_s.realBuffer[modPos] * BeamFirFilter_100_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_100_s.pos = ((BeamFirFilter_100_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_100BeamFirFilter_101, real_curr) ; 
		push_float(&BeamFirFilter_100BeamFirFilter_101, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_99BeamFirFilter_100) ; 
		}
		ENDFOR
		BeamFirFilter_100_s.count = (BeamFirFilter_100_s.count + 1) ; 
		if(BeamFirFilter_100_s.count == 1024) {
			BeamFirFilter_100_s.count = 0 ; 
			BeamFirFilter_100_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_100_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_100_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_101() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_101_s.realBuffer[(63 - BeamFirFilter_101_s.pos)] = pop_float(&BeamFirFilter_100BeamFirFilter_101) ; 
	BeamFirFilter_101_s.imagBuffer[(63 - BeamFirFilter_101_s.pos)] = pop_float(&BeamFirFilter_100BeamFirFilter_101) ; 
	modPos = (63 - BeamFirFilter_101_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_101_s.realBuffer[modPos] * BeamFirFilter_101_s.real_weight[i]) + (BeamFirFilter_101_s.imagBuffer[modPos] * BeamFirFilter_101_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_101_s.imagBuffer[modPos] * BeamFirFilter_101_s.real_weight[i]) + (BeamFirFilter_101_s.realBuffer[modPos] * BeamFirFilter_101_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_101_s.pos = ((BeamFirFilter_101_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[10], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[10], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_100BeamFirFilter_101) ; 
	}
	ENDFOR
	BeamFirFilter_101_s.count = (BeamFirFilter_101_s.count + 2) ; 
	if(BeamFirFilter_101_s.count == 1024) {
		BeamFirFilter_101_s.count = 0 ; 
		BeamFirFilter_101_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_101_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_101_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void InputGenerate_103(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		if((FALSE && InputGenerate_103_s.curSample == 256)) {
			push_float(&InputGenerate_103BeamFirFilter_104, ((float) sqrt((InputGenerate_103_s.curSample * 11)))) ; 
			push_float(&InputGenerate_103BeamFirFilter_104, (((float) sqrt((InputGenerate_103_s.curSample * 11))) + 1.0)) ; 
		}
		else {
			push_float(&InputGenerate_103BeamFirFilter_104, -((float) sqrt((InputGenerate_103_s.curSample * 11)))) ; 
			push_float(&InputGenerate_103BeamFirFilter_104, -(((float) sqrt((InputGenerate_103_s.curSample * 11))) + 1.0)) ; 
		}
		InputGenerate_103_s.curSample++ ; 
		if((InputGenerate_103_s.curSample >= 1024)) {
			InputGenerate_103_s.curSample = 0 ; 
		}
	}
	ENDFOR
}

void BeamFirFilter_104(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float real_curr = 0.0;
		float imag_curr = 0.0;
		int modPos = 0;
		BeamFirFilter_104_s.realBuffer[(63 - BeamFirFilter_104_s.pos)] = pop_float(&InputGenerate_103BeamFirFilter_104) ; 
		BeamFirFilter_104_s.imagBuffer[(63 - BeamFirFilter_104_s.pos)] = pop_float(&InputGenerate_103BeamFirFilter_104) ; 
		modPos = (63 - BeamFirFilter_104_s.pos) ; 
		FOR(int, i, 0,  < , 64, i++) {
			real_curr = (real_curr + ((BeamFirFilter_104_s.realBuffer[modPos] * BeamFirFilter_104_s.real_weight[i]) + (BeamFirFilter_104_s.imagBuffer[modPos] * BeamFirFilter_104_s.imag_weight[i]))) ; 
			imag_curr = (imag_curr + ((BeamFirFilter_104_s.imagBuffer[modPos] * BeamFirFilter_104_s.real_weight[i]) + (BeamFirFilter_104_s.realBuffer[modPos] * BeamFirFilter_104_s.imag_weight[i]))) ; 
			modPos = ((modPos + 1) & 63) ; 
		}
		ENDFOR
		BeamFirFilter_104_s.pos = ((BeamFirFilter_104_s.pos + 1) & 63) ; 
		push_float(&BeamFirFilter_104BeamFirFilter_105, real_curr) ; 
		push_float(&BeamFirFilter_104BeamFirFilter_105, imag_curr) ; 
		FOR(int, i, 2,  < , 2, i++) {
			pop_float(&InputGenerate_103BeamFirFilter_104) ; 
		}
		ENDFOR
		BeamFirFilter_104_s.count = (BeamFirFilter_104_s.count + 1) ; 
		if(BeamFirFilter_104_s.count == 1024) {
			BeamFirFilter_104_s.count = 0 ; 
			BeamFirFilter_104_s.pos = 0 ; 
			FOR(int, i, 0,  < , 64, i++) {
				BeamFirFilter_104_s.realBuffer[i] = 0.0 ; 
				BeamFirFilter_104_s.imagBuffer[i] = 0.0 ; 
			}
			ENDFOR
		}
	}
	ENDFOR
}

void BeamFirFilter_105() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_105_s.realBuffer[(63 - BeamFirFilter_105_s.pos)] = pop_float(&BeamFirFilter_104BeamFirFilter_105) ; 
	BeamFirFilter_105_s.imagBuffer[(63 - BeamFirFilter_105_s.pos)] = pop_float(&BeamFirFilter_104BeamFirFilter_105) ; 
	modPos = (63 - BeamFirFilter_105_s.pos) ; 
	FOR(int, i, 0,  < , 64, i++) {
		real_curr = (real_curr + ((BeamFirFilter_105_s.realBuffer[modPos] * BeamFirFilter_105_s.real_weight[i]) + (BeamFirFilter_105_s.imagBuffer[modPos] * BeamFirFilter_105_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_105_s.imagBuffer[modPos] * BeamFirFilter_105_s.real_weight[i]) + (BeamFirFilter_105_s.realBuffer[modPos] * BeamFirFilter_105_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 63) ; 
	}
	ENDFOR
	BeamFirFilter_105_s.pos = ((BeamFirFilter_105_s.pos + 1) & 63) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[11], real_curr) ; 
	push_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[11], imag_curr) ; 
	FOR(int, i, 2,  < , 4, i++) {
		pop_float(&BeamFirFilter_104BeamFirFilter_105) ; 
	}
	ENDFOR
	BeamFirFilter_105_s.count = (BeamFirFilter_105_s.count + 2) ; 
	if(BeamFirFilter_105_s.count == 1024) {
		BeamFirFilter_105_s.count = 0 ; 
		BeamFirFilter_105_s.pos = 0 ; 
		FOR(int, i, 0,  < , 64, i++) {
			BeamFirFilter_105_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_105_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


void WEIGHTED_ROUND_ROBIN_Splitter_126() {
SimNamedMarker(5, __func__);
}

void WEIGHTED_ROUND_ROBIN_Joiner_127() {
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_, 0, <, 12, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_127DUPLICATE_Splitter_128, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[__iter_]));
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_127DUPLICATE_Splitter_128, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[__iter_]));
	ENDFOR
}

void BeamForm_107() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	FOR(int, i, 0,  < , 12, i++) {
		float real_pop = 0.0;
		float imag_pop = 0.0;
		real_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[0]) ; 
		imag_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[0]) ; 
		real_curr = (real_curr + ((BeamForm_107_s.real_weight[i] * real_pop) - (BeamForm_107_s.imag_weight[i] * imag_pop))) ; 
		imag_curr = (imag_curr + ((BeamForm_107_s.real_weight[i] * imag_pop) + (BeamForm_107_s.imag_weight[i] * real_pop))) ; 
	}
	ENDFOR
	push_float(&BeamForm_107BeamFirFilter_108, real_curr) ; 
	push_float(&BeamForm_107BeamFirFilter_108, imag_curr) ; 
}


void BeamFirFilter_108() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_108_s.realBuffer[(511 - BeamFirFilter_108_s.pos)] = pop_float(&BeamForm_107BeamFirFilter_108) ; 
	BeamFirFilter_108_s.imagBuffer[(511 - BeamFirFilter_108_s.pos)] = pop_float(&BeamForm_107BeamFirFilter_108) ; 
	modPos = (511 - BeamFirFilter_108_s.pos) ; 
	FOR(int, i, 0,  < , 512, i++) {
		real_curr = (real_curr + ((BeamFirFilter_108_s.realBuffer[modPos] * BeamFirFilter_108_s.real_weight[i]) + (BeamFirFilter_108_s.imagBuffer[modPos] * BeamFirFilter_108_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_108_s.imagBuffer[modPos] * BeamFirFilter_108_s.real_weight[i]) + (BeamFirFilter_108_s.realBuffer[modPos] * BeamFirFilter_108_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 511) ; 
	}
	ENDFOR
	BeamFirFilter_108_s.pos = ((BeamFirFilter_108_s.pos + 1) & 511) ; 
	push_float(&BeamFirFilter_108Magnitude_109, real_curr) ; 
	push_float(&BeamFirFilter_108Magnitude_109, imag_curr) ; 
	FOR(int, i, 2,  < , 2, i++) {
		pop_float(&BeamForm_107BeamFirFilter_108) ; 
	}
	ENDFOR
	BeamFirFilter_108_s.count = (BeamFirFilter_108_s.count + 1) ; 
	if(BeamFirFilter_108_s.count == 512) {
		BeamFirFilter_108_s.count = 0 ; 
		BeamFirFilter_108_s.pos = 0 ; 
		FOR(int, i, 0,  < , 512, i++) {
			BeamFirFilter_108_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_108_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


float Magnitude_109_mag(float real, float imag) {
	return ((float) sqrt(((real * real) + (imag * imag))));
}
void Magnitude_109() {
SimNamedMarker(5, __func__);
	float f1 = 0.0;
	float f2 = 0.0;
	f1 = pop_float(&BeamFirFilter_108Magnitude_109) ; 
	f2 = pop_float(&BeamFirFilter_108Magnitude_109) ; 
	push_float(&Magnitude_109FloatPrinter_110, Magnitude_109_mag(f1, f2)) ; 
}


void FloatPrinter_110() {
	printf("%.10f", pop_float(&Magnitude_109FloatPrinter_110));
	printf("\n");
}


void BeamForm_112() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	FOR(int, i, 0,  < , 12, i++) {
		float real_pop = 0.0;
		float imag_pop = 0.0;
		real_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[1]) ; 
		imag_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[1]) ; 
		real_curr = (real_curr + ((BeamForm_112_s.real_weight[i] * real_pop) - (BeamForm_112_s.imag_weight[i] * imag_pop))) ; 
		imag_curr = (imag_curr + ((BeamForm_112_s.real_weight[i] * imag_pop) + (BeamForm_112_s.imag_weight[i] * real_pop))) ; 
	}
	ENDFOR
	push_float(&BeamForm_112BeamFirFilter_113, real_curr) ; 
	push_float(&BeamForm_112BeamFirFilter_113, imag_curr) ; 
}


void BeamFirFilter_113() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_113_s.realBuffer[(511 - BeamFirFilter_113_s.pos)] = pop_float(&BeamForm_112BeamFirFilter_113) ; 
	BeamFirFilter_113_s.imagBuffer[(511 - BeamFirFilter_113_s.pos)] = pop_float(&BeamForm_112BeamFirFilter_113) ; 
	modPos = (511 - BeamFirFilter_113_s.pos) ; 
	FOR(int, i, 0,  < , 512, i++) {
		real_curr = (real_curr + ((BeamFirFilter_113_s.realBuffer[modPos] * BeamFirFilter_113_s.real_weight[i]) + (BeamFirFilter_113_s.imagBuffer[modPos] * BeamFirFilter_113_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_113_s.imagBuffer[modPos] * BeamFirFilter_113_s.real_weight[i]) + (BeamFirFilter_113_s.realBuffer[modPos] * BeamFirFilter_113_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 511) ; 
	}
	ENDFOR
	BeamFirFilter_113_s.pos = ((BeamFirFilter_113_s.pos + 1) & 511) ; 
	push_float(&BeamFirFilter_113Magnitude_114, real_curr) ; 
	push_float(&BeamFirFilter_113Magnitude_114, imag_curr) ; 
	FOR(int, i, 2,  < , 2, i++) {
		pop_float(&BeamForm_112BeamFirFilter_113) ; 
	}
	ENDFOR
	BeamFirFilter_113_s.count = (BeamFirFilter_113_s.count + 1) ; 
	if(BeamFirFilter_113_s.count == 512) {
		BeamFirFilter_113_s.count = 0 ; 
		BeamFirFilter_113_s.pos = 0 ; 
		FOR(int, i, 0,  < , 512, i++) {
			BeamFirFilter_113_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_113_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


float Magnitude_114_mag(float real, float imag) {
	return ((float) sqrt(((real * real) + (imag * imag))));
}
void Magnitude_114() {
SimNamedMarker(5, __func__);
	float f1 = 0.0;
	float f2 = 0.0;
	f1 = pop_float(&BeamFirFilter_113Magnitude_114) ; 
	f2 = pop_float(&BeamFirFilter_113Magnitude_114) ; 
	push_float(&Magnitude_114FloatPrinter_115, Magnitude_114_mag(f1, f2)) ; 
}


void FloatPrinter_115() {
	printf("%.10f", pop_float(&Magnitude_114FloatPrinter_115));
	printf("\n");
}


void BeamForm_117() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	FOR(int, i, 0,  < , 12, i++) {
		float real_pop = 0.0;
		float imag_pop = 0.0;
		real_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[2]) ; 
		imag_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[2]) ; 
		real_curr = (real_curr + ((BeamForm_117_s.real_weight[i] * real_pop) - (BeamForm_117_s.imag_weight[i] * imag_pop))) ; 
		imag_curr = (imag_curr + ((BeamForm_117_s.real_weight[i] * imag_pop) + (BeamForm_117_s.imag_weight[i] * real_pop))) ; 
	}
	ENDFOR
	push_float(&BeamForm_117BeamFirFilter_118, real_curr) ; 
	push_float(&BeamForm_117BeamFirFilter_118, imag_curr) ; 
}


void BeamFirFilter_118() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_118_s.realBuffer[(511 - BeamFirFilter_118_s.pos)] = pop_float(&BeamForm_117BeamFirFilter_118) ; 
	BeamFirFilter_118_s.imagBuffer[(511 - BeamFirFilter_118_s.pos)] = pop_float(&BeamForm_117BeamFirFilter_118) ; 
	modPos = (511 - BeamFirFilter_118_s.pos) ; 
	FOR(int, i, 0,  < , 512, i++) {
		real_curr = (real_curr + ((BeamFirFilter_118_s.realBuffer[modPos] * BeamFirFilter_118_s.real_weight[i]) + (BeamFirFilter_118_s.imagBuffer[modPos] * BeamFirFilter_118_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_118_s.imagBuffer[modPos] * BeamFirFilter_118_s.real_weight[i]) + (BeamFirFilter_118_s.realBuffer[modPos] * BeamFirFilter_118_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 511) ; 
	}
	ENDFOR
	BeamFirFilter_118_s.pos = ((BeamFirFilter_118_s.pos + 1) & 511) ; 
	push_float(&BeamFirFilter_118Magnitude_119, real_curr) ; 
	push_float(&BeamFirFilter_118Magnitude_119, imag_curr) ; 
	FOR(int, i, 2,  < , 2, i++) {
		pop_float(&BeamForm_117BeamFirFilter_118) ; 
	}
	ENDFOR
	BeamFirFilter_118_s.count = (BeamFirFilter_118_s.count + 1) ; 
	if(BeamFirFilter_118_s.count == 512) {
		BeamFirFilter_118_s.count = 0 ; 
		BeamFirFilter_118_s.pos = 0 ; 
		FOR(int, i, 0,  < , 512, i++) {
			BeamFirFilter_118_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_118_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


float Magnitude_119_mag(float real, float imag) {
	return ((float) sqrt(((real * real) + (imag * imag))));
}
void Magnitude_119() {
SimNamedMarker(5, __func__);
	float f1 = 0.0;
	float f2 = 0.0;
	f1 = pop_float(&BeamFirFilter_118Magnitude_119) ; 
	f2 = pop_float(&BeamFirFilter_118Magnitude_119) ; 
	push_float(&Magnitude_119FloatPrinter_120, Magnitude_119_mag(f1, f2)) ; 
}


void FloatPrinter_120() {
	printf("%.10f", pop_float(&Magnitude_119FloatPrinter_120));
	printf("\n");
}


void BeamForm_122() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	FOR(int, i, 0,  < , 12, i++) {
		float real_pop = 0.0;
		float imag_pop = 0.0;
		real_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[3]) ; 
		imag_pop = pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[3]) ; 
		real_curr = (real_curr + ((BeamForm_122_s.real_weight[i] * real_pop) - (BeamForm_122_s.imag_weight[i] * imag_pop))) ; 
		imag_curr = (imag_curr + ((BeamForm_122_s.real_weight[i] * imag_pop) + (BeamForm_122_s.imag_weight[i] * real_pop))) ; 
	}
	ENDFOR
	push_float(&BeamForm_122BeamFirFilter_123, real_curr) ; 
	push_float(&BeamForm_122BeamFirFilter_123, imag_curr) ; 
}


void BeamFirFilter_123() {
SimNamedMarker(5, __func__);
	float real_curr = 0.0;
	float imag_curr = 0.0;
	int modPos = 0;
	BeamFirFilter_123_s.realBuffer[(511 - BeamFirFilter_123_s.pos)] = pop_float(&BeamForm_122BeamFirFilter_123) ; 
	BeamFirFilter_123_s.imagBuffer[(511 - BeamFirFilter_123_s.pos)] = pop_float(&BeamForm_122BeamFirFilter_123) ; 
	modPos = (511 - BeamFirFilter_123_s.pos) ; 
	FOR(int, i, 0,  < , 512, i++) {
		real_curr = (real_curr + ((BeamFirFilter_123_s.realBuffer[modPos] * BeamFirFilter_123_s.real_weight[i]) + (BeamFirFilter_123_s.imagBuffer[modPos] * BeamFirFilter_123_s.imag_weight[i]))) ; 
		imag_curr = (imag_curr + ((BeamFirFilter_123_s.imagBuffer[modPos] * BeamFirFilter_123_s.real_weight[i]) + (BeamFirFilter_123_s.realBuffer[modPos] * BeamFirFilter_123_s.imag_weight[i]))) ; 
		modPos = ((modPos + 1) & 511) ; 
	}
	ENDFOR
	BeamFirFilter_123_s.pos = ((BeamFirFilter_123_s.pos + 1) & 511) ; 
	push_float(&BeamFirFilter_123Magnitude_124, real_curr) ; 
	push_float(&BeamFirFilter_123Magnitude_124, imag_curr) ; 
	FOR(int, i, 2,  < , 2, i++) {
		pop_float(&BeamForm_122BeamFirFilter_123) ; 
	}
	ENDFOR
	BeamFirFilter_123_s.count = (BeamFirFilter_123_s.count + 1) ; 
	if(BeamFirFilter_123_s.count == 512) {
		BeamFirFilter_123_s.count = 0 ; 
		BeamFirFilter_123_s.pos = 0 ; 
		FOR(int, i, 0,  < , 512, i++) {
			BeamFirFilter_123_s.realBuffer[i] = 0.0 ; 
			BeamFirFilter_123_s.imagBuffer[i] = 0.0 ; 
		}
		ENDFOR
	}
}


float Magnitude_124_mag(float real, float imag) {
	return ((float) sqrt(((real * real) + (imag * imag))));
}
void Magnitude_124() {
SimNamedMarker(5, __func__);
	float f1 = 0.0;
	float f2 = 0.0;
	f1 = pop_float(&BeamFirFilter_123Magnitude_124) ; 
	f2 = pop_float(&BeamFirFilter_123Magnitude_124) ; 
	push_float(&Magnitude_124FloatPrinter_125, Magnitude_124_mag(f1, f2)) ; 
}


void FloatPrinter_125() {
	printf("%.10f", pop_float(&Magnitude_124FloatPrinter_125));
	printf("\n");
}


void DUPLICATE_Splitter_128() {
{
	FOR(uint32_t, __iter_steady_, 0, <, 24, __iter_steady_++)
		float __token_ = pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_127DUPLICATE_Splitter_128);
		FOR(uint32_t, __iter_dup_, 0, <, 4, __iter_dup_++)
			push_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[__iter_dup_], __token_);
		ENDFOR
	ENDFOR
}}

void WEIGHTED_ROUND_ROBIN_Joiner_129() {
SimNamedMarker(5, __func__);
}

void __stream_init__() {
	init_buffer_float(&Magnitude_109FloatPrinter_110);
	init_buffer_float(&BeamFirFilter_60BeamFirFilter_61);
	init_buffer_float(&BeamFirFilter_100BeamFirFilter_101);
	init_buffer_float(&BeamFirFilter_68BeamFirFilter_69);
	init_buffer_float(&InputGenerate_67BeamFirFilter_68);
	init_buffer_float(&BeamFirFilter_104BeamFirFilter_105);
	init_buffer_float(&InputGenerate_75BeamFirFilter_76);
	init_buffer_float(&BeamForm_107BeamFirFilter_108);
	init_buffer_float(&BeamFirFilter_92BeamFirFilter_93);
	FOR(int, __iter_init_0_, 0, <, 4, __iter_init_0_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_join[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&InputGenerate_99BeamFirFilter_100);
	init_buffer_float(&InputGenerate_79BeamFirFilter_80);
	init_buffer_float(&BeamFirFilter_80BeamFirFilter_81);
	init_buffer_float(&BeamFirFilter_84BeamFirFilter_85);
	init_buffer_float(&BeamFirFilter_123Magnitude_124);
	init_buffer_float(&BeamFirFilter_76BeamFirFilter_77);
	init_buffer_float(&BeamFirFilter_113Magnitude_114);
	init_buffer_float(&Magnitude_124FloatPrinter_125);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_127DUPLICATE_Splitter_128);
	FOR(int, __iter_init_1_, 0, <, 4, __iter_init_1_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_AnonFilter_a3_56_132_150_168_split[__iter_init_1_]);
	ENDFOR
	init_buffer_float(&InputGenerate_71BeamFirFilter_72);
	init_buffer_float(&BeamForm_112BeamFirFilter_113);
	init_buffer_float(&Magnitude_114FloatPrinter_115);
	init_buffer_float(&BeamFirFilter_118Magnitude_119);
	init_buffer_float(&BeamFirFilter_64BeamFirFilter_65);
	init_buffer_float(&BeamFirFilter_108Magnitude_109);
	init_buffer_float(&BeamForm_117BeamFirFilter_118);
	init_buffer_float(&InputGenerate_63BeamFirFilter_64);
	init_buffer_float(&InputGenerate_103BeamFirFilter_104);
	init_buffer_float(&BeamFirFilter_72BeamFirFilter_73);
	init_buffer_float(&InputGenerate_59BeamFirFilter_60);
	init_buffer_float(&InputGenerate_95BeamFirFilter_96);
	init_buffer_float(&Magnitude_119FloatPrinter_120);
	init_buffer_float(&InputGenerate_87BeamFirFilter_88);
	init_buffer_float(&BeamFirFilter_88BeamFirFilter_89);
	init_buffer_float(&InputGenerate_83BeamFirFilter_84);
	init_buffer_float(&BeamForm_122BeamFirFilter_123);
	FOR(int, __iter_init_2_, 0, <, 12, __iter_init_2_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_split[__iter_init_2_]);
	ENDFOR
	FOR(int, __iter_init_3_, 0, <, 12, __iter_init_3_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_AnonFilter_a1_50_130_148_167_join[__iter_init_3_]);
	ENDFOR
	init_buffer_float(&BeamFirFilter_96BeamFirFilter_97);
	init_buffer_float(&InputGenerate_91BeamFirFilter_92);
// --- init: InputGenerate_59
	 {
	InputGenerate_59_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_60
	 {
	BeamFirFilter_60_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_60_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_60_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_61
	 {
	BeamFirFilter_61_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_61_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_61_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_63
	 {
	InputGenerate_63_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_64
	 {
	BeamFirFilter_64_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_64_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_64_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_65
	 {
	BeamFirFilter_65_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_65_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_65_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_67
	 {
	InputGenerate_67_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_68
	 {
	BeamFirFilter_68_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_68_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_68_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_69
	 {
	BeamFirFilter_69_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_69_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_69_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_71
	 {
	InputGenerate_71_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_72
	 {
	BeamFirFilter_72_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_72_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_72_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_73
	 {
	BeamFirFilter_73_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_73_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_73_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_75
	 {
	InputGenerate_75_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_76
	 {
	BeamFirFilter_76_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_76_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_76_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_77
	 {
	BeamFirFilter_77_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_77_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_77_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_79
	 {
	InputGenerate_79_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_80
	 {
	BeamFirFilter_80_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_80_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_80_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_81
	 {
	BeamFirFilter_81_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_81_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_81_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_83
	 {
	InputGenerate_83_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_84
	 {
	BeamFirFilter_84_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_84_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_84_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_85
	 {
	BeamFirFilter_85_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_85_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_85_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_87
	 {
	InputGenerate_87_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_88
	 {
	BeamFirFilter_88_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_88_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_88_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_89
	 {
	BeamFirFilter_89_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_89_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_89_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_91
	 {
	InputGenerate_91_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_92
	 {
	BeamFirFilter_92_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_92_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_92_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_93
	 {
	BeamFirFilter_93_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_93_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_93_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_95
	 {
	InputGenerate_95_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_96
	 {
	BeamFirFilter_96_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_96_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_96_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_97
	 {
	BeamFirFilter_97_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_97_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_97_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_99
	 {
	InputGenerate_99_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_100
	 {
	BeamFirFilter_100_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_100_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_100_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_101
	 {
	BeamFirFilter_101_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_101_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_101_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: InputGenerate_103
	 {
	InputGenerate_103_s.curSample = 0 ; 
}
//--------------------------------
// --- init: BeamFirFilter_104
	 {
	BeamFirFilter_104_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_104_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_104_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_105
	 {
	BeamFirFilter_105_s.pos = 0 ; 
	FOR(int, j, 0,  < , 64, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_105_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_105_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamForm_107
	 {
	FOR(int, j, 0,  < , 12, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamForm_107_s.real_weight[j] = (((float) sin(idx)) / (0 + idx)) ; 
		BeamForm_107_s.imag_weight[j] = (((float) cos(idx)) / (0 + idx)) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_108
	 {
	BeamFirFilter_108_s.pos = 0 ; 
	FOR(int, j, 0,  < , 512, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_108_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_108_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamForm_112
	 {
	FOR(int, j, 0,  < , 12, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamForm_112_s.real_weight[j] = (((float) sin(idx)) / (1 + idx)) ; 
		BeamForm_112_s.imag_weight[j] = (((float) cos(idx)) / (1 + idx)) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_113
	 {
	BeamFirFilter_113_s.pos = 0 ; 
	FOR(int, j, 0,  < , 512, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_113_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_113_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamForm_117
	 {
	FOR(int, j, 0,  < , 12, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamForm_117_s.real_weight[j] = (((float) sin(idx)) / (2 + idx)) ; 
		BeamForm_117_s.imag_weight[j] = (((float) cos(idx)) / (2 + idx)) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_118
	 {
	BeamFirFilter_118_s.pos = 0 ; 
	FOR(int, j, 0,  < , 512, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_118_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_118_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamForm_122
	 {
	FOR(int, j, 0,  < , 12, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamForm_122_s.real_weight[j] = (((float) sin(idx)) / (3 + idx)) ; 
		BeamForm_122_s.imag_weight[j] = (((float) cos(idx)) / (3 + idx)) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: BeamFirFilter_123
	 {
	BeamFirFilter_123_s.pos = 0 ; 
	FOR(int, j, 0,  < , 512, j++) {
		int idx = 0;
		idx = (j + 1) ; 
		BeamFirFilter_123_s.real_weight[j] = (((float) sin(idx)) / idx) ; 
		BeamFirFilter_123_s.imag_weight[j] = (((float) cos(idx)) / idx) ; 
	}
	ENDFOR
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
		WEIGHTED_ROUND_ROBIN_Splitter_126();
			InputGenerate_59();
			BeamFirFilter_60();
			BeamFirFilter_61();
			InputGenerate_63();
			BeamFirFilter_64();
			BeamFirFilter_65();
			InputGenerate_67();
			BeamFirFilter_68();
			BeamFirFilter_69();
			InputGenerate_71();
			BeamFirFilter_72();
			BeamFirFilter_73();
			InputGenerate_75();
			BeamFirFilter_76();
			BeamFirFilter_77();
			InputGenerate_79();
			BeamFirFilter_80();
			BeamFirFilter_81();
			InputGenerate_83();
			BeamFirFilter_84();
			BeamFirFilter_85();
			InputGenerate_87();
			BeamFirFilter_88();
			BeamFirFilter_89();
			InputGenerate_91();
			BeamFirFilter_92();
			BeamFirFilter_93();
			InputGenerate_95();
			BeamFirFilter_96();
			BeamFirFilter_97();
			InputGenerate_99();
			BeamFirFilter_100();
			BeamFirFilter_101();
			InputGenerate_103();
			BeamFirFilter_104();
			BeamFirFilter_105();
		WEIGHTED_ROUND_ROBIN_Joiner_127();
		DUPLICATE_Splitter_128();
			BeamForm_107();
			BeamFirFilter_108();
			Magnitude_109();
			FloatPrinter_110();
			BeamForm_112();
			BeamFirFilter_113();
			Magnitude_114();
			FloatPrinter_115();
			BeamForm_117();
			BeamFirFilter_118();
			Magnitude_119();
			FloatPrinter_120();
			BeamForm_122();
			BeamFirFilter_123();
			Magnitude_124();
			FloatPrinter_125();
		WEIGHTED_ROUND_ROBIN_Joiner_129();
	ENDFOR
	return EXIT_SUCCESS;
}
