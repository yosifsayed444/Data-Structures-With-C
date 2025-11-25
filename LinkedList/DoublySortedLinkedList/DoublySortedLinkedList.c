#include <stdio.h>
#include <stdlib.h>
#include "DoublySortedLinkedList.h"
void printList(int key, int value)
{
    printf("key = %d, value = %d\n", key, value);
}
int main()
{
    DoublySortedLinkedList list;
    CreateDoublySortedLinkedList(&list);

    printf("Inserting nodes...\n");
    insertUniquelySortedByKey(&list, 10, 100);
    insertUniquelySortedByKey(&list, 20, 200);
    insertUniquelySortedByKey(&list, 10, 300);
    insertUniquelySortedByKey(&list, 40, 200);
    insertUniquelySortedByKey(&list, 50, 500);
    insertUniquelySortedByKey(&list, 20, 900);
    insertUniquelySortedByKey(&list, 35, 50);
    insertUniquelySortedByKey(&list, 45, 450);
    insertUniquelySortedByKey(&list, 55, 550);

    printf("\nList forward:\n");
    traverseListforward(&list, printList);

    printf("\nList backward:\n");
    traverseListbackward(&list, printList);

    printf("\nRetrieve (remove) element with key 25...\n");
    int value = retrieveByKey(&list, 25);
    printf("Retrieved value = %d\n", value);

    printf("\nList after removing key 3 (forward):\n");
    traverseListforward(&list, printList);

    printf("\nList after removing key 3 (backward):\n");
    traverseListbackward(&list, printList);

    freeList(&list);

    return 0;
}
