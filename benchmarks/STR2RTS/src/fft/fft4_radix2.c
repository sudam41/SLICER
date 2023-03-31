#include "FFT4.h"
// GLOBAL_N is defined in the header file and its value is 2

void fft4_one_source() { ... }
void fft4_identity() { ... }
void fft4_multiply() { ... }
void fft4_add() {
_Pragma("loopbound min "GLOBAL_N/2" max "GLOBAL_N/2) 
  for(int i=0 ; i < GLOBAL_N/2 ; i++) {
    float v1 = pop_float(&AddBuf.buffer_in);
    float v2 = pop_float(&AddBuf.buffer_in);
    push_float(&AddBuf.buffer_out, v1+v2);
  }
}
void fft4_subtract() { ... }
void fft4_float_printer() { ... }
void fft4_init() { ... }
void fft4_split1_weighted_round_robin( uint32_t nb ) { ... }
void fft4_join1_round_robin() { ... }
void fft4_split2_duplicate() { ... }
void fft4_join2_weighted_round_robin( uint32_t nb ) { ... }
int sequential_main( int argv, char **argc ) {
  fft4_init();
_Pragma("loopbound min "MAX_ITERATION" max "MAX_ITERATION)
  for( int i=0 ; i < MAX_ITERATION ; i++ ) {
    fft4_OneSource();
_Pragma("loopbound min "(GLOBAL_N/2-1)" max "(GLOBAL_N/2-1))
    for( int j = 1 ; j < GLOBAL_N ; j *= 2 ) {
      fft4_split1_weighted_round_robinv(j);
        fft4_identity();
        fft4_multiply();
      fft4_join1_round_robin();
      fft4_split2_duplicate();
        fft4_add();
        fft4_subtract();
      fft4_join2_weighted_round_robin(j);
    }
    fft4_float_printer();
  }
  return EXIT_SUCCESS;
}