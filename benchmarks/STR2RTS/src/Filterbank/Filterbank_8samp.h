#ifndef FILTERBANK_H
#define FILTERBANK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "globals.h"

#define TheGlobal_N_sim 1024 * 2
#define TheGlobal_N_samp 8
#define TheGlobal_N_col 32
#define TheGlobal_MAX_SOURCE 1000.0
    
typedef struct {
    float r[TheGlobal_N_sim];
    float H[TheGlobal_N_samp][TheGlobal_N_col];
    float F[TheGlobal_N_samp][TheGlobal_N_col];
} TheGlobal_t;

typedef struct {
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} channel_t;
    
#ifdef __cplusplus
}
#endif

#endif /* FILTERBANK_H */

