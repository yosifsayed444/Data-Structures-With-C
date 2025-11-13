#include <stdio.h>
#include "stack.h"
#include"linkedList.h"

void createStack(Stack *stack) {
    createLinkedList(&stack->list);
}

int isStackEmpty(Stack stack) {
    return isLinkedListEmpty(stack.list);
}

int isStackFull(Stack stack) {
    return isLinkedListFull(stack.list);
}

void push(Stack *stack, Type value) {
    if (isStackFull(*stack)) {
        printf("Stack overflow. Cannot push.\n");
        return;
    }
   insertElement(&stack->list, value,0);
}

Type pop(Stack *stack) {
    if (isStackEmpty(*stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }
   return retrieveElement(&stack->list, 0);
}

Type peek(Stack stack) {
    Type item=pop(&stack);
    push(&stack,item);
    return item;
}
void displayStack(Stack stack){
   if (isStackEmpty(stack))
    {
        printf("null\n");
        return;
    }

    Node* current = stack.list.head;
    while (current != NULL)
    {
        printf("%d >> ",current->data);
        current = current->next;
    }
}
