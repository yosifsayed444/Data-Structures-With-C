#include <stdio.h>
#include "linkedQueue1.h"
// #include "linkedQueue2.h"

void printValue(type *x)
{
    printf("Value: %d ", *x);
}
int main()
{
    linkedQueue q;
    createlinkedQueue(&q);

    printf("Is queue empty? %d\n", isQueueEmpty(&q));
    enqueue(10, &q);
    enqueue(20, &q);
    enqueue(30, &q);

    printf("Queue after enqueue 10, 20, 30: ");
    traverselinkedQueue(&q, printValue);
    printf("\n");
    printf("Front: %d\n", front(&q));
    printf("Rear: %d\n", rear(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue after dequeue: ");
    traverselinkedQueue(&q, printValue);
    printf("\n");
    printf("Front: %d\n", front(&q));
    printf("Rear: %d\n", rear(&q));
    enqueue(40, &q);
    enqueue(50, &q);
    printf("Queue after enqueue 40, 50: ");
    traverselinkedQueue(&q, printValue);
    printf("\n");
    clearlinkedQueue(&q);
    printf("Queue cleared. Is empty? %d\n", isQueueEmpty(&q));

    // Uncomment to test second Queue implementation

    // printf("\n============= Testing LinkedQueue2 ============\n");
    // linkedQueue2 q2;
    // createLinkedQueue(&q2);

    // printf("=== Testing enqueue ===\n");
    // enqueue(10, &q2);
    // enqueue(20, &q2);
    // enqueue(30, &q2);
    // enqueue(40, &q2);
    // enqueue(50, &q2);
    // enqueue(60, &q2);
    // enqueue(70, &q2);
    // displaylinkedQueue(&q2);

    // printf("\n=== Testing front ===\n");
    // printf("Front element = %d\n", front(&q2));
    // printf("\n=== Testing rear ===\n");
    // printf("Rear element = %d\n", rear(&q2));

    // printf("\n=== Testing dequeue ===\n");
    // printf("Dequeued = %d\n", dequeue(&q2));
    // displaylinkedQueue(&q2);

    // printf("\n=== Testing traverse ===\n");
    // traverselinkedQueue(&q2, printValue);

    // printf("\n=== Testing clearQueue ===\n");
    // clearlinkedQueue(&q2);
    // displaylinkedQueue(&q2);

    return 0;
}
