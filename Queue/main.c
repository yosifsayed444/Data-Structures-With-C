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
    dequeue(&q);
    traverseQueue(&q,print) ;

}