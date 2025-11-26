#include "linkedlist_with_C.h"
typedef int type;
typedef struct StackList1
{
    linkedlist l;
} StackList1;

void createStack(StackList1 *s)
{
    createList(&s->l);
}
int isStackEmpty(StackList1 *s)
{
    return isEmpty(&s->l );
}
int isStackFull(StackList1 *s)
{
    return isFull(&s->l );
}
void push(type data, StackList1 *s)
{
    insertNodeAtPosition(0, data, &s->l);
}
type pop(StackList1 *s)
{
    return retrieveAtPosition(&s->l, 0);
}
void clearStack(StackList1 *s)
{
    clearList(s);
}
type peek(StackList1 *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->l.head->value;
}
type stackSize(StackList1 *s)
{
    return s->l.size;
}
void traverseStackList(StackList1 *s, void (*func)(type *))
{
    node *temp = s->l.head;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}