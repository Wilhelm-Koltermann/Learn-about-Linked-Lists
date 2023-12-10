#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <stdint.h>

static NODE* create_new_node(uint8_t data)
{
    NODE* new = (NODE*) malloc(sizeof(NODE));
    if(NULL == new)
    {
        return new;
    }
    new->data = data;
    new->next = NULL;
    return new;
}

void insert_at_beginning(NODE** head, uint8_t data)
{
    NODE* new = create_new_node(data);
    if(NULL == new)
    {
        printf("Something went wrong when allocating memory for the new node!\n");
        return;
    }
    
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
    if(NULL == *head)
    { 
        printf("This list is already empty, there is nothing to free here.\n");
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