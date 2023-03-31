#include "globals.h"

#ifdef NOSTDLIB

#ifndef NULL
#define NULL (void*)(0x0)
#endif

    int printf(const char *format, ...) {
        return 0;
    }
    FILE *fopen(const char *path, const char *mode) {
        return 0;
    }
    int fclose(FILE *stream) {
        return 0;
    }
    int fflush(FILE *stream) {return 0; }
    void assert(unsigned long expression) {}
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {return size*nmemb;}
    size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream) {return size*nmemb;}
    
    int strncmp(const char *s1, const char *s2, size_t n) {return 0;}
    
#endif
    
#ifdef NOMATHLIB
    double sqrt(double x) {
        
    }
    float sqrtf(float x) {
        
    }

    double ceil(double x) {
        
    }
    float ceilf(float x) {
        
    }

    double floor(double x) {
        
    }
    float floorf(float x) {
        
    }
    
    double cos(double x) {
        
    }
    float cosf(float x) {
        
    }
    
    double asin(double x) {
        
    }
    double sin(double x) {
        
    }
    float sinf(float x) {
        
    }
    double atan(double x) {
        
    }
    double log(double x) {
        
    }
    double exp(double x) {
        
    }
    double pow(double x, double y) {
        
    }
#endif


void FileReader_init(char * f, char *type) {
    FileReaderBuf.fh = fopen(f, "r");
    assert(FileReaderBuf.fh != NULL);
    FileReaderBuf.type = type;
    
    init_buffer_bit(&FileReaderBufBit);
    init_buffer_int(&FileReaderBufInt);
    init_buffer_float(&FileReaderBufFloat);
    init_buffer_double(&FileReaderBufDouble);
    init_buffer_boolean(&FileReaderBufBoolean);
    init_buffer_char(&FileReaderBufChar);
}

void FileReader_close() {
    fclose(FileReaderBuf.fh);
}

void FileReader_float(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        float data;
        fread(&data, sizeof (float), 1, FileReaderBuf.fh);
        push_float(&FileReaderBufFloat, data);
    ENDFOR
}
char last_read = 0;
unsigned int bit = 1; //should be initialised to 8, but if I do it doesn't match the read output from streamit, a bug on their side?
void FileReader_bit(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        if(bit == 8) {
            fread(&last_read, sizeof(char), 1, FileReaderBuf.fh);
            bit = 0;
        }
    
        BIT data = (last_read >> bit) & 0x01;
        push_bit(&FileReaderBufBit, data);
        bit++;
    ENDFOR
}
void FileReader_int(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        int data;
        fread(&data, sizeof (int), 1, FileReaderBuf.fh);
        push_int(&FileReaderBufInt, data);
    ENDFOR
}
void FileReader_char(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        char data;
        fread(&data, sizeof (char), 1, FileReaderBuf.fh);
        push_char(&FileReaderBufChar, data);
    ENDFOR
}
void FileReader_double(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        double data;
        fread(&data, sizeof (double), 1, FileReaderBuf.fh);
        push_double(&FileReaderBufDouble, data);
    ENDFOR
}
void FileReader_boolean(int amount_data) {
    assert(FALSE); //check if the sizeof(boolean) returns the good value
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        boolean data;
        fread(&data, sizeof (boolean), 1, FileReaderBuf.fh);
        push_boolean(&FileReaderBufBoolean, data);
    ENDFOR
}

void FileReader_complex(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAREAD_IN_FILE, i++)
        complex_t data;
        fread(&data, sizeof (complex_t), 1, FileReaderBuf.fh);
        push_complex(&FileReaderBufComplex, data);
    ENDFOR
}

void FileReader(int amount_data) {
    if(strncmp(FileReaderBuf.type, "float", 5) == 0) {
        FileReader_float(amount_data);
    }
    else if(strncmp(FileReaderBuf.type, "bit", 4) == 0) {
        FileReader_bit(amount_data);
    }
    else if(strncmp(FileReaderBuf.type, "int", 4) == 0) {
        FileReader_int(amount_data);
    }
    else if(strncmp(FileReaderBuf.type, "char", 4) == 0) {
        FileReader_char(amount_data);
    }
    else if(strncmp(FileReaderBuf.type, "double", 6) == 0) {
        FileReader_double(amount_data);
    }
    else if(strncmp(FileReaderBuf.type, "boolean", 6) == 0) {
        FileReader_boolean(amount_data);
    }
    else if(strncmp(FileReaderBuf.type, "complex", 7) == 0) {
        FileReader_complex(amount_data);
    }
    else {
        printf("---> %s\n", FileReaderBuf.type);
        assert(FALSE && FileReaderBuf.type);
    }
}

void FileWriter_init(char * f, char *type) {
    FileWriterBuf.fh = fopen(f, "w");
    assert(FileWriterBuf.fh != NULL);
    FileWriterBuf.type = type;
    
    init_buffer_bit(&FileWriterBufBit);
    init_buffer_int(&FileWriterBufInt);
    init_buffer_float(&FileWriterBufFloat);
    init_buffer_double(&FileWriterBufDouble);
    init_buffer_boolean(&FileWriterBufBoolean);
    init_buffer_char(&FileWriterBufChar);
}

void FileWriter_float(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        float data = pop_float(&FileWriterBufFloat);
        fwrite(&data, sizeof (float), 1, FileWriterBuf.fh);
    ENDFOR
}
void FileWriter_bit(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        BIT data = pop_bit(&FileWriterBufBit);
        fwrite(&data, sizeof (BIT), 1, FileWriterBuf.fh);
    ENDFOR
}
void FileWriter_int(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        int data = pop_int(&FileWriterBufInt);
        fwrite(&data, sizeof (int), 1, FileWriterBuf.fh);
    ENDFOR
}
void FileWriter_char(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        char data = pop_char(&FileWriterBufChar);
        fwrite(&data, sizeof (char), 1, FileWriterBuf.fh);
    ENDFOR
}
void FileWriter_double(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        double data = pop_double(&FileWriterBufDouble);
        fwrite(&data, sizeof (double), 1, FileWriterBuf.fh);
    ENDFOR
}
void FileWriter_boolean(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        boolean data = pop_boolean(&FileWriterBufBoolean);
        fwrite(&data, sizeof (boolean), 1, FileWriterBuf.fh);
    ENDFOR
}

void FileWriter_complex(int amount_data) {
    FOR2(uint32_t, i, 0, <, amount_data, MAX_DATAWRITE_IN_FILE, i++)
        complex_t data = pop_complex(&FileWriterBufComplex);
        fwrite(&data, sizeof (complex_t), 1, FileWriterBuf.fh);
    ENDFOR
}

void FileWriter(int amount_data) {
    if(strncmp(FileWriterBuf.type, "float", 5) == 0) {
        FileWriter_float(amount_data);
    }
    else if(strncmp(FileWriterBuf.type, "bit", 4) == 0) {
        FileWriter_bit(amount_data);
    }
    else if(strncmp(FileWriterBuf.type, "int", 4) == 0) {
        FileWriter_int(amount_data);
    }
    else if(strncmp(FileWriterBuf.type, "char", 4) == 0) {
        FileWriter_char(amount_data);
    }
    else if(strncmp(FileWriterBuf.type, "double", 6) == 0) {
        FileWriter_double(amount_data);
    }
    else if(strncmp(FileWriterBuf.type, "boolean", 6) == 0) {
        FileWriter_boolean(amount_data);
    }
    else if(strncmp(FileWriterBuf.type, "complex", 7) == 0) {
        FileWriter_complex(amount_data);
    }
    else {
        printf("---> %s\n", FileWriterBuf.type);
        assert(FALSE && FileWriterBuf.type);
    }
}

void FileWriter_close() {
    if(!FileWriterBuf.fh) return;
    fflush(FileWriterBuf.fh);
    fclose(FileWriterBuf.fh);
}