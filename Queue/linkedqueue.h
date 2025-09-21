#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct
{
    linkedlist l;
} Queue;

void createQueue(Queue *q)
{
    createList(&q->l);
}

int isqueueEmpty(Queue q)
{
    return isEmpty(&q.l);
}

void enqueue(Queue *q, type item)
{
    insertNode(size(&q->l), item, &q->l); 
}

type dequeue(Queue *q)
{
    if (isqueueEmpty(*q))
    {
        printf("Queue is empty!\n");
        exit(1);
    }
    type item = retrieveList(&q->l, 0);          
    return item;
}
