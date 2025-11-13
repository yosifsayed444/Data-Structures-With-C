#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void mainpro()
{
    int n=10;
    Stack myStack;
    createStack(&myStack);
    while (n > 0)
    {
      // This line pushes the value of n%2 to stack S    1010
      push(&myStack, n%2);
      n = n/2;
    }
    while (!isStackEmpty(myStack))
      printf("%d ", pop(&myStack));
}
