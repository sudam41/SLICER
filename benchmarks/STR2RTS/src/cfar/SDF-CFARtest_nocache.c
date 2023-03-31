#include "SDF-CFARtest_nocache.h"

buffer_float_t CFAR_gather_17AnonFilter_a0_18;
buffer_float_t SquareAndScale_16CFAR_gather_17;
buffer_complex_t ComplexSource_14SquareAndScale_16;


ComplexSource_14_t ComplexSource_14_s;
CFAR_gather_17_t CFAR_gather_17_s;

void ComplexSource_14() {
	FOR(int, i, 0,  < , 64, i++) {
		complex_t c = {
			.real = 0,
			.imag = 0
		};
		ComplexSource_14_s.theta = (ComplexSource_14_s.theta + 0.19634955) ; 
		c.real = ((((float) sin(ComplexSource_14_s.theta)) * (((float) cos(ComplexSource_14_s.theta)) + ((0.0 * ((float) sin(ComplexSource_14_s.theta))) - 0.0))) - (0.0 * (0.0 + (1.0 * ((float) sin(ComplexSource_14_s.theta)))))) ; 
		c.imag = ((((float) sin(ComplexSource_14_s.theta)) * (0.0 + (1.0 * ((float) sin(ComplexSource_14_s.theta))))) + (0.0 * (((float) cos(ComplexSource_14_s.theta)) + ((0.0 * ((float) sin(ComplexSource_14_s.theta))) - 0.0)))) ; 
		push_complex(&ComplexSource_14SquareAndScale_16, c) ; 
	}
	ENDFOR
}


void SquareAndScale_16(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		complex_t c = ((complex_t) pop_complex(&ComplexSource_14SquareAndScale_16));
		float mag = 0.0;
		mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
		push_float(&SquareAndScale_16CFAR_gather_17, ((mag * mag) / 10.0)) ; 
	}
	ENDFOR
}

void CFAR_gather_17(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		float sum = 0.0;
		FOR4(int, i__conflict__1, 0, ((i__conflict__1 < 5) && (((i__conflict__1 + CFAR_gather_17_s.pos) - 5) >= 0)), __DEFLOOPBOUND__2__, i__conflict__1++) {
			sum = (sum + CFAR_gather_17_s.poke[((5 - i__conflict__1) - 1)]) ; 
		}
		ENDFOR
		FOR4(int, i__conflict__0, 5, ((i__conflict__0 <= 9) && ((i__conflict__0 + CFAR_gather_17_s.pos) < 64)), __DEFLOOPBOUND__3__, i__conflict__0++) {
			sum = (sum + peek_float(&SquareAndScale_16CFAR_gather_17, i__conflict__0)) ; 
		}
		ENDFOR
		push_float(&CFAR_gather_17AnonFilter_a0_18, sum) ; 
		FOR(int, i, 1,  < , 9, i++) {
			CFAR_gather_17_s.poke[(i - 1)] = CFAR_gather_17_s.poke[i] ; 
		}
		ENDFOR
		CFAR_gather_17_s.poke[8] = pop_float(&SquareAndScale_16CFAR_gather_17) ; 
		CFAR_gather_17_s.pos++ ; 
		if(CFAR_gather_17_s.pos == 64) {
			CFAR_gather_17_s.pos = 0 ; 
		}
	}
	ENDFOR
}

void AnonFilter_a0_18(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		printf("%.10f", pop_float(&CFAR_gather_17AnonFilter_a0_18));
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_float(&CFAR_gather_17AnonFilter_a0_18);
	init_buffer_float(&SquareAndScale_16CFAR_gather_17);
	init_buffer_complex(&ComplexSource_14SquareAndScale_16);
// --- init: ComplexSource_14
	 {
	ComplexSource_14_s.theta = 0.0 ; 
}
	 {
	FOR(int, i, 0,  < , 64, i++) {
		complex_t c = {
			.real = 0,
			.imag = 0
		};
		ComplexSource_14_s.theta = (ComplexSource_14_s.theta + 0.19634955) ; 
		c.real = ((((float) sin(ComplexSource_14_s.theta)) * (((float) cos(ComplexSource_14_s.theta)) + ((0.0 * ((float) sin(ComplexSource_14_s.theta))) - 0.0))) - (0.0 * (0.0 + (1.0 * ((float) sin(ComplexSource_14_s.theta)))))) ; 
		c.imag = ((((float) sin(ComplexSource_14_s.theta)) * (0.0 + (1.0 * ((float) sin(ComplexSource_14_s.theta))))) + (0.0 * (((float) cos(ComplexSource_14_s.theta)) + ((0.0 * ((float) sin(ComplexSource_14_s.theta))) - 0.0)))) ; 
		push_complex(&ComplexSource_14SquareAndScale_16, c) ; 
	}
	ENDFOR
}
//--------------------------------
// --- init: SquareAndScale_16
	FOR(uint32_t, __iter_init_, 0, <, 64, __iter_init_++) {
		complex_t c = ((complex_t) pop_complex(&ComplexSource_14SquareAndScale_16));
		float mag = 0.0;
		mag = ((float) sqrt(((c.real * c.real) + (c.imag * c.imag)))) ; 
		push_float(&SquareAndScale_16CFAR_gather_17, ((mag * mag) / 10.0)) ; 
	}
	ENDFOR
//--------------------------------
// --- init: CFAR_gather_17
	 {
	CFAR_gather_17_s.pos = 0 ; 
}
	FOR(uint32_t, __iter_init_, 0, <, 55, __iter_init_++) {
		float sum = 0.0;
		FOR4(int, i__conflict__1, 0, ((i__conflict__1 < 5) && (((i__conflict__1 + CFAR_gather_17_s.pos) - 5) >= 0)), __DEFLOOPBOUND__4__, i__conflict__1++) {
			sum = (sum + CFAR_gather_17_s.poke[((5 - i__conflict__1) - 1)]) ; 
		}
		ENDFOR
		FOR4(int, i__conflict__0, 5, ((i__conflict__0 <= 9) && ((i__conflict__0 + CFAR_gather_17_s.pos) < 64)), __DEFLOOPBOUND__5__, i__conflict__0++) {
			sum = (sum + peek_float(&SquareAndScale_16CFAR_gather_17, i__conflict__0)) ; 
		}
		ENDFOR
		push_float(&CFAR_gather_17AnonFilter_a0_18, sum) ; 
		FOR(int, i, 1,  < , 9, i++) {
			CFAR_gather_17_s.poke[(i - 1)] = CFAR_gather_17_s.poke[i] ; 
		}
		ENDFOR
		CFAR_gather_17_s.poke[8] = pop_float(&SquareAndScale_16CFAR_gather_17) ; 
		CFAR_gather_17_s.pos++ ; 
		if(CFAR_gather_17_s.pos == 64) {
			CFAR_gather_17_s.pos = 0 ; 
		}
	}
	ENDFOR
//--------------------------------
// --- init: AnonFilter_a0_18
	FOR(uint32_t, __iter_init_, 0, <, 55, __iter_init_++) {
		printf("%.10f", pop_float(&CFAR_gather_17AnonFilter_a0_18));
		printf("\n");
	}
	ENDFOR
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		ComplexSource_14();
		SquareAndScale_16();
		CFAR_gather_17();
		AnonFilter_a0_18();
	ENDFOR
	return EXIT_SUCCESS;
}
