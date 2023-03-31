#include "DES_16rounds.h"

TheGlobal_t TheGlobalBuf = {
    .USERKEYS = {{0,0},
            {-1,-1},
            {805306368,0},
            {286331153,286331153},
            {19088743,-1985229329},
            {286331153,286331153},
            {0,0},
            {-19088744,1985229328},
            {2090930245,1243246167},
            {20044129,-1648281746},
            {127996734,1242244742},
            {944334668,637677982},
            {79238586,1140766134},
            {18069872,-46861618},
            {24179061,1183823334},
            {1126793133,954430462},
            {128390000,1171925526},
            {73961732,-1023591633},
            {936405941,382432582},
            {520627725,448939614},
            {1480598372,448422262},
            {39327254,1177137159},
            {1232682684,2041783695},
            {1336958485,363557799},
            {1240030573,1285695935},
            {25366748,1083909846},
            {475561756,328355823},
            {16843009,16843009},
            {522133279,235802126},
            {-520167170,-234950146},
            {0,0},
            {-1,-1},
            {19088743,-1985229329},
            {-19088744,1985229328}}, // Statics.str:15
    .PC1 = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4}, // Statics.str:51
    .PC2 = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32}, // Statics.str:61
    .RT = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1}, // Statics.str:71
    .IP = {58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7}, // Statics.str:77
    .E = {32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1}, // Statics.str:87
    .P = {16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25}, // Statics.str:97
    .IPm1 = {40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25}, // Statics.str:107
    //*
    .SBox[0] = {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}}, // Statics.str:117
    .SBox[1] = {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                    {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                    {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                    {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}}, // Statics.str:122
    .SBox[2] = {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                    {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                    {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                    {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}}, // Statics.str:127
    .SBox[3] = {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                    {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                    {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                    {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}}, // Statics.str:132
    .SBox[4] = {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                    {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                    {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                    {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}}, // Statics.str:137
    .SBox[5] = {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                    {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                    {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                    {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}}, // Statics.str:142
    .SBox[6] = {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                    {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                    {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                    {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}}, // Statics.str:147
    .SBox[7] = {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                    {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                    {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                    {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}, // Statics.str:152
    .PlainTextSource = {
                       {0x00000000, 0x00000000},  // 0x0000000000000000
                       {0xFFFFFFFF, 0xFFFFFFFF},  // 0xFFFFFFFFFFFFFFFF
                       {0x10000000, 0x00000001},  // 0x1000000000000001
                       {0x11111111, 0x11111111},  // 0x1111111111111111
                       {0x11111111, 0x11111111},  // 0x1111111111111111
                       {0x01234567, 0x89ABCDEF},  // 0x0123456789ABCDEF
                       {0x00000000, 0x00000000},  // 0x0000000000000000
                       {0x01234567, 0x89ABCDEF},  // 0x0123456789ABCDEF
                       {0x01A1D6D0, 0x39776742},  // 0x01A1D6D039776742
                       {0x5CD54CA8, 0x3DEF57DA},  // 0x5CD54CA83DEF57DA
                       {0x0248D438, 0x06F67172},  // 0x0248D43806F67172
                       {0x51454B58, 0x2DDF440A},  // 0x51454B582DDF440A
                       {0x42FD4430, 0x59577FA2},  // 0x42FD443059577FA2
                       {0x059B5E08, 0x51CF143A},  // 0x059B5E0851CF143A
                       {0x0756D8E0, 0x774761D2},  // 0x0756D8E0774761D2
                       {0x762514B8, 0x29BF486A},  // 0x762514B829BF486A
                       {0x3BDD1190, 0x49372802},  // 0x3BDD119049372802
                       {0x26955F68, 0x35AF609A},  // 0x26955F6835AF609A
                       {0x164D5E40, 0x4F275232},  // 0x164D5E404F275232
                       {0x6B056E18, 0x759F5CCA},  // 0x6B056E18759F5CCA
                       {0x004BD6EF, 0x09176062},  // 0x004BD6EF09176062
                       {0x480D3900, 0x6EE762F2},  // 0x480D39006EE762F2
                       {0x437540C8, 0x698F3CFA},  // 0x437540C8698F3CFA
                       {0x072D43A0, 0x77075292},  // 0x072D43A077075292
                       {0x02FE5577, 0x8117F12A},  // 0x02FE55778117F12A
                       {0x1D9D5C50, 0x18F728C2},  // 0x1D9D5C5018F728C2
                       {0x30553228, 0x6D6F295A},  // 0x305532286D6F295A
                       {0x01234567, 0x89ABCDEF},  // 0x0123456789ABCDEF
                       {0x01234567, 0x89ABCDEF},  // 0x0123456789ABCDEF
                       {0x01234567, 0x89ABCDEF},  // 0x0123456789ABCDEF
                       {0xFFFFFFFF, 0xFFFFFFFF},  // 0xFFFFFFFFFFFFFFFF
                       {0x00000000, 0x00000000},  // 0x0000000000000000
                       {0x00000000, 0x00000000},  // 0x0000000000000000
                       {0xFFFFFFFF, 0xFFFFFFFF}} // 0xFFFFFFFFFFFFFFFF
};
channel_bit_t doIPBuf;
channel_bit_t doEBuf;
channel_bit_t doPBuf;
channel_bit_t SboxBuf[TheGlobal_NB_SBox];
channel_bit_t CrissCrossBuf;
IntoBits_t IntoBitsBuf;
BitstoInts_t BitstoIntsBuf;
channel_bit_t AnonFilter_a1Buf;
channel_bit_t KeyScheduleBuf;
//AnonFilter_a6_t AnonFilter_a6Buf;

channel_bit_t nextRBuf;
channel_bit_t nextLBuf;
channel_bit_t fBuf;
channel_bit_t IdentityBufR;
channel_bit_t xorNr;
channel_bit_t xorf;
channel_bit_t IdentityBufL;

// AnonFilter_a14
void des16r_plain_text_source() { // Source.str:45
    push_int(&IntoBitsBuf.buffer_in, TheGlobalBuf.PlainTextSource[TheGlobal_testvector][1]); // Source.str:46
    push_int(&IntoBitsBuf.buffer_in, TheGlobalBuf.PlainTextSource[TheGlobal_testvector][0]); // Source.str:47
}

void des16r_int_to_bits() { // Utils.str:38
    FOR(uint32_t, r, 0, <, TheGlobal_NBSamples_Chunk , r++)
        int v = pop_int(&IntoBitsBuf.buffer_in); // Utils.str:39
        int m = 1; // Utils.str:40
        FOR(uint32_t, i, 0, <, TheGlobal_NBits/TheGlobal_NBSamples_Chunk, (i)++) // Utils.str:42
            if ((((v & m) >> i) != 0)) { // Utils.str:44
                push_bit(&IntoBitsBuf.buffer_out, 1); // Utils.str:44
            } else { // Utils.str:46
                push_bit(&IntoBitsBuf.buffer_out, 0); // Utils.str:46
            }
            m = (m << 1); // Utils.str:47
        ENDFOR
    ENDFOR
}

void des16r_do_ip() { // DES.str:35
    FOR(uint32_t, i, 0, <, TheGlobal_NBits, i++) // DES.str:36
        push_bit(&doIPBuf.buffer_out, peek_bit(&IntoBitsBuf.buffer_out, (TheGlobalBuf.IP[i] - 1))); // DES.str:37
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits, i++) // DES.str:39
        pop_bit(&IntoBitsBuf.buffer_out); // DES.str:40
    ENDFOR
}

void des16r_do_e() { // DES.str:94
    FOR(uint32_t, i, 0, <, TheGlobal_Length_PC2, (i)++) // DES.str:95
        push_bit(&doEBuf.buffer_out, peek_bit(&doEBuf.buffer_in, (TheGlobalBuf.E[i] - 1))); // DES.str:96
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2, (i)++) // DES.str:98
        pop_bit(&doEBuf.buffer_in); // DES.str:99
    ENDFOR
}
// AnonFilter_a5
void des16r_key_schedule(int round) { // Keys.str:63
    FOR(uint32_t, i, 0, <, TheGlobal_Length_PC2, (i)++) // Keys.str:64
        push_bit(&KeyScheduleBuf.buffer_out, TheGlobalBuf.keys[round][i]); // Keys.str:65
    ENDFOR
}

void des16r_do_p() { // DES.str:106
    FOR2(int, i, (TheGlobal_NBits/2)-1, >=, 0, TheGlobal_NBits/2, i--) // DES.str:115
        push_bit(&doPBuf.buffer_out, peek_bit(&doPBuf.buffer_in, (32 - TheGlobalBuf.P[i]))); // DES.str:116
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2, i++) // DES.str:118
        pop_bit(&doPBuf.buffer_in); // DES.str:119
    ENDFOR
}
void des16r_do_ip_m1() { // DES.str:126
    FOR(uint32_t, i, 0, <, TheGlobal_NBits, (i)++) // DES.str:127
        push_bit(&BitstoIntsBuf.buffer_in, peek_bit(&CrissCrossBuf.buffer_out, (TheGlobalBuf.IPm1[i] - 1))); // DES.str:128
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits, (i)++) // DES.str:130
        pop_bit(&CrissCrossBuf.buffer_out); // DES.str:131
    ENDFOR
}
void des16r_sbox(int numbox) {
    int r = pop_bit(&SboxBuf[numbox].buffer_in); // Sboxes.str:25
    int c = pop_bit(&SboxBuf[numbox].buffer_in); // Sboxes.str:26
    c = ((pop_bit(&SboxBuf[numbox].buffer_in) << 1) | c); // Sboxes.str:27
    c = ((pop_bit(&SboxBuf[numbox].buffer_in) << 2) | c); // Sboxes.str:28
    c = ((pop_bit(&SboxBuf[numbox].buffer_in) << 3) | c); // Sboxes.str:29
    r = ((pop_bit(&SboxBuf[numbox].buffer_in) << 1) | r); // Sboxes.str:30
    
    int out = TheGlobalBuf.SBox[TheGlobal_NB_SBox-1-numbox][r][c]; // Sboxes.str:32
    push_bit(&SboxBuf[numbox].buffer_out, ((((out & 1) >> 0)))); // Sboxes.str:33
    push_bit(&SboxBuf[numbox].buffer_out, ((((out & 2) >> 1)))); // Sboxes.str:34
    push_bit(&SboxBuf[numbox].buffer_out, ((((out & 4) >> 2)))); // Sboxes.str:35
    push_bit(&SboxBuf[numbox].buffer_out, ((((out & 8) >> 3)))); // Sboxes.str:36
}
void des16r_xor(uint32_t size, buffer_bit_t *bufin, buffer_bit_t *bufout) { // Utils.str:8
    FOR2(uint32_t, s, 0, <, size, TheGlobal_Length_PC2, s++)
        BIT _bit_x = pop_bit(bufin); // Utils.str:9
        BIT _bit_y = pop_bit(bufin); // Utils.str:11
        _bit_x = (_bit_x ^ _bit_y); // Utils.str:12
        
        push_bit(bufout, _bit_x); // Utils.str:14
    ENDFOR
}
void des16r_criss_cross() { // Utils.str:21
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2, i++) // Utils.str:22
        push_bit(&CrissCrossBuf.buffer_out, peek_bit(&doIPBuf.buffer_out, (32 + i))); // Utils.str:23
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2, i++) // Utils.str:25
        push_bit(&CrissCrossBuf.buffer_out, pop_bit(&doIPBuf.buffer_out)); // Utils.str:26
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2, i++) // Utils.str:28
        pop_bit(&doIPBuf.buffer_out); // Utils.str:29
    ENDFOR
}

void des16r_bits_to_ints() { // Utils.str:56
    FOR(uint32_t, x, 0, <, TheGlobal_NBytes , ++x)
        int v = 0; // Utils.str:57
        FOR(uint32_t, i, 0, <, TheGlobal_ByteSize, i++) // Utils.str:58
            v = (v | (pop_bit(&BitstoIntsBuf.buffer_in) << i)); // Utils.str:59
        ENDFOR
        push_int(&BitstoIntsBuf.buffer_out, v); // Utils.str:61
    ENDFOR
}
void des16r_anonfilter_a1() { // DES.str:53
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        pop_bit(&AnonFilter_a1Buf.buffer_in); // DES.str:53
    ENDFOR
}

//AnonFilter_a16
void des16r_hex_printer() { // Utils.str:86
    FOR2(int, i, (TheGlobal_NBytes - 1), >=, 0, TheGlobal_NBytes, i--) // Utils.str:96
        int v = peek_int(&BitstoIntsBuf.buffer_out, i); // Utils.str:97
        if (v < 10) // Utils.str:98
            v += 48;
        else
            v += 55;
        printf("%c", v); // Utils.str:98
    ENDFOR
    printf("\n"); // Utils.str:110
    FOR(uint32_t, i, 0, <, TheGlobal_NBytes, i++) // Utils.str:113
        pop_int(&BitstoIntsBuf.buffer_out); // Utils.str:113
    ENDFOR
}

void des16r_identity(buffer_bit_t *in, buffer_bit_t *out) {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(out, pop_bit(in));
    ENDFOR
}

void des16r_init() {
     // Keys.str:13
    BIT k64 [TheGlobal_NBits]; // Keys.str:14
    FOR2(int, w, 1, >=, 0, 2, w--) // Keys.str:16
        int v = TheGlobalBuf.USERKEYS[TheGlobal_testvector][w]; // Keys.str:17
        int m = 1; // Keys.str:18
        FOR(uint32_t, i, 0, <, TheGlobal_NBits/2, (i)++) // Keys.str:19
            if ((((v & m) >> i) != 0)) { // Keys.str:21
                k64[(((1 - w) * (TheGlobal_NBits/2)) + i)] = 1; // Keys.str:21
            } else { // Keys.str:23
                k64[(((1 - w) * (TheGlobal_NBits/2)) + i)] = 0; // Keys.str:23
            }
            m = (m << 1); // Keys.str:24
        ENDFOR
    ENDFOR
                
    BIT k56 [TheGlobal_Length_PC1]; // Keys.str:29
    FOR(uint32_t, i, 0, <, TheGlobal_Length_PC1, (i)++) // Keys.str:30
        k56[i] = k64[(TheGlobal_NBits - TheGlobalBuf.PC1[i])]; // Keys.str:37
    ENDFOR
    FOR(uint32_t, r, 0, <, TheGlobal_MAXROUNDS, (r)++) // Keys.str:40
        BIT bits [TheGlobal_Length_PC1]; // Keys.str:43
        FOR(uint32_t, i, 0, <, TheGlobal_Length_PC1/2, (i)++) // Keys.str:45
            bits[i] = k56[((i + TheGlobalBuf.RT[r]) % (TheGlobal_Length_PC1/2))]; // Keys.str:45
        ENDFOR
        FOR2(uint32_t, i, TheGlobal_Length_PC1/2, <, TheGlobal_Length_PC1, TheGlobal_Length_PC1-(TheGlobal_Length_PC1/2), i++) // Keys.str:47
            bits[i] = k56[((TheGlobal_Length_PC1/2) + ((i + TheGlobalBuf.RT[r]) % (TheGlobal_Length_PC1/2)))]; // Keys.str:47
        ENDFOR
        FOR(uint32_t, i, 0, <, TheGlobal_Length_PC1, (i)++) // Keys.str:49
            k56[i] = bits[i]; // Keys.str:49
        ENDFOR
        FOR2(int, i, TheGlobal_Length_PC2-1, >=, 0, TheGlobal_Length_PC2, i--) // Keys.str:52
            TheGlobalBuf.keys[r][(TheGlobal_Length_PC2-1 - i)] = k56[(TheGlobalBuf.PC2[i] - 1)]; // Keys.str:58
        ENDFOR
    ENDFOR
    
    init_buffer_int(&IntoBitsBuf.buffer_in);
    init_buffer_bit(&IntoBitsBuf.buffer_out);
    init_buffer_bit(&BitstoIntsBuf.buffer_in);
    init_buffer_int(&BitstoIntsBuf.buffer_out);
    
    init_buffer_bit(&doIPBuf.buffer_out);
    init_buffer_bit(&KeyScheduleBuf.buffer_out);
    
    init_buffer_bit(&AnonFilter_a1Buf.buffer_in);
    
    init_buffer_bit(&doEBuf.buffer_in);
    init_buffer_bit(&doEBuf.buffer_out);
    init_buffer_bit(&doPBuf.buffer_in);
    init_buffer_bit(&doPBuf.buffer_out);
    init_buffer_bit(&CrissCrossBuf.buffer_in);
    init_buffer_bit(&CrissCrossBuf.buffer_out);
    FOR(uint32_t, i, 0, <, TheGlobal_NB_SBox , i++)
        init_buffer_bit(&SboxBuf[i].buffer_in);
        init_buffer_bit(&SboxBuf[i].buffer_out);
    ENDFOR
    
    init_buffer_bit(&nextRBuf.buffer_in);
    init_buffer_bit(&nextRBuf.buffer_out);
    init_buffer_bit(&nextLBuf.buffer_in);
    init_buffer_bit(&nextLBuf.buffer_out);
    
    init_buffer_bit(&fBuf.buffer_in);
    init_buffer_bit(&IdentityBufR.buffer_in);
    init_buffer_bit(&IdentityBufR.buffer_out);
    init_buffer_bit(&xorNr.buffer_in);
    init_buffer_bit(&xorNr.buffer_out);
    init_buffer_bit(&xorf.buffer_in);
    init_buffer_bit(&xorf.buffer_out);
    init_buffer_bit(&IdentityBufL.buffer_in);
    init_buffer_bit(&IdentityBufL.buffer_out);
    
}

void des16r_split4_duplicate() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits , i++)
        BIT b = pop_bit(&doIPBuf.buffer_out);
        push_bit(&nextRBuf.buffer_in, b);
        push_bit(&nextLBuf.buffer_in, b);
    ENDFOR
}

void des16r_split6_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&fBuf.buffer_in, pop_bit(&nextRBuf.buffer_in));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&IdentityBufR.buffer_in, pop_bit(&nextRBuf.buffer_in));
    ENDFOR
}
void des16r_join6_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&xorNr.buffer_in, pop_bit(&doPBuf.buffer_out));
        push_bit(&xorNr.buffer_in, pop_bit(&IdentityBufR.buffer_out));
    ENDFOR
}
void des16r_split7_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&doEBuf.buffer_in, pop_bit(&fBuf.buffer_in));
    ENDFOR
}
void des16r_join7_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_Length_PC2 , i++)
        push_bit(&xorf.buffer_in, pop_bit(&doEBuf.buffer_out));
        push_bit(&xorf.buffer_in, pop_bit(&KeyScheduleBuf.buffer_out));
    ENDFOR
}

void des16r_split1_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NB_SBox , i++)
        FOR(uint32_t, j, 0, <, 6 /* 6*8=48 */ , j++)
            push_bit(&SboxBuf[i].buffer_in, pop_bit(&xorf.buffer_out));
        ENDFOR
    ENDFOR
}

void des16r_join1_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NB_SBox , i++)
        FOR(uint32_t, j, 0, <, 4 , j++)
            push_bit(&doPBuf.buffer_in, pop_bit(&SboxBuf[i].buffer_out));
        ENDFOR
    ENDFOR
}

void des16r_split5_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&IdentityBufL.buffer_in, pop_bit(&nextLBuf.buffer_in));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&AnonFilter_a1Buf.buffer_in, pop_bit(&nextLBuf.buffer_in));
    ENDFOR
}
void des16r_join5_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&nextLBuf.buffer_out, pop_bit(&IdentityBufL.buffer_out));
    ENDFOR
}

void des16r_join4_weighted_round_robin() {
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&doIPBuf.buffer_out, pop_bit(&xorNr.buffer_out));
    ENDFOR
    FOR(uint32_t, i, 0, <, TheGlobal_NBits/2 , i++)
        push_bit(&doIPBuf.buffer_out, pop_bit(&nextLBuf.buffer_out));
    ENDFOR
}

int main(int argv, char** argc) {
    des16r_init();

    FOR(uint32_t, iter, 0, <, MAX_ITERATION , iter++)
        des16r_plain_text_source();
        des16r_int_to_bits();
        des16r_do_ip();
        FOR(uint32_t, round, 0, <, TheGlobal_MAXROUNDS, round++) // DES.str:18
            des16r_split4_duplicate();
                //nextR
                des16r_split6_weighted_round_robin();
                    des16r_split7_weighted_round_robin();
                        des16r_do_e();
                        des16r_key_schedule(round);
                    des16r_join7_round_robin();
                    des16r_xor(TheGlobal_Length_PC2, &xorf.buffer_in, &xorf.buffer_out);
                    des16r_split1_round_robin();  // Sboxes.str:8
                    FOR(uint32_t, sb, 0, <, TheGlobal_NB_SBox , ++sb)
                        des16r_sbox(sb);
                    ENDFOR
                    des16r_join1_round_robin();
                    des16r_do_p();
                    des16r_identity(&IdentityBufR.buffer_in, &IdentityBufR.buffer_out);
                des16r_join6_round_robin();
                des16r_xor(TheGlobal_NBits/2, &xorNr.buffer_in, &xorNr.buffer_out);
                //nextL
                des16r_split5_weighted_round_robin();
                    des16r_identity(&IdentityBufL.buffer_in, &IdentityBufL.buffer_out);
                    des16r_anonfilter_a1();
                des16r_join5_weighted_round_robin();
            des16r_join4_weighted_round_robin();
        ENDFOR
        des16r_criss_cross();
        des16r_do_ip_m1();
        des16r_bits_to_ints();
        des16r_hex_printer();
    ENDFOR
    
    return EXIT_SUCCESS;
} 
