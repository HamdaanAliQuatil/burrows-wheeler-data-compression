#include "DoublyLinkedList.h"

struct node {
    unsigned char ch;
    struct node *prev;
    struct node *next;
};

static struct node *create_node(unsigned char ch) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->ch = ch;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_start(list *l, unsigned char ch) {
    struct node *new_node = create_node(ch);

    if (l->first == NULL) {
        l->first = new_node;
        l->last = l->first;
    } else {
        new_node->next = l->first;
        l->first->prev = new_node;
        l->first = new_node;
    }
}

void insert_end(list *l, unsigned char ch) {
    struct node *new_node = create_node(ch);

    if (l->last == NULL) {
        l->last = new_node;
        l->first = l->last;
    } else {
        l->last->next = new_node;
        new_node->prev = l->last;
        l->last = new_node;
    }
}

int find_index(list *l, unsigned char ch) {
    int index = 0;
    struct node *p = l->first;

    while (p != NULL && p->ch != ch) {
        ++index;
        p = p->next;
    }
    return index;
}

void delete(list *l, unsigned char ch) {
    struct node *p = l->first;
    while (p != NULL && p->ch != ch)
        p = p->next;

    if (p == NULL)
        return;

    if (p == l->first) {
        if (p->next == NULL) {
            l->first = NULL;
            l->last = NULL;
        } else {
            l->first = p->next;
            l->first->prev = NULL;
        }
    } else if (p == l->last) {
        if (p->prev == NULL) {
            l->first = NULL;
            l->last = NULL;
        } else {
            l->last = p->prev;
            l->last->next = NULL;
        }
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    free(p);
}

unsigned char delete_index(list *l, int index) {
    struct node *p = l->first;
    while (index-- && p != NULL)
        p = p->next;

    unsigned char ch = p->ch;
    if (p == l->first) {
        if (p->next == NULL) {
            l->first = NULL;
            l->last = NULL;
        } else {
            l->first = p->next;
            l->first->prev = NULL;
        }
    } else if (p == l->last) {
        if (p->prev == NULL) {
            l->first = NULL;
            l->last = NULL;
        } else {
            l->last = p->prev;
            l->last->next = NULL;
        }
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    free(p);
    return ch;
}