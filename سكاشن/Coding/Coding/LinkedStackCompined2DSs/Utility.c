#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"


void print(Type *value)
{
    printf("value is: %d\n", *value);
}
void Increment(Type* value)
{
    (*value)++;
}

void PrintList(LinkedList* list) {
    Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
