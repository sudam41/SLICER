#include "globals.h"

#ifndef CFAR_H
#define CFAR_H

#ifdef __cplusplus
extern "C" {
#endif

#define TheGlobal_ROW_LENGTH 64
#define TheGlobal_NB_IGNORED_GATES 4
#define TheGlobal_NB_CONSIDERED_GATES 5
    
typedef struct {  // .CFARtest.str:24
    buffer_float_t buffer_out;
} channel_t;

typedef struct {  // .CFARtest.str:37
    int pos;	// .CFARtest.str:39
    float poke [TheGlobal_NB_CONSIDERED_GATES + TheGlobal_NB_IGNORED_GATES];	// .CFARtest.str:40
    buffer_float_t buffer_out;
} CFAR_gather_t;

typedef struct {  // .CFARtest.str:77
    double theta;	// .CFARtest.str:79
    buffer_complex_t buffer_out;
} ComplexSource_t;

void  cfar_init();
void  cfar_square_and_scale();
void  cfar_gather_work();
void  cfar_gather();
void  cfar_complex_source();
void  cfar_printer();


#ifdef __cplusplus
}
#endif

#endif /* CFAR_H */

