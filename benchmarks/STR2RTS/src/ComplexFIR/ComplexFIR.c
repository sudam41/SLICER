#include "ComplexFIR.h"

FIR_t _fir;

void  complexfir_fir() { // Complex_fir.str:64
    float real_sum = 0; // Complex_fir.str:65
    float imag_sum = 0; // Complex_fir.str:66
    FOR(uint32_t, i, 0, <, TheGlobal_N, i++) // Complex_fir.str:67
        float real = peek_float (&FileReaderBufFloat, (2 * i)); // Complex_fir.str:68
        float imag = peek_float (&FileReaderBufFloat, ((2 * i) + 1)); // Complex_fir.str:69
        real_sum += ((real * _fir.coeff_real[i]) - (imag * _fir.coeff_imag[i])); // Complex_fir.str:70
        imag_sum += ((real * _fir.coeff_imag[i]) + (imag * _fir.coeff_real[i])); // Complex_fir.str:71
    ENDFOR
    pop_float(&FileReaderBufFloat); // Complex_fir.str:73
    pop_float(&FileReaderBufFloat); // Complex_fir.str:74
    push_float(&_fir.buffer_out, real_sum); // Complex_fir.str:75
    push_float(&_fir.buffer_out, imag_sum); // Complex_fir.str:76
}

void complexfir_printer() { // Complex_fir.str:81
    printf("%f\n", pop_float (&_fir.buffer_out)); // Complex_fir.str:82
    printf("%f\n", pop_float (&_fir.buffer_out)); // Complex_fir.str:83
}

void  complexfir_init() { // Complex_fir.str:1
    FileReader_init(TheGlobal_FILE, "float");
    
    _fir.coeff_real[15] = 9.980292;
    _fir.coeff_real[14] = 6.467147;
    _fir.coeff_real[13] = 8.173388;
    _fir.coeff_real[12] = 0.255656;
    _fir.coeff_real[11] = 0.911332;
    _fir.coeff_real[10] = -6.625836;
    _fir.coeff_real[9]= -1.361192;
    _fir.coeff_real[8] = 8.983362;
    _fir.coeff_real[7] = 9.621704;
    _fir.coeff_real[6] = 4.036057;
    _fir.coeff_real[5] = -0.631137;
    _fir.coeff_real[4] = -0.308623;
    _fir.coeff_real[3] = 6.231595;
    _fir.coeff_real[2] = -1.412280;
    _fir.coeff_real[1] = -6.305478;
    _fir.coeff_real[0] = 7.632966;


    _fir.coeff_imag[15] = 10.000000;
    _fir.coeff_imag[14] = 9.167380;
    _fir.coeff_imag[13] = 2.707955;
    _fir.coeff_imag[12] = 8.154047;
    _fir.coeff_imag[11] = -0.535006;
    _fir.coeff_imag[10] = 5.336431;
    _fir.coeff_imag[9] = -8.634630;
    _fir.coeff_imag[8] = -1.121887;
    _fir.coeff_imag[7] = -5.341023;
    _fir.coeff_imag[6] = 4.952805;
    _fir.coeff_imag[5] = -7.519617;
    _fir.coeff_imag[4] = -8.405219;
    _fir.coeff_imag[3] = -6.208589;
    _fir.coeff_imag[2] = -7.726289;
    _fir.coeff_imag[1] = 8.464509;
    _fir.coeff_imag[0] = -9.697820;
    
    init_buffer_float(&_fir.buffer_out);
}
int main(int argv, char** argc) {
    complexfir_init();
    
    FileReader(30);
    
    FOR(uint32_t, iter, 0, <, MAX_ITERATION, iter++)
        FileReader(2);
        complexfir_fir();
        complexfir_printer();
    ENDFOR
    
    FileWriter_close();
    
    return EXIT_SUCCESS;
} 
