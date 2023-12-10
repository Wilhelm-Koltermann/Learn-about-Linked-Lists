#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void main()
{
    NODE* head = NULL;
    print_list(head);
    free_list(&head);
    
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 22);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 25);
    insert_at_beginning(&head, 6);

    print_list(head);
    free_list(&head);
    return;
}