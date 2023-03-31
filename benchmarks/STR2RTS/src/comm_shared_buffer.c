#include "globals.h"

inline void init_buffer_bit(buffer_bit_t *buffer) {
    buffer->head = buffer->tail = 0;
}
inline void init_buffer_int(buffer_int_t *buffer) {
    buffer->head = buffer->tail = 0;
}
inline void init_buffer_float(buffer_float_t *buffer) {
    buffer->head = buffer->tail = 0;
}
inline void init_buffer_double(buffer_double_t *buffer) {
    buffer->head = buffer->tail = 0;
}
inline void init_buffer_boolean(buffer_boolean_t *buffer) {
    buffer->head = buffer->tail = 0;
}
inline void init_buffer_char(buffer_char_t *buffer) {
    buffer->head = buffer->tail = 0;
}

inline void init_buffer_complex(buffer_complex_t *buffer) {
    buffer->head = buffer->tail = 0;
}

BIT peek_bit(buffer_bit_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

BIT pop_bit(buffer_bit_t *buffer) {
    int res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_bit(buffer_bit_t *buffer, BIT val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_bit(buffer_bit_t *out, buffer_bit_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_bit(in, pop_bit(out));
    ENDFOR
}

int peek_int(buffer_int_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

int pop_int(buffer_int_t *buffer) {
    int res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_int(buffer_int_t *buffer, int val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_int(buffer_int_t *out, buffer_int_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_int(in, pop_int(out));
    ENDFOR
}

float peek_float(buffer_float_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

float pop_float(buffer_float_t *buffer) {
    float res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_float(buffer_float_t *buffer, float val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_float(buffer_float_t *out, buffer_float_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_float(in, pop_float(out));
    ENDFOR
}

double peek_double(buffer_double_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

double pop_double(buffer_double_t *buffer) {
    double res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_double(buffer_double_t *buffer, double val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_double(buffer_double_t *out, buffer_double_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_double(in, pop_double(out));
    ENDFOR
}

boolean peek_boolean(buffer_boolean_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

boolean pop_boolean(buffer_boolean_t *buffer) {
    boolean res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_boolean(buffer_boolean_t *buffer, boolean val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_boolean(buffer_boolean_t *out, buffer_boolean_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_boolean(in, pop_boolean(out));
    ENDFOR
}

char peek_char(buffer_char_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

char pop_char(buffer_char_t *buffer) {
    char res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_char(buffer_char_t *buffer, char val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_char(buffer_char_t *out, buffer_char_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_char(in, pop_char(out));
    ENDFOR
}

complex_t peek_complex(buffer_complex_t *buffer, int offset) {
    return (buffer->buffer)[(buffer->tail+offset)%BUF_SIZEMAX];
}

complex_t pop_complex(buffer_complex_t *buffer) {
    complex_t res = (buffer->buffer)[buffer->tail];
    buffer->tail = (buffer->tail+1)%BUF_SIZEMAX;
    return res;
}

void push_complex(buffer_complex_t *buffer, complex_t val) {
    (buffer->buffer)[buffer->head] = val;
    buffer->head = (buffer->head+1)%BUF_SIZEMAX;
}

void copy_complex(buffer_complex_t *out, buffer_complex_t *in, uint32_t size) {
    FOR2(uint32_t, i, 0, <, size, BUF_SIZEMAX, i++)
        push_complex(in, pop_complex(out));
    ENDFOR
}