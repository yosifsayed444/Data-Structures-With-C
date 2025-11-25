#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_with_C.h"

void print(int *x)
{
    printf("Value: %d ->", *x);
}
int main()
{
    linkedlist l;
    createList(&l);
    insertNodeAtPosition(0, 10, &l);
    insertNodeAtPosition(1, 20, &l);
    insertNodeAtPosition(2, 30, &l);
    insertNodeAtPosition(4, 40, &l);
    insertNodeAtPosition(3, 50, &l);
    traverseLinkedlist(&l, print);
    int item = retrieveAtPosition(&l, 3);
    printf("deleted item is %d\n", item);
    traverseLinkedlist(&l, print);
    clearList(&l);
    traverseLinkedlist(&l, print);
}