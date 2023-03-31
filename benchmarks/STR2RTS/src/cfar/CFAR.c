#include "CFAR.h"

#include "sim_api.h"

channel_t cfar_square_and_scaleBuf;
CFAR_gather_t CFAR_gatherBuf;
ComplexSource_t ComplexSourceBuf;

void cfar_square_and_scale() { // .CFARtest.str:27
	SimNamedMarker(5, __func__);
    FOR(uint32_t, cell, 0, <, TheGlobal_ROW_LENGTH , cell++)
        complex_t c = pop_complex(&ComplexSourceBuf.buffer_out); // .CFARtest.str:28
        float mag = sqrt(((c.real * c.real) + (c.imag * c.imag))); // .CFARtest.str:29
        push_float(&cfar_square_and_scaleBuf.buffer_out, ((mag * mag) / 10.0f));//(float)(2*TheGlobal_NB_CONSIDERED_GATES))); // .CFARtest.str:30
    ENDFOR
}

//-- cfar_gather splitted in 2 functions to easily handle the initialisation phase
inline void cfar_gather_work() { // .CFARtest.str:46
    float sum = 0; // .CFARtest.str:47
    FOR2(uint32_t, i, 0, <, TheGlobal_NB_CONSIDERED_GATES && (i + CFAR_gatherBuf.pos - TheGlobal_NB_CONSIDERED_GATES) >= 0, TheGlobal_NB_CONSIDERED_GATES, i++) // .CFARtest.str:50
        sum += CFAR_gatherBuf.poke[((TheGlobal_NB_CONSIDERED_GATES - i) - 1)]; // .CFARtest.str:50
    ENDFOR

    FOR2(uint32_t, i, (TheGlobal_NB_IGNORED_GATES + 1), <=, (TheGlobal_NB_CONSIDERED_GATES + TheGlobal_NB_IGNORED_GATES) && 
                                                  (i + CFAR_gatherBuf.pos) < TheGlobal_ROW_LENGTH, TheGlobal_NB_CONSIDERED_GATES+1, i++) // .CFARtest.str:53
        sum += peek_float(&cfar_square_and_scaleBuf.buffer_out, i); // .CFARtest.str:53
    ENDFOR

    push_float(&CFAR_gatherBuf.buffer_out, sum); // .CFARtest.str:55
    FOR2(uint32_t, i, 1, <, TheGlobal_NB_CONSIDERED_GATES + TheGlobal_NB_IGNORED_GATES, TheGlobal_NB_CONSIDERED_GATES+TheGlobal_NB_IGNORED_GATES-1, i++) // .CFARtest.str:58
        CFAR_gatherBuf.poke[(i - 1)] = CFAR_gatherBuf.poke[i]; // .CFARtest.str:58
    ENDFOR
    CFAR_gatherBuf.poke[((TheGlobal_NB_CONSIDERED_GATES + TheGlobal_NB_IGNORED_GATES) - 1)] = pop_float(&cfar_square_and_scaleBuf.buffer_out); // .CFARtest.str:59
    CFAR_gatherBuf.pos = (CFAR_gatherBuf.pos+1)%TheGlobal_ROW_LENGTH; // .CFARtest.str:61
}
void cfar_gather() { // .CFARtest.str:46
	SimNamedMarker(5, __func__);
    FOR(uint32_t, cell, 0, <, TheGlobal_ROW_LENGTH, cell++)
        cfar_gather_work();
    ENDFOR
}

void cfar_complex_source() { // .CFARtest.str:85
	SimNamedMarker(5, __func__);
    FOR(uint32_t, i, 0, <, TheGlobal_ROW_LENGTH*2, i++) // .CFARtest.str:87
        ComplexSourceBuf.theta += 0.19634955f;//(3.141592653589793f / 16); // .CFARtest.str:88
        complex_t c = {
            .real = sinf(ComplexSourceBuf.theta) * cosf(ComplexSourceBuf.theta), // .CFARtest.str:89
            .imag = sinf(ComplexSourceBuf.theta) * sinf(ComplexSourceBuf.theta)
        }; // .CFARtest.str:89
        push_complex(&ComplexSourceBuf.buffer_out, c); // .CFARtest.str:91
    ENDFOR
}

void cfar_printer() { // .CFARtest.str:72
	SimNamedMarker(5, __func__);
    FOR(uint32_t, cell, 0, <, TheGlobal_ROW_LENGTH , cell++)
        float res = pop_float(&CFAR_gatherBuf.buffer_out);
        printf("%f\n", res); // .CFARtest.str:72
    ENDFOR
}

void cfar_init() { // .CFARtest.str:17
    init_buffer_float(&cfar_square_and_scaleBuf.buffer_out);
    ComplexSourceBuf.theta = 0; // .CFARtest.str:82
    init_buffer_complex(&ComplexSourceBuf.buffer_out);
    
    CFAR_gatherBuf.pos = 0; // .CFARtest.str:43
    FOR(uint32_t, i, 0, <, TheGlobal_NB_CONSIDERED_GATES+TheGlobal_NB_IGNORED_GATES , i++)
        CFAR_gatherBuf.poke[i] = 0;
    ENDFOR
    init_buffer_float(&CFAR_gatherBuf.buffer_out);
    
    cfar_complex_source();
    cfar_square_and_scale();
    FOR(uint32_t, i, 0, <, 55, i++) 
        cfar_gather_work();
        float res = pop_float(&CFAR_gatherBuf.buffer_out);
        printf("%f\n", res); // .CFARtest.str:72
    ENDFOR
}

int main(int argv, char** argc) {
    cfar_init();
    
    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        cfar_complex_source();
        cfar_square_and_scale();
        cfar_gather();
        cfar_printer();
    ENDFOR
    
    return EXIT_SUCCESS;
}
