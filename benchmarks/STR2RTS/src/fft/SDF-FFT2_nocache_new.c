#include "sim_api.h"
#include "SDF-FFT2_nocache.h"

buffer_float_t FFTReorderSimple_46CombineDFT_47;
buffer_float_t CombineDFT_48CombineDFT_49;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_join[2];
buffer_float_t CombineDFT_47CombineDFT_48;
buffer_float_t FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65;
buffer_float_t CombineDFT_62CombineDFT_63;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_66FloatPrinter_64;
buffer_float_t FFTReorderSimple_57CombineDFT_58;
buffer_float_t CombineDFT_61CombineDFT_62;
buffer_float_t CombineDFT_49CombineDFT_50;
buffer_float_t CombineDFT_60CombineDFT_61;
buffer_float_t CombineDFT_59CombineDFT_60;
buffer_float_t CombineDFT_51CombineDFT_52;
buffer_float_t CombineDFT_50CombineDFT_51;
buffer_float_t FFTReorderSimple_53FFTReorderSimple_54;
buffer_float_t FFTReorderSimple_55FFTReorderSimple_56;
buffer_float_t FFTReorderSimple_54FFTReorderSimple_55;
buffer_float_t FFTReorderSimple_42FFTReorderSimple_43;
buffer_float_t FFTReorderSimple_56FFTReorderSimple_57;
buffer_float_t FFTReorderSimple_43FFTReorderSimple_44;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[2];
buffer_float_t FFTReorderSimple_44FFTReorderSimple_45;
buffer_float_t CombineDFT_58CombineDFT_59;
buffer_float_t FFTReorderSimple_45FFTReorderSimple_46;


CombineDFT_47_t CombineDFT_47_s;
CombineDFT_48_t CombineDFT_48_s;
CombineDFT_49_t CombineDFT_49_s;
CombineDFT_50_t CombineDFT_50_s;
CombineDFT_51_t CombineDFT_51_s;
CombineDFT_52_t CombineDFT_52_s;
CombineDFT_47_t CombineDFT_58_s;
CombineDFT_48_t CombineDFT_59_s;
CombineDFT_49_t CombineDFT_60_s;
CombineDFT_50_t CombineDFT_61_s;
CombineDFT_51_t CombineDFT_62_s;
CombineDFT_52_t CombineDFT_63_s;

void FFTTestSource_41(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		push_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65, 0.0) ; 
		push_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65, 0.0) ; 
		push_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65, 1.0) ; 
		push_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65, 0.0) ; 
		FOR(int, i, 0,  < , 124, i++) {
			push_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65, 0.0) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_42() {
SimNamedMarker(5, __func__);
	FOR(int, i, 0,  < , 128, i = (i + 4)) {
		push_float(&FFTReorderSimple_42FFTReorderSimple_43, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0], i)) ; 
		push_float(&FFTReorderSimple_42FFTReorderSimple_43, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0], (i + 1))) ; 
	}
	ENDFOR
	FOR(int, i, 2,  < , 128, i = (i + 4)) {
		push_float(&FFTReorderSimple_42FFTReorderSimple_43, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0], i)) ; 
		push_float(&FFTReorderSimple_42FFTReorderSimple_43, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0], (i + 1))) ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0]) ; 
		pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0]) ; 
	}
	ENDFOR
}


void FFTReorderSimple_43(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		FOR(int, i, 0,  < , 64, i = (i + 4)) {
			push_float(&FFTReorderSimple_43FFTReorderSimple_44, peek_float(&FFTReorderSimple_42FFTReorderSimple_43, i)) ; 
			push_float(&FFTReorderSimple_43FFTReorderSimple_44, peek_float(&FFTReorderSimple_42FFTReorderSimple_43, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 64, i = (i + 4)) {
			push_float(&FFTReorderSimple_43FFTReorderSimple_44, peek_float(&FFTReorderSimple_42FFTReorderSimple_43, i)) ; 
			push_float(&FFTReorderSimple_43FFTReorderSimple_44, peek_float(&FFTReorderSimple_42FFTReorderSimple_43, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 32, i++) {
			pop_float(&FFTReorderSimple_42FFTReorderSimple_43) ; 
			pop_float(&FFTReorderSimple_42FFTReorderSimple_43) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_44(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		FOR(int, i, 0,  < , 32, i = (i + 4)) {
			push_float(&FFTReorderSimple_44FFTReorderSimple_45, peek_float(&FFTReorderSimple_43FFTReorderSimple_44, i)) ; 
			push_float(&FFTReorderSimple_44FFTReorderSimple_45, peek_float(&FFTReorderSimple_43FFTReorderSimple_44, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 32, i = (i + 4)) {
			push_float(&FFTReorderSimple_44FFTReorderSimple_45, peek_float(&FFTReorderSimple_43FFTReorderSimple_44, i)) ; 
			push_float(&FFTReorderSimple_44FFTReorderSimple_45, peek_float(&FFTReorderSimple_43FFTReorderSimple_44, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 16, i++) {
			pop_float(&FFTReorderSimple_43FFTReorderSimple_44) ; 
			pop_float(&FFTReorderSimple_43FFTReorderSimple_44) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_45(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		FOR(int, i, 0,  < , 16, i = (i + 4)) {
			push_float(&FFTReorderSimple_45FFTReorderSimple_46, peek_float(&FFTReorderSimple_44FFTReorderSimple_45, i)) ; 
			push_float(&FFTReorderSimple_45FFTReorderSimple_46, peek_float(&FFTReorderSimple_44FFTReorderSimple_45, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 16, i = (i + 4)) {
			push_float(&FFTReorderSimple_45FFTReorderSimple_46, peek_float(&FFTReorderSimple_44FFTReorderSimple_45, i)) ; 
			push_float(&FFTReorderSimple_45FFTReorderSimple_46, peek_float(&FFTReorderSimple_44FFTReorderSimple_45, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 8, i++) {
			pop_float(&FFTReorderSimple_44FFTReorderSimple_45) ; 
			pop_float(&FFTReorderSimple_44FFTReorderSimple_45) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_46(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		FOR(int, i, 0,  < , 8, i = (i + 4)) {
			push_float(&FFTReorderSimple_46CombineDFT_47, peek_float(&FFTReorderSimple_45FFTReorderSimple_46, i)) ; 
			push_float(&FFTReorderSimple_46CombineDFT_47, peek_float(&FFTReorderSimple_45FFTReorderSimple_46, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 8, i = (i + 4)) {
			push_float(&FFTReorderSimple_46CombineDFT_47, peek_float(&FFTReorderSimple_45FFTReorderSimple_46, i)) ; 
			push_float(&FFTReorderSimple_46CombineDFT_47, peek_float(&FFTReorderSimple_45FFTReorderSimple_46, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 4, i++) {
			pop_float(&FFTReorderSimple_45FFTReorderSimple_46) ; 
			pop_float(&FFTReorderSimple_45FFTReorderSimple_46) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_47(){
	FOR(uint32_t, __iter_steady_, 0, <, 32, __iter_steady_++) {
		float results[4];
		FOR(int, i, 0,  < , 2, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&FFTReorderSimple_46CombineDFT_47, i) ; 
			y0_i = peek_float(&FFTReorderSimple_46CombineDFT_47, i_plus_1) ; 
			y1_r = peek_float(&FFTReorderSimple_46CombineDFT_47, (2 + i)) ; 
			y1_i = peek_float(&FFTReorderSimple_46CombineDFT_47, (2 + i_plus_1)) ; 
			weight_real = CombineDFT_47_s.w[i] ; 
			weight_imag = CombineDFT_47_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(2 + i)] = (y0_r - y1w_r) ; 
			results[((2 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 4, i++) {
			pop_float(&FFTReorderSimple_46CombineDFT_47) ; 
			push_float(&CombineDFT_47CombineDFT_48, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_48(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		float results[8];
		FOR(int, i, 0,  < , 4, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_47CombineDFT_48, i) ; 
			y0_i = peek_float(&CombineDFT_47CombineDFT_48, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_47CombineDFT_48, (4 + i)) ; 
			y1_i = peek_float(&CombineDFT_47CombineDFT_48, (4 + i_plus_1)) ; 
			weight_real = CombineDFT_48_s.w[i] ; 
			weight_imag = CombineDFT_48_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(4 + i)] = (y0_r - y1w_r) ; 
			results[((4 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 8, i++) {
			pop_float(&CombineDFT_47CombineDFT_48) ; 
			push_float(&CombineDFT_48CombineDFT_49, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_49(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float results[16];
		FOR(int, i, 0,  < , 8, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_48CombineDFT_49, i) ; 
			y0_i = peek_float(&CombineDFT_48CombineDFT_49, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_48CombineDFT_49, (8 + i)) ; 
			y1_i = peek_float(&CombineDFT_48CombineDFT_49, (8 + i_plus_1)) ; 
			weight_real = CombineDFT_49_s.w[i] ; 
			weight_imag = CombineDFT_49_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(8 + i)] = (y0_r - y1w_r) ; 
			results[((8 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 16, i++) {
			pop_float(&CombineDFT_48CombineDFT_49) ; 
			push_float(&CombineDFT_49CombineDFT_50, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_50(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		float results[32];
		FOR(int, i, 0,  < , 16, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_49CombineDFT_50, i) ; 
			y0_i = peek_float(&CombineDFT_49CombineDFT_50, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_49CombineDFT_50, (16 + i)) ; 
			y1_i = peek_float(&CombineDFT_49CombineDFT_50, (16 + i_plus_1)) ; 
			weight_real = CombineDFT_50_s.w[i] ; 
			weight_imag = CombineDFT_50_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(16 + i)] = (y0_r - y1w_r) ; 
			results[((16 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 32, i++) {
			pop_float(&CombineDFT_49CombineDFT_50) ; 
			push_float(&CombineDFT_50CombineDFT_51, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_51(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float results[64];
		FOR(int, i, 0,  < , 32, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_50CombineDFT_51, i) ; 
			y0_i = peek_float(&CombineDFT_50CombineDFT_51, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_50CombineDFT_51, (32 + i)) ; 
			y1_i = peek_float(&CombineDFT_50CombineDFT_51, (32 + i_plus_1)) ; 
			weight_real = CombineDFT_51_s.w[i] ; 
			weight_imag = CombineDFT_51_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(32 + i)] = (y0_r - y1w_r) ; 
			results[((32 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 64, i++) {
			pop_float(&CombineDFT_50CombineDFT_51) ; 
			push_float(&CombineDFT_51CombineDFT_52, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_52() {
SimNamedMarker(5, __func__);
	float results[128];
	FOR(int, i, 0,  < , 64, i = (i + 2)) {
		int i_plus_1 = 0;
		float y0_r = 0.0;
		float y0_i = 0.0;
		float y1_r = 0.0;
		float y1_i = 0.0;
		float weight_real = 0.0;
		float weight_imag = 0.0;
		float y1w_r = 0.0;
		float y1w_i = 0.0;
		i_plus_1 = (i + 1) ; 
		y0_r = peek_float(&CombineDFT_51CombineDFT_52, i) ; 
		y0_i = peek_float(&CombineDFT_51CombineDFT_52, i_plus_1) ; 
		y1_r = peek_float(&CombineDFT_51CombineDFT_52, (64 + i)) ; 
		y1_i = peek_float(&CombineDFT_51CombineDFT_52, (64 + i_plus_1)) ; 
		weight_real = CombineDFT_52_s.w[i] ; 
		weight_imag = CombineDFT_52_s.w[i_plus_1] ; 
		y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
		y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
		results[i] = (y0_r + y1w_r) ; 
		results[(i + 1)] = (y0_i + y1w_i) ; 
		results[(64 + i)] = (y0_r - y1w_r) ; 
		results[((64 + i) + 1)] = (y0_i - y1w_i) ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 128, i++) {
		pop_float(&CombineDFT_51CombineDFT_52) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_join[0], results[i]) ; 
	}
	ENDFOR
}


void FFTReorderSimple_53() {
SimNamedMarker(5, __func__);
	FOR(int, i, 0,  < , 128, i = (i + 4)) {
		push_float(&FFTReorderSimple_53FFTReorderSimple_54, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1], i)) ; 
		push_float(&FFTReorderSimple_53FFTReorderSimple_54, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1], (i + 1))) ; 
	}
	ENDFOR
	FOR(int, i, 2,  < , 128, i = (i + 4)) {
		push_float(&FFTReorderSimple_53FFTReorderSimple_54, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1], i)) ; 
		push_float(&FFTReorderSimple_53FFTReorderSimple_54, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1], (i + 1))) ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1]) ; 
		pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1]) ; 
	}
	ENDFOR
}


void FFTReorderSimple_54(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		FOR(int, i, 0,  < , 64, i = (i + 4)) {
			push_float(&FFTReorderSimple_54FFTReorderSimple_55, peek_float(&FFTReorderSimple_53FFTReorderSimple_54, i)) ; 
			push_float(&FFTReorderSimple_54FFTReorderSimple_55, peek_float(&FFTReorderSimple_53FFTReorderSimple_54, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 64, i = (i + 4)) {
			push_float(&FFTReorderSimple_54FFTReorderSimple_55, peek_float(&FFTReorderSimple_53FFTReorderSimple_54, i)) ; 
			push_float(&FFTReorderSimple_54FFTReorderSimple_55, peek_float(&FFTReorderSimple_53FFTReorderSimple_54, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 32, i++) {
			pop_float(&FFTReorderSimple_53FFTReorderSimple_54) ; 
			pop_float(&FFTReorderSimple_53FFTReorderSimple_54) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_55(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		FOR(int, i, 0,  < , 32, i = (i + 4)) {
			push_float(&FFTReorderSimple_55FFTReorderSimple_56, peek_float(&FFTReorderSimple_54FFTReorderSimple_55, i)) ; 
			push_float(&FFTReorderSimple_55FFTReorderSimple_56, peek_float(&FFTReorderSimple_54FFTReorderSimple_55, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 32, i = (i + 4)) {
			push_float(&FFTReorderSimple_55FFTReorderSimple_56, peek_float(&FFTReorderSimple_54FFTReorderSimple_55, i)) ; 
			push_float(&FFTReorderSimple_55FFTReorderSimple_56, peek_float(&FFTReorderSimple_54FFTReorderSimple_55, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 16, i++) {
			pop_float(&FFTReorderSimple_54FFTReorderSimple_55) ; 
			pop_float(&FFTReorderSimple_54FFTReorderSimple_55) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_56(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		FOR(int, i, 0,  < , 16, i = (i + 4)) {
			push_float(&FFTReorderSimple_56FFTReorderSimple_57, peek_float(&FFTReorderSimple_55FFTReorderSimple_56, i)) ; 
			push_float(&FFTReorderSimple_56FFTReorderSimple_57, peek_float(&FFTReorderSimple_55FFTReorderSimple_56, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 16, i = (i + 4)) {
			push_float(&FFTReorderSimple_56FFTReorderSimple_57, peek_float(&FFTReorderSimple_55FFTReorderSimple_56, i)) ; 
			push_float(&FFTReorderSimple_56FFTReorderSimple_57, peek_float(&FFTReorderSimple_55FFTReorderSimple_56, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 8, i++) {
			pop_float(&FFTReorderSimple_55FFTReorderSimple_56) ; 
			pop_float(&FFTReorderSimple_55FFTReorderSimple_56) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_57(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		FOR(int, i, 0,  < , 8, i = (i + 4)) {
			push_float(&FFTReorderSimple_57CombineDFT_58, peek_float(&FFTReorderSimple_56FFTReorderSimple_57, i)) ; 
			push_float(&FFTReorderSimple_57CombineDFT_58, peek_float(&FFTReorderSimple_56FFTReorderSimple_57, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 2,  < , 8, i = (i + 4)) {
			push_float(&FFTReorderSimple_57CombineDFT_58, peek_float(&FFTReorderSimple_56FFTReorderSimple_57, i)) ; 
			push_float(&FFTReorderSimple_57CombineDFT_58, peek_float(&FFTReorderSimple_56FFTReorderSimple_57, (i + 1))) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 4, i++) {
			pop_float(&FFTReorderSimple_56FFTReorderSimple_57) ; 
			pop_float(&FFTReorderSimple_56FFTReorderSimple_57) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_58(){
	FOR(uint32_t, __iter_steady_, 0, <, 32, __iter_steady_++) {
		float results[4];
		FOR(int, i, 0,  < , 2, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&FFTReorderSimple_57CombineDFT_58, i) ; 
			y0_i = peek_float(&FFTReorderSimple_57CombineDFT_58, i_plus_1) ; 
			y1_r = peek_float(&FFTReorderSimple_57CombineDFT_58, (2 + i)) ; 
			y1_i = peek_float(&FFTReorderSimple_57CombineDFT_58, (2 + i_plus_1)) ; 
			weight_real = CombineDFT_58_s.w[i] ; 
			weight_imag = CombineDFT_58_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(2 + i)] = (y0_r - y1w_r) ; 
			results[((2 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 4, i++) {
			pop_float(&FFTReorderSimple_57CombineDFT_58) ; 
			push_float(&CombineDFT_58CombineDFT_59, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_59(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		float results[8];
		FOR(int, i, 0,  < , 4, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_58CombineDFT_59, i) ; 
			y0_i = peek_float(&CombineDFT_58CombineDFT_59, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_58CombineDFT_59, (4 + i)) ; 
			y1_i = peek_float(&CombineDFT_58CombineDFT_59, (4 + i_plus_1)) ; 
			weight_real = CombineDFT_59_s.w[i] ; 
			weight_imag = CombineDFT_59_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(4 + i)] = (y0_r - y1w_r) ; 
			results[((4 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 8, i++) {
			pop_float(&CombineDFT_58CombineDFT_59) ; 
			push_float(&CombineDFT_59CombineDFT_60, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_60(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float results[16];
		FOR(int, i, 0,  < , 8, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_59CombineDFT_60, i) ; 
			y0_i = peek_float(&CombineDFT_59CombineDFT_60, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_59CombineDFT_60, (8 + i)) ; 
			y1_i = peek_float(&CombineDFT_59CombineDFT_60, (8 + i_plus_1)) ; 
			weight_real = CombineDFT_60_s.w[i] ; 
			weight_imag = CombineDFT_60_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(8 + i)] = (y0_r - y1w_r) ; 
			results[((8 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 16, i++) {
			pop_float(&CombineDFT_59CombineDFT_60) ; 
			push_float(&CombineDFT_60CombineDFT_61, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_61(){
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		float results[32];
		FOR(int, i, 0,  < , 16, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_60CombineDFT_61, i) ; 
			y0_i = peek_float(&CombineDFT_60CombineDFT_61, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_60CombineDFT_61, (16 + i)) ; 
			y1_i = peek_float(&CombineDFT_60CombineDFT_61, (16 + i_plus_1)) ; 
			weight_real = CombineDFT_61_s.w[i] ; 
			weight_imag = CombineDFT_61_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(16 + i)] = (y0_r - y1w_r) ; 
			results[((16 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 32, i++) {
			pop_float(&CombineDFT_60CombineDFT_61) ; 
			push_float(&CombineDFT_61CombineDFT_62, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_62(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float results[64];
		FOR(int, i, 0,  < , 32, i = (i + 2)) {
			int i_plus_1 = 0;
			float y0_r = 0.0;
			float y0_i = 0.0;
			float y1_r = 0.0;
			float y1_i = 0.0;
			float weight_real = 0.0;
			float weight_imag = 0.0;
			float y1w_r = 0.0;
			float y1w_i = 0.0;
			i_plus_1 = (i + 1) ; 
			y0_r = peek_float(&CombineDFT_61CombineDFT_62, i) ; 
			y0_i = peek_float(&CombineDFT_61CombineDFT_62, i_plus_1) ; 
			y1_r = peek_float(&CombineDFT_61CombineDFT_62, (32 + i)) ; 
			y1_i = peek_float(&CombineDFT_61CombineDFT_62, (32 + i_plus_1)) ; 
			weight_real = CombineDFT_62_s.w[i] ; 
			weight_imag = CombineDFT_62_s.w[i_plus_1] ; 
			y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
			y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
			results[i] = (y0_r + y1w_r) ; 
			results[(i + 1)] = (y0_i + y1w_i) ; 
			results[(32 + i)] = (y0_r - y1w_r) ; 
			results[((32 + i) + 1)] = (y0_i - y1w_i) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 64, i++) {
			pop_float(&CombineDFT_61CombineDFT_62) ; 
			push_float(&CombineDFT_62CombineDFT_63, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_63() {
SimNamedMarker(5, __func__);
	float results[128];
	FOR(int, i, 0,  < , 64, i = (i + 2)) {
		int i_plus_1 = 0;
		float y0_r = 0.0;
		float y0_i = 0.0;
		float y1_r = 0.0;
		float y1_i = 0.0;
		float weight_real = 0.0;
		float weight_imag = 0.0;
		float y1w_r = 0.0;
		float y1w_i = 0.0;
		i_plus_1 = (i + 1) ; 
		y0_r = peek_float(&CombineDFT_62CombineDFT_63, i) ; 
		y0_i = peek_float(&CombineDFT_62CombineDFT_63, i_plus_1) ; 
		y1_r = peek_float(&CombineDFT_62CombineDFT_63, (64 + i)) ; 
		y1_i = peek_float(&CombineDFT_62CombineDFT_63, (64 + i_plus_1)) ; 
		weight_real = CombineDFT_63_s.w[i] ; 
		weight_imag = CombineDFT_63_s.w[i_plus_1] ; 
		y1w_r = ((y1_r * weight_real) - (y1_i * weight_imag)) ; 
		y1w_i = ((y1_r * weight_imag) + (y1_i * weight_real)) ; 
		results[i] = (y0_r + y1w_r) ; 
		results[(i + 1)] = (y0_i + y1w_i) ; 
		results[(64 + i)] = (y0_r - y1w_r) ; 
		results[((64 + i) + 1)] = (y0_i - y1w_i) ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 128, i++) {
		pop_float(&CombineDFT_62CombineDFT_63) ; 
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_join[1], results[i]) ; 
	}
	ENDFOR
}


void WEIGHTED_ROUND_ROBIN_Splitter_65() {
	FOR(uint32_t, __iter_, 0, <, 128, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[0], pop_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 128, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[1], pop_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_66() {
SimNamedMarker(5, __func__);
	FOR(uint32_t, __iter_, 0, <, 128, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_66FloatPrinter_64, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_join[0]));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 128, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_66FloatPrinter_64, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_join[1]));
	ENDFOR
}

void FloatPrinter_64(){
	FOR(uint32_t, __iter_steady_, 0, <, 256, __iter_steady_++) {
		printf("%.10f", pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_66FloatPrinter_64));
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&FFTReorderSimple_46CombineDFT_47);
	init_buffer_float(&CombineDFT_48CombineDFT_49);
	FOR(int, __iter_init_0_, 0, <, 2, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_join[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&CombineDFT_47CombineDFT_48);
	init_buffer_float(&FFTTestSource_41WEIGHTED_ROUND_ROBIN_Splitter_65);
	init_buffer_float(&CombineDFT_62CombineDFT_63);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_66FloatPrinter_64);
	init_buffer_float(&FFTReorderSimple_57CombineDFT_58);
	init_buffer_float(&CombineDFT_61CombineDFT_62);
	init_buffer_float(&CombineDFT_49CombineDFT_50);
	init_buffer_float(&CombineDFT_60CombineDFT_61);
	init_buffer_float(&CombineDFT_59CombineDFT_60);
	init_buffer_float(&CombineDFT_51CombineDFT_52);
	init_buffer_float(&CombineDFT_50CombineDFT_51);
	init_buffer_float(&FFTReorderSimple_53FFTReorderSimple_54);
	init_buffer_float(&FFTReorderSimple_55FFTReorderSimple_56);
	init_buffer_float(&FFTReorderSimple_54FFTReorderSimple_55);
	init_buffer_float(&FFTReorderSimple_42FFTReorderSimple_43);
	init_buffer_float(&FFTReorderSimple_56FFTReorderSimple_57);
	init_buffer_float(&FFTReorderSimple_43FFTReorderSimple_44);
	FOR(int, __iter_init_1_, 0, <, 2, __iter_init_1_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_FFTKernel2_31_67_70_74_split[__iter_init_1_]);
	ENDFOR
	init_buffer_float(&FFTReorderSimple_44FFTReorderSimple_45);
	init_buffer_float(&CombineDFT_58CombineDFT_59);
	init_buffer_float(&FFTReorderSimple_45FFTReorderSimple_46);
// --- init: CombineDFT_47
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 2, i = (i + 2)) {
		CombineDFT_47_s.w[i] = real ; 
		CombineDFT_47_s.w[(i + 1)] = imag ; 
		next_real = ((real * -1.0) - (imag * 8.742278E-8)) ; 
		next_imag = ((real * 8.742278E-8) + (imag * -1.0)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_48
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 4, i = (i + 2)) {
		CombineDFT_48_s.w[i] = real ; 
		CombineDFT_48_s.w[(i + 1)] = imag ; 
		next_real = ((real * -4.371139E-8) - (imag * -1.0)) ; 
		next_imag = ((real * -1.0) + (imag * -4.371139E-8)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_49
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 8, i = (i + 2)) {
		CombineDFT_49_s.w[i] = real ; 
		CombineDFT_49_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.70710677) - (imag * -0.70710677)) ; 
		next_imag = ((real * -0.70710677) + (imag * 0.70710677)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_50
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 16, i = (i + 2)) {
		CombineDFT_50_s.w[i] = real ; 
		CombineDFT_50_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.9238795) - (imag * -0.38268346)) ; 
		next_imag = ((real * -0.38268346) + (imag * 0.9238795)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_51
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 32, i = (i + 2)) {
		CombineDFT_51_s.w[i] = real ; 
		CombineDFT_51_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.98078525) - (imag * -0.19509032)) ; 
		next_imag = ((real * -0.19509032) + (imag * 0.98078525)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_52
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 64, i = (i + 2)) {
		CombineDFT_52_s.w[i] = real ; 
		CombineDFT_52_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.9951847) - (imag * -0.09801714)) ; 
		next_imag = ((real * -0.09801714) + (imag * 0.9951847)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_58
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 2, i = (i + 2)) {
		CombineDFT_58_s.w[i] = real ; 
		CombineDFT_58_s.w[(i + 1)] = imag ; 
		next_real = ((real * -1.0) - (imag * 8.742278E-8)) ; 
		next_imag = ((real * 8.742278E-8) + (imag * -1.0)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_59
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 4, i = (i + 2)) {
		CombineDFT_59_s.w[i] = real ; 
		CombineDFT_59_s.w[(i + 1)] = imag ; 
		next_real = ((real * -4.371139E-8) - (imag * -1.0)) ; 
		next_imag = ((real * -1.0) + (imag * -4.371139E-8)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_60
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 8, i = (i + 2)) {
		CombineDFT_60_s.w[i] = real ; 
		CombineDFT_60_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.70710677) - (imag * -0.70710677)) ; 
		next_imag = ((real * -0.70710677) + (imag * 0.70710677)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_61
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 16, i = (i + 2)) {
		CombineDFT_61_s.w[i] = real ; 
		CombineDFT_61_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.9238795) - (imag * -0.38268346)) ; 
		next_imag = ((real * -0.38268346) + (imag * 0.9238795)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_62
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 32, i = (i + 2)) {
		CombineDFT_62_s.w[i] = real ; 
		CombineDFT_62_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.98078525) - (imag * -0.19509032)) ; 
		next_imag = ((real * -0.19509032) + (imag * 0.98078525)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: CombineDFT_63
	 {
	float real = 0.0;
	float imag = 0.0;
	float next_real = 0.0;
	float next_imag = 0.0;
	real = 1.0 ; 
	FOR(int, i, 0,  < , 64, i = (i + 2)) {
		CombineDFT_63_s.w[i] = real ; 
		CombineDFT_63_s.w[(i + 1)] = imag ; 
		next_real = ((real * 0.9951847) - (imag * -0.09801714)) ; 
		next_imag = ((real * -0.09801714) + (imag * 0.9951847)) ; 
		real = next_real ; 
		imag = next_imag ; 
	}
	ENDFOR
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		FFTTestSource_41();
		WEIGHTED_ROUND_ROBIN_Splitter_65();
			FFTReorderSimple_42();
			FFTReorderSimple_43();
			FFTReorderSimple_44();
			FFTReorderSimple_45();
			FFTReorderSimple_46();
			CombineDFT_47();
			CombineDFT_48();
			CombineDFT_49();
			CombineDFT_50();
			CombineDFT_51();
			CombineDFT_52();
			FFTReorderSimple_53();
			FFTReorderSimple_54();
			FFTReorderSimple_55();
			FFTReorderSimple_56();
			FFTReorderSimple_57();
			CombineDFT_58();
			CombineDFT_59();
			CombineDFT_60();
			CombineDFT_61();
			CombineDFT_62();
			CombineDFT_63();
		WEIGHTED_ROUND_ROBIN_Joiner_66();
		FloatPrinter_64();
	ENDFOR
	return EXIT_SUCCESS;
}
