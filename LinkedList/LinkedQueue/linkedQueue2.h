#include "global.h"
#include <stdio.h>
node *createNode(type data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void createLinkedQueue(linkedQueue2 *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(linkedQueue2 *q)
{
    return q->front == NULL;
}

int isFull(linkedQueue2 *q)
{
    return 0;
}

void enqueue(type data, linkedQueue2 *q)
{
    node *newNode = createNode(data);
    if (q->rear == NULL || q->size == 0)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

type dequeue(linkedQueue2 *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    if (q->size == 1)
    {
        type item = q->front->value;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        q->size = 0;
        return item;
    }
    else
    {
        node *temp = q->front;
        type item;
        q->front = q->front->next;
        item = temp->value;
        free(temp);
        q->size--;
        return item;
    }
}
void clearlinkedQueue(linkedQueue2 *l)
{
    node *temp;
    while (temp != NULL)
    {
        temp = l->front;
        l->front = l->front->next;
        free(temp);
    }
    l->front = NULL;
    l->rear = NULL;
    l->size = 0;
}

void displaylinkedQueue(linkedQueue2 *l)
{
    node *temp = l->front;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    if (isEmpty(l))
        printf("QueuelinkedQueue is empty\n");
}
void traverselinkedQueue(linkedQueue2 *l, void (*func)(type *))
{
    node *temp = l->front;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}
type front(linkedQueue2 *l)
{
    if (isEmpty(l))
    {
        printf("QueuelinkedQueue is empty\n");
        return -1;
    }
    return l->front->value;
}
type rear(linkedQueue2 *l)
{
    if (isEmpty(l))
    {
        printf("QueuelinkedQueue is empty\n");
        return -1;
    }
    return l->rear->value;
}