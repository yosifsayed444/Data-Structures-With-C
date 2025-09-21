#include <stdio.h>
typedef int type;
#define MAX 10
typedef struct
{
    int top;
    type items[MAX];
}Stack;
void createStack(Stack *s)
{
    s->top = -1;
}
int isstackempty(Stack s)
{
    return s.top == -1;
}
int isstackfull(Stack s)
{
    return s.top == MAX - 1;
}
void push(type item, Stack *s)
{

    if (isstackfull(*s))
    {
        printf("Stack Over Flow \n");
    }
    else
    {
        s->top++;
        s->items[s->top] = item;
    }
}
type pop(Stack *s)
{
    type item;

    if (isstackempty(*s))
    {
        printf("Stack UnderFlow \n");
    }
    else
    {
        item = s->items[s->top];
        s->top--;
    }
    return item;
}
type peek(Stack s)
{
    if (!isstackempty(s))
        return s.items[s.top];
    else
        printf("stack over flow");
}
