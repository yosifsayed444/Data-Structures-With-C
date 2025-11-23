#include <stdio.h>
#include "doublyLinkedList.h"

void printList(int value) {
    printf("%d ", value);
}

int main() {
    DoublyLinkedList list;
    CreateDoublyLinkedList(&list);

    insertAtPosition(&list, 10, 0); 
    insertAtPosition(&list, 50, 1); 

    printf("List after insertions (size=%d):\n", getSize(&list));
    traverseListforward(&list, printList);
    printf("\n");

    int value = RetrieveAtPosition(&list, 0);
    printf("List after deleting position 0 (size=%d):\n", getSize(&list));
    traverseListbackward(&list, printList);
    printf("\n");
    printf("deleted value: %d\n", value);
    printf("\n");

    freeList(&list);
    printf("List after free = %d", getSize(&list));
    return 0;
}