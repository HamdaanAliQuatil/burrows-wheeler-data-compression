#include <stdio.h>
#include <string.h>
#include "DoublyLinkedList.h"

list init_list(void) {
    list l = {NULL};
    for (int ch = 0; ch < 256; ++ch) {
        insert_end(&l, ch);
    }
    return l;
}

void encode(void) {
    int index, ch;
    list l = init_list();

    while ((ch = getchar()) != EOF) {
        index = find_index(&l, ch);
        delete(&l, ch);
        insert_start(&l, ch);
        putchar(index);
    }
}

void decode(void) {
    int index, ch;
    list l = init_list();

    while ((index = getchar()) != EOF) {
        ch = delete_index(&l, index);
        insert_start(&l, ch);
        putchar(ch);
    }
}

int main(int argc, char *argv[]) {
    if (!strcmp(argv[1], "-"))
        encode();
    else if (!strcmp(argv[1], "+"))
        decode();
    return 0;
}