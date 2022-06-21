#include "utility.h"

static int length = 0;

int sortRotation(const void *x, const void *y) {
    rotation *rx = (rotation *)x;
    rotation *ry = (rotation *)y;
    return memcmp(rx->suffix, ry->suffix, length);
}

int *suffixArray(unsigned char *input_text, long length) {
    rotation *suff = malloc(sizeof(rotation) * length);

    for (long i = 0; i < length; i++) {
        suff[i].index = i;
        suff[i].suffix = (input_text + i);
    }

    qsort(suff, length, sizeof(rotation), sortRotation);

    int *suffix_array = malloc(length * sizeof(int));

    for (long i = 0; i < length; i++)
        suffix_array[i] = suff[i].index;

    return suffix_array;
}

unsigned char *findLastChar(unsigned char *input_text, int *suffix_array, long n) {
    unsigned char *transformed_array = malloc(n * sizeof(unsigned char));

    long i;
    for (i = 0; i < n; i++) {
        long j = suffix_array[i] - 1;
        if (j < 0)
            j = j + n;

        transformed_array[i] = input_text[j];
    }

    transformed_array[i] = '\0';

    return transformed_array;
}

int main() {
    long index = 0, input_size = 16;
    unsigned char *input_text = malloc(sizeof(unsigned char) * input_size);

    int ch;
    while ((ch = getchar()) != EOF) {
        input_text[index++] = ch;
        if (index == input_size) {
            input_size *= 2;
            input_text = realloc(input_text, sizeof(unsigned char) * input_size);
        }
    }

    length = index;

    int *suffix_array = suffixArray(input_text, length);

    unsigned char *transformed_array = findLastChar(input_text, suffix_array, length);

    for (long i = 0; i < length; ++i) {
        putchar(transformed_array[i]);
    }

    return 0;
}
