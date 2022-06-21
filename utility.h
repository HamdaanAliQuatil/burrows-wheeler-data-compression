#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef UTILITY_H
#define UTILITY_H

typedef struct rt{
    int index;
    unsigned char* suffix;
}rotation;

int sortRotation(const void* x, const void* y);
int* suffixArray(unsigned char* input_text, long length);
unsigned char* findLastChar(unsigned char* input_text, int* suffix_array, long n);

#endif
