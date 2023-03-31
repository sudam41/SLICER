#include "SDF-FFT6_nocache.h"

buffer_complex_t CombineDFT_32CombineDFT_33;
buffer_complex_t CombineDFT_31CombineDFT_32;
buffer_complex_t CombineDFT_30CombineDFT_31;
buffer_complex_t FFTTestSource_22FFTReorderSimple_23;
buffer_complex_t FFTReorderSimple_23FFTReorderSimple_24;
buffer_complex_t FFTReorderSimple_27CombineDFT_28;
buffer_complex_t FFTReorderSimple_24FFTReorderSimple_25;
buffer_complex_t CombineDFT_28CombineDFT_29;
buffer_complex_t FFTReorderSimple_25FFTReorderSimple_26;
buffer_complex_t CombineDFT_33CPrinter_34;
buffer_complex_t CombineDFT_29CombineDFT_30;
buffer_complex_t FFTReorderSimple_26FFTReorderSimple_27;


CombineDFT_28_t CombineDFT_28_s;
CombineDFT_28_t CombineDFT_29_s;
CombineDFT_28_t CombineDFT_30_s;
CombineDFT_28_t CombineDFT_31_s;
CombineDFT_28_t CombineDFT_32_s;
CombineDFT_28_t CombineDFT_33_s;

void FFTTestSource_22() {
	complex_t c1;
	complex_t zero;
	c1.real = 1.0 ; 
	c1.imag = 0.0 ; 
	zero.real = 0.0 ; 
	zero.imag = 0.0 ; 
	push_complex(&FFTTestSource_22FFTReorderSimple_23, zero) ; 
	push_complex(&FFTTestSource_22FFTReorderSimple_23, c1) ; 
	FOR(int, i, 0,  < , 62, i++) {
		push_complex(&FFTTestSource_22FFTReorderSimple_23, zero) ; 
	}
	ENDFOR
}


void FFTReorderSimple_23() {
	FOR(int, i, 0,  < , 64, i = (i + 2)) {
		complex_t __sa7 = {
			.real = 0,
			.imag = 0
		};
		__sa7 = ((complex_t) peek_complex(&FFTTestSource_22FFTReorderSimple_23, i)) ; 
		push_complex(&FFTReorderSimple_23FFTReorderSimple_24, __sa7) ; 
	}
	ENDFOR
	FOR(int, i, 1,  < , 64, i = (i + 2)) {
		complex_t __sa8 = {
			.real = 0,
			.imag = 0
		};
		__sa8 = ((complex_t) peek_complex(&FFTTestSource_22FFTReorderSimple_23, i)) ; 
		push_complex(&FFTReorderSimple_23FFTReorderSimple_24, __sa8) ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_complex(&FFTTestSource_22FFTReorderSimple_23) ; 
	}
	ENDFOR
}


void FFTReorderSimple_24(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		FOR(int, i, 0,  < , 32, i = (i + 2)) {
			complex_t __sa7 = {
				.real = 0,
				.imag = 0
			};
			__sa7 = ((complex_t) peek_complex(&FFTReorderSimple_23FFTReorderSimple_24, i)) ; 
			push_complex(&FFTReorderSimple_24FFTReorderSimple_25, __sa7) ; 
		}
		ENDFOR
		FOR(int, i, 1,  < , 32, i = (i + 2)) {
			complex_t __sa8 = {
				.real = 0,
				.imag = 0
			};
			__sa8 = ((complex_t) peek_complex(&FFTReorderSimple_23FFTReorderSimple_24, i)) ; 
			push_complex(&FFTReorderSimple_24FFTReorderSimple_25, __sa8) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 32, i++) {
			pop_complex(&FFTReorderSimple_23FFTReorderSimple_24) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_25(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		FOR(int, i, 0,  < , 16, i = (i + 2)) {
			complex_t __sa7 = {
				.real = 0,
				.imag = 0
			};
			__sa7 = ((complex_t) peek_complex(&FFTReorderSimple_24FFTReorderSimple_25, i)) ; 
			push_complex(&FFTReorderSimple_25FFTReorderSimple_26, __sa7) ; 
		}
		ENDFOR
		FOR(int, i, 1,  < , 16, i = (i + 2)) {
			complex_t __sa8 = {
				.real = 0,
				.imag = 0
			};
			__sa8 = ((complex_t) peek_complex(&FFTReorderSimple_24FFTReorderSimple_25, i)) ; 
			push_complex(&FFTReorderSimple_25FFTReorderSimple_26, __sa8) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 16, i++) {
			pop_complex(&FFTReorderSimple_24FFTReorderSimple_25) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_26(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		FOR(int, i, 0,  < , 8, i = (i + 2)) {
			complex_t __sa7 = {
				.real = 0,
				.imag = 0
			};
			__sa7 = ((complex_t) peek_complex(&FFTReorderSimple_25FFTReorderSimple_26, i)) ; 
			push_complex(&FFTReorderSimple_26FFTReorderSimple_27, __sa7) ; 
		}
		ENDFOR
		FOR(int, i, 1,  < , 8, i = (i + 2)) {
			complex_t __sa8 = {
				.real = 0,
				.imag = 0
			};
			__sa8 = ((complex_t) peek_complex(&FFTReorderSimple_25FFTReorderSimple_26, i)) ; 
			push_complex(&FFTReorderSimple_26FFTReorderSimple_27, __sa8) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 8, i++) {
			pop_complex(&FFTReorderSimple_25FFTReorderSimple_26) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void FFTReorderSimple_27(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		FOR(int, i, 0,  < , 4, i = (i + 2)) {
			complex_t __sa7 = {
				.real = 0,
				.imag = 0
			};
			__sa7 = ((complex_t) peek_complex(&FFTReorderSimple_26FFTReorderSimple_27, i)) ; 
			push_complex(&FFTReorderSimple_27CombineDFT_28, __sa7) ; 
		}
		ENDFOR
		FOR(int, i, 1,  < , 4, i = (i + 2)) {
			complex_t __sa8 = {
				.real = 0,
				.imag = 0
			};
			__sa8 = ((complex_t) peek_complex(&FFTReorderSimple_26FFTReorderSimple_27, i)) ; 
			push_complex(&FFTReorderSimple_27CombineDFT_28, __sa8) ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 4, i++) {
			pop_complex(&FFTReorderSimple_26FFTReorderSimple_27) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_28(){
	FOR(uint32_t, __iter_steady_, 0, <, 32, __iter_steady_++) {
		complex_t w;
		complex_t y0;
		complex_t y1;
		complex_t y1w;
		complex_t w_next;
		complex_t results[2];
		w.real = 1.0 ; 
		w.imag = 0.0 ; 
		FOR(int, i, 0,  < , 1, i++) {
			complex_t __sa1 = {
				.real = 0,
				.imag = 0
			};
			complex_t __sa2 = {
				.real = 0,
				.imag = 0
			};
			__sa1 = ((complex_t) peek_complex(&FFTReorderSimple_27CombineDFT_28, i)) ; 
			y0.real = __sa1.real ; 
			y0.imag = __sa1.imag ; 
			__sa2 = ((complex_t) peek_complex(&FFTReorderSimple_27CombineDFT_28, (1 + i))) ; 
			y1.real = __sa2.real ; 
			y1.imag = __sa2.imag ; 
			y1w.real = ((y1.real * w.real) - (y1.imag * w.imag)) ; 
			y1w.imag = ((y1.real * w.imag) + (y1.imag * w.real)) ; 
			results[i].real = (y0.real + y1w.real) ; 
			results[i].imag = (y0.imag + y1w.imag) ; 
			results[(1 + i)].real = (y0.real - y1w.real) ; 
			results[(1 + i)].imag = (y0.imag - y1w.imag) ; 
			w_next.real = ((w.real * CombineDFT_28_s.wn.real) - (w.imag * CombineDFT_28_s.wn.imag)) ; 
			w_next.imag = ((w.real * CombineDFT_28_s.wn.imag) + (w.imag * CombineDFT_28_s.wn.real)) ; 
			w.real = w_next.real ; 
			w.imag = w_next.imag ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 2, i++) {
			pop_complex(&FFTReorderSimple_27CombineDFT_28) ; 
			push_complex(&CombineDFT_28CombineDFT_29, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_29(){
	FOR(uint32_t, __iter_steady_, 0, <, 16, __iter_steady_++) {
		complex_t w;
		complex_t y0;
		complex_t y1;
		complex_t y1w;
		complex_t w_next;
		complex_t results[4];
		w.real = 1.0 ; 
		w.imag = 0.0 ; 
		FOR(int, i, 0,  < , 2, i++) {
			complex_t __sa1 = {
				.real = 0,
				.imag = 0
			};
			complex_t __sa2 = {
				.real = 0,
				.imag = 0
			};
			__sa1 = ((complex_t) peek_complex(&CombineDFT_28CombineDFT_29, i)) ; 
			y0.real = __sa1.real ; 
			y0.imag = __sa1.imag ; 
			__sa2 = ((complex_t) peek_complex(&CombineDFT_28CombineDFT_29, (2 + i))) ; 
			y1.real = __sa2.real ; 
			y1.imag = __sa2.imag ; 
			y1w.real = ((y1.real * w.real) - (y1.imag * w.imag)) ; 
			y1w.imag = ((y1.real * w.imag) + (y1.imag * w.real)) ; 
			results[i].real = (y0.real + y1w.real) ; 
			results[i].imag = (y0.imag + y1w.imag) ; 
			results[(2 + i)].real = (y0.real - y1w.real) ; 
			results[(2 + i)].imag = (y0.imag - y1w.imag) ; 
			w_next.real = ((w.real * CombineDFT_29_s.wn.real) - (w.imag * CombineDFT_29_s.wn.imag)) ; 
			w_next.imag = ((w.real * CombineDFT_29_s.wn.imag) + (w.imag * CombineDFT_29_s.wn.real)) ; 
			w.real = w_next.real ; 
			w.imag = w_next.imag ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 4, i++) {
			pop_complex(&CombineDFT_28CombineDFT_29) ; 
			push_complex(&CombineDFT_29CombineDFT_30, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_30(){
	FOR(uint32_t, __iter_steady_, 0, <, 8, __iter_steady_++) {
		complex_t w;
		complex_t y0;
		complex_t y1;
		complex_t y1w;
		complex_t w_next;
		complex_t results[8];
		w.real = 1.0 ; 
		w.imag = 0.0 ; 
		FOR(int, i, 0,  < , 4, i++) {
			complex_t __sa1 = {
				.real = 0,
				.imag = 0
			};
			complex_t __sa2 = {
				.real = 0,
				.imag = 0
			};
			__sa1 = ((complex_t) peek_complex(&CombineDFT_29CombineDFT_30, i)) ; 
			y0.real = __sa1.real ; 
			y0.imag = __sa1.imag ; 
			__sa2 = ((complex_t) peek_complex(&CombineDFT_29CombineDFT_30, (4 + i))) ; 
			y1.real = __sa2.real ; 
			y1.imag = __sa2.imag ; 
			y1w.real = ((y1.real * w.real) - (y1.imag * w.imag)) ; 
			y1w.imag = ((y1.real * w.imag) + (y1.imag * w.real)) ; 
			results[i].real = (y0.real + y1w.real) ; 
			results[i].imag = (y0.imag + y1w.imag) ; 
			results[(4 + i)].real = (y0.real - y1w.real) ; 
			results[(4 + i)].imag = (y0.imag - y1w.imag) ; 
			w_next.real = ((w.real * CombineDFT_30_s.wn.real) - (w.imag * CombineDFT_30_s.wn.imag)) ; 
			w_next.imag = ((w.real * CombineDFT_30_s.wn.imag) + (w.imag * CombineDFT_30_s.wn.real)) ; 
			w.real = w_next.real ; 
			w.imag = w_next.imag ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 8, i++) {
			pop_complex(&CombineDFT_29CombineDFT_30) ; 
			push_complex(&CombineDFT_30CombineDFT_31, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_31(){
	FOR(uint32_t, __iter_steady_, 0, <, 4, __iter_steady_++) {
		complex_t w;
		complex_t y0;
		complex_t y1;
		complex_t y1w;
		complex_t w_next;
		complex_t results[16];
		w.real = 1.0 ; 
		w.imag = 0.0 ; 
		FOR(int, i, 0,  < , 8, i++) {
			complex_t __sa1 = {
				.real = 0,
				.imag = 0
			};
			complex_t __sa2 = {
				.real = 0,
				.imag = 0
			};
			__sa1 = ((complex_t) peek_complex(&CombineDFT_30CombineDFT_31, i)) ; 
			y0.real = __sa1.real ; 
			y0.imag = __sa1.imag ; 
			__sa2 = ((complex_t) peek_complex(&CombineDFT_30CombineDFT_31, (8 + i))) ; 
			y1.real = __sa2.real ; 
			y1.imag = __sa2.imag ; 
			y1w.real = ((y1.real * w.real) - (y1.imag * w.imag)) ; 
			y1w.imag = ((y1.real * w.imag) + (y1.imag * w.real)) ; 
			results[i].real = (y0.real + y1w.real) ; 
			results[i].imag = (y0.imag + y1w.imag) ; 
			results[(8 + i)].real = (y0.real - y1w.real) ; 
			results[(8 + i)].imag = (y0.imag - y1w.imag) ; 
			w_next.real = ((w.real * CombineDFT_31_s.wn.real) - (w.imag * CombineDFT_31_s.wn.imag)) ; 
			w_next.imag = ((w.real * CombineDFT_31_s.wn.imag) + (w.imag * CombineDFT_31_s.wn.real)) ; 
			w.real = w_next.real ; 
			w.imag = w_next.imag ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 16, i++) {
			pop_complex(&CombineDFT_30CombineDFT_31) ; 
			push_complex(&CombineDFT_31CombineDFT_32, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_32(){
	FOR(uint32_t, __iter_steady_, 0, <, 2, __iter_steady_++) {
		complex_t w;
		complex_t y0;
		complex_t y1;
		complex_t y1w;
		complex_t w_next;
		complex_t results[32];
		w.real = 1.0 ; 
		w.imag = 0.0 ; 
		FOR(int, i, 0,  < , 16, i++) {
			complex_t __sa1 = {
				.real = 0,
				.imag = 0
			};
			complex_t __sa2 = {
				.real = 0,
				.imag = 0
			};
			__sa1 = ((complex_t) peek_complex(&CombineDFT_31CombineDFT_32, i)) ; 
			y0.real = __sa1.real ; 
			y0.imag = __sa1.imag ; 
			__sa2 = ((complex_t) peek_complex(&CombineDFT_31CombineDFT_32, (16 + i))) ; 
			y1.real = __sa2.real ; 
			y1.imag = __sa2.imag ; 
			y1w.real = ((y1.real * w.real) - (y1.imag * w.imag)) ; 
			y1w.imag = ((y1.real * w.imag) + (y1.imag * w.real)) ; 
			results[i].real = (y0.real + y1w.real) ; 
			results[i].imag = (y0.imag + y1w.imag) ; 
			results[(16 + i)].real = (y0.real - y1w.real) ; 
			results[(16 + i)].imag = (y0.imag - y1w.imag) ; 
			w_next.real = ((w.real * CombineDFT_32_s.wn.real) - (w.imag * CombineDFT_32_s.wn.imag)) ; 
			w_next.imag = ((w.real * CombineDFT_32_s.wn.imag) + (w.imag * CombineDFT_32_s.wn.real)) ; 
			w.real = w_next.real ; 
			w.imag = w_next.imag ; 
		}
		ENDFOR
		FOR(int, i, 0,  < , 32, i++) {
			pop_complex(&CombineDFT_31CombineDFT_32) ; 
			push_complex(&CombineDFT_32CombineDFT_33, results[i]) ; 
		}
		ENDFOR
	}
	ENDFOR
}

void CombineDFT_33() {
	complex_t w;
	complex_t y0;
	complex_t y1;
	complex_t y1w;
	complex_t w_next;
	complex_t results[64];
	w.real = 1.0 ; 
	w.imag = 0.0 ; 
	FOR(int, i, 0,  < , 32, i++) {
		complex_t __sa1 = {
			.real = 0,
			.imag = 0
		};
		complex_t __sa2 = {
			.real = 0,
			.imag = 0
		};
		__sa1 = ((complex_t) peek_complex(&CombineDFT_32CombineDFT_33, i)) ; 
		y0.real = __sa1.real ; 
		y0.imag = __sa1.imag ; 
		__sa2 = ((complex_t) peek_complex(&CombineDFT_32CombineDFT_33, (32 + i))) ; 
		y1.real = __sa2.real ; 
		y1.imag = __sa2.imag ; 
		y1w.real = ((y1.real * w.real) - (y1.imag * w.imag)) ; 
		y1w.imag = ((y1.real * w.imag) + (y1.imag * w.real)) ; 
		results[i].real = (y0.real + y1w.real) ; 
		results[i].imag = (y0.imag + y1w.imag) ; 
		results[(32 + i)].real = (y0.real - y1w.real) ; 
		results[(32 + i)].imag = (y0.imag - y1w.imag) ; 
		w_next.real = ((w.real * CombineDFT_33_s.wn.real) - (w.imag * CombineDFT_33_s.wn.imag)) ; 
		w_next.imag = ((w.real * CombineDFT_33_s.wn.imag) + (w.imag * CombineDFT_33_s.wn.real)) ; 
		w.real = w_next.real ; 
		w.imag = w_next.imag ; 
	}
	ENDFOR
	FOR(int, i, 0,  < , 64, i++) {
		pop_complex(&CombineDFT_32CombineDFT_33) ; 
		push_complex(&CombineDFT_33CPrinter_34, results[i]) ; 
	}
	ENDFOR
}


void CPrinter_34(){
	FOR(uint32_t, __iter_steady_, 0, <, 64, __iter_steady_++) {
		complex_t c = ((complex_t) pop_complex(&CombineDFT_33CPrinter_34));
		printf("%.10f", c.real);
		printf("\n");
		printf("%.10f", c.imag);
		printf("\n");
	}
	ENDFOR
}

void __stream_init__() {
	init_buffer_complex(&CombineDFT_32CombineDFT_33);
	init_buffer_complex(&CombineDFT_31CombineDFT_32);
	init_buffer_complex(&CombineDFT_30CombineDFT_31);
	init_buffer_complex(&FFTTestSource_22FFTReorderSimple_23);
	init_buffer_complex(&FFTReorderSimple_23FFTReorderSimple_24);
	init_buffer_complex(&FFTReorderSimple_27CombineDFT_28);
	init_buffer_complex(&FFTReorderSimple_24FFTReorderSimple_25);
	init_buffer_complex(&CombineDFT_28CombineDFT_29);
	init_buffer_complex(&FFTReorderSimple_25FFTReorderSimple_26);
	init_buffer_complex(&CombineDFT_33CPrinter_34);
	init_buffer_complex(&CombineDFT_29CombineDFT_30);
	init_buffer_complex(&FFTReorderSimple_26FFTReorderSimple_27);
// --- init: CombineDFT_28
	 {
	 ; 
	CombineDFT_28_s.wn.real = -1.0 ; 
	CombineDFT_28_s.wn.imag = 8.742278E-8 ; 
}
//--------------------------------
// --- init: CombineDFT_29
	 {
	 ; 
	CombineDFT_29_s.wn.real = -4.371139E-8 ; 
	CombineDFT_29_s.wn.imag = -1.0 ; 
}
//--------------------------------
// --- init: CombineDFT_30
	 {
	 ; 
	CombineDFT_30_s.wn.real = 0.70710677 ; 
	CombineDFT_30_s.wn.imag = -0.70710677 ; 
}
//--------------------------------
// --- init: CombineDFT_31
	 {
	 ; 
	CombineDFT_31_s.wn.real = 0.9238795 ; 
	CombineDFT_31_s.wn.imag = -0.38268346 ; 
}
//--------------------------------
// --- init: CombineDFT_32
	 {
	 ; 
	CombineDFT_32_s.wn.real = 0.98078525 ; 
	CombineDFT_32_s.wn.imag = -0.19509032 ; 
}
//--------------------------------
// --- init: CombineDFT_33
	 {
	 ; 
	CombineDFT_33_s.wn.real = 0.9951847 ; 
	CombineDFT_33_s.wn.imag = -0.09801714 ; 
}
//--------------------------------
}
int main(int argv, char** argc) {
	__stream_init__();

	FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
		FFTTestSource_22();
		FFTReorderSimple_23();
		FFTReorderSimple_24();
		FFTReorderSimple_25();
		FFTReorderSimple_26();
		FFTReorderSimple_27();
		CombineDFT_28();
		CombineDFT_29();
		CombineDFT_30();
		CombineDFT_31();
		CombineDFT_32();
		CombineDFT_33();
		CPrinter_34();
	ENDFOR
	return EXIT_SUCCESS;
}
