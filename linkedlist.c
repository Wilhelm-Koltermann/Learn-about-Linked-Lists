#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <stdint.h>

void insert_at_beginning(NODE** head, uint8_t data)
{
    NODE* new = (NODE*) malloc(sizeof(NODE));
    if(NULL == new)
    {
        printf("Something went wrong when allocating memory for the new node!\n");
        exit(1);
    }
    new->data = data;
    new->next = *head;
    *head = new;
    return;
}

void print_list(NODE* head)
{
    if(NULL == head)
    { 
        printf("The list is empty: head --> NULL\n");
        return;
    }

    for(NODE* current = head; current != NULL; current = current->next)
    {
        printf("|%u|-->", current->data);
    }
    printf("NULL\n");
    return;
}

void free_list(NODE** head)
{
    if(NULL == head)
    { 
        printf("This list is already empty: head --> NULL\n");
        return;
    }

    NODE* current = *head;
    while(current != NULL)
    {
        NODE* temp_node = current;
        current = current->next;
        free(temp_node);
    }
    *head = NULL;
    return;
}