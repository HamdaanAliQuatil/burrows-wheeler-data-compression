// Trie implementation for Huffman codes

#include <string.h>
#include "Trie.h"
#include "Bitstream.h"
#include "MinimumPriorityQueue.h"

enum { N = 256 }; // Number of characters in extended ASCII

// checks if the node if a leaf node
int is_leaf(trie_node *t) {
    return t->left == NULL && t->right == NULL;
}

// creates a trie node and returns a pointer to it
static trie_node *create_node(unsigned char ch, int freq, trie_node *left, trie_node *right) {
    trie_node *new_node = malloc(sizeof(trie_node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

// creates the Huffman encoding trie and returns a pointer to its root
trie_node *create_trie(long freq[]) {
    // fill the minimum-oriented priority queue with trie node pointers
    for (int ch = 0; ch < N; ++ch)
        if (freq[ch] > 0)
            pq_insert((create_node(ch, freq[ch], NULL, NULL)));

    while (pq_size() > 1) {
        trie_node *m = pq_delete_min();
        trie_node *n = pq_delete_min();

        // Parent is made by merging the two smallest tries
        trie_node *parent = create_node('\0', m->freq + n->freq, m, n);
        pq_insert(parent);
    }
    return pq_delete_min();
}

// builds the encoding table 
static void build_table(unsigned char *table[], trie_node *root, unsigned char *str, int count) {
    if (is_leaf(root)) {
        memcpy(table[(int) root->ch], str, count + 1);
        table[(int) root->ch][count] = '\0';
        return;
    }
    str[count] = '0';
    build_table(table, root->left, str, count + 1);
    str[count] = '1';
    build_table(table, root->right, str, count + 1);
    str[count] = '\0';
}

void create_code(unsigned char *table[], trie_node *root) {
    unsigned char str[N] = {'\0'};
    build_table(table, root, str, 0);
}

// read the trie at the beginning of encoded input
trie_node *read_trie(void) {
    if (read_bit())
        return create_node(read_char(), 0, NULL, NULL);
    return create_node('\0', 0, read_trie(), read_trie());
}

// write the trie to output as a sequence of bits
void write_trie(trie_node *root) {
    if (is_leaf(root)) {
        write_bit(1);
        write_byte(root->ch);
        return;
    }
    write_bit(0);
    write_trie(root->left);
    write_trie(root->right);
}