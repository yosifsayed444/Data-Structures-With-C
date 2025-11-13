#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack myStack;
    createStack(&myStack);

    printf("Pushing elements onto the stack:\n");
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);

    printf("Stack contents after pushing:\n");
    displayStack(myStack);

    printf("Popping elements from the stack:\n");
    while (!isStackEmpty(myStack)) {
        printf("Popped element: %d\n", pop(&myStack));
    }

    printf("Stack contents after popping:\n");
    displayStack(myStack);

    return 0;
}
