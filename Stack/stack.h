#include <stdio.h>
typedef int type;
#define MAX 100
typedef struct
{
    int top;
    type items[MAX];
} Stack;
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
        return 0;
    }
    else
    {
        item = s->items[s->top];
        s->top--;
    }
    return item;
}
void Pop(type *item, Stack *s)
{
    if (isstackempty(*s))
    {
        printf("Stack UnderFlow \n");
    }
    else
    {
        *item = s->items[s->top--];
    }
}
type peeklast(Stack s)
{
    if (!isstackempty(s))
        return s.items[s.top];
    else
        printf("stack over flow ");
}
type peekfirst(Stack s)
{
    if (!isstackempty(s))
        return s.items[0];
    else
        printf("stack over flow ");
}
int size(Stack s)
{
    if (isstackempty(s))
    {
        return 0;
    }
    return s.top + 1;
}

void distroyStack(Stack *s)
{
    s->top = -1;
}
void copyStack(Stack old, Stack *s)
{
    s->top = old.top;
    for (int i = 0; i <= s->top; i++)
        s->items[i] = old.items[i];
}
void printStack(Stack s)
{
    printf("[Top -> Bottom] ");
    while (!isstackempty(s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");
}
void reverseStack(Stack *s)
{
    Stack temp;
    createStack(&temp);

    while (!isstackempty(*s))
    {
        int item = pop(s);
        push(item, &temp);
    }
    *s = temp;
}
void SortStack(Stack *s)
{
    Stack temp;
    createStack(&temp);
    while (!isstackempty(*s))
    {
        int item = pop(s);
        while (!isstackempty(temp) && peeklast(temp) > item)
        {
            push(pop(&temp), s);
        }
        push(item, &temp);
    }
    *s = temp;
}
