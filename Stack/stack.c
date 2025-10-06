#include <stdio.h>
#include "stack.h"
int main()
{
    Stack s;
    int n;
    createStack(&s);
    for (int i = 1; i <= 4; i++)
    {
        if (!isstackfull(s))
        {
            push(i, &s);

            printf("Pushed: %d\n", i);
        }
    }
    printf("peek: %d\n", peek(s)); 

    return 0;
}
