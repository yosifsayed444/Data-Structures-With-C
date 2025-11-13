#include <stdio.h>
typedef int type;
#define MAX1 100

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
void traverseQueue(Queue *q, void (*f)(type *))
{
    int i, siz;
    for (i = q->front, siz = 0; siz < q->size; siz++)
    {
        (*f)(&q->arr[i]);
        i = (i + 1) % MAX1;
    }
}

void searchq(Queue *q, type key)
{
    int found = 0;
    int i, siz;
    for (i = q->front, siz = 0; siz < q->size; siz++)
    {

        if (q->arr[i] == key)
        {
            printf("Element %d found in the queue\n", key);
            return;
        }
        i = (i + 1) % MAX1;
    }
    printf("Element %d not found in the queue\n", key);
}
Queue MergeQueue(Queue q1, Queue q2)
{
    Queue q3;
    createQueue(&q3);
    while(!isqueueEmpty(q1) && !isqueueEmpty(q2)){
        int SecCode=dequeue(&q1);
        int GroupCode=dequeue(&q2);
        int result = SecCode*10 + GroupCode;
        enqueue(&q3,result);
    }
    return q3;
}