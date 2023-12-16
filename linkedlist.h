#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

#define LISTS_CONSISTENCY_EMPTY_OK 0
#define LISTS_CONSISTENCY_POPULATED_OK 1
#define LISTS_CONSISTENCY_TAIL_POPULATED_HEAD_NOT_NOK 2
#define LISTS_CONSISTENCY_HEAD_POPULATED_TAIL_NOT_NOK 3
#define TAIL_STRING_ELEMENTS 3

typedef struct NODE NODE;
struct NODE
{
    uint8_t data;
    NODE* next;
};

typedef struct 
{
    NODE* head;
    NODE* tail;
}LinkedList;

void insert_at_beginning(LinkedList* mylist, uint8_t data);
void print_list(LinkedList* mylist);
void free_list(LinkedList* mylist);
void insert_at_end(LinkedList* mylist, uint8_t data);

#endif