#include <stdio.h>
#include "queue.h"

int mainFE() {
    Queue myQueue;
    createQueue(&myQueue);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    Type frontElement = GetFirstElement(myQueue);
    printf("Front element: %d\n", frontElement);
    return 0;
}
