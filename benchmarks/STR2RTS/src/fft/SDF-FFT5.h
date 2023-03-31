#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=32 on the compile command line
#else
#if BUF_SIZEMAX < 32
#error BUF_SIZEMAX too small, it must be at least 32
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif


void source(buffer_complex_t *chanout);
void source_205();
void WEIGHTED_ROUND_ROBIN_Splitter_385();
void WEIGHTED_ROUND_ROBIN_Splitter_387();
void WEIGHTED_ROUND_ROBIN_Splitter_389();
void WEIGHTED_ROUND_ROBIN_Splitter_391();
void Identity(buffer_complex_t *chanin, buffer_complex_t *chanout);
void Identity_215();
void Identity_217();
void WEIGHTED_ROUND_ROBIN_Joiner_392();
void WEIGHTED_ROUND_ROBIN_Splitter_393();
void Identity_221();
void Identity_223();
void WEIGHTED_ROUND_ROBIN_Joiner_394();
void WEIGHTED_ROUND_ROBIN_Joiner_390();
void WEIGHTED_ROUND_ROBIN_Splitter_395();
void WEIGHTED_ROUND_ROBIN_Splitter_397();
void Identity_229();
void Identity_231();
void WEIGHTED_ROUND_ROBIN_Joiner_398();
void WEIGHTED_ROUND_ROBIN_Splitter_399();
void Identity_235();
void Identity_237();
void WEIGHTED_ROUND_ROBIN_Joiner_400();
void WEIGHTED_ROUND_ROBIN_Joiner_396();
void WEIGHTED_ROUND_ROBIN_Joiner_388();
void WEIGHTED_ROUND_ROBIN_Splitter_401();
void WEIGHTED_ROUND_ROBIN_Splitter_403();
void WEIGHTED_ROUND_ROBIN_Splitter_405();
void Identity_245();
void Identity_247();
void WEIGHTED_ROUND_ROBIN_Joiner_406();
void WEIGHTED_ROUND_ROBIN_Splitter_407();
void Identity_251();
void Identity_253();
void WEIGHTED_ROUND_ROBIN_Joiner_408();
void WEIGHTED_ROUND_ROBIN_Joiner_404();
void WEIGHTED_ROUND_ROBIN_Splitter_409();
void WEIGHTED_ROUND_ROBIN_Splitter_411();
void Identity_259();
void Identity_261();
void WEIGHTED_ROUND_ROBIN_Joiner_412();
void WEIGHTED_ROUND_ROBIN_Splitter_413();
void Identity_265();
void Identity_267();
void WEIGHTED_ROUND_ROBIN_Joiner_414();
void WEIGHTED_ROUND_ROBIN_Joiner_410();
void WEIGHTED_ROUND_ROBIN_Joiner_402();
void WEIGHTED_ROUND_ROBIN_Joiner_386();
void WEIGHTED_ROUND_ROBIN_Splitter_529();
void WEIGHTED_ROUND_ROBIN_Splitter_531();
void Pre_CollapsedDataParallel_1(buffer_complex_t *chanin, buffer_complex_t *chanout);
void Pre_CollapsedDataParallel_1_362();
void butterfly(buffer_complex_t *chanin, buffer_complex_t *chanout);
void butterfly_269();
void Post_CollapsedDataParallel_2(buffer_complex_t *chanin, buffer_complex_t *chanout);
void Post_CollapsedDataParallel_2_363();
void Pre_CollapsedDataParallel_1_365();
void butterfly_270();
void Post_CollapsedDataParallel_2_366();
void Pre_CollapsedDataParallel_1_368();
void butterfly_271();
void Post_CollapsedDataParallel_2_369();
void Pre_CollapsedDataParallel_1_371();
void butterfly_272();
void Post_CollapsedDataParallel_2_372();
void WEIGHTED_ROUND_ROBIN_Joiner_532();
void WEIGHTED_ROUND_ROBIN_Splitter_533();
void Pre_CollapsedDataParallel_1_374();
void butterfly_273();
void Post_CollapsedDataParallel_2_375();
void Pre_CollapsedDataParallel_1_377();
void butterfly_274();
void Post_CollapsedDataParallel_2_378();
void Pre_CollapsedDataParallel_1_380();
void butterfly_275();
void Post_CollapsedDataParallel_2_381();
void Pre_CollapsedDataParallel_1_383();
void butterfly_276();
void Post_CollapsedDataParallel_2_384();
void WEIGHTED_ROUND_ROBIN_Joiner_534();
void WEIGHTED_ROUND_ROBIN_Joiner_530();
void WEIGHTED_ROUND_ROBIN_Splitter_535();
void WEIGHTED_ROUND_ROBIN_Splitter_537();
void WEIGHTED_ROUND_ROBIN_Splitter_419();
void butterfly_278();
void butterfly_279();
void WEIGHTED_ROUND_ROBIN_Joiner_420();
void WEIGHTED_ROUND_ROBIN_Splitter_421();
void butterfly_280();
void butterfly_281();
void WEIGHTED_ROUND_ROBIN_Joiner_422();
void WEIGHTED_ROUND_ROBIN_Joiner_538();
void WEIGHTED_ROUND_ROBIN_Splitter_539();
void WEIGHTED_ROUND_ROBIN_Splitter_423();
void butterfly_282();
void butterfly_283();
void WEIGHTED_ROUND_ROBIN_Joiner_424();
void WEIGHTED_ROUND_ROBIN_Splitter_425();
void butterfly_284();
void butterfly_285();
void WEIGHTED_ROUND_ROBIN_Joiner_426();
void WEIGHTED_ROUND_ROBIN_Joiner_540();
void WEIGHTED_ROUND_ROBIN_Joiner_536();
void WEIGHTED_ROUND_ROBIN_Splitter_427();
void WEIGHTED_ROUND_ROBIN_Splitter_429();
void butterfly_287();
void butterfly_288();
void butterfly_289();
void butterfly_290();
void WEIGHTED_ROUND_ROBIN_Joiner_430();
void WEIGHTED_ROUND_ROBIN_Splitter_431();
void butterfly_291();
void butterfly_292();
void butterfly_293();
void butterfly_294();
void WEIGHTED_ROUND_ROBIN_Joiner_432();
void WEIGHTED_ROUND_ROBIN_Joiner_428();
void magnitude(buffer_complex_t *chanin, buffer_float_t *chanout);
void magnitude_295();
void sink(buffer_float_t *chanin);
void sink_296();

#ifdef __cplusplus
}
#endif
#endif
