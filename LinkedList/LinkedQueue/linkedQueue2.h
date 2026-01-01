#include <stdio.h>
#include <stdlib.h>
typedef int type;
typedef struct node
{
    type value;
    struct node *next;
} node;
typedef struct linkedQueue2
{
    int data;
    node *rear;
    node *front;
    int size;
} linkedQueue2;

node *createNode(type data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void createLinkedQueue(linkedQueue2 *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(linkedQueue2 *q)
{
    return q->front == NULL;
}

int isFull(linkedQueue2 *q)
{
    return 0;
}

void enqueue(type data, linkedQueue2 *q)
{
    node *newNode = createNode(data);
    if (!q->rear)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

type dequeue(linkedQueue2 *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    if (q->front == q->rear)
    {
        type item = q->front->value;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        q->size = 0;
        return item;
    }
    else
    {
        node *temp = q->front;
        type item;
        q->front = q->front->next;
        item = temp->value;
        free(temp);
        q->size--;
        return item;
    }
}
void clearlinkedQueue(linkedQueue2 *l)
{
    node *temp;
    while (temp != NULL)
    {
        temp = l->front;
        l->front = l->front->next;
        free(temp);
    }
    l->front = NULL;
    l->rear = NULL;
    l->size = 0;
}

void displaylinkedQueue(linkedQueue2 *l)
{
    node *temp = l->front;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    if (isEmpty(l))
        printf("QueuelinkedQueue is empty\n");
}
void traverselinkedQueue(linkedQueue2 *l, void (*func)(type *))
{
    node *temp = l->front;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}
type front(linkedQueue2 *l)
{
    if (isEmpty(l))
    {
        printf("QueuelinkedQueue is empty\n");
        return -1;
    }
    return l->front->value;
}
type rear(linkedQueue2 *l)
{
    if (isEmpty(l))
    {
        printf("linkedQueue is empty\n");
        return -1;
    }
    return l->rear->value;
}
void searchAndMoveToFront(linkedQueue2 *q, int x)
{
    if (!q->front || q->front->value == x)
        return;
    node *prev = q->front, *cur = q->front->next;
    while (cur)
    {
        if (cur->value == x)
        {
            prev->next = cur->next;
            cur->next = q->front;
            q->front = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
void EnqueuePositive_Negative(linkedQueue2 *q, int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->next = NULL;
    p->value = x;
    if (!q->rear)
    {
        q->front = p;
        q->rear = p;
    }
    else
    {
        if (x < 0)
        {
            q->rear->next = p;
            q->rear = p;
        }
        else
        {
            p->next = q->front;
            q->front = p;
        }
    }
}
int searchAndDelete(linkedQueue2 *q, int x)
{
    if (!q->front || q->front->value == x)
        return;
    node *prev = NULL, *cur = q->front;
    while (cur && cur->value != x)
    {
        prev = cur;
        cur = cur->next;
    }
    if (!prev)
        q->front = cur->next;
    else
        prev->next = cur->next;
    free(cur);
    return 1;
}
void removeDuplicates(linkedQueue2 *q)
{
    if (!q->front)
        return;
    node *prev = NULL, *cur = q->front;

    while (cur)
    {
        if (cur->value == cur->next->value)
        {
            node *temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }

        prev = cur;
        cur = cur->next;
    }
}
void reverseQueue(linkedQueue2 *q) {
    node *prev = NULL;
    node *curr = q->front;
    node *next;

    q->rear = q->front;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    q->front = prev;
}
