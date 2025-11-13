#include <stdio.h>
#include "Queue.h"

void print(int *item){
    printf("%d\n", *item);
}
void increment(int *item){
    (*item)++;
}

int main(){
    Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 70);
    enqueue(&q, 20);

    Queue q2;
    createQueue(&q2);
    enqueue(&q2, 10);
    enqueue(&q2, 20);
    enqueue(&q2, 30);
    enqueue(&q2, 70);
    enqueue(&q2, 20);

    Queue q3 = MergeQueue(q, q2);
    traverseQueue(&q3, print);
   

}