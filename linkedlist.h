#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

typedef struct NODE NODE;
struct NODE
{
    uint8_t data;
    NODE* next;
};

void insert_at_beginning(NODE** head, uint8_t data);
void print_list(NODE* head);
void free_list(NODE** head);

#endif