#include "SDF-FMRadio.h"

buffer_float_t Subtracter_127Amplify_128;
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[10];
buffer_float_t SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_split[2];
buffer_float_t SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_split[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_193Subtracter_148;
buffer_float_t SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_join[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_185Subtracter_120;
buffer_float_t Subtracter_120Amplify_121;
buffer_float_t FloatOneSource_103LowPassFilter_105;
buffer_float_t SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_join[2];
buffer_float_t Subtracter_155Amplify_156;
buffer_float_t SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_split[2];
buffer_float_t SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_join[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_181AnonFilter_a0_178;
buffer_float_t Subtracter_134Amplify_135;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_189Subtracter_134;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_195Subtracter_155;
buffer_float_t Subtracter_162Amplify_163;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_201Subtracter_176;
buffer_float_t AnonFilter_a0_178FloatPrinter_179;
buffer_float_t SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_split[2];
buffer_float_t SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_join[2];
buffer_float_t SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_split[2];
buffer_float_t SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_join[2];
buffer_float_t Subtracter_141Amplify_142;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_199Subtracter_169;
buffer_float_t Subtracter_176Amplify_177;
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_join[2];
buffer_float_t SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_split[2];
buffer_float_t SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_split[2];
buffer_float_t SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_join[2];
buffer_float_t SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_split[2];
buffer_float_t SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[10];
buffer_float_t SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_split[2];
buffer_float_t Subtracter_169Amplify_170;
buffer_float_t FMDemodulator_106DUPLICATE_Splitter_180;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_187Subtracter_127;
buffer_float_t SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_join[2];
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_191Subtracter_141;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_197Subtracter_162;
buffer_float_t WEIGHTED_ROUND_ROBIN_Joiner_183Subtracter_113;
buffer_float_t SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_split[2];
buffer_float_t Subtracter_148Amplify_149;
buffer_float_t LowPassFilter_105FMDemodulator_106;
buffer_float_t SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_join[2];
buffer_float_t Subtracter_113Amplify_114;
buffer_float_t SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_join[2];


FloatOneSource_103_t FloatOneSource_103_s;
LowPassFilter_105_t LowPassFilter_105_s;
LowPassFilter_105_t LowPassFilter_111_s;
LowPassFilter_105_t LowPassFilter_112_s;
LowPassFilter_105_t LowPassFilter_118_s;
LowPassFilter_105_t LowPassFilter_119_s;
LowPassFilter_105_t LowPassFilter_125_s;
LowPassFilter_105_t LowPassFilter_126_s;
LowPassFilter_105_t LowPassFilter_132_s;
LowPassFilter_105_t LowPassFilter_133_s;
LowPassFilter_105_t LowPassFilter_139_s;
LowPassFilter_105_t LowPassFilter_140_s;
LowPassFilter_105_t LowPassFilter_146_s;
LowPassFilter_105_t LowPassFilter_147_s;
LowPassFilter_105_t LowPassFilter_153_s;
LowPassFilter_105_t LowPassFilter_154_s;
LowPassFilter_105_t LowPassFilter_160_s;
LowPassFilter_105_t LowPassFilter_161_s;
LowPassFilter_105_t LowPassFilter_167_s;
LowPassFilter_105_t LowPassFilter_168_s;
LowPassFilter_105_t LowPassFilter_174_s;
LowPassFilter_105_t LowPassFilter_175_s;

void FloatOneSource(buffer_float_t *chanout) {
		push_float(&(*chanout), FloatOneSource_103_s.x++) ; 
	}


void FloatOneSource_103() {
	FOR(uint32_t, __iter_steady_, 0, <, 5, __iter_steady_++)
		FloatOneSource(&(FloatOneSource_103LowPassFilter_105));
	ENDFOR
}

void LowPassFilter(buffer_float_t *chanin, buffer_float_t *chanout) {
	float sum = 0.0;
	FOR(int, i__conflict__0, 0,  < , 64, i__conflict__0++) {
		sum = (sum + (peek_float(&(*chanin), i__conflict__0) * LowPassFilter_105_s.coeff[i__conflict__0])) ; 
	}
	ENDFOR
	push_float(&(*chanout), sum) ; 
	FOR(int, i, 0,  < , 4, i++) {
		pop_float(&(*chanin)) ; 
	}
	ENDFOR
	pop_float(&(*chanin)) ; 
}


void LowPassFilter_105() {
	LowPassFilter(&(FloatOneSource_103LowPassFilter_105), &(LowPassFilter_105FMDemodulator_106));
}

void FMDemodulator(buffer_float_t *chanin, buffer_float_t *chanout) {
	float temp = 0.0;
	temp = ((float) (peek_float(&(*chanin), 0) * peek_float(&(*chanin), 1))) ; 
	temp = ((float) (2.14859168E8 * ((float) atan(temp)))) ; 
	pop_float(&(*chanin)) ; 
	push_float(&(*chanout), temp) ; 
}


void FMDemodulator_106() {
	FMDemodulator(&(LowPassFilter_105FMDemodulator_106), &(FMDemodulator_106DUPLICATE_Splitter_180));
}

void LowPassFilter_111() {
	LowPassFilter(&(SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_split[0]), &(SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_join[0]));
}

void LowPassFilter_112() {
	LowPassFilter(&(SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_split[1]), &(SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_join[1]));
}

void DUPLICATE_Splitter_182() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[0]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_183() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_183Subtracter_113, pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_183Subtracter_113, pop_float(&SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_join[1]));
}

void Subtracter(buffer_float_t *chanin, buffer_float_t *chanout) {
	push_float(&(*chanout), (peek_float(&(*chanin), 1) - peek_float(&(*chanin), 0))) ; 
	pop_float(&(*chanin)) ; 
	pop_float(&(*chanin)) ; 
}


void Subtracter_113() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_183Subtracter_113), &(Subtracter_113Amplify_114));
}

void Amplify(buffer_float_t *chanin, buffer_float_t *chanout) {
	push_float(&(*chanout), (pop_float(&(*chanin)) * 1.1)) ; 
}


void Amplify_114() {
	Amplify(&(Subtracter_113Amplify_114), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[0]));
}

void LowPassFilter_118() {
	LowPassFilter(&(SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_split[0]), &(SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_join[0]));
}

void LowPassFilter_119() {
	LowPassFilter(&(SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_split[1]), &(SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_join[1]));
}

void DUPLICATE_Splitter_184() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[1]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_185() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_185Subtracter_120, pop_float(&SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_185Subtracter_120, pop_float(&SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_join[1]));
}

void Subtracter_120() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_185Subtracter_120), &(Subtracter_120Amplify_121));
}

void Amplify_121() {
	Amplify(&(Subtracter_120Amplify_121), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[1]));
}

void LowPassFilter_125() {
	LowPassFilter(&(SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_split[0]), &(SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_join[0]));
}

void LowPassFilter_126() {
	LowPassFilter(&(SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_split[1]), &(SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_join[1]));
}

void DUPLICATE_Splitter_186() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[2]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_187() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_187Subtracter_127, pop_float(&SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_187Subtracter_127, pop_float(&SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_join[1]));
}

void Subtracter_127() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_187Subtracter_127), &(Subtracter_127Amplify_128));
}

void Amplify_128() {
	Amplify(&(Subtracter_127Amplify_128), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[2]));
}

void LowPassFilter_132() {
	LowPassFilter(&(SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_split[0]), &(SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_join[0]));
}

void LowPassFilter_133() {
	LowPassFilter(&(SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_split[1]), &(SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_join[1]));
}

void DUPLICATE_Splitter_188() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[3]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_189() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_189Subtracter_134, pop_float(&SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_189Subtracter_134, pop_float(&SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_join[1]));
}

void Subtracter_134() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_189Subtracter_134), &(Subtracter_134Amplify_135));
}

void Amplify_135() {
	Amplify(&(Subtracter_134Amplify_135), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[3]));
}

void LowPassFilter_139() {
	LowPassFilter(&(SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_split[0]), &(SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_join[0]));
}

void LowPassFilter_140() {
	LowPassFilter(&(SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_split[1]), &(SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_join[1]));
}

void DUPLICATE_Splitter_190() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[4]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_191() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_191Subtracter_141, pop_float(&SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_191Subtracter_141, pop_float(&SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_join[1]));
}

void Subtracter_141() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_191Subtracter_141), &(Subtracter_141Amplify_142));
}

void Amplify_142() {
	Amplify(&(Subtracter_141Amplify_142), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[4]));
}

void LowPassFilter_146() {
	LowPassFilter(&(SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_split[0]), &(SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_join[0]));
}

void LowPassFilter_147() {
	LowPassFilter(&(SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_split[1]), &(SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_join[1]));
}

void DUPLICATE_Splitter_192() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[5]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_193() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_193Subtracter_148, pop_float(&SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_193Subtracter_148, pop_float(&SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_join[1]));
}

void Subtracter_148() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_193Subtracter_148), &(Subtracter_148Amplify_149));
}

void Amplify_149() {
	Amplify(&(Subtracter_148Amplify_149), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[5]));
}

void LowPassFilter_153() {
	LowPassFilter(&(SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_split[0]), &(SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_join[0]));
}

void LowPassFilter_154() {
	LowPassFilter(&(SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_split[1]), &(SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_join[1]));
}

void DUPLICATE_Splitter_194() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[6]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_195() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_195Subtracter_155, pop_float(&SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_195Subtracter_155, pop_float(&SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_join[1]));
}

void Subtracter_155() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_195Subtracter_155), &(Subtracter_155Amplify_156));
}

void Amplify_156() {
	Amplify(&(Subtracter_155Amplify_156), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[6]));
}

void LowPassFilter_160() {
	LowPassFilter(&(SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_split[0]), &(SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_join[0]));
}

void LowPassFilter_161() {
	LowPassFilter(&(SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_split[1]), &(SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_join[1]));
}

void DUPLICATE_Splitter_196() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[7]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_197() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_197Subtracter_162, pop_float(&SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_197Subtracter_162, pop_float(&SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_join[1]));
}

void Subtracter_162() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_197Subtracter_162), &(Subtracter_162Amplify_163));
}

void Amplify_163() {
	Amplify(&(Subtracter_162Amplify_163), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[7]));
}

void LowPassFilter_167() {
	LowPassFilter(&(SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_split[0]), &(SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_join[0]));
}

void LowPassFilter_168() {
	LowPassFilter(&(SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_split[1]), &(SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_join[1]));
}

void DUPLICATE_Splitter_198() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[8]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_199() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_199Subtracter_169, pop_float(&SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_199Subtracter_169, pop_float(&SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_join[1]));
}

void Subtracter_169() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_199Subtracter_169), &(Subtracter_169Amplify_170));
}

void Amplify_170() {
	Amplify(&(Subtracter_169Amplify_170), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[8]));
}

void LowPassFilter_174() {
	LowPassFilter(&(SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_split[0]), &(SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_join[0]));
}

void LowPassFilter_175() {
	LowPassFilter(&(SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_split[1]), &(SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_join[1]));
}

void DUPLICATE_Splitter_200() {
	float __token_ = pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[9]);
	FOR(uint32_t, __iter_dup_, 0, <, 2, __iter_dup_++)
		push_float(&SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_201() {
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_201Subtracter_176, pop_float(&SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_join[0]));
	push_float(&WEIGHTED_ROUND_ROBIN_Joiner_201Subtracter_176, pop_float(&SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_join[1]));
}

void Subtracter_176() {
	Subtracter(&(WEIGHTED_ROUND_ROBIN_Joiner_201Subtracter_176), &(Subtracter_176Amplify_177));
}

void Amplify_177() {
	Amplify(&(Subtracter_176Amplify_177), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[9]));
}

void DUPLICATE_Splitter_180() {
	float __token_ = pop_float(&FMDemodulator_106DUPLICATE_Splitter_180);
	FOR(uint32_t, __iter_dup_, 0, <, 10, __iter_dup_++)
		push_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[__iter_dup_], __token_);
	ENDFOR
}

void WEIGHTED_ROUND_ROBIN_Joiner_181() {
	FOR(uint32_t, __iter_, 0, <, 10, __iter_++)
		push_float(&WEIGHTED_ROUND_ROBIN_Joiner_181AnonFilter_a0_178, pop_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[__iter_]));
	ENDFOR
}

void AnonFilter_a0(buffer_float_t *chanin, buffer_float_t *chanout) {
	float sum = 0.0;
	FOR(int, i, 0,  < , 10, i++) {
		sum = (sum + pop_float(&(*chanin))) ; 
	}
	ENDFOR
	push_float(&(*chanout), sum) ; 
}


void AnonFilter_a0_178() {
	AnonFilter_a0(&(WEIGHTED_ROUND_ROBIN_Joiner_181AnonFilter_a0_178), &(AnonFilter_a0_178FloatPrinter_179));
}

void FloatPrinter(buffer_float_t *chanin) {
	printf("%.10f", pop_float(&(*chanin)));
	printf("\n");
}


void FloatPrinter_179() {
	FloatPrinter(&(AnonFilter_a0_178FloatPrinter_179));
}

void __stream_init__() {
	init_buffer_float(&Subtracter_127Amplify_128);
	FOR(int, __iter_init_0_, 0, <, 10, __iter_init_0_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_join[__iter_init_0_]);
	ENDFOR
	FOR(int, __iter_init_1_, 0, <, 2, __iter_init_1_++)
		init_buffer_float(&SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_split[__iter_init_1_]);
	ENDFOR
	FOR(int, __iter_init_2_, 0, <, 2, __iter_init_2_++)
		init_buffer_float(&SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_split[__iter_init_2_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_193Subtracter_148);
	FOR(int, __iter_init_3_, 0, <, 2, __iter_init_3_++)
		init_buffer_float(&SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_join[__iter_init_3_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_185Subtracter_120);
	init_buffer_float(&Subtracter_120Amplify_121);
	init_buffer_float(&FloatOneSource_103LowPassFilter_105);
	FOR(int, __iter_init_4_, 0, <, 2, __iter_init_4_++)
		init_buffer_float(&SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_join[__iter_init_4_]);
	ENDFOR
	init_buffer_float(&Subtracter_155Amplify_156);
	FOR(int, __iter_init_5_, 0, <, 2, __iter_init_5_++)
		init_buffer_float(&SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_split[__iter_init_5_]);
	ENDFOR
	FOR(int, __iter_init_6_, 0, <, 2, __iter_init_6_++)
		init_buffer_float(&SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_join[__iter_init_6_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_181AnonFilter_a0_178);
	init_buffer_float(&Subtracter_134Amplify_135);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_189Subtracter_134);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_195Subtracter_155);
	init_buffer_float(&Subtracter_162Amplify_163);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_201Subtracter_176);
	init_buffer_float(&AnonFilter_a0_178FloatPrinter_179);
	FOR(int, __iter_init_7_, 0, <, 2, __iter_init_7_++)
		init_buffer_float(&SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_split[__iter_init_7_]);
	ENDFOR
	FOR(int, __iter_init_8_, 0, <, 2, __iter_init_8_++)
		init_buffer_float(&SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_join[__iter_init_8_]);
	ENDFOR
	FOR(int, __iter_init_9_, 0, <, 2, __iter_init_9_++)
		init_buffer_float(&SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_split[__iter_init_9_]);
	ENDFOR
	FOR(int, __iter_init_10_, 0, <, 2, __iter_init_10_++)
		init_buffer_float(&SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_join[__iter_init_10_]);
	ENDFOR
	init_buffer_float(&Subtracter_141Amplify_142);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_199Subtracter_169);
	init_buffer_float(&Subtracter_176Amplify_177);
	FOR(int, __iter_init_11_, 0, <, 2, __iter_init_11_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_join[__iter_init_11_]);
	ENDFOR
	FOR(int, __iter_init_12_, 0, <, 2, __iter_init_12_++)
		init_buffer_float(&SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_split[__iter_init_12_]);
	ENDFOR
	FOR(int, __iter_init_13_, 0, <, 2, __iter_init_13_++)
		init_buffer_float(&SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_split[__iter_init_13_]);
	ENDFOR
	FOR(int, __iter_init_14_, 0, <, 2, __iter_init_14_++)
		init_buffer_float(&SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_join[__iter_init_14_]);
	ENDFOR
	FOR(int, __iter_init_15_, 0, <, 2, __iter_init_15_++)
		init_buffer_float(&SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_split[__iter_init_15_]);
	ENDFOR
	FOR(int, __iter_init_16_, 0, <, 10, __iter_init_16_++)
		init_buffer_float(&SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[__iter_init_16_]);
	ENDFOR
	FOR(int, __iter_init_17_, 0, <, 2, __iter_init_17_++)
		init_buffer_float(&SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_split[__iter_init_17_]);
	ENDFOR
	init_buffer_float(&Subtracter_169Amplify_170);
	init_buffer_float(&FMDemodulator_106DUPLICATE_Splitter_180);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_187Subtracter_127);
	FOR(int, __iter_init_18_, 0, <, 2, __iter_init_18_++)
		init_buffer_float(&SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_join[__iter_init_18_]);
	ENDFOR
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_191Subtracter_141);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_197Subtracter_162);
	init_buffer_float(&WEIGHTED_ROUND_ROBIN_Joiner_183Subtracter_113);
	FOR(int, __iter_init_19_, 0, <, 2, __iter_init_19_++)
		init_buffer_float(&SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_split[__iter_init_19_]);
	ENDFOR
	init_buffer_float(&Subtracter_148Amplify_149);
	init_buffer_float(&LowPassFilter_105FMDemodulator_106);
	FOR(int, __iter_init_20_, 0, <, 2, __iter_init_20_++)
		init_buffer_float(&SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_join[__iter_init_20_]);
	ENDFOR
	init_buffer_float(&Subtracter_113Amplify_114);
	FOR(int, __iter_init_21_, 0, <, 2, __iter_init_21_++)
		init_buffer_float(&SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_join[__iter_init_21_]);
	ENDFOR
// --- init: FloatOneSource_103
	 {
	FloatOneSource_103_s.x = 0.0 ; 
}
	FOR(uint32_t, __iter_init_, 0, <, 379, __iter_init_++)
		FloatOneSource(&(FloatOneSource_103LowPassFilter_105));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_105
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_105_s.coeff[i] = 0.864 ; 
		}
		else {
			LowPassFilter_105_s.coeff[i] = (((((float) sin((2.7143362 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
	FOR(uint32_t, __iter_init_, 0, <, 64, __iter_init_++)
		LowPassFilter(&(FloatOneSource_103LowPassFilter_105), &(LowPassFilter_105FMDemodulator_106));
	ENDFOR
//--------------------------------
// --- init: FMDemodulator_106
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		FMDemodulator(&(LowPassFilter_105FMDemodulator_106), &(FMDemodulator_106DUPLICATE_Splitter_180));
	ENDFOR
//--------------------------------
// --- init: DUPLICATE_Splitter_180
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(FMDemodulator_106DUPLICATE_Splitter_180), &(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: DUPLICATE_Splitter_182
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[0]), &(SplitJoin2_SplitJoin2_SplitJoin2_BPFCore_110_203_234_246_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_111
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_111_s.coeff[i] = 4.4E-7 ; 
		}
		else {
			LowPassFilter_111_s.coeff[i] = (((((float) sin((1.3823009E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_112
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_112_s.coeff[i] = 6.2225394E-7 ; 
		}
		else {
			LowPassFilter_112_s.coeff[i] = (((((float) sin((1.9548684E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_184
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[1]), &(SplitJoin6_SplitJoin6_SplitJoin6_BPFCore_117_206_235_247_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_118
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_118_s.coeff[i] = 6.2225394E-7 ; 
		}
		else {
			LowPassFilter_118_s.coeff[i] = (((((float) sin((1.9548684E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_119
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_119_s.coeff[i] = 8.8E-7 ; 
		}
		else {
			LowPassFilter_119_s.coeff[i] = (((((float) sin((2.7646017E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_186
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[2]), &(SplitJoin10_SplitJoin10_SplitJoin10_BPFCore_124_209_236_248_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_125
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_125_s.coeff[i] = 8.8E-7 ; 
		}
		else {
			LowPassFilter_125_s.coeff[i] = (((((float) sin((2.7646017E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_126
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_126_s.coeff[i] = 1.2445082E-6 ; 
		}
		else {
			LowPassFilter_126_s.coeff[i] = (((((float) sin((3.909738E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_188
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[3]), &(SplitJoin14_SplitJoin14_SplitJoin14_BPFCore_131_212_237_249_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_132
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_132_s.coeff[i] = 1.2445082E-6 ; 
		}
		else {
			LowPassFilter_132_s.coeff[i] = (((((float) sin((3.909738E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_133
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_133_s.coeff[i] = 1.76E-6 ; 
		}
		else {
			LowPassFilter_133_s.coeff[i] = (((((float) sin((5.5292035E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_190
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[4]), &(SplitJoin18_SplitJoin18_SplitJoin18_BPFCore_138_215_238_250_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_139
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_139_s.coeff[i] = 1.76E-6 ; 
		}
		else {
			LowPassFilter_139_s.coeff[i] = (((((float) sin((5.5292035E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_140
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_140_s.coeff[i] = 2.4890157E-6 ; 
		}
		else {
			LowPassFilter_140_s.coeff[i] = (((((float) sin((7.8194735E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_192
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[5]), &(SplitJoin22_SplitJoin22_SplitJoin22_BPFCore_145_218_239_251_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_146
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_146_s.coeff[i] = 2.4890157E-6 ; 
		}
		else {
			LowPassFilter_146_s.coeff[i] = (((((float) sin((7.8194735E-6 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_147
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_147_s.coeff[i] = 3.52E-6 ; 
		}
		else {
			LowPassFilter_147_s.coeff[i] = (((((float) sin((1.1058407E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_194
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[6]), &(SplitJoin26_SplitJoin26_SplitJoin26_BPFCore_152_221_240_252_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_153
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_153_s.coeff[i] = 3.52E-6 ; 
		}
		else {
			LowPassFilter_153_s.coeff[i] = (((((float) sin((1.1058407E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_154
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_154_s.coeff[i] = 4.978033E-6 ; 
		}
		else {
			LowPassFilter_154_s.coeff[i] = (((((float) sin((1.5638952E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_196
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[7]), &(SplitJoin30_SplitJoin30_SplitJoin30_BPFCore_159_224_241_253_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_160
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_160_s.coeff[i] = 4.978033E-6 ; 
		}
		else {
			LowPassFilter_160_s.coeff[i] = (((((float) sin((1.5638952E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_161
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_161_s.coeff[i] = 7.04E-6 ; 
		}
		else {
			LowPassFilter_161_s.coeff[i] = (((((float) sin((2.2116814E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_198
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[8]), &(SplitJoin34_SplitJoin34_SplitJoin34_BPFCore_166_227_242_254_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_167
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_167_s.coeff[i] = 7.04E-6 ; 
		}
		else {
			LowPassFilter_167_s.coeff[i] = (((((float) sin((2.2116814E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_168
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_168_s.coeff[i] = 9.956063E-6 ; 
		}
		else {
			LowPassFilter_168_s.coeff[i] = (((((float) sin((3.1277894E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: DUPLICATE_Splitter_200
	FOR(uint32_t, __iter_init_, 0, <, 63, __iter_init_++)
		DUPLICATE_Splitter(&(SplitJoin0_SplitJoin0_SplitJoin0_EqSplit_101_202_233_245_split[9]), &(SplitJoin38_SplitJoin38_SplitJoin38_BPFCore_173_230_243_255_split[Need Human for iter var]));
	ENDFOR
//--------------------------------
// --- init: LowPassFilter_174
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_174_s.coeff[i] = 9.956063E-6 ; 
		}
		else {
			LowPassFilter_174_s.coeff[i] = (((((float) sin((3.1277894E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
// --- init: LowPassFilter_175
	 {
	FOR(int, i, 0,  < , 64, i++) {
		if((i - 31.5) == 0.0) {
			LowPassFilter_175_s.coeff[i] = 1.408E-5 ; 
		}
		else {
			LowPassFilter_175_s.coeff[i] = (((((float) sin((4.4233628E-5 * (i - 31.5)))) / 3.1415927) / (i - 31.5)) * (0.54 - (0.46 * ((float) cos(((6.2831855 * i) / 63.0)))))) ; 
		}
	}
	ENDFOR
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		FloatOneSource_103();
		LowPassFilter_105();
		FMDemodulator_106();
		DUPLICATE_Splitter_180();
			DUPLICATE_Splitter_182();
				LowPassFilter_111();
				LowPassFilter_112();
			WEIGHTED_ROUND_ROBIN_Joiner_183();
			Subtracter_113();
			Amplify_114();
			DUPLICATE_Splitter_184();
				LowPassFilter_118();
				LowPassFilter_119();
			WEIGHTED_ROUND_ROBIN_Joiner_185();
			Subtracter_120();
			Amplify_121();
			DUPLICATE_Splitter_186();
				LowPassFilter_125();
				LowPassFilter_126();
			WEIGHTED_ROUND_ROBIN_Joiner_187();
			Subtracter_127();
			Amplify_128();
			DUPLICATE_Splitter_188();
				LowPassFilter_132();
				LowPassFilter_133();
			WEIGHTED_ROUND_ROBIN_Joiner_189();
			Subtracter_134();
			Amplify_135();
			DUPLICATE_Splitter_190();
				LowPassFilter_139();
				LowPassFilter_140();
			WEIGHTED_ROUND_ROBIN_Joiner_191();
			Subtracter_141();
			Amplify_142();
			DUPLICATE_Splitter_192();
				LowPassFilter_146();
				LowPassFilter_147();
			WEIGHTED_ROUND_ROBIN_Joiner_193();
			Subtracter_148();
			Amplify_149();
			DUPLICATE_Splitter_194();
				LowPassFilter_153();
				LowPassFilter_154();
			WEIGHTED_ROUND_ROBIN_Joiner_195();
			Subtracter_155();
			Amplify_156();
			DUPLICATE_Splitter_196();
				LowPassFilter_160();
				LowPassFilter_161();
			WEIGHTED_ROUND_ROBIN_Joiner_197();
			Subtracter_162();
			Amplify_163();
			DUPLICATE_Splitter_198();
				LowPassFilter_167();
				LowPassFilter_168();
			WEIGHTED_ROUND_ROBIN_Joiner_199();
			Subtracter_169();
			Amplify_170();
			DUPLICATE_Splitter_200();
				LowPassFilter_174();
				LowPassFilter_175();
			WEIGHTED_ROUND_ROBIN_Joiner_201();
			Subtracter_176();
			Amplify_177();
		WEIGHTED_ROUND_ROBIN_Joiner_181();
		AnonFilter_a0_178();
		FloatPrinter_179();
	ENDFOR
	return EXIT_SUCCESS;
}
