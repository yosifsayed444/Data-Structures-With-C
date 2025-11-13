#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = MAX_QUEUE_SIZE-1;
    queue->size=0;
}

int isQueueEmpty(Queue queue)
{
    return (queue.size==0);
}

int isQueueFull(Queue queue)
{
    return ( queue.size == MAX_QUEUE_SIZE);
}

void enqueue(Queue *queue, Type value)
{
    if (isQueueFull(*queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->data[queue->rear] = value;
        queue->size++;
    }

}

Type dequeue(Queue *queue)
{
    Type value;

    if (isQueueEmpty(*queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return (Type)-1;
    }
    else
    {
        value=queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->size--;
        return value;
    }


}

void traverseQueue(Queue *queue,void (*f)(Type*))
{
    int i,s;

    for(i=queue->front,s=0; s<queue->size; s++)
    {
        (*f)(&queue->data[i]);
        i=(i+1)%MAX_QUEUE_SIZE;
    }
}

Type GetFirstElement(Queue queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot retrieve the front element.\n");
        return (Type)-1;
    } else {
        return queue.data[queue.front];
    }
}
