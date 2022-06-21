#include <stdio.h>

#ifndef BITSTREAM_H
#define BITSTREAM_H

int read_bit(void);
int read_char(void);
int read_int(void);
long read_long(void);

void write_bit(unsigned int bit);
void write_byte(unsigned char ch);
void write_int(unsigned int k);
void write_long(unsigned long k);
void flush_output(void);

#endif