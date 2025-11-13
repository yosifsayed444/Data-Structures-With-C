#include <stdio.h>
#include "queue.h"

int main()
{
//    Queue myQueue = createQueue(5);  // Create a queue with a maximum size of 5
    Queue myQueue;
    createQueue(&myQueue);
    printf("Enqueuing elements into the queue:\n");
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    printf("the first element is %d:\n",GetFirstElement(myQueue));


    printf("Dequeuing elements from the queue:\n");
    while (!isQueueEmpty(myQueue))
    {
        printf("Dequeued element: %d\n", dequeue(&myQueue));
    }

    // Queue is empty, attempting to dequeue again
    printf("Dequeuing from an empty queue:\n");
    printf("Dequeued element: %d\n", dequeue(&myQueue));


    return 0;
}
