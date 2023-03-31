#ifndef FMRADIO_7BANDS_H
#define FMRADIO_7BANDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "globals.h"
    
#define TheGlobal_samplingRate (float)250000000 // 250 MHz sampling rate is sensible
#define TheGlobal_cutoffFrequency (float)108000000 //guess... doesn't FM freq max at 108 Mhz? 
#define TheGlobal_numberOfTaps 64
#define TheGlobal_maxAmplitude (float)27000
#define TheGlobal_bandwidth (float)10000

// determine where equalizer cuts.  Note that <eqBands> is the
// number of CUTS; there are <eqBands>-1 bands, with parameters
// held in slots 1..<eqBands> of associated arrays.
#define TheGlobal_eqBands 7
#define TheGlobal_low (float)55
#define TheGlobal_high (float)1760
    
typedef struct {
    float source_x;
    float eqGain[TheGlobal_eqBands];
    
    float coeff_4s[TheGlobal_numberOfTaps];
    float coeff[TheGlobal_eqBands][TheGlobal_numberOfTaps];
} TheGlobal_t;

typedef struct {
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} channel_t;
typedef struct {
    buffer_float_t buffer_in[2];
    buffer_float_t buffer_out[2];
} channel2_t;

void fm7b_subtracter(uint32_t k);
void fm7b_equalizer();
void fm7b_amplify(uint32_t k);
void fm7b_lowpass_filter(uint32_t k, uint32_t l);
void fm7b_low_pass_filter_4samp();
void fm7b_fmdemodulator();
void fm7b_float_one_source();
void fm7b_float_printer();
void fm7b_init();
void fm7b_split1_duplicate(); 
void fm7b_join1_round_robin();
void fm7b_split2_duplicate(uint32_t i);
void fm7b_join2_round_robin(uint32_t i);

#ifdef __cplusplus
}
#endif

#endif /* FMRADIO_7BANDS_H */

