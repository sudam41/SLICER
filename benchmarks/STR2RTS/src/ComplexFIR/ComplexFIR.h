#ifndef COMPLEXFIR_H
#define COMPLEXFIR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "globals.h"
    
#define TheGlobal_N 16
#define TheGlobal_INPUT_SIZE 2048
#define TheGlobal_FILE "/home/sudam/STR2RTS/STR2RTS/streamit/streams/apps/benchmarks/complex-fir/streamit/input.txt"
    
typedef struct {  // ComplexFIR.str:19
    float coeff_real [TheGlobal_N];	// ComplexFIR.str:20
    float coeff_imag [TheGlobal_N];	// ComplexFIR.str:21
    buffer_float_t buffer_out;
} FIR_t;

void  complexfir_init();
void  complexfir_fir();
void  complexfir_printer();


#ifdef __cplusplus
}
#endif

#endif /* COMPLEXFIR_H */

