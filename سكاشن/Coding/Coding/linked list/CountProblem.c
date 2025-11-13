#include <stdio.h>
#include "linkedlist.h"
#include "Utility.h"

int Count(LinkedList* myList, int target)
{
    int count = 0;
    Node* current = myList->head;

    while (current != NULL)
    {

        if (current->data == target)
        {
            count++;
        }
        current = current->next;
    }

    return count;
}
int mainCP()
{
    LinkedList* myList;
    createLinkedList(&myList,10);
    // Insert some elements into the list (for demonstration)
    insertElement(&myList, 30, 0);
    insertElement(&myList, 20, 0);
    insertElement(&myList, 10, 0);
    traverseLinkedList(&myList,&print);
//    // Count occurrences of a specific value (e.g., count occurrences of '1')
    int targetValue = 10;
    int occurrences = Count(&myList, targetValue);
    printf("The value %d occurs %d time(s) in the list.\n", targetValue, occurrences);
    return 0;
}
