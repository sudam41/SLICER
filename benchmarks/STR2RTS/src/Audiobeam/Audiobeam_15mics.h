#ifndef AUDIOBEAM_H
#define AUDIOBEAM_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif
    
//#define TheGlobal_MODE 0 // /tmp/Audiobeam.str:4
#define TheGlobal_HAMMING FALSE // /tmp/Audiobeam.str:6
#define TheGlobal_SOUND_SPEED 342 // /tmp/Audiobeam.str:8
#define TheGlobal_SAMPLING_RATE 16000 // /tmp/Audiobeam.str:9
#define TheGlobal_NUM_MICS 15 // /tmp/Audiobeam.str:11
    
#define TheGlobal_FILEIN "/home/sudam/STR2RTS/STR2RTS/streamit/streams/apps/benchmarks/audiobeam/data/c-data/near-field/data2"
    
#define TheGlobal_MAX_DATAREAD_IN_FILE TheGlobal_NUM_MICS
    
#define TheGlobal_TIMEINDEX_INCR (1.0f / TheGlobal_SAMPLING_RATE)
    
typedef struct {  // /tmp/Audiobeam.str:72
    float SOURCE_LOCATION[3]; // /tmp/Audiobeam.str:22
    float MIC_LOCATIONS[TheGlobal_NUM_MICS][3];
} TheGlobal_t;
TheGlobal_t TheGlobalBuf;

typedef struct {  // /tmp/Audiobeam.str:196
    int low_index;	// /tmp/Audiobeam.str:197
    int high_index;	// /tmp/Audiobeam.str:197
    float delay_offset;	// /tmp/Audiobeam.str:198
    float weights [TheGlobal_NUM_MICS];	// /tmp/Audiobeam.str:196
    float delays_mic;	// /tmp/Audiobeam.str:196
    
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} Interpolate_t;

typedef struct {
    buffer_float_t buffer_in;
    buffer_float_t buffer_out;
} Average_t;

typedef struct {  // /tmp/Audiobeam.str:222
    float time_index;	// /tmp/Audiobeam.str:224
} Printer_t;

void audiobeam_init();
void audiobeam_average();
void audiobeam_interpolate(int _param_mic);
void audiobeam_printer();
void audiobeam_split_round_robin();
void audiobeam_join_round_robin();

#ifdef __cplusplus
}
#endif

#endif /* AUDIOBEAM_H */

