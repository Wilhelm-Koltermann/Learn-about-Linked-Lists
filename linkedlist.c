#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <stdint.h>

static NODE* create_new_node(uint8_t data)
{
    NODE* new = (NODE*) malloc(sizeof(NODE));
    if(NULL == new)
    {
        printf("Something went wrong when allocating memory for the new node!\n");
        return new;
    }
    new->data = data;
    new->next = NULL;
    return new;
}

static uint8_t check_lists_consistency(LinkedList* mylist)
{
    if( NULL == mylist->head && NULL == mylist->tail )
    {
        return LISTS_CONSISTENCY_EMPTY_OK;   
    }
    else if ( NULL != mylist->head && NULL != mylist->tail )
    {
        return LISTS_CONSISTENCY_POPULATED_OK;
    }
    else if ( NULL == mylist->head && NULL != mylist->tail )
    {
        printf("HEAD --> NULL but TAIL not");
        return LISTS_CONSISTENCY_TAIL_POPULATED_HEAD_NOT_NOK;
    }
    else
    {
        printf("TAIL --> NULL but HEAD not");
        return LISTS_CONSISTENCY_HEAD_POPULATED_TAIL_NOT_NOK;
    }
}

void insert_at_beginning(LinkedList* mylist, uint8_t data)
{
    uint8_t list_status = check_lists_consistency(mylist);
    if(LISTS_CONSISTENCY_TAIL_POPULATED_HEAD_NOT_NOK == list_status || LISTS_CONSISTENCY_HEAD_POPULATED_TAIL_NOT_NOK == list_status){ return; }

    NODE* new = create_new_node(data);
    if(NULL == new){ return; }
    
    // if list is empty let head and tail point to the new node
    // as the new node already points to NULL its next pointer doesn't have to be updated
    if(NULL == mylist->head && NULL == mylist->tail)
    {
        mylist->head = new;
        mylist->tail = new;
        return;
    }

    // if list isn't empty let new point to whatever head is pointing to at the moment i.e. the soon to be second node in the list
    // let head point to the new beginning of the list i.e. the new node
    new->next = mylist->head;
    mylist->head = new;
    return;
}

void insert_at_end(LinkedList* mylist, uint8_t data)
{
    uint8_t list_status = check_lists_consistency(mylist);
    if(LISTS_CONSISTENCY_TAIL_POPULATED_HEAD_NOT_NOK == list_status || LISTS_CONSISTENCY_HEAD_POPULATED_TAIL_NOT_NOK == list_status){ return; }

    NODE* new = create_new_node(data);
    if(NULL == new){ return; }

    if( LISTS_CONSISTENCY_EMPTY_OK == list_status )
    {
        mylist->head;
        mylist->tail;
    }

    mylist->tail->next = new;
    mylist->tail = new;
    return;
}

static uint8_t determine_number_of_decimals(uint8_t data)
{

    if(0 == data/10)
    {
        return 1;
    }
    else if(0 == data/100)
    {
        return 2;
    }

    return 3;
}

void print_list(LinkedList* mylist)
{
    uint8_t list_status = check_lists_consistency(mylist);
    if(LISTS_CONSISTENCY_TAIL_POPULATED_HEAD_NOT_NOK == list_status || LISTS_CONSISTENCY_HEAD_POPULATED_TAIL_NOT_NOK == list_status){ return; }
    
    if(LISTS_CONSISTENCY_EMPTY_OK == list_status)
    { 
        printf("The list is empty: HEAD --> NULL <-- TAIL\n");
        return;
    }

    uint16_t white_space_counter = 0;
    printf("\nHEAD\n|\nv\n");
    for(NODE* current = mylist->head; current != NULL; current = current->next)
    {
        printf("|%u|-->", current->data);

        if(current != mylist->tail)
        {
            uint8_t number_of_decimals = determine_number_of_decimals(current->data);
            switch (number_of_decimals)
            {
            case 1:
                white_space_counter += 6;
                break;
            case 2:
                white_space_counter += 7;
                break;
            case 3:
                white_space_counter += 8;
                break;
            default:
                printf("Something went wrong incrementing the white_space_counter!\n");
                break;
            }
        }
        
    }
    printf("NULL\n");

    for(uint8_t string_element_counter = 0; string_element_counter < TAIL_STRING_ELEMENTS; string_element_counter += 1)
    {
        for(uint8_t i = 0; i < white_space_counter; i += 1)
        {
            //number of white spaces to insert to cover one printed list element
            printf(" ");
        }

        switch (string_element_counter)
        {
        case 0:
            printf("^\n");
            break;
        case 1:
            printf("|\n");
            break;
        case 2:
            printf("TAIL\n");
            break;
        default:
            printf("Something went wrong printing the tail string!\n");
            break;
        }
    }


    return;
}

void free_list(LinkedList* mylist)
{
    uint8_t list_status = check_lists_consistency(mylist);
    if(LISTS_CONSISTENCY_TAIL_POPULATED_HEAD_NOT_NOK == list_status || LISTS_CONSISTENCY_HEAD_POPULATED_TAIL_NOT_NOK == list_status){ return; }

    if(LISTS_CONSISTENCY_EMPTY_OK == list_status)
    { 
        printf("This list is already empty, there is nothing to free here.\n");
        return;
    }

    NODE* current = mylist->head;
    while(current != NULL)
    {
        NODE* temp_node = current;
        current = current->next;
        free(temp_node);
    }

    mylist->head = NULL;
    mylist->tail = NULL;
    return;
}