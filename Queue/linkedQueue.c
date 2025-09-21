//#include"linkedqueue.h"
#include"linkedqueue2.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    while(!isqueueEmpty(q)){
        printf("%d\n",dequeue(&q));
    }
}