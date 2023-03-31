/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   globals.h
 * Author: brouxel
 *
 * Created on 3 août 2016, 16:28
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#ifdef NOSTDLIB
    typedef int FILE;
    typedef unsigned long size_t;
    typedef unsigned int uint32_t;
    typedef unsigned short uint16_t;
    
    int __errno;
    
    int printf(const char *format, ...) ;
    FILE *fopen(const char *path, const char *mode) ;
    int fclose(FILE *stream) ;
    void assert(unsigned long expression) ;
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
    int fflush(FILE *stream);
    
    int strncmp(const char *s1, const char *s2, size_t n);
    
    #define EXIT_SUCCESS 0
#else 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#endif

#ifdef NOMATHLIB
    double sqrt(double x);
    float sqrtf(float x);

    double ceil(double x);
    float ceilf(float x);

    double floor(double x);
    float floorf(float x);
    
    double cos(double x);
    float cosf(float x);
    
    double asin(double x);
    double sin(double x);
    float sinf(float x);
    
    double atan(double x);
    double log(double x);
    double exp(double x);
    double pow(double x, double y);
#else
#include <math.h>
#endif
    
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef short boolean;
#define TRUE 1
#define FALSE 0

typedef struct {
    double real;
    double imag;
} complex_t;

#ifndef BUF_SIZEMAX
    #define BUF_SIZEMAX 1
    #error no "-DBUF_SIZEMAX=" specified
#endif

#ifndef MAX_ITERATION
    #define MAX_ITERATION 1
#endif

#define MIN(A,B)  (((A)<(B))?(A):(B))
#define MAX(A,B)  (((A)<(B))?(B):(A))

#ifdef HEPTANE
    #include "annot.h"
    #define FOR(TYPE, VAR, INI, SIGN, END, INC) for(TYPE VAR = INI ; VAR SIGN END ; INC) { ANNOT_MAXITER((END))
    #define FOR2(TYPE, VAR, INI, SIGN, END, MAX, INC) for(TYPE VAR = INI ; VAR SIGN END ; INC) { ANNOT_MAXITER((MAX))
    #define FOR3(TYPE, VAR, INI, SIGN, END, DEC) for(TYPE VAR = INI ; VAR SIGN END ; DEC) { ANNOT_MAXITER((INI))
    // Should replace for2
    #define FOR4(TYPE, VAR, INI, END, MAX, INC) for(TYPE VAR = INI ; END ; INC) { ANNOT_MAXITER((MAX))
#endif

#ifdef FLOWFACTS
    #define STRINGIFY(X) #X
    #define FOR(TYPE, VAR, INI, SIGN, END, INC) _Pragma(STRINGIFY(loopbound max (END))) for(TYPE VAR = INI ; VAR SIGN END ; INC) {
    #define FOR2(TYPE, VAR, INI, SIGN, END, MAX, INC) _Pragma(STRINGIFY(loopbound max (MAX))) for(TYPE VAR = INI ; VAR SIGN END ; INC) {
    #define FOR3(TYPE, VAR, INI, SIGN, END, DEC) _Pragma(STRINGIFY(loopbound max (INI))) for(TYPE VAR = INI ; VAR SIGN END ; DEC) {
    //Should replace for2
    #define FOR4(TYPE, VAR, INI, END, MAX, INC) _Pragma(STRINGIFY(loopbound max (MAX))) for(TYPE VAR = INI ; END ; INC) {
#endif

#if !defined(HEPTANE) && !defined(FLOWFACTS)
#define FOR(TYPE, VAR, INI, SIGN, END, INC) for(TYPE VAR = INI ; VAR SIGN END ; INC) {
#define FOR2(TYPE, VAR, INI, SIGN, END, MAX, INC) for(TYPE VAR = INI ; VAR SIGN END ; INC) {
#define FOR3(TYPE, VAR, INI, SIGN, END, DEC) for(TYPE VAR = INI ; VAR SIGN END ; DEC) {
//Should replace for2
#define FOR4(TYPE, VAR, INI, END, MAX, INC) for(TYPE VAR = INI ; END ; INC) {
#endif

#define ENDFOR }

#ifndef MAX_DATAREAD_IN_FILE
#define MAX_DATAREAD_IN_FILE 0
#endif
#ifndef MAX_DATAWRITE_IN_FILE
#define MAX_DATAWRITE_IN_FILE 0
#endif

#define BIT char
/*typedef struct {
    uint32_t head;
    uint32_t tail;
    BIT buffer [BUF_SIZEMAX];
} buffer_bit_t;*/
typedef struct {
    uint32_t head;
    uint32_t tail;
    int buffer[BUF_SIZEMAX];
} buffer_int_t;
#define buffer_bit_t buffer_int_t // Pb type assignment in 802.11a
typedef struct {
    uint32_t head;
    uint32_t tail;
    float buffer[BUF_SIZEMAX];
} buffer_float_t;
typedef struct {
    uint32_t head;
    uint32_t tail;
    double buffer[BUF_SIZEMAX];
} buffer_double_t;
typedef struct {
    uint32_t head;
    uint32_t tail;
    char buffer[BUF_SIZEMAX];
} buffer_char_t;
typedef struct {
    uint32_t size;
    uint32_t head;
    uint32_t tail;
    boolean buffer[BUF_SIZEMAX];
} buffer_boolean_t;
typedef struct {
    uint32_t head;
    uint32_t tail;
    complex_t buffer[BUF_SIZEMAX];
} buffer_complex_t;

typedef struct {
    buffer_complex_t buffer_in;
    buffer_complex_t buffer_out;
} channel_complex_t;

typedef struct {
    buffer_bit_t buffer_in;
    buffer_bit_t buffer_out;
} channel_bit_t;

typedef struct {
    buffer_bit_t buffer_in;
    buffer_complex_t buffer_out;
} channel_b2c_t;

buffer_bit_t FileReaderBufBit;
buffer_int_t FileReaderBufInt;
buffer_float_t FileReaderBufFloat;
buffer_boolean_t FileReaderBufBoolean;
buffer_double_t FileReaderBufDouble;
buffer_char_t FileReaderBufChar;
buffer_complex_t FileReaderBufComplex;

buffer_bit_t FileWriterBufBit;
buffer_int_t FileWriterBufInt;
buffer_float_t FileWriterBufFloat;
buffer_boolean_t FileWriterBufBoolean;
buffer_double_t FileWriterBufDouble;
buffer_char_t FileWriterBufChar;
buffer_complex_t FileWriterBufComplex;

void init_buffer_bit(buffer_bit_t *buffer);
void init_buffer_int(buffer_int_t *buffer);
void init_buffer_float(buffer_float_t *buffer);
void init_buffer_double(buffer_double_t *buffer);
void init_buffer_boolean(buffer_boolean_t *buffer);
void init_buffer_char(buffer_char_t *buffer);
void init_buffer_complex(buffer_complex_t *buffer);

BIT peek_bit(buffer_bit_t*, int offset);
BIT pop_bit(buffer_bit_t*);
void push_bit(buffer_bit_t*, BIT val);
void copy_bit(buffer_bit_t *, buffer_bit_t *, uint32_t size);

int peek_int(buffer_int_t*, int offset);
int pop_int(buffer_int_t*);
void push_int(buffer_int_t*, int val);
void copy_int(buffer_int_t *, buffer_int_t *, uint32_t size);

float peek_float(buffer_float_t*, int offset);
float pop_float(buffer_float_t*) ;
void push_float(buffer_float_t*, float val);
void copy_float(buffer_float_t *, buffer_float_t *, uint32_t size);

double peek_double(buffer_double_t*, int offset);
double pop_double(buffer_double_t*);
void push_double(buffer_double_t*, double val);
void copy_double(buffer_double_t *, buffer_double_t *, uint32_t size);

boolean peek_boolean(buffer_boolean_t*, int offset);
boolean pop_boolean(buffer_boolean_t*);
void push_boolean(buffer_boolean_t*, boolean val);
void copy_boolean(buffer_boolean_t *, buffer_boolean_t *, uint32_t size);

char peek_char(buffer_char_t*, int offset);
char pop_char(buffer_char_t*);
void push_char(buffer_char_t*, char val);
void copy_char(buffer_char_t *, buffer_char_t *, uint32_t size);

complex_t peek_complex(buffer_complex_t*, int offset);
complex_t pop_complex(buffer_complex_t*);
void push_complex(buffer_complex_t*, complex_t val);
void copy_complex(buffer_complex_t *, buffer_complex_t *, uint32_t size);

typedef struct {
    FILE * fh;
    char * type;
} File_t;
File_t FileReaderBuf;

void FileReader_init(char * f, char *u);
void FileReader(int amount_data);
void FileReader_close();

File_t FileWriterBuf;

void FileWriter_init(char * f, char *u);
void FileWriter(int);
void FileWriter_close();

#ifdef __cplusplus
}
#endif

#endif /* GLOBALS_H */

