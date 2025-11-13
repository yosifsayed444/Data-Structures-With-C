#include <stdio.h>
#include "queue.h"


Type GetFirstElementUL(Queue MyQueue){
    if(!isQueueEmpty(MyQueue))
        return dequeue(&MyQueue);
    else
    return 0;
}
int main() {
    Queue myQueue;
    createQueue(&myQueue);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    Type frontElement = GetFirstElementUL(myQueue);
    printf("Front element: %d\n", frontElement);
    printf("Dequeuing elements from the queue:\n");

    while (!isQueueEmpty(myQueue))
    {
        printf("Dequeued element: %d\n", dequeue(&myQueue));
    }
    return 0;
}
