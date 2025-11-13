#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 5
typedef int Type;

typedef struct queue{
    Type data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void createQueue(Queue *queue);
int isQueueEmpty(Queue queue);
int isQueueFull(Queue queue);
void enqueue(Queue *queue, Type value);
Type dequeue(Queue *queue);
void traverseQueue(Queue *queue,void (*f)(Type*));
Type GetFirstElement(Queue queue);
#endif  /* QUEUE_H */
