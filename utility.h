#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef UTILITY_H
#define UTILITY_H

typedef struct rt{
    int index;
    char* suffix;
}rotation;

int sortRotation(const void* x, const void* y);
int* suffixArray(char* input_text, int length);
char* findLastChar(char* input_text, int* suffix_array, int n);

#endif
