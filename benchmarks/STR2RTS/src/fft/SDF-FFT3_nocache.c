#include "SDF-FFT3_nocache.h"

buffer_float_t Butterfly_168Post_CollapsedDataParallel_2_445;
buffer_float_t Pre_CollapsedDataParallel_1_426Butterfly_150;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_538WEIGHTED_ROUND_ROBIN_Splitter_543;
buffer_float_t SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[4];
buffer_float_t Butterfly_114Post_CollapsedDataParallel_2_415;
buffer_float_t Pre_CollapsedDataParallel_1_438Butterfly_164;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[2];
buffer_float_t Butterfly_174Post_CollapsedDataParallel_2_454;
buffer_float_t Butterfly_150Post_CollapsedDataParallel_2_427;
buffer_float_t Pre_CollapsedDataParallel_1_456Butterfly_176;
buffer_float_t FloatSource_113Pre_CollapsedDataParallel_1_414;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[2];
buffer_float_t SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_join[2];
buffer_float_t Butterfly_130Post_CollapsedDataParallel_2_418;
buffer_float_t Pre_CollapsedDataParallel_1_423Butterfly_146;
buffer_float_t Butterfly_158Post_CollapsedDataParallel_2_433;
buffer_float_t SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[8];
buffer_float_t Pre_CollapsedDataParallel_1_414Butterfly_114;
buffer_float_t SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_split[2];
buffer_float_t SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_join[2];
buffer_float_t BitReverse_194FloatPrinter_195;
buffer_float_t Butterfly_146Post_CollapsedDataParallel_2_424;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_544WEIGHTED_ROUND_ROBIN_Splitter_549;
buffer_float_t Pre_CollapsedDataParallel_1_444Butterfly_168;
buffer_float_t Pre_CollapsedDataParallel_1_441Butterfly_166;
buffer_float_t SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[8];
buffer_float_t Pre_CollapsedDataParallel_1_420Butterfly_138;
buffer_float_t SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[2];
buffer_float_t Butterfly_138Post_CollapsedDataParallel_2_421;
buffer_float_t Butterfly_164Post_CollapsedDataParallel_2_439;
buffer_float_t Pre_CollapsedDataParallel_1_435Butterfly_162;
buffer_float_t Pre_CollapsedDataParallel_1_447Butterfly_170;
buffer_float_t Butterfly_170Post_CollapsedDataParallel_2_448;
buffer_float_t Butterfly_154Post_CollapsedDataParallel_2_430;
buffer_float_t Pre_CollapsedDataParallel_1_429Butterfly_154;
buffer_float_t Post_CollapsedDataParallel_2_421WEIGHTED_ROUND_ROBIN_Splitter_541;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_join[2];
buffer_float_t SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[8];
buffer_float_t Post_CollapsedDataParallel_2_415WEIGHTED_ROUND_ROBIN_Splitter_458;
buffer_float_t Post_CollapsedDataParallel_2_418WEIGHTED_ROUND_ROBIN_Splitter_539;
buffer_float_t Butterfly_176Post_CollapsedDataParallel_2_457;
buffer_float_t SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_join[2];
buffer_float_t Butterfly_172Post_CollapsedDataParallel_2_451;
buffer_float_t SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[4];
buffer_float_t Pre_CollapsedDataParallel_1_432Butterfly_158;
buffer_float_t Pre_CollapsedDataParallel_1_417Butterfly_130;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[2];
buffer_float_t SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[4];
buffer_float_t SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[8];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194;
buffer_float_t SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[4];
buffer_float_t Pre_CollapsedDataParallel_1_453Butterfly_174;
buffer_float_t Pre_CollapsedDataParallel_1_450Butterfly_172;
buffer_float_t SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_split[2];
buffer_float_t Butterfly_166Post_CollapsedDataParallel_2_442;
buffer_float_t Butterfly_162Post_CollapsedDataParallel_2_436;


FloatSource_113_t FloatSource_113_s;

void FloatSource_113(){
	FOR(uint32_t, __iter_steady_, 0, <, 32, __iter_steady_++) {
		push_float(&FloatSource_113Pre_CollapsedDataParallel_1_414, FloatSource_113_s.A_re[FloatSource_113_s.idx]) ; 
		push_float(&FloatSource_113Pre_CollapsedDataParallel_1_414, FloatSource_113_s.A_im[FloatSource_113_s.idx]) ; 
		FloatSource_113_s.idx++ ; 
		if((FloatSource_113_s.idx >= 32)) {
			FloatSource_113_s.idx = 0 ; 
		}
	}
	ENDFOR
}

void Pre_CollapsedDataParallel_1_414() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 16, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_414Butterfly_114, peek_float(&FloatSource_113Pre_CollapsedDataParallel_1_414, (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 32) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&FloatSource_113Pre_CollapsedDataParallel_1_414) ; 
}


void Butterfly_114(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_414Butterfly_114) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_414Butterfly_114) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_414Butterfly_114) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_414Butterfly_114) ; 
		wt_re = ((1.0 * t_re) - (0.0 * t_im)) ; 
		wt_im = ((1.0 * t_im) + (0.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_114Post_CollapsedDataParallel_2_415, u_re) ; 
		push_float(&Butterfly_114Post_CollapsedDataParallel_2_415, u_im) ; 
		push_float(&Butterfly_114Post_CollapsedDataParallel_2_415, t_re) ; 
		push_float(&Butterfly_114Post_CollapsedDataParallel_2_415, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_415() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 16, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Post_CollapsedDataParallel_2_415WEIGHTED_ROUND_ROBIN_Splitter_458, peek_float(&Butterfly_114Post_CollapsedDataParallel_2_415, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_114Post_CollapsedDataParallel_2_415) ; 
}


void Pre_CollapsedDataParallel_1_417() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_417Butterfly_130, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[0], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 16) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[0]) ; 
}


void Butterfly_130(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_417Butterfly_130) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_417Butterfly_130) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_417Butterfly_130) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_417Butterfly_130) ; 
		wt_re = ((1.0 * t_re) - (0.0 * t_im)) ; 
		wt_im = ((1.0 * t_im) + (0.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_130Post_CollapsedDataParallel_2_418, u_re) ; 
		push_float(&Butterfly_130Post_CollapsedDataParallel_2_418, u_im) ; 
		push_float(&Butterfly_130Post_CollapsedDataParallel_2_418, t_re) ; 
		push_float(&Butterfly_130Post_CollapsedDataParallel_2_418, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_418() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 8, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Post_CollapsedDataParallel_2_418WEIGHTED_ROUND_ROBIN_Splitter_539, peek_float(&Butterfly_130Post_CollapsedDataParallel_2_418, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_130Post_CollapsedDataParallel_2_418) ; 
}


void Pre_CollapsedDataParallel_1_423() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 4, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_423Butterfly_146, peek_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[0], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 8) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[0]) ; 
}


void Butterfly_146(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_423Butterfly_146) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_423Butterfly_146) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_423Butterfly_146) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_423Butterfly_146) ; 
		wt_re = ((1.0 * t_re) - (0.0 * t_im)) ; 
		wt_im = ((1.0 * t_im) + (0.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_146Post_CollapsedDataParallel_2_424, u_re) ; 
		push_float(&Butterfly_146Post_CollapsedDataParallel_2_424, u_im) ; 
		push_float(&Butterfly_146Post_CollapsedDataParallel_2_424, t_re) ; 
		push_float(&Butterfly_146Post_CollapsedDataParallel_2_424, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_424() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 4, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_join[0], peek_float(&Butterfly_146Post_CollapsedDataParallel_2_424, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_146Post_CollapsedDataParallel_2_424) ; 
}


void Pre_CollapsedDataParallel_1_426() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 4, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_426Butterfly_150, peek_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[1], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 8) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[1]) ; 
}


void Butterfly_150(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_426Butterfly_150) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_426Butterfly_150) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_426Butterfly_150) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_426Butterfly_150) ; 
		wt_re = ((-4.371139E-8 * t_re) - (1.0 * t_im)) ; 
		wt_im = ((-4.371139E-8 * t_im) + (1.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_150Post_CollapsedDataParallel_2_427, u_re) ; 
		push_float(&Butterfly_150Post_CollapsedDataParallel_2_427, u_im) ; 
		push_float(&Butterfly_150Post_CollapsedDataParallel_2_427, t_re) ; 
		push_float(&Butterfly_150Post_CollapsedDataParallel_2_427, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_427() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 4, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_join[1], peek_float(&Butterfly_150Post_CollapsedDataParallel_2_427, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_150Post_CollapsedDataParallel_2_427) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_539() {
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[0], pop_float(&Post_CollapsedDataParallel_2_418WEIGHTED_ROUND_ROBIN_Splitter_539));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[1], pop_float(&Post_CollapsedDataParallel_2_418WEIGHTED_ROUND_ROBIN_Splitter_539));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_540() {
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[0], pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_join[0]));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[0], pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_join[1]));
	ENDFOR
}

void Pre_CollapsedDataParallel_1_420() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 8, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_420Butterfly_138, peek_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[1], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 16) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[1]) ; 
}


void Butterfly_138(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_420Butterfly_138) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_420Butterfly_138) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_420Butterfly_138) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_420Butterfly_138) ; 
		wt_re = ((-4.371139E-8 * t_re) - (1.0 * t_im)) ; 
		wt_im = ((-4.371139E-8 * t_im) + (1.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_138Post_CollapsedDataParallel_2_421, u_re) ; 
		push_float(&Butterfly_138Post_CollapsedDataParallel_2_421, u_im) ; 
		push_float(&Butterfly_138Post_CollapsedDataParallel_2_421, t_re) ; 
		push_float(&Butterfly_138Post_CollapsedDataParallel_2_421, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_421() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 8, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Post_CollapsedDataParallel_2_421WEIGHTED_ROUND_ROBIN_Splitter_541, peek_float(&Butterfly_138Post_CollapsedDataParallel_2_421, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_138Post_CollapsedDataParallel_2_421) ; 
}


void Pre_CollapsedDataParallel_1_429() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 4, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_429Butterfly_154, peek_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[0], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 8) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[0]) ; 
}


void Butterfly_154(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_429Butterfly_154) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_429Butterfly_154) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_429Butterfly_154) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_429Butterfly_154) ; 
		wt_re = ((0.70710677 * t_re) - (0.70710677 * t_im)) ; 
		wt_im = ((0.70710677 * t_im) + (0.70710677 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_154Post_CollapsedDataParallel_2_430, u_re) ; 
		push_float(&Butterfly_154Post_CollapsedDataParallel_2_430, u_im) ; 
		push_float(&Butterfly_154Post_CollapsedDataParallel_2_430, t_re) ; 
		push_float(&Butterfly_154Post_CollapsedDataParallel_2_430, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_430() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 4, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_join[0], peek_float(&Butterfly_154Post_CollapsedDataParallel_2_430, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_154Post_CollapsedDataParallel_2_430) ; 
}


void Pre_CollapsedDataParallel_1_432() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 4, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_432Butterfly_158, peek_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[1], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 8) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[1]) ; 
}


void Butterfly_158(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_432Butterfly_158) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_432Butterfly_158) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_432Butterfly_158) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_432Butterfly_158) ; 
		wt_re = ((-0.70710677 * t_re) - (0.70710677 * t_im)) ; 
		wt_im = ((-0.70710677 * t_im) + (0.70710677 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_158Post_CollapsedDataParallel_2_433, u_re) ; 
		push_float(&Butterfly_158Post_CollapsedDataParallel_2_433, u_im) ; 
		push_float(&Butterfly_158Post_CollapsedDataParallel_2_433, t_re) ; 
		push_float(&Butterfly_158Post_CollapsedDataParallel_2_433, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_433() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 4, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_join[1], peek_float(&Butterfly_158Post_CollapsedDataParallel_2_433, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_158Post_CollapsedDataParallel_2_433) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_541() {
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[0], pop_float(&Post_CollapsedDataParallel_2_421WEIGHTED_ROUND_ROBIN_Splitter_541));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[1], pop_float(&Post_CollapsedDataParallel_2_421WEIGHTED_ROUND_ROBIN_Splitter_541));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_542() {
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[1], pop_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_join[0]));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 16, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[1], pop_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_join[1]));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Splitter_458() {
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[0], pop_float(&Post_CollapsedDataParallel_2_415WEIGHTED_ROUND_ROBIN_Splitter_458));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[1], pop_float(&Post_CollapsedDataParallel_2_415WEIGHTED_ROUND_ROBIN_Splitter_458));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_538() {
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_538WEIGHTED_ROUND_ROBIN_Splitter_543, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[0]));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_538WEIGHTED_ROUND_ROBIN_Splitter_543, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[1]));
	ENDFOR
}

void Pre_CollapsedDataParallel_1_435() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_435Butterfly_162, peek_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[0], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[0]) ; 
}


void Butterfly_162(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_435Butterfly_162) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_435Butterfly_162) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_435Butterfly_162) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_435Butterfly_162) ; 
		wt_re = ((1.0 * t_re) - (0.0 * t_im)) ; 
		wt_im = ((1.0 * t_im) + (0.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_162Post_CollapsedDataParallel_2_436, u_re) ; 
		push_float(&Butterfly_162Post_CollapsedDataParallel_2_436, u_im) ; 
		push_float(&Butterfly_162Post_CollapsedDataParallel_2_436, t_re) ; 
		push_float(&Butterfly_162Post_CollapsedDataParallel_2_436, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_436() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[0], peek_float(&Butterfly_162Post_CollapsedDataParallel_2_436, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_162Post_CollapsedDataParallel_2_436) ; 
}


void Pre_CollapsedDataParallel_1_438() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_438Butterfly_164, peek_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[1], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[1]) ; 
}


void Butterfly_164(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_438Butterfly_164) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_438Butterfly_164) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_438Butterfly_164) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_438Butterfly_164) ; 
		wt_re = ((-4.371139E-8 * t_re) - (1.0 * t_im)) ; 
		wt_im = ((-4.371139E-8 * t_im) + (1.0 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_164Post_CollapsedDataParallel_2_439, u_re) ; 
		push_float(&Butterfly_164Post_CollapsedDataParallel_2_439, u_im) ; 
		push_float(&Butterfly_164Post_CollapsedDataParallel_2_439, t_re) ; 
		push_float(&Butterfly_164Post_CollapsedDataParallel_2_439, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_439() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[1], peek_float(&Butterfly_164Post_CollapsedDataParallel_2_439, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_164Post_CollapsedDataParallel_2_439) ; 
}


void Pre_CollapsedDataParallel_1_441() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_441Butterfly_166, peek_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[2], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[2]) ; 
}


void Butterfly_166(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_441Butterfly_166) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_441Butterfly_166) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_441Butterfly_166) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_441Butterfly_166) ; 
		wt_re = ((0.70710677 * t_re) - (0.70710677 * t_im)) ; 
		wt_im = ((0.70710677 * t_im) + (0.70710677 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_166Post_CollapsedDataParallel_2_442, u_re) ; 
		push_float(&Butterfly_166Post_CollapsedDataParallel_2_442, u_im) ; 
		push_float(&Butterfly_166Post_CollapsedDataParallel_2_442, t_re) ; 
		push_float(&Butterfly_166Post_CollapsedDataParallel_2_442, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_442() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[2], peek_float(&Butterfly_166Post_CollapsedDataParallel_2_442, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_166Post_CollapsedDataParallel_2_442) ; 
}


void Pre_CollapsedDataParallel_1_444() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_444Butterfly_168, peek_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[3], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[3]) ; 
}


void Butterfly_168(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_444Butterfly_168) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_444Butterfly_168) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_444Butterfly_168) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_444Butterfly_168) ; 
		wt_re = ((-0.70710677 * t_re) - (0.70710677 * t_im)) ; 
		wt_im = ((-0.70710677 * t_im) + (0.70710677 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_168Post_CollapsedDataParallel_2_445, u_re) ; 
		push_float(&Butterfly_168Post_CollapsedDataParallel_2_445, u_im) ; 
		push_float(&Butterfly_168Post_CollapsedDataParallel_2_445, t_re) ; 
		push_float(&Butterfly_168Post_CollapsedDataParallel_2_445, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_445() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[3], peek_float(&Butterfly_168Post_CollapsedDataParallel_2_445, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_168Post_CollapsedDataParallel_2_445) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_545() {
	FOR(uint32_t, __iter_dec_, 0, <, 4, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[__iter_dec_], pop_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_split[0]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_546() {
	FOR(uint32_t, __iter_dec_, 0, <, 4, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_join[0], pop_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void Pre_CollapsedDataParallel_1_447() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_447Butterfly_170, peek_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[0], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[0]) ; 
}


void Butterfly_170(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_447Butterfly_170) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_447Butterfly_170) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_447Butterfly_170) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_447Butterfly_170) ; 
		wt_re = ((0.9238795 * t_re) - (0.38268346 * t_im)) ; 
		wt_im = ((0.9238795 * t_im) + (0.38268346 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_170Post_CollapsedDataParallel_2_448, u_re) ; 
		push_float(&Butterfly_170Post_CollapsedDataParallel_2_448, u_im) ; 
		push_float(&Butterfly_170Post_CollapsedDataParallel_2_448, t_re) ; 
		push_float(&Butterfly_170Post_CollapsedDataParallel_2_448, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_448() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[0], peek_float(&Butterfly_170Post_CollapsedDataParallel_2_448, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_170Post_CollapsedDataParallel_2_448) ; 
}


void Pre_CollapsedDataParallel_1_450() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_450Butterfly_172, peek_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[1], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[1]) ; 
}


void Butterfly_172(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_450Butterfly_172) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_450Butterfly_172) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_450Butterfly_172) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_450Butterfly_172) ; 
		wt_re = ((-0.38268352 * t_re) - (0.9238795 * t_im)) ; 
		wt_im = ((-0.38268352 * t_im) + (0.9238795 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_172Post_CollapsedDataParallel_2_451, u_re) ; 
		push_float(&Butterfly_172Post_CollapsedDataParallel_2_451, u_im) ; 
		push_float(&Butterfly_172Post_CollapsedDataParallel_2_451, t_re) ; 
		push_float(&Butterfly_172Post_CollapsedDataParallel_2_451, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_451() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[1], peek_float(&Butterfly_172Post_CollapsedDataParallel_2_451, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_172Post_CollapsedDataParallel_2_451) ; 
}


void Pre_CollapsedDataParallel_1_453() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_453Butterfly_174, peek_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[2], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[2]) ; 
}


void Butterfly_174(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_453Butterfly_174) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_453Butterfly_174) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_453Butterfly_174) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_453Butterfly_174) ; 
		wt_re = ((0.38268343 * t_re) - (0.9238795 * t_im)) ; 
		wt_im = ((0.38268343 * t_im) + (0.9238795 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_174Post_CollapsedDataParallel_2_454, u_re) ; 
		push_float(&Butterfly_174Post_CollapsedDataParallel_2_454, u_im) ; 
		push_float(&Butterfly_174Post_CollapsedDataParallel_2_454, t_re) ; 
		push_float(&Butterfly_174Post_CollapsedDataParallel_2_454, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_454() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[2], peek_float(&Butterfly_174Post_CollapsedDataParallel_2_454, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_174Post_CollapsedDataParallel_2_454) ; 
}


void Pre_CollapsedDataParallel_1_456() {
 {
	int partialSum_k = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int iTimesSumOfWeights_Plus_PartialSum_k = partialSum_k;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&Pre_CollapsedDataParallel_1_456Butterfly_176, peek_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[3], (iTimesSumOfWeights_Plus_PartialSum_k + _j))) ; 
			}
			ENDFOR
		}
			iTimesSumOfWeights_Plus_PartialSum_k = (iTimesSumOfWeights_Plus_PartialSum_k + 4) ; 
		}
		ENDFOR
	}
		partialSum_k = (partialSum_k + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[3]) ; 
}


void Butterfly_176(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		float u_re = 0.0;
		float u_im = 0.0;
		float t_re = 0.0;
		float t_im = 0.0;
		float wt_re = 0.0;
		float wt_im = 0.0;
		u_re = pop_float(&Pre_CollapsedDataParallel_1_456Butterfly_176) ; 
		u_im = pop_float(&Pre_CollapsedDataParallel_1_456Butterfly_176) ; 
		t_re = pop_float(&Pre_CollapsedDataParallel_1_456Butterfly_176) ; 
		t_im = pop_float(&Pre_CollapsedDataParallel_1_456Butterfly_176) ; 
		wt_re = ((-0.9238796 * t_re) - (0.38268328 * t_im)) ; 
		wt_im = ((-0.9238796 * t_im) + (0.38268328 * t_re)) ; 
		t_re = (u_re - wt_re) ; 
		t_im = (u_im - wt_im) ; 
		u_re = (u_re + wt_re) ; 
		u_im = (u_im + wt_im) ; 
		push_float(&Butterfly_176Post_CollapsedDataParallel_2_457, u_re) ; 
		push_float(&Butterfly_176Post_CollapsedDataParallel_2_457, u_im) ; 
		push_float(&Butterfly_176Post_CollapsedDataParallel_2_457, t_re) ; 
		push_float(&Butterfly_176Post_CollapsedDataParallel_2_457, t_im) ; 
	}
	ENDFOR
}

void Post_CollapsedDataParallel_2_457() {
 {
	int kTimesWeights_i = 0;
 {
	FOR(int, _k, 0,  < , 2, _k++) {
		int partialSum_i = 0;
 {
		FOR(int, _i, 0,  < , 2, _i++) {
 {
			FOR(int, _j, 0,  < , 2, _j++) {
				push_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[3], peek_float(&Butterfly_176Post_CollapsedDataParallel_2_457, (kTimesWeights_i + (partialSum_i + _j)))) ; 
			}
			ENDFOR
		}
			partialSum_i = (partialSum_i + 4) ; 
		}
		ENDFOR
	}
		kTimesWeights_i = (kTimesWeights_i + 2) ; 
	}
	ENDFOR
}
}
	pop_float(&Butterfly_176Post_CollapsedDataParallel_2_457) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_547() {
	FOR(uint32_t, __iter_dec_, 0, <, 4, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[__iter_dec_], pop_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_split[1]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_548() {
	FOR(uint32_t, __iter_dec_, 0, <, 4, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 8, __iter_tok_++)
			push_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_join[1], pop_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Splitter_543() {
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_split[0], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_538WEIGHTED_ROUND_ROBIN_Splitter_543));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_split[1], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_538WEIGHTED_ROUND_ROBIN_Splitter_543));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_544() {
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_544WEIGHTED_ROUND_ROBIN_Splitter_549, pop_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_join[0]));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_544WEIGHTED_ROUND_ROBIN_Splitter_549, pop_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_join[1]));
	ENDFOR
}

void Butterfly_178() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[0]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[0]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[0]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[0]) ; 
	wt_re = ((1.0 * t_re) - (0.0 * t_im)) ; 
	wt_im = ((1.0 * t_im) + (0.0 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[0], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[0], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[0], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[0], t_im) ; 
}


void Butterfly_179() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[1]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[1]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[1]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[1]) ; 
	wt_re = ((-4.371139E-8 * t_re) - (1.0 * t_im)) ; 
	wt_im = ((-4.371139E-8 * t_im) + (1.0 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[1], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[1], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[1], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[1], t_im) ; 
}


void Butterfly_180() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[2]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[2]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[2]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[2]) ; 
	wt_re = ((0.70710677 * t_re) - (0.70710677 * t_im)) ; 
	wt_im = ((0.70710677 * t_im) + (0.70710677 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[2], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[2], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[2], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[2], t_im) ; 
}


void Butterfly_181() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[3]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[3]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[3]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[3]) ; 
	wt_re = ((-0.70710677 * t_re) - (0.70710677 * t_im)) ; 
	wt_im = ((-0.70710677 * t_im) + (0.70710677 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[3], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[3], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[3], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[3], t_im) ; 
}


void Butterfly_182() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[4]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[4]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[4]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[4]) ; 
	wt_re = ((0.9238795 * t_re) - (0.38268346 * t_im)) ; 
	wt_im = ((0.9238795 * t_im) + (0.38268346 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[4], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[4], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[4], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[4], t_im) ; 
}


void Butterfly_183() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[5]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[5]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[5]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[5]) ; 
	wt_re = ((-0.38268352 * t_re) - (0.9238795 * t_im)) ; 
	wt_im = ((-0.38268352 * t_im) + (0.9238795 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[5], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[5], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[5], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[5], t_im) ; 
}


void Butterfly_184() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[6]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[6]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[6]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[6]) ; 
	wt_re = ((0.38268343 * t_re) - (0.9238795 * t_im)) ; 
	wt_im = ((0.38268343 * t_im) + (0.9238795 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[6], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[6], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[6], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[6], t_im) ; 
}


void Butterfly_185() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[7]) ; 
	u_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[7]) ; 
	t_re = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[7]) ; 
	t_im = pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[7]) ; 
	wt_re = ((-0.9238796 * t_re) - (0.38268328 * t_im)) ; 
	wt_im = ((-0.9238796 * t_im) + (0.38268328 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[7], u_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[7], u_im) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[7], t_re) ; 
	push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[7], t_im) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_551() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 4, __iter_tok_++)
			push_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[__iter_dec_], pop_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_split[0]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_552() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 4, __iter_tok_++)
			push_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_join[0], pop_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void Butterfly_186() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[0]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[0]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[0]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[0]) ; 
	wt_re = ((0.98078525 * t_re) - (0.19509032 * t_im)) ; 
	wt_im = ((0.98078525 * t_im) + (0.19509032 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[0], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[0], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[0], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[0], t_im) ; 
}


void Butterfly_187() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[1]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[1]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[1]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[1]) ; 
	wt_re = ((-0.19509032 * t_re) - (0.98078525 * t_im)) ; 
	wt_im = ((-0.19509032 * t_im) + (0.98078525 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[1], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[1], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[1], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[1], t_im) ; 
}


void Butterfly_188() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[2]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[2]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[2]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[2]) ; 
	wt_re = ((0.5555702 * t_re) - (0.83146966 * t_im)) ; 
	wt_im = ((0.5555702 * t_im) + (0.83146966 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[2], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[2], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[2], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[2], t_im) ; 
}


void Butterfly_189() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[3]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[3]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[3]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[3]) ; 
	wt_re = ((-0.83146966 * t_re) - (0.5555702 * t_im)) ; 
	wt_im = ((-0.83146966 * t_im) + (0.5555702 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[3], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[3], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[3], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[3], t_im) ; 
}


void Butterfly_190() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[4]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[4]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[4]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[4]) ; 
	wt_re = ((0.8314696 * t_re) - (0.55557024 * t_im)) ; 
	wt_im = ((0.8314696 * t_im) + (0.55557024 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[4], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[4], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[4], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[4], t_im) ; 
}


void Butterfly_191() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[5]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[5]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[5]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[5]) ; 
	wt_re = ((-0.55557036 * t_re) - (0.83146954 * t_im)) ; 
	wt_im = ((-0.55557036 * t_im) + (0.83146954 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[5], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[5], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[5], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[5], t_im) ; 
}


void Butterfly_192() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[6]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[6]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[6]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[6]) ; 
	wt_re = ((0.19509023 * t_re) - (0.9807853 * t_im)) ; 
	wt_im = ((0.19509023 * t_im) + (0.9807853 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[6], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[6], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[6], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[6], t_im) ; 
}


void Butterfly_193() {
	float u_re = 0.0;
	float u_im = 0.0;
	float t_re = 0.0;
	float t_im = 0.0;
	float wt_re = 0.0;
	float wt_im = 0.0;
	u_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[7]) ; 
	u_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[7]) ; 
	t_re = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[7]) ; 
	t_im = pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[7]) ; 
	wt_re = ((-0.9807853 * t_re) - (0.19509031 * t_im)) ; 
	wt_im = ((-0.9807853 * t_im) + (0.19509031 * t_re)) ; 
	t_re = (u_re - wt_re) ; 
	t_im = (u_im - wt_im) ; 
	u_re = (u_re + wt_re) ; 
	u_im = (u_im + wt_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[7], u_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[7], u_im) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[7], t_re) ; 
	push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[7], t_im) ; 
}


void WEIGHTED_ROUND_ROBIN_Splitter_553() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 4, __iter_tok_++)
			push_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[__iter_dec_], pop_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_split[1]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_554() {
	FOR(uint32_t, __iter_dec_, 0, <, 8, __iter_dec_++)
		FOR(uint32_t, __iter_tok_, 0, <, 4, __iter_tok_++)
			push_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_join[1], pop_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[__iter_dec_]));
		ENDFOR
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Splitter_549() {
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_split[0], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_544WEIGHTED_ROUND_ROBIN_Splitter_549));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_split[1], pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_544WEIGHTED_ROUND_ROBIN_Splitter_549));
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_550() {
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194, pop_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_join[0]));
	ENDFOR
	FOR(uint32_t, __iter_, 0, <, 32, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194, pop_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_join[1]));
	ENDFOR
}

int BitReverse_194_bitrev(int inp) {
	int rev = 0;
	FOR(int, i, 0,  < , 5, i++) {
		rev = ((rev * 2) | (inp & 1)) ; 
		inp = (inp / 2) ; 
	}
	ENDFOR
	return rev;
}
void BitReverse_194() {
	FOR(int, i__conflict__0, 0,  < , 32, i__conflict__0++) {
		int br = 0;
		br = BitReverse_194_bitrev(i__conflict__0) ; 
		push_float(&BitReverse_194FloatPrinter_195, peek_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194, (2 * br))) ; 
		push_float(&BitReverse_194FloatPrinter_195, peek_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194, ((2 * br) + 1))) ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 32, i++) {
		pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194) ; 
		pop_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194) ; 
	}
	ENDFOR
}


void FloatPrinter_195(){
	FOR(uint32_t, __iter_steady_, 0, <, 32, __iter_steady_++) {
		printf("%.10f", pop_float(&BitReverse_194FloatPrinter_195));
		printf("\n");
		printf("%.10f", pop_float(&BitReverse_194FloatPrinter_195));
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&Butterfly_168Post_CollapsedDataParallel_2_445);
	init_buffer_float(&Pre_CollapsedDataParallel_1_426Butterfly_150);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_538WEIGHTED_ROUND_ROBIN_Splitter_543);
	FOR(int, __iter_init_0_, 0, <, 4, __iter_init_0_++)
		init_buffer_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_join[__iter_init_0_]);
	ENDFOR
	init_buffer_float(&Butterfly_114Post_CollapsedDataParallel_2_415);
	init_buffer_float(&Pre_CollapsedDataParallel_1_438Butterfly_164);
	FOR(int, __iter_init_1_, 0, <, 2, __iter_init_1_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_split[__iter_init_1_]);
	ENDFOR
	init_buffer_float(&Butterfly_174Post_CollapsedDataParallel_2_454);
	init_buffer_float(&Butterfly_150Post_CollapsedDataParallel_2_427);
	init_buffer_float(&Pre_CollapsedDataParallel_1_456Butterfly_176);
	init_buffer_float(&FloatSource_113Pre_CollapsedDataParallel_1_414);
	FOR(int, __iter_init_2_, 0, <, 2, __iter_init_2_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_ComputeStage_71_466_SplitJoin2_SplitJoin2_ComputeStage_80_468_Hier_555_561_join[__iter_init_2_]);
	ENDFOR
	FOR(int, __iter_init_3_, 0, <, 2, __iter_init_3_++)
		init_buffer_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_join[__iter_init_3_]);
	ENDFOR
	init_buffer_float(&Butterfly_130Post_CollapsedDataParallel_2_418);
	init_buffer_float(&Pre_CollapsedDataParallel_1_423Butterfly_146);
	init_buffer_float(&Butterfly_158Post_CollapsedDataParallel_2_433);
	FOR(int, __iter_init_4_, 0, <, 8, __iter_init_4_++)
		init_buffer_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_join[__iter_init_4_]);
	ENDFOR
	init_buffer_float(&Pre_CollapsedDataParallel_1_414Butterfly_114);
	FOR(int, __iter_init_5_, 0, <, 2, __iter_init_5_++)
		init_buffer_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_split[__iter_init_5_]);
	ENDFOR
	FOR(int, __iter_init_6_, 0, <, 2, __iter_init_6_++)
		init_buffer_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_join[__iter_init_6_]);
	ENDFOR
	init_buffer_float(&BitReverse_194FloatPrinter_195);
	init_buffer_float(&Butterfly_146Post_CollapsedDataParallel_2_424);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_544WEIGHTED_ROUND_ROBIN_Splitter_549);
	init_buffer_float(&Pre_CollapsedDataParallel_1_444Butterfly_168);
	init_buffer_float(&Pre_CollapsedDataParallel_1_441Butterfly_166);
	FOR(int, __iter_init_7_, 0, <, 8, __iter_init_7_++)
		init_buffer_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_split[__iter_init_7_]);
	ENDFOR
	init_buffer_float(&Pre_CollapsedDataParallel_1_420Butterfly_138);
	FOR(int, __iter_init_8_, 0, <, 2, __iter_init_8_++)
		init_buffer_float(&SplitJoin40_SplitJoin2_SplitJoin2_ComputeStage_80_468_child1_512_563_split[__iter_init_8_]);
	ENDFOR
	init_buffer_float(&Butterfly_138Post_CollapsedDataParallel_2_421);
	init_buffer_float(&Butterfly_164Post_CollapsedDataParallel_2_439);
	init_buffer_float(&Pre_CollapsedDataParallel_1_435Butterfly_162);
	init_buffer_float(&Pre_CollapsedDataParallel_1_447Butterfly_170);
	init_buffer_float(&Butterfly_170Post_CollapsedDataParallel_2_448);
	init_buffer_float(&Butterfly_154Post_CollapsedDataParallel_2_430);
	init_buffer_float(&Pre_CollapsedDataParallel_1_429Butterfly_154);
	init_buffer_float(&Post_CollapsedDataParallel_2_421WEIGHTED_ROUND_ROBIN_Splitter_541);
	FOR(int, __iter_init_9_, 0, <, 2, __iter_init_9_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_join[__iter_init_9_]);
	ENDFOR
	FOR(int, __iter_init_10_, 0, <, 8, __iter_init_10_++)
		init_buffer_float(&SplitJoin10_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child0_558_568_split[__iter_init_10_]);
	ENDFOR
	init_buffer_float(&Post_CollapsedDataParallel_2_415WEIGHTED_ROUND_ROBIN_Splitter_458);
	init_buffer_float(&Post_CollapsedDataParallel_2_418WEIGHTED_ROUND_ROBIN_Splitter_539);
	init_buffer_float(&Butterfly_176Post_CollapsedDataParallel_2_457);
	FOR(int, __iter_init_11_, 0, <, 2, __iter_init_11_++)
		init_buffer_float(&SplitJoin8_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_Hier_557_567_join[__iter_init_11_]);
	ENDFOR
	init_buffer_float(&Butterfly_172Post_CollapsedDataParallel_2_451);
	FOR(int, __iter_init_12_, 0, <, 4, __iter_init_12_++)
		init_buffer_float(&SplitJoin33_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child1_537_566_split[__iter_init_12_]);
	ENDFOR
	init_buffer_float(&Pre_CollapsedDataParallel_1_432Butterfly_158);
	init_buffer_float(&Pre_CollapsedDataParallel_1_417Butterfly_130);
	FOR(int, __iter_init_13_, 0, <, 2, __iter_init_13_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_ComputeStage_80_468_child0_507_562_split[__iter_init_13_]);
	ENDFOR
	FOR(int, __iter_init_14_, 0, <, 4, __iter_init_14_++)
		init_buffer_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_split[__iter_init_14_]);
	ENDFOR
	FOR(int, __iter_init_15_, 0, <, 8, __iter_init_15_++)
		init_buffer_float(&SplitJoin20_SplitJoin6_SplitJoin6_LastComputeStage_111_472_Hier_child1_559_569_join[__iter_init_15_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_550BitReverse_194);
	FOR(int, __iter_init_16_, 0, <, 4, __iter_init_16_++)
		init_buffer_float(&SplitJoin6_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_child0_536_565_join[__iter_init_16_]);
	ENDFOR
	init_buffer_float(&Pre_CollapsedDataParallel_1_453Butterfly_174);
	init_buffer_float(&Pre_CollapsedDataParallel_1_450Butterfly_172);
	FOR(int, __iter_init_17_, 0, <, 2, __iter_init_17_++)
		init_buffer_float(&SplitJoin4_SplitJoin4_SplitJoin4_ComputeStage_93_470_Hier_Hier_556_564_split[__iter_init_17_]);
	ENDFOR
	init_buffer_float(&Butterfly_166Post_CollapsedDataParallel_2_442);
	init_buffer_float(&Butterfly_162Post_CollapsedDataParallel_2_436);
// --- init: FloatSource_113
	 {
	FOR(int, i, 0,  < , 32, i++) {
		FloatSource_113_s.A_re[i] = 0.0 ; 
		FloatSource_113_s.A_im[i] = 0.0 ; 
	}
	ENDFOR
	FloatSource_113_s.A_re[1] = 1.0 ; 
	FloatSource_113_s.idx = 0 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		FloatSource_113();
		Pre_CollapsedDataParallel_1_414();
		Butterfly_114();
		Post_CollapsedDataParallel_2_415();
		WEIGHTED_ROUND_ROBIN_Splitter_458();
			Pre_CollapsedDataParallel_1_417();
			Butterfly_130();
			Post_CollapsedDataParallel_2_418();
			WEIGHTED_ROUND_ROBIN_Splitter_539();
				Pre_CollapsedDataParallel_1_423();
				Butterfly_146();
				Post_CollapsedDataParallel_2_424();
				Pre_CollapsedDataParallel_1_426();
				Butterfly_150();
				Post_CollapsedDataParallel_2_427();
			WEIGHTED_ROUND_ROBIN_Joiner_540();
			Pre_CollapsedDataParallel_1_420();
			Butterfly_138();
			Post_CollapsedDataParallel_2_421();
			WEIGHTED_ROUND_ROBIN_Splitter_541();
				Pre_CollapsedDataParallel_1_429();
				Butterfly_154();
				Post_CollapsedDataParallel_2_430();
				Pre_CollapsedDataParallel_1_432();
				Butterfly_158();
				Post_CollapsedDataParallel_2_433();
			WEIGHTED_ROUND_ROBIN_Joiner_542();
		WEIGHTED_ROUND_ROBIN_Joiner_538();
		WEIGHTED_ROUND_ROBIN_Splitter_543();
			WEIGHTED_ROUND_ROBIN_Splitter_545();
				Pre_CollapsedDataParallel_1_435();
				Butterfly_162();
				Post_CollapsedDataParallel_2_436();
				Pre_CollapsedDataParallel_1_438();
				Butterfly_164();
				Post_CollapsedDataParallel_2_439();
				Pre_CollapsedDataParallel_1_441();
				Butterfly_166();
				Post_CollapsedDataParallel_2_442();
				Pre_CollapsedDataParallel_1_444();
				Butterfly_168();
				Post_CollapsedDataParallel_2_445();
			WEIGHTED_ROUND_ROBIN_Joiner_546();
			WEIGHTED_ROUND_ROBIN_Splitter_547();
				Pre_CollapsedDataParallel_1_447();
				Butterfly_170();
				Post_CollapsedDataParallel_2_448();
				Pre_CollapsedDataParallel_1_450();
				Butterfly_172();
				Post_CollapsedDataParallel_2_451();
				Pre_CollapsedDataParallel_1_453();
				Butterfly_174();
				Post_CollapsedDataParallel_2_454();
				Pre_CollapsedDataParallel_1_456();
				Butterfly_176();
				Post_CollapsedDataParallel_2_457();
			WEIGHTED_ROUND_ROBIN_Joiner_548();
		WEIGHTED_ROUND_ROBIN_Joiner_544();
		WEIGHTED_ROUND_ROBIN_Splitter_549();
			WEIGHTED_ROUND_ROBIN_Splitter_551();
				Butterfly_178();
				Butterfly_179();
				Butterfly_180();
				Butterfly_181();
				Butterfly_182();
				Butterfly_183();
				Butterfly_184();
				Butterfly_185();
			WEIGHTED_ROUND_ROBIN_Joiner_552();
			WEIGHTED_ROUND_ROBIN_Splitter_553();
				Butterfly_186();
				Butterfly_187();
				Butterfly_188();
				Butterfly_189();
				Butterfly_190();
				Butterfly_191();
				Butterfly_192();
				Butterfly_193();
			WEIGHTED_ROUND_ROBIN_Joiner_554();
		WEIGHTED_ROUND_ROBIN_Joiner_550();
		BitReverse_194();
		FloatPrinter_195();
	ENDFOR
	return EXIT_SUCCESS;
}
