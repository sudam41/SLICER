#ifndef BEAMFORMER_H
#define BEAMFORMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "globals.h"
    
#define TheGlobal_numChannels 12 // BeamFormer.str:2
#define TheGlobal_numSamples 1024 // BeamFormer.str:3
#define TheGlobal_numBeams 4 // BeamFormer.str:4
#define TheGlobal_numCoarseFilterTaps 64 // BeamFormer.str:5
#define TheGlobal_numFineFilterTaps 64 // BeamFormer.str:6
#define TheGlobal_coarseDecimationRatio 1 // BeamFormer.str:7
#define TheGlobal_fineDecimationRatio 2 // BeamFormer.str:8
#define TheGlobal_numSegments 1 // BeamFormer.str:9
#define TheGlobal_numPostDec1 (TheGlobal_numSamples / TheGlobal_coarseDecimationRatio) // BeamFormer.str:10
#define TheGlobal_numPostDec2 (TheGlobal_numPostDec1 / TheGlobal_fineDecimationRatio) // BeamFormer.str:11
#define TheGlobal_mfSize (TheGlobal_numSegments * TheGlobal_numPostDec2) // BeamFormer.str:12
#define TheGlobal_pulseSize (TheGlobal_numPostDec2 / 2) // BeamFormer.str:13
#define TheGlobal_predecPulseSize ((TheGlobal_pulseSize * TheGlobal_coarseDecimationRatio) * TheGlobal_fineDecimationRatio) // BeamFormer.str:14
#define TheGlobal_targetBeam (TheGlobal_numBeams / 4) // BeamFormer.str:15
#define TheGlobal_targetSample (TheGlobal_numSamples / 4) // BeamFormer.str:16
#define TheGlobal_targetSamplePostDec ((TheGlobal_targetSample / TheGlobal_coarseDecimationRatio) / TheGlobal_fineDecimationRatio) // BeamFormer.str:17
#define TheGlobal_dOverLambda 0.5f // BeamFormer.str:18
#define TheGlobal_cfarThreshold (((0.95f * TheGlobal_dOverLambda) * TheGlobal_numChannels) * (0.5f * TheGlobal_pulseSize)) // BeamFormer.str:19

typedef struct {  // BeamFormer.str:44
    int curSample;	// BeamFormer.str:45
    buffer_float_t buffer_out;
} InputGenerate_t;

typedef struct {  // BeamFormer.str:68
    float real_weight [MAX(MAX(TheGlobal_numCoarseFilterTaps, TheGlobal_numFineFilterTaps), TheGlobal_mfSize)];	// BeamFormer.str:69
    float imag_weight [MAX(MAX(TheGlobal_numCoarseFilterTaps, TheGlobal_numFineFilterTaps), TheGlobal_mfSize)];	// BeamFormer.str:70
    float realBuffer [MAX(MAX(TheGlobal_numCoarseFilterTaps, TheGlobal_numFineFilterTaps), TheGlobal_mfSize)];	// BeamFormer.str:72
    float imagBuffer [MAX(MAX(TheGlobal_numCoarseFilterTaps, TheGlobal_numFineFilterTaps), TheGlobal_mfSize)];	// BeamFormer.str:73
    int count;	// BeamFormer.str:74
    int pos;	// BeamFormer.str:75
    buffer_float_t buffer_out;
} BeamFirFilter_t;

typedef struct {  // BeamFormer.str:179
    float real_weight [TheGlobal_numChannels];	// BeamFormer.str:180
    float imag_weight [TheGlobal_numChannels];	// BeamFormer.str:181
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} BeamForm_t;

typedef struct {  // BeamFormer.str:204
    buffer_float_t buffer_out;
} Magnitude_t;

void bf12c4b_init();
void bf12c4b_input_generate(int);
void bf12c4b_float_printer(int);
void bf12c4b_beam_fir_filter_coarse(int);
void bf12c4b_beam_fir_filter_fine(int);
void bf12c4b_beam_fir_filter_mf(int);
void bf12c4b_beam_form(int);
void bf12c4b_magnitude(int);
void bf12c4b_split_round_robin();
void bf12c4b_join_round_robin();
void bf12c4b_split_duplicate();
void bf12c4b_join2_round_robin();

#ifdef __cplusplus
}
#endif

#endif /* BEAMFORMER_H */

