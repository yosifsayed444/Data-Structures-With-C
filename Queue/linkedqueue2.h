#include <stdio.h>
#include <stdlib.h>
typedef int type;

typedef struct node
{
    type value;
    struct node *next;
} node;

typedef struct
{
    node *head;
} Queue;

void createQueue(Queue *q)
{
    q->head = NULL;
}

int isqueueEmpty(Queue q)
{
    return (q.head == NULL);
}

void enqueue(Queue *q, type item)  //insert last  at tail
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = item;
    newNode->next = NULL;

    if (isqueueEmpty(*q))
    {
        q->head = newNode; 
    }
    else
    {
        node *temp = q->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode; 
    }
}

type dequeue(Queue *q)   //delete first
{
    if (isqueueEmpty(*q))
    {
        printf("Queue is empty!\n");
        exit(1);
    }

    node *temp = q->head;
    type item = temp->value;

    q->head = q->head->next; 
    free(temp);

    return item;
}
