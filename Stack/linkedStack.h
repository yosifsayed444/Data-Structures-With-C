#include "linkedlist.h"
#include <stdio.h>
void createStack(Stack *s)
{
    createList(&s->l);
}
int isstackempty(Stack s)
{
    return isEmpty(&s.l);
}
void push(type item, Stack *s)
{
    insertNode(0, item, &s->l);
}
type pop(Stack *s)
{
    retrieveList(&s->l, 0);
}
type peek(Stack s)
{
    type item = retrieveList(&s.l, 0);
    push(item, &s);
    return item;
}