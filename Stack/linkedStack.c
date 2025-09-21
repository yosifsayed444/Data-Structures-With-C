#include <stdio.h>
#include "linkedStack.h"
//#include "linkedStack2.h"
int main()
{
    Stack s;
    createStack(&s);
    for (int i = 1; i <= 4; i++)
    {

        push(i, &s);

        printf("Pushed: %d\n", i);
    }
    pop(&s);
    while (!isstackempty(s))
    {
        int item = pop(&s);
        printf("after delete: %d\n", item);
    }
    printf("peek: %d\n", peek(s));

    return 0;
}
