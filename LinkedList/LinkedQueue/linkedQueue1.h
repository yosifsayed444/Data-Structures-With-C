#include "linkedlist_with_C.h"
typedef int type;
typedef struct linkedQueue
{
    linkedlist l;
} linkedQueue;
void createlinkedQueue(linkedQueue *q)
{
    createList(&q->l);
}
int isQueueEmpty(linkedQueue *q)
{
    return isEmpty(&q->l);
}
int isQueueFull(linkedQueue *q)
{
    return isFull(&q->l);
}
void enqueue(type data, linkedQueue *q)
{
    insertNodeAtPosition(q->l.size, data, &q->l);
}

type dequeue(linkedQueue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return retrieveAtPosition(&q->l, 0);
}

type front(linkedQueue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->l.head->value;
}

type rear(linkedQueue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    node *temp = q->l.head;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}

void traverselinkedQueue(linkedQueue *q, void (*func)(type *))
{
    traverseLinkedlist(&q->l, func);
}
void clearlinkedQueue(linkedQueue *q)
{
    clearList(&q->l);
}