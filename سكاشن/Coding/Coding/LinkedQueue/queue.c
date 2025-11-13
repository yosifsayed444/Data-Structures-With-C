#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *queue)
{
    queue->front=NULL;
    queue->rear=NULL;
}

int isQueueEmpty(Queue queue)
{
    return queue.front==NULL;
}

int isQueueFull(Queue queue)
{
    return 0;
}

void enqueue(Queue *queue, Type value)
{
     Node *newNode = (Node*)malloc(sizeof(Node));
     newNode->data=value;
     newNode->next=NULL;
     if(queue->rear==NULL){
        queue->front=newNode;
        queue->rear=newNode;
     }else{
         queue->rear->next=newNode;
         queue->rear=newNode;
     }
}

Type dequeue(Queue *queue)
{
    Type value;

    if (isQueueEmpty(*queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return (Type)-1;
    }
    else
    {
       Node* temp=queue->front;
       queue->front=queue->front->next;
       value=temp->data;
       free(temp);
       if(queue->front==NULL){
        queue->rear=NULL;
       }
       return value;
    }



}



Type GetFirstElement(Queue queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot retrieve the front element.\n");
        return (Type)-1;
    } else {
        return queue.front->data;
    }
}
