#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct node
{
    type value;
    struct node *next;
} node;

typedef struct circularLinkedList
{
    node *head;
    node *tail;
    int size;
} circularLinkedList;

node *createNode(type data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void createCircularLinkedList(circularLinkedList *l)
{
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

int isEmpty(circularLinkedList *l)
{
    return l->head == NULL;
}
int isFull(circularLinkedList *l)
{
    return 0;
}

void insertNodeAtPosition(int pos, type data, circularLinkedList *l)
{
    if (pos < 0 || pos > l->size)
    {
        printf("Position out of range\n");
        return;
    }

    node *newNode = createNode(data);

    if (isEmpty(l))
    {
        newNode->next = newNode;
        l->head = l->tail = newNode;
    }
    else if (pos == 0)
    {
        newNode->next = l->head;
        l->head = newNode;
        l->tail->next = l->head;
    }
    else if (pos == l->size)
    {
        l->tail->next = newNode;
        newNode->next = l->head;
        l->tail = newNode;
    }
    else
    {
        node *temp = l->head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    l->size++;
}

type retrieveAtPosition(circularLinkedList *l, int pos)
{
    if (isEmpty(l) || pos < 0 || pos >= l->size)
    {
        printf("Position out of range or list empty\n");
        return -1;
    }

    node *temp = l->head;
    type item;

    if (pos == 0)
    {
        item = temp->value;
        if (l->size == 1)
        {
            free(temp);
            l->head = l->tail = NULL;
        }
        else
        {
            l->head = temp->next;
            l->tail->next = l->head;
            free(temp);
        }
    }
    else
    {
        node *prev = NULL;
        for (int i = 0; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == l->tail)
            l->tail = prev;
        item = temp->value;
        free(temp);
    }

    l->size--;
    return item;
}

void clearList(circularLinkedList *l)
{
    if (isEmpty(l))
        return;

    node *temp = l->head;
    node *nextNode;
    do
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != l->head);

    l->head = l->tail = NULL;
    l->size = 0;
}

void displayList(circularLinkedList *l)
{
    if (isEmpty(l))
    {
        printf("List is empty\n");
        return;
    }

    node *temp = l->head;
    do
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    } while (temp != l->head);
    printf("(head)\n");
}

void traverseCircularLinkedList(circularLinkedList *l, void (*func)(type *))
{
    if (isEmpty(l))
        return;
    node *temp = l->head;
    do
    {
        func(&temp->value);
        temp = temp->next;
    } while (temp != l->head);
}
