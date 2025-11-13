#include <stdio.h>
#include <stdlib.h> //system headers
#include "stack.h" // user defined

int main()
{
    Stack myStack;
    createStack(&myStack);

    printf("Pushing elements onto the stack\n");
    push(&myStack, 10);
    push(&myStack, 20);
    printf("the elements of stack after push 10 20\n");
    displayStack(myStack);
    push(&myStack, 30);
    push(&myStack, 40);
    printf("Popping elements from the stack:\n");
    while (!isStackEmpty(myStack))
    {
        printf("Popped element: %d\n", pop(&myStack));
    }

    return 0;
}
