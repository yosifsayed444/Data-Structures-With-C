#include <stdio.h>
//#include "linkedQueue1.h"
#include "linkedQueue2.h"

void print(type *x)
{
    printf("Value: %d ", *x);
}

int main()
{
    // linkedQueue1 q1;
    // createlinkedQueue1(&q1);

    // printf("============= Testing LinkedQueue1 ============\n");

    // printf("=== Testing enqueue ===\n");
    // enqueue1(10, &q1);
    // enqueue1(20, &q1);
    // enqueue1(30, &q1);
    // enqueue1(40, &q1);
    // enqueue1(50, &q1);
    // enqueue1(60, &q1);
    // enqueue1(70, &q1);
    // displaylinkedQueue1(&q1);

    // printf("\n=== Testing front ===\n");
    // printf("Front element = %d\n", front1(&q1));

    // printf("\n=== Testing rear ===\n");
    // printf("Rear element = %d\n", rear1(&q1));

    // printf("\n=== Testing dequeue ===\n");
    // type removed = dequeue1(&q1);
    // printf("Dequeued = %d\n", removed);
    // displaylinkedQueue1(&q1);

    // printf("\n=== Testing traverse ===\n");
    // traverselinkedQueue1(&q1, print);

    // printf("\n=== Testing clearQueue ===\n");
    // clearlinkedQueue1(&q1);
    // displaylinkedQueue1(&q1);

    // Uncomment to test second Queue implementation
    
    printf("\n============= Testing LinkedQueue2 ============\n");
    linkedQueue2 q2;
    createLinkedQueue(&q2);

    printf("=== Testing enqueue ===\n");
    enqueue(10, &q2);
    enqueue(20, &q2);
    enqueue(30, &q2);
    enqueue(40, &q2);
    enqueue(50, &q2);
    enqueue(60, &q2);
    enqueue(70, &q2);
    displaylinkedQueue(&q2);

    printf("\n=== Testing front ===\n");
    printf("Front element = %d\n", front(&q2));
    printf("\n=== Testing rear ===\n");
    printf("Rear element = %d\n", rear(&q2));

    printf("\n=== Testing dequeue ===\n");
    printf("Dequeued = %d\n", dequeue(&q2));
    displaylinkedQueue(&q2);

    printf("\n=== Testing traverse ===\n");
    traverselinkedQueue(&q2, print);

    printf("\n=== Testing clearQueue ===\n");
    clearlinkedQueue(&q2);
    displaylinkedQueue(&q2);
    

    return 0;
}
