#include <stdio.h>
#include "linkedlist.h"
#include "Utility.h"


int mainM()
{
    LinkedList* myList;
    createLinkedList(&myList,10);  // Create a linked list with a maximum size of 10
    traverseLinkedList(&myList,&print);
    // Insert elements into the linked list
    printf("Inserting elements into the linked list:\n");
    insertElement(&myList, 10, 0);  // Insert at position 0
    traverseLinkedList(&myList,&print);
//
    insertElement(&myList, 20, 1);  // Insert at position 1
    insertElement(&myList, 30, 2);  // Insert at position 2
    traverseLinkedList(&myList,&print);
//    // Retrieve and delete elements from the linked list
//    printf("Retrieving and deleting elements from the linked list:\n");
    int i=1;
    printf("Retrieved values: %d from position %d\n", retrieveElement(&myList, i),i); // Retrieve and delete from position 1
    traverseLinkedList(&myList,&print);
    i=0;
    printf("Retrieved values: %d from position %d\n", retrieveElement(&myList, i),i);
    traverseLinkedList(&myList,&print);
//
    printf("Retrieved values: %d from position %d\n", retrieveElement(&myList, i),i);
    traverseLinkedList(&myList,&print);
//
//    printf("Retrieved values: %d from position %d\n", retrieveElement(&myList, i),i);
//    traverseLinkedList(&myList,&print);

//    // Destroy the linked list to free memory
    PrintList(&myList);
    clearLinkedList(&myList);
    return 0;
}
