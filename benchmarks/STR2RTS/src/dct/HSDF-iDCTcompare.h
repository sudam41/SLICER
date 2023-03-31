#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=384 on the compile command line
#else
#if BUF_SIZEMAX < 384
#error BUF_SIZEMAX too small, it must be at least 384
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float coeff[8][8];
} iDCT_2D_reference_coarse_374_t;

typedef struct {
	int buffer[64];
} iDCT8x8_1D_col_fast_398_t;

typedef struct {
	float count;
	float errors;
} AnonFilter_a2_399_t;
void AnonFilter_a0(buffer_int_t *chanout);
void AnonFilter_a0_371();
void DUPLICATE_Splitter_446();
void iDCT_2D_reference_coarse(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT_2D_reference_coarse_374();
void WEIGHTED_ROUND_ROBIN_Splitter_454();
void AnonFilter_a3(buffer_int_t *chanin, buffer_float_t *chanout);
void AnonFilter_a3_456();
void AnonFilter_a3_457();
void AnonFilter_a3_458();
void AnonFilter_a3_459();
void AnonFilter_a3_460();
void AnonFilter_a3_461();
void AnonFilter_a3_462();
void AnonFilter_a3_463();
void AnonFilter_a3_464();
void AnonFilter_a3_465();
void AnonFilter_a3_466();
void AnonFilter_a3_467();
void AnonFilter_a3_468();
void AnonFilter_a3_469();
void AnonFilter_a3_470();
void AnonFilter_a3_471();
void AnonFilter_a3_472();
void AnonFilter_a3_473();
void AnonFilter_a3_474();
void AnonFilter_a3_475();
void AnonFilter_a3_476();
void AnonFilter_a3_477();
void AnonFilter_a3_478();
void AnonFilter_a3_479();
void AnonFilter_a3_480();
void AnonFilter_a3_481();
void AnonFilter_a3_482();
void AnonFilter_a3_483();
void AnonFilter_a3_484();
void AnonFilter_a3_485();
void AnonFilter_a3_486();
void AnonFilter_a3_487();
void AnonFilter_a3_488();
void AnonFilter_a3_489();
void AnonFilter_a3_490();
void AnonFilter_a3_491();
void AnonFilter_a3_492();
void AnonFilter_a3_493();
void AnonFilter_a3_494();
void AnonFilter_a3_495();
void AnonFilter_a3_496();
void AnonFilter_a3_497();
void AnonFilter_a3_498();
void AnonFilter_a3_499();
void AnonFilter_a3_500();
void AnonFilter_a3_501();
void AnonFilter_a3_502();
void AnonFilter_a3_503();
void AnonFilter_a3_504();
void AnonFilter_a3_505();
void AnonFilter_a3_506();
void AnonFilter_a3_507();
void AnonFilter_a3_508();
void AnonFilter_a3_509();
void AnonFilter_a3_510();
void AnonFilter_a3_511();
void AnonFilter_a3_512();
void AnonFilter_a3_513();
void AnonFilter_a3_514();
void AnonFilter_a3_515();
void AnonFilter_a3_516();
void AnonFilter_a3_517();
void AnonFilter_a3_518();
void AnonFilter_a3_519();
void WEIGHTED_ROUND_ROBIN_Joiner_455();
void Pre_CollapsedDataParallel_1(buffer_float_t *chanin, buffer_float_t *chanout);
void Pre_CollapsedDataParallel_1_444();
void WEIGHTED_ROUND_ROBIN_Splitter_520();
void iDCT_1D_reference_fine(buffer_float_t *chanin, buffer_float_t *chanout);
void iDCT_1D_reference_fine_522();
void iDCT_1D_reference_fine_523();
void iDCT_1D_reference_fine_524();
void iDCT_1D_reference_fine_525();
void iDCT_1D_reference_fine_526();
void iDCT_1D_reference_fine_527();
void iDCT_1D_reference_fine_528();
void iDCT_1D_reference_fine_529();
void WEIGHTED_ROUND_ROBIN_Joiner_521();
void Post_CollapsedDataParallel_2(buffer_float_t *chanin, buffer_float_t *chanout);
void Post_CollapsedDataParallel_2_445();
void WEIGHTED_ROUND_ROBIN_Splitter_530();
void iDCT_1D_reference_fine_532();
void iDCT_1D_reference_fine_533();
void iDCT_1D_reference_fine_534();
void iDCT_1D_reference_fine_535();
void iDCT_1D_reference_fine_536();
void iDCT_1D_reference_fine_537();
void iDCT_1D_reference_fine_538();
void iDCT_1D_reference_fine_539();
void WEIGHTED_ROUND_ROBIN_Joiner_531();
void WEIGHTED_ROUND_ROBIN_Splitter_540();
void AnonFilter_a4(buffer_float_t *chanin, buffer_int_t *chanout);
void AnonFilter_a4_542();
void AnonFilter_a4_543();
void AnonFilter_a4_544();
void AnonFilter_a4_545();
void AnonFilter_a4_546();
void AnonFilter_a4_547();
void AnonFilter_a4_548();
void AnonFilter_a4_549();
void AnonFilter_a4_550();
void AnonFilter_a4_551();
void AnonFilter_a4_552();
void AnonFilter_a4_553();
void AnonFilter_a4_554();
void AnonFilter_a4_555();
void AnonFilter_a4_556();
void AnonFilter_a4_557();
void AnonFilter_a4_558();
void AnonFilter_a4_559();
void AnonFilter_a4_560();
void AnonFilter_a4_561();
void AnonFilter_a4_562();
void AnonFilter_a4_563();
void AnonFilter_a4_564();
void AnonFilter_a4_565();
void AnonFilter_a4_566();
void AnonFilter_a4_567();
void AnonFilter_a4_568();
void AnonFilter_a4_569();
void AnonFilter_a4_570();
void AnonFilter_a4_571();
void AnonFilter_a4_572();
void AnonFilter_a4_573();
void AnonFilter_a4_574();
void AnonFilter_a4_575();
void AnonFilter_a4_576();
void AnonFilter_a4_577();
void AnonFilter_a4_578();
void AnonFilter_a4_579();
void AnonFilter_a4_580();
void AnonFilter_a4_581();
void AnonFilter_a4_582();
void AnonFilter_a4_583();
void AnonFilter_a4_584();
void AnonFilter_a4_585();
void AnonFilter_a4_586();
void AnonFilter_a4_587();
void AnonFilter_a4_588();
void AnonFilter_a4_589();
void AnonFilter_a4_590();
void AnonFilter_a4_591();
void AnonFilter_a4_592();
void AnonFilter_a4_593();
void AnonFilter_a4_594();
void AnonFilter_a4_595();
void AnonFilter_a4_596();
void AnonFilter_a4_597();
void AnonFilter_a4_598();
void AnonFilter_a4_599();
void AnonFilter_a4_600();
void AnonFilter_a4_601();
void AnonFilter_a4_602();
void AnonFilter_a4_603();
void AnonFilter_a4_604();
void AnonFilter_a4_605();
void WEIGHTED_ROUND_ROBIN_Joiner_541();
void WEIGHTED_ROUND_ROBIN_Splitter_606();
void iDCT8x8_1D_row_fast(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT8x8_1D_row_fast_608();
void iDCT8x8_1D_row_fast_609();
void iDCT8x8_1D_row_fast_610();
void iDCT8x8_1D_row_fast_611();
void iDCT8x8_1D_row_fast_612();
void iDCT8x8_1D_row_fast_613();
void iDCT8x8_1D_row_fast_614();
void iDCT8x8_1D_row_fast_615();
void WEIGHTED_ROUND_ROBIN_Joiner_607();
void iDCT8x8_1D_col_fast(buffer_int_t *chanin, buffer_int_t *chanout);
void iDCT8x8_1D_col_fast_398();
void WEIGHTED_ROUND_ROBIN_Joiner_447();
void AnonFilter_a2(buffer_int_t *chanin);
void AnonFilter_a2_399();

#ifdef __cplusplus
}
#endif
#endif
