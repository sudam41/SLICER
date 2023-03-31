#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=512 on the compile command line
#else
#if BUF_SIZEMAX < 512
#error BUF_SIZEMAX too small, it must be at least 512
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float w[2];
} CombineDFT_207_t;

typedef struct {
	float w[4];
} CombineDFT_241_t;

typedef struct {
	float w[8];
} CombineDFT_259_t;

typedef struct {
	float w[16];
} CombineDFT_269_t;

typedef struct {
	float w[32];
} CombineDFT_275_t;

typedef struct {
	float w[64];
} CombineDFT_142_t;
void WEIGHTED_ROUND_ROBIN_Splitter_163();
void FFTTestSource(buffer_void_t *chanin, buffer_float_t *chanout);
void FFTTestSource_165();
void FFTTestSource_166();
void WEIGHTED_ROUND_ROBIN_Joiner_164();
void WEIGHTED_ROUND_ROBIN_Splitter_155();
void FFTReorderSimple(buffer_float_t *chanin, buffer_float_t *chanout);
void FFTReorderSimple_132();
void WEIGHTED_ROUND_ROBIN_Splitter_167();
void FFTReorderSimple_169();
void FFTReorderSimple_170();
void WEIGHTED_ROUND_ROBIN_Joiner_168();
void WEIGHTED_ROUND_ROBIN_Splitter_171();
void FFTReorderSimple_173();
void FFTReorderSimple_174();
void FFTReorderSimple_175();
void FFTReorderSimple_176();
void WEIGHTED_ROUND_ROBIN_Joiner_172();
void WEIGHTED_ROUND_ROBIN_Splitter_177();
void FFTReorderSimple_179();
void FFTReorderSimple_180();
void FFTReorderSimple_181();
void FFTReorderSimple_182();
void FFTReorderSimple_183();
void FFTReorderSimple_184();
void FFTReorderSimple_185();
void FFTReorderSimple_186();
void WEIGHTED_ROUND_ROBIN_Joiner_178();
void WEIGHTED_ROUND_ROBIN_Splitter_187();
void FFTReorderSimple_189();
void FFTReorderSimple_190();
void FFTReorderSimple_191();
void FFTReorderSimple_192();
void FFTReorderSimple_193();
void FFTReorderSimple_194();
void FFTReorderSimple_195();
void FFTReorderSimple_196();
void FFTReorderSimple_197();
void FFTReorderSimple_198();
void FFTReorderSimple_199();
void FFTReorderSimple_200();
void FFTReorderSimple_201();
void FFTReorderSimple_202();
void FFTReorderSimple_203();
void FFTReorderSimple_204();
void WEIGHTED_ROUND_ROBIN_Joiner_188();
void WEIGHTED_ROUND_ROBIN_Splitter_205();
void CombineDFT(buffer_float_t *chanin, buffer_float_t *chanout);
void CombineDFT_207();
void CombineDFT_208();
void CombineDFT_209();
void CombineDFT_210();
void CombineDFT_211();
void CombineDFT_212();
void CombineDFT_213();
void CombineDFT_214();
void CombineDFT_215();
void CombineDFT_216();
void CombineDFT_217();
void CombineDFT_218();
void CombineDFT_219();
void CombineDFT_220();
void CombineDFT_221();
void CombineDFT_222();
void CombineDFT_223();
void CombineDFT_224();
void CombineDFT_225();
void CombineDFT_226();
void CombineDFT_227();
void CombineDFT_228();
void CombineDFT_229();
void CombineDFT_230();
void CombineDFT_231();
void CombineDFT_232();
void CombineDFT_233();
void CombineDFT_234();
void CombineDFT_235();
void CombineDFT_236();
void CombineDFT_237();
void CombineDFT_238();
void WEIGHTED_ROUND_ROBIN_Joiner_206();
void WEIGHTED_ROUND_ROBIN_Splitter_239();
void CombineDFT_241();
void CombineDFT_242();
void CombineDFT_243();
void CombineDFT_244();
void CombineDFT_245();
void CombineDFT_246();
void CombineDFT_247();
void CombineDFT_248();
void CombineDFT_249();
void CombineDFT_250();
void CombineDFT_251();
void CombineDFT_252();
void CombineDFT_253();
void CombineDFT_254();
void CombineDFT_255();
void CombineDFT_256();
void WEIGHTED_ROUND_ROBIN_Joiner_240();
void WEIGHTED_ROUND_ROBIN_Splitter_257();
void CombineDFT_259();
void CombineDFT_260();
void CombineDFT_261();
void CombineDFT_262();
void CombineDFT_263();
void CombineDFT_264();
void CombineDFT_265();
void CombineDFT_266();
void WEIGHTED_ROUND_ROBIN_Joiner_258();
void WEIGHTED_ROUND_ROBIN_Splitter_267();
void CombineDFT_269();
void CombineDFT_270();
void CombineDFT_271();
void CombineDFT_272();
void WEIGHTED_ROUND_ROBIN_Joiner_268();
void WEIGHTED_ROUND_ROBIN_Splitter_273();
void CombineDFT_275();
void CombineDFT_276();
void WEIGHTED_ROUND_ROBIN_Joiner_274();
void CombineDFT_142();
void FFTReorderSimple_143();
void WEIGHTED_ROUND_ROBIN_Splitter_277();
void FFTReorderSimple_279();
void FFTReorderSimple_280();
void WEIGHTED_ROUND_ROBIN_Joiner_278();
void WEIGHTED_ROUND_ROBIN_Splitter_281();
void FFTReorderSimple_283();
void FFTReorderSimple_284();
void FFTReorderSimple_285();
void FFTReorderSimple_286();
void WEIGHTED_ROUND_ROBIN_Joiner_282();
void WEIGHTED_ROUND_ROBIN_Splitter_287();
void FFTReorderSimple_289();
void FFTReorderSimple_290();
void FFTReorderSimple_291();
void FFTReorderSimple_292();
void FFTReorderSimple_293();
void FFTReorderSimple_294();
void FFTReorderSimple_295();
void FFTReorderSimple_296();
void WEIGHTED_ROUND_ROBIN_Joiner_288();
void WEIGHTED_ROUND_ROBIN_Splitter_297();
void FFTReorderSimple_299();
void FFTReorderSimple_300();
void FFTReorderSimple_301();
void FFTReorderSimple_302();
void FFTReorderSimple_303();
void FFTReorderSimple_304();
void FFTReorderSimple_305();
void FFTReorderSimple_306();
void FFTReorderSimple_307();
void FFTReorderSimple_308();
void FFTReorderSimple_309();
void FFTReorderSimple_310();
void FFTReorderSimple_311();
void FFTReorderSimple_312();
void FFTReorderSimple_313();
void FFTReorderSimple_314();
void WEIGHTED_ROUND_ROBIN_Joiner_298();
void WEIGHTED_ROUND_ROBIN_Splitter_315();
void CombineDFT_317();
void CombineDFT_318();
void CombineDFT_319();
void CombineDFT_320();
void CombineDFT_321();
void CombineDFT_322();
void CombineDFT_323();
void CombineDFT_324();
void CombineDFT_325();
void CombineDFT_326();
void CombineDFT_327();
void CombineDFT_328();
void CombineDFT_329();
void CombineDFT_330();
void CombineDFT_331();
void CombineDFT_332();
void CombineDFT_333();
void CombineDFT_334();
void CombineDFT_335();
void CombineDFT_336();
void CombineDFT_337();
void CombineDFT_338();
void CombineDFT_339();
void CombineDFT_340();
void CombineDFT_341();
void CombineDFT_342();
void CombineDFT_343();
void CombineDFT_344();
void CombineDFT_345();
void CombineDFT_346();
void CombineDFT_347();
void CombineDFT_348();
void WEIGHTED_ROUND_ROBIN_Joiner_316();
void WEIGHTED_ROUND_ROBIN_Splitter_349();
void CombineDFT_351();
void CombineDFT_352();
void CombineDFT_353();
void CombineDFT_354();
void CombineDFT_355();
void CombineDFT_356();
void CombineDFT_357();
void CombineDFT_358();
void CombineDFT_359();
void CombineDFT_360();
void CombineDFT_361();
void CombineDFT_362();
void CombineDFT_363();
void CombineDFT_364();
void CombineDFT_365();
void CombineDFT_366();
void WEIGHTED_ROUND_ROBIN_Joiner_350();
void WEIGHTED_ROUND_ROBIN_Splitter_367();
void CombineDFT_369();
void CombineDFT_370();
void CombineDFT_371();
void CombineDFT_372();
void CombineDFT_373();
void CombineDFT_374();
void CombineDFT_375();
void CombineDFT_376();
void WEIGHTED_ROUND_ROBIN_Joiner_368();
void WEIGHTED_ROUND_ROBIN_Splitter_377();
void CombineDFT_379();
void CombineDFT_380();
void CombineDFT_381();
void CombineDFT_382();
void WEIGHTED_ROUND_ROBIN_Joiner_378();
void WEIGHTED_ROUND_ROBIN_Splitter_383();
void CombineDFT_385();
void CombineDFT_386();
void WEIGHTED_ROUND_ROBIN_Joiner_384();
void CombineDFT_153();
void WEIGHTED_ROUND_ROBIN_Joiner_156();
void FloatPrinter(buffer_float_t *chanin);
void FloatPrinter_154();

#ifdef __cplusplus
}
#endif
#endif
