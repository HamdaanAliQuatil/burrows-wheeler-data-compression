#include "Trie.h"

#ifndef MINIMUM_PRIORITY_QUEUE
#define MINIMUM_PRIORITY_QUEUE

int pq_size(void);
void pq_insert(trie_node *t);
trie_node *pq_delete_min(void);

#endif