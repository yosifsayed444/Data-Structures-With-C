#include <stdio.h>
#include "CircularLinkedList.h" 

void printValue(type *val)
{
    printf("%d ", *val);
}

int main()
{
    circularLinkedList list;
    createCircularLinkedList(&list);

    insertNodeAtPosition(0, 10, &list); 
    insertNodeAtPosition(1, 20, &list); 
    insertNodeAtPosition(1, 15, &list); 

    printf("List after insertions (size=%d):\n", list.size);
    displayList(&list); 

    
    type deleted = retrieveAtPosition(&list, 1);
    printf("Deleted value at position 1: %d\n", deleted);
    printf("List after deletion (size=%d):\n", list.size);
    displayList(&list);

    
    printf("Traverse list: ");
    traverseCircularLinkedList(&list, printValue);
    printf("\n");

  
    clearList(&list);
    printf("List after clear (size=%d):\n", list.size);
    displayList(&list);

    return 0;
}
