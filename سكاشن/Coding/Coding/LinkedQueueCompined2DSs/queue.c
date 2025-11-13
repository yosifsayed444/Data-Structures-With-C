#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *queue)
{
    createLinkedList(&queue->list);
}

int isQueueEmpty(Queue queue)
{
    return isLinkedListEmpty(queue.list);
}

int isQueueFull(Queue queue)
{
    return isLinkedListFull(queue.list);
}

void enqueue(Queue *queue, Type value)
{
    if (isQueueFull(*queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else
    {
        insertElement(&queue->list, value, queue->list.size);
    }

}

Type dequeue(Queue *queue)
{
    Type value;

    if (isQueueEmpty(*queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else
    {
        value=retrieveElement(&queue->list,0);
        return value;
    }


}



Type GetFirstElement(Queue queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot retrieve the front element.\n");
        return (Type)-1;
    } else {
        return queue.list.head->data;
    }
}
