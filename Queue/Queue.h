#include <stdio.h>
typedef int type;
#define MAX1 3

typedef struct
{
    int front;
    int rear;
    int size;
    type arr[MAX1];
} Queue;

void createQueue(Queue *q)
{
    q->front = 0;
    q->rear = MAX1 - 1;
    q->size = 0;
}
int isqueueEmpty(Queue q)
{
    return q.size == 0;
}
int isqueueFull(Queue q)
{
    return q.size == MAX1;
}
void enqueue(Queue *q, type item)
{
    if (isqueueFull(*q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % MAX1;
        q->arr[q->rear] = item;
        q->size++;
    }
}
type dequeue(Queue *q)
{
    type item;
    if (isqueueEmpty(*q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = q->arr[q->front];
        q->front = (q->front + 1) % MAX1;
        q->size--;
    }
    return item;
}
void traverseQueue(Queue *q, void (*func)(type *))
{
    int i = q->front;
    while (1)
    {
        func(&q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX1;
    }
}