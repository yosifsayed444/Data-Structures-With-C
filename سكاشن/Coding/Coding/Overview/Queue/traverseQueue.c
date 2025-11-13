
#include<stdio.h>
#include"queue.h"
void print(Type *value)
{
    printf("value is: %d\n", *value);
}

void Increment(Type* value)
{
    (*value)++;
}

int mainT()
{
    Queue myQueue;
    createQueue(&myQueue);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    traverseQueue(&myQueue,&Increment);
    traverseQueue(&myQueue,&print);


}
