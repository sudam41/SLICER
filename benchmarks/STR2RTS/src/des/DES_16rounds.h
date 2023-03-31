#ifndef DES_H
#define DES_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TheGlobal_testvector    7       // DES.str:6
#define TheGlobal_PLAINTEXT     0   	// Statics.str:7
#define TheGlobal_USERKEY       1   	// Statics.str:8
#define TheGlobal_CIPHERTEXT	2       // Statics.str:9
#define TheGlobal_MAXROUNDS	16      // Statics.str:12
    
#define TheGlobal_NBSamples  34
#define TheGlobal_NBSamples_Chunk  2
    
#define TheGlobal_PrinterDesc   "CIPHERTEXT"
#define TheGlobal_NBits         64
#define TheGlobal_ByteSize       4
#define TheGlobal_NBytes         TheGlobal_NBits/TheGlobal_ByteSize

#define TheGlobal_NB_SBox   8
    
#define TheGlobal_Length_PC1 56
#define TheGlobal_Length_PC2 48
    
typedef struct {  // Statics.str:4
    int USERKEYS [TheGlobal_NBSamples][TheGlobal_NBSamples_Chunk];	// Statics.str:15

    int PC1 [TheGlobal_Length_PC1];	// Statics.str:51
    int PC2 [TheGlobal_Length_PC2];	// Statics.str:61
    int RT [TheGlobal_NBytes];	// Statics.str:71
    int IP [TheGlobal_NBits];	// Statics.str:77
    int E [TheGlobal_Length_PC2];	// Statics.str:87
    int P [TheGlobal_NBits/2];	// Statics.str:97
    int IPm1 [TheGlobal_NBits];	// Statics.str:107
    int SBox[TheGlobal_NB_SBox][TheGlobal_ByteSize][TheGlobal_NBytes];	// Statics.str:117

    int PlainTextSource [TheGlobal_NBSamples][TheGlobal_NBSamples_Chunk]; // Source.str:9
    BIT keys [TheGlobal_MAXROUNDS][TheGlobal_Length_PC2];	// Keys.str:10
} TheGlobal_t;

typedef struct {  // Utils.str:36
    buffer_int_t buffer_in;
    buffer_bit_t buffer_out;
} IntoBits_t;

typedef struct {  // Utils.str:54
    buffer_bit_t buffer_in;
    buffer_int_t buffer_out;
} BitstoInts_t;

void des16r_init();
void des16r_plain_text_source();
void des16r_do_ip();
void des16r_do_e();
void des16r_do_p();
void des16r_do_ip_m1();
void des16r_sbox(int numbox);
void des16r_key_schedule(int round);
void des16r_xor(uint32_t size, buffer_bit_t *bufin, buffer_bit_t *bufout);
void des16r_criss_cross();
void des16r_int_to_bits();
void des16r_bits_to_ints();
void des16r_anonfilter_a1();
void des16r_identity(buffer_bit_t *in, buffer_bit_t *out);
void des16r_hex_printer();

void des16r_split6_weighted_round_robin();
void des16r_join6_round_robin() ;
void des16r_split7_weighted_round_robin() ;
void des16r_join7_round_robin() ;
void des16r_split1_round_robin();
void des16r_join1_round_robin();
void des16r_split5_weighted_round_robin() ;
void des16r_join5_weighted_round_robin();
void des16r_split4_duplicate();
void des16r_join4_weighted_round_robin();

#ifdef __cplusplus
}
#endif

#endif /* DES_H */

