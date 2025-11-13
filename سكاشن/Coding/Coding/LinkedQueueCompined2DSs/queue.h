#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 5
#include "linkedList.h"
typedef int Type;

typedef struct queue{
LinkedList list;
} Queue;

void createQueue(Queue *queue);
int isQueueEmpty(Queue queue);
int isQueueFull(Queue queue);
void enqueue(Queue *queue, Type value);
Type dequeue(Queue *queue);
Type GetFirstElement(Queue queue);
#endif  /* QUEUE_H */
