#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_with_C.h"
int main()
{
    linkedlist l;
    createList(&l);
    insertNode(0, 10, &l);
    insertNode(1, 20, &l);
    insertNode(2, 30, &l);
    insertNode(3, 40, &l);
    insertNode(4, 50, &l);
    int item = retrieveList(&l, 3);
    printf("deleted item is %d\n", item);
    displayLinkedlist(&l);
    reverseLinkedlist(&l);

    // if (isEmpty(&l))
    // {
    //     printf("list is empty\n");
    // }
}