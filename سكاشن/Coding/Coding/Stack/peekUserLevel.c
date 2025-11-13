#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



Type StackTop(Stack s)
{
    Type item;
    item=pop(&s);
    push(&s, item);
    return item;
}
int mainpeeku()
{
    Stack myStack;
    createStack(&myStack);
    printf("Pushing elements onto the stack:\n");
    push(&myStack, 10);
    push(&myStack, 20);
    displayStack(myStack);
    printf("The last element is %d\n",StackTop(myStack));
    displayStack(myStack);
}
