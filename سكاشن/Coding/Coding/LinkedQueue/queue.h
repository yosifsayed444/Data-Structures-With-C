#ifndef QUEUE_H
#define QUEUE_H

typedef int Type;
typedef struct NodeT {
    Type data;
    struct Node* next;
} Node;


typedef struct queue{
    Node* front;
    Node* rear;
} Queue;

void createQueue(Queue *queue);
int isQueueEmpty(Queue queue);
int isQueueFull(Queue queue);
void enqueue(Queue *queue, Type value);
Type dequeue(Queue *queue);
Type GetFirstElement(Queue queue);
#endif  /* QUEUE_H */
