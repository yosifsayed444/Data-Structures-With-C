#include <stdio.h>
#include "stack.h" 

int main()
{
    Stack s;
    createStack(&s);

    push(3, &s);
    push(7, &s);
    push(2, &s);
    push(10, &s);
    push(8, &s);
    push(9, &s);

    printf("\nBefore reverse:\n");
    printStack(s);

    printf("\n Sorted stack:\n");
    SortStack(&s);
    printStack(s);

    printf("\nAfter reverse:\n");
    reverseStack(&s);
    printStack(s);
}
