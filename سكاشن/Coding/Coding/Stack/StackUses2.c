#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int mains2()
{
    Stack mystack;
//Initialize the stack to be empty
    createStack(&mystack);
    char item = getchar() ;
    while (!isStackFull(mystack)&& item!= '\n')
    {
        push(&mystack,item);
        item = getchar();
    }

    while (!isStackEmpty(mystack))
    {
        item=pop(&mystack);
        putchar(item);
    }

    return 0;
}
