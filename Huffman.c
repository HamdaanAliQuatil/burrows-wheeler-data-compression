// Huffman coding

#include <string.h>
#include "Trie.h"
#include "Bitstream.h"

enum { N = 256 }; // Number of characters in extended ASCII

void compress(void) {
    // Allocate a buffer for input
    long index = 0, input_size = 256; 
    unsigned char *input = malloc(sizeof(unsigned char) * input_size);

    // read input and resize the buffer if necessary
    int ch;
    while ((ch = getchar()) != EOF) {
        input[index++] = ch;
        if (index == input_size) {
            input_size *= 2;
            input = realloc(input, sizeof(unsigned char) * input_size);
        }
    }

    // Get the frequency of all characters in input
    long freq[N] = {0};
    for (long i = 0; i < index; ++i)
        freq[input[i]]++;

    // Creating the trie for encoding
    trie_node *root = create_trie(freq);

    // create the encoding table for each character in input
    unsigned char *table[N];
    for (int i = 0; i < N; ++i) 
        table[i] = malloc(sizeof(unsigned char) * 16);
    create_code(table, root);

    // write the trie and its length to output
    write_trie(root);
    write_long(index);

    // write encoded input to output
    for (long i = 0; i < index; ++i) {
        unsigned char *code = table[input[i]];
        for (int j = 0; code[j] != '\0'; ++j) {
            if (code[j] == '1')
                write_bit(1);
            else
                write_bit(0);
        }
    }
    flush_output();
}

void expand(void) {
    // read the trie and it's length
    trie_node *root = read_trie();
    long length = read_long();
    if (length == EOF) {
        fprintf(stderr, "Couldn't read input length");
        exit(EXIT_FAILURE);
    }

    // decode the input based on the trie read
    for (int i = 0; i < length; ++i) {
        trie_node *t = root;
        while (!is_leaf(t)) {
            int bit = read_bit();
            if (bit == EOF) {
                flush_output();   
                return;
            }
            else if (bit)
                t = t->right;
            else    
                t = t->left;
        }
        write_byte(t->ch);
    }
    flush_output();
}

int main(int argc, char *argv[]) {
    if (!strcmp(argv[1], "-"))
        compress();
    else if (!strcmp(argv[1], "+"))
        expand();
    return 0;
}