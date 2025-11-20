#include "linkedlist_with_C.h"
void createlinkedQueue1(linkedQueue1 *l)
{
    createList(l);
}
int isEmpty1(linkedQueue1 *l)
{
    return isEmpty(l);
}
int isFull1(linkedQueue1 *l)
{
    return isFull(l);
}
void enqueue1(type data, linkedQueue1 *l)
{
   insertNodeAtPosition(l->size, data, l);
}
 type dequeue1(linkedQueue1 *l)
{
   return retrieveAtPosition(0, l);
}
void displaylinkedQueue1(linkedQueue1 *l)
{
    displaylinkedlist(l);
}
void clearlinkedQueue1(linkedQueue1 *l)
{
    clearlist(l);
}
void traverselinkedQueue1(linkedQueue1 *l,void (*func)(type*)){
    traverselinkedlist(l,func);
}
 type front1(linkedQueue1 *l)
{
    if (isEmpty(l))
    {
        printf("QueuelinkedQueue1 is empty\n");
        return -1;
    }
    return l->head->value;
}
 type rear1(linkedQueue1 *l)
{
    if (isEmpty(l))
    {
        printf("QueuelinkedQueue1 is empty\n");
        return -1;
    }
    node *temp = l->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->value;
}