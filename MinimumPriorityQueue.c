// Minimum priority queue implementation for Huffman codes

#include "MinimumPriorityQueue.h"

enum { PQ_SIZE = 256 }; 

static int n = 0; // Number of elements in the priority queue
static trie_node *pq[PQ_SIZE + 1];

// checks if a trie node is greater than other
static int is_greater(int i, int j) {
    if (pq[i]->freq > pq[j]->freq)
        return 1;
    return 0;
}

// swaps two nodes of the priority queue at given index
static void swap(int i, int j) {
    trie_node *t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
}

// moves value at 'k' up to maintain heap invariant
static void swim(int k) {
    while (k > 1 && is_greater(k / 2, k)) {
        swap(k / 2, k);
        k = k / 2;
    }
}

// moves value at 'k' down to maintain heap invariant
static void sink(int k) {
    while (2 * k <= n) {
        int i = 2 * k;
        if (i < n && is_greater(i, i + 1))
            i++;
        swap(k, i);
        k = i;
    }
}

// returns number of elements in the priority queue
int pq_size(void) {
    return n;
}

// inserts a trie node pointer in the priority queue
void pq_insert(trie_node *t) {
    pq[++n] = t;
    swim(n);
}

// deletes and returns the node with minimum value
trie_node *pq_delete_min(void) {
    trie_node *min = pq[1];
    swap(1, n--);
    sink(1);
    return min;
}



