#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef struct DoublyLinkedList
{
    node *head;
    int size;
} DoublyLinkedList;

void CreateDoublyLinkedList(DoublyLinkedList *l)
{
    l->head = NULL;
    l->size = 0;
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int isEmpty(DoublyLinkedList *l)
{
    return l->head == NULL;
}

int getSize(DoublyLinkedList *l)
{
    return l->size;
}
int isFull(DoublyLinkedList *l)
{
    return 0;
}

void insertAtPosition(DoublyLinkedList *l, int value, int pos)
{
    if (pos < 0 || pos > l->size)
    {
        printf("Position out of range\n");
        return;
    }

    node *newNode = createNode(value);

    if (l->head == NULL)
    {
        l->head = newNode;
    }
    else if (pos == 0)
    {
        newNode->next = l->head;
        l->head->prev = newNode;
        l->head = newNode;
    }
    else if (pos == l->size)
    {
        node *temp = l->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    else // إدخال في المنتصف
    {
        node *temp = l->head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    l->size++;
}

type RetrieveAtPosition(DoublyLinkedList *l, int pos)
{
    if (pos < 0 || pos >= l->size)
    {
        printf("Position out of range\n");
        return -999;
    }

    if (l->head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    node *temp = l->head;

    for (int i = 0; i < pos; i++)
        temp = temp->next;

    type value = temp->value;

    if (temp->prev == NULL)
    {
        l->head = temp->next;
        if (l->head != NULL)
            l->head->prev = NULL;
    }
    else if (temp->next == NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    l->size--;
    return value;
}

void traverseListforward(DoublyLinkedList *l, void (*func)(int))
{
    node *temp = l->head;
    while (temp != NULL)
    {
        func(temp->value);
        temp = temp->next;
    }
}

void traverseListbackward(DoublyLinkedList *l, void (*func)(int))
{
    node *temp = l->head;
    if (temp == NULL)
        return;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        func(temp->value);
        temp = temp->prev;
    }
}

void freeList(DoublyLinkedList *l)
{
    node *temp = l->head;

    while (temp != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    l->head = NULL;
    l->size = 0;
}