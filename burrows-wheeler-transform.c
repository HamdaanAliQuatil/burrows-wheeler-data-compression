#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
  
int sortRotation(const void* x, const void* y){
    rotation* rx = (rotation*)x;
    rotation* ry = (rotation*)y;
    return strcmp(rx->suffix, ry->suffix);
}
  
int* suffixArray(char* input_text, int length){
    rotation suff[length];
  
    for (int i = 0; i < length; i++) {
        suff[i].index = i;
        suff[i].suffix = (input_text + i);
    }
  

    qsort(suff, length, sizeof(rotation), sortRotation);

    int* suffix_array = (int*)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
        suffix_array[i] = suff[i].index;
  
    return suffix_array;
}
  
char* findLastChar(char* input_text, int* suffix_array, int n){
    char* transformed_array= (char*)malloc(n * sizeof(char));
    
    int i;
    for (i = 0; i < n; i++) {
        int j = suffix_array[i] - 1;
        if (j < 0)
            j = j + n;
  
        transformed_array[i] = input_text[j];
    }
  
    transformed_array[i] = '\0';

    return transformed_array;
}

int main(){
    printf("Enter the string to perform Burrows Wheeler Transformation on: ");

    char input_text[100];
    scanf("%s", input_text);

    int length = strlen(input_text);
  
    int* suffix_array= suffixArray(input_text, length);

    char* transformed_array= findLastChar(input_text, suffix_array, length);
  
    printf("Input text : %s\n", input_text);
    printf("Burrows - Wheeler Transform : %s\n", transformed_array);
    return 0;
}