#include <stdlib.h>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct {
    struct node *first;
    struct node *last;
} list;

unsigned char delete_index(list *l, int index);
void insert_start(list *l, unsigned char ch);
void insert_end(list *l, unsigned char ch);
int find_index(list *l, unsigned char ch);
void delete(list *l, unsigned char ch);

#endif