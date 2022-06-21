// Reading and writing bits to the standard input and output streams

#include "Bitstream.h"

// buffers for storing bits
static unsigned char input_buffer = 0;
static unsigned char output_buffer = 0;

// number of bits in buffer
static int in_bits = 0;
static int out_bits = 0;

// read a byte of input
static int get_input(void) {
    int ch = getchar();
    if (ch == EOF)
        return EOF;
    input_buffer = ch;
    in_bits = 8;
    return input_buffer;
}

// returns the bit read from stdin as an integer
int read_bit(void) {
    if (in_bits == 0) {
        int ch = get_input();
        if (ch == EOF)
            return EOF;
    } 
    --in_bits;
    int bit = ((input_buffer >> in_bits) & 1) == 1;
    return bit;
}

// reads a single character from input stream
int read_char(void) {
    if (in_bits == 0) {
        int ch = get_input();
        if (ch == EOF)
            return EOF;
        return output_buffer;
    }
    int ch = input_buffer, prev = in_bits;
    ch <<= (8 - in_bits);

    int temp = get_input();
    if (temp == EOF)
        return EOF;
    in_bits = prev;
    ch |= (input_buffer >> in_bits);
    return ch;
}

// reads an integer from input stream
int read_int(void) {
    int k = 0;
    for (int i = 0; i < 4; ++i) {
        int t = read_char();
        if (t == EOF)
            return EOF;
        k <<= 8;
        k |= t;
    }
    return k;
}

// reads a long integer from input stream
long read_long(void) {
    long k = 0;
    for (int i = 0; i < 8; ++i) {
        int t = read_char();
        if (t == EOF)
            return EOF;
        k <<= 8;
        k |= t;
    }
    return k;
}

// keeps bits in byte-sized output_buffer and writes when full
void write_bit(unsigned int bit) {
    output_buffer <<= 1;
    if (bit)
        output_buffer |= 1;
    
    ++out_bits;
    if (out_bits == 8) {
        putchar(output_buffer);
        out_bits = 0;
        output_buffer = 0;
    }
}

// writes the byte a bit at a time using write_bit
void write_byte(unsigned char ch) {
    if (out_bits == 0) {
        putchar(ch);
        return;
    }
    for (int i = 0; i < 8; ++i) {
        unsigned int bit = ((ch >> (8 - i - 1)) & 1) == 1;
        write_bit(bit);
    }
}

// writes an integer to the output stream
void write_int(unsigned int k) {
    for (int i = 3; i >= 0; --i) 
        write_byte((k >> (8 * i)) & 0xff);
}

// writes a long integer to the output stream
void write_long(unsigned long k) {
    for (int i = 7; i >= 0; --i) 
        write_byte((k >> (8 * i)) & 0xff);
}

// writes any left over bits to stdout and flushes it to 
void flush_output(void) {
    putchar(output_buffer);
    fflush(stdout);
}

