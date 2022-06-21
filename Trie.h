#include <stdlib.h>

#ifndef TRIE_H
#define TRIE_H

typedef struct node {
    int freq;
    unsigned char ch;
    struct node *left, *right;
} trie_node;

int is_leaf(trie_node *t);
trie_node *create_trie(long freq[]);
void create_code(unsigned char *table[], trie_node *root);
trie_node *read_trie(void);
void write_trie(trie_node *root);

#endif