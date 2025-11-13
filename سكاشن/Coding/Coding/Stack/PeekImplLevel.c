
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
    displayStack(myStack);
    printf("The last element is %d\n",peek(myStack));
    displayStack(myStack);
}
