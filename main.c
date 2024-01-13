#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void main()
{
    LinkedList mylist = {NULL, NULL};
    print_list(&mylist);
    free_list(&mylist);

    insert_at_beginning(&mylist, 2);
    insert_at_end(&mylist, 1);
    insert_at_beginning(&mylist, 4);
    insert_at_beginning(&mylist, 3);
    insert_at_beginning(&mylist, 5);
    insert_at_end(&mylist, 7);

    //printf("%u\n", mylist.tail->data);
    
    print_list(&mylist);
    free_list(&mylist);
    print_list(&mylist);

    return;
}