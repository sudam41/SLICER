#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=1309 on the compile command line
#else
#if BUF_SIZEMAX < 1309
#error BUF_SIZEMAX too small, it must be at least 1309
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float theta;
} ComplexSource_27_t;

typedef struct {
	int pos;
	float poke[9];
} CFAR_gather_30_t;
void ComplexSource_27();
void WEIGHTED_ROUND_ROBIN_Splitter_33();
void SquareAndScale_35();
void SquareAndScale_36();
void SquareAndScale_37();
void SquareAndScale_38();
void SquareAndScale_39();
void SquareAndScale_40();
void SquareAndScale_41();
void SquareAndScale_42();
void SquareAndScale_43();
void SquareAndScale_44();
void SquareAndScale_45();
void SquareAndScale_46();
void SquareAndScale_47();
void SquareAndScale_48();
void SquareAndScale_49();
void SquareAndScale_50();
void SquareAndScale_51();
void SquareAndScale_52();
void SquareAndScale_53();
void SquareAndScale_54();
void SquareAndScale_55();
void SquareAndScale_56();
void SquareAndScale_57();
void SquareAndScale_58();
void SquareAndScale_59();
void SquareAndScale_60();
void SquareAndScale_61();
void SquareAndScale_62();
void SquareAndScale_63();
void SquareAndScale_64();
void SquareAndScale_65();
void SquareAndScale_66();
void SquareAndScale_67();
void SquareAndScale_68();
void SquareAndScale_69();
void SquareAndScale_70();
void SquareAndScale_71();
void SquareAndScale_72();
void SquareAndScale_73();
void SquareAndScale_74();
void SquareAndScale_75();
void SquareAndScale_76();
void SquareAndScale_77();
void SquareAndScale_78();
void SquareAndScale_79();
void SquareAndScale_80();
void SquareAndScale_81();
void SquareAndScale_82();
void SquareAndScale_83();
void SquareAndScale_84();
void SquareAndScale_85();
void SquareAndScale_86();
void SquareAndScale_87();
void SquareAndScale_88();
void SquareAndScale_89();
void SquareAndScale_90();
void SquareAndScale_91();
void SquareAndScale_92();
void SquareAndScale_93();
void SquareAndScale_94();
void SquareAndScale_95();
void SquareAndScale_96();
void SquareAndScale_97();
void SquareAndScale_98();
void WEIGHTED_ROUND_ROBIN_Joiner_34();
void CFAR_gather_30();
void AnonFilter_a0_31();
#define __DEFLOOPBOUND__0__ -1

#define __DEFLOOPBOUND__1__ -1

#define __DEFLOOPBOUND__2__ -1

#define __DEFLOOPBOUND__3__ -1

#define __DEFLOOPBOUND__4__ -1

#define __DEFLOOPBOUND__5__ -1

#define __DEFLOOPBOUND__6__ -1

#define __DEFLOOPBOUND__7__ -1

#define __DEFLOOPBOUND__8__ -1

#define __DEFLOOPBOUND__9__ -1

#define __DEFLOOPBOUND__10__ -1

#define __DEFLOOPBOUND__11__ -1


#ifdef __cplusplus
}
#endif
#endif
