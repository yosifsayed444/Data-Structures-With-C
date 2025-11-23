#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_with_C.h"
int main()
{
    linkedlist l;
    createList(&l);
    insertNodeAtPosition(0, 10, &l);
    insertNodeAtPosition(1, 20, &l);
    insertNodeAtPosition(2, 30, &l);
    insertNodeAtPosition(4, 40, &l);
    insertNodeAtPosition(3, 50, &l);
    insertNodeintoTail(60, &l);
    displayLinkedlist(&l);
    int item = retrieveAtPosition(&l, 3);
    printf("deleted item is %d\n", item);
    displayLinkedlist(&l);
    clearList(&l);
    displayLinkedlist(&l);
}