#include <stdio.h>
#include <stdlib.h>
#include "global.h"
node *createNode(type data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void createList(StackList1 *l)
{
    l->head = NULL;
    l->size = 0;
}

int isEmpty(StackList1 *l)
{
    return l->head == NULL;
}

int isFull(StackList1 *l)
{
    return 0;
}

void insertNodeAtPosition(int pos, type data, StackList1 *l)
{
    node *newNode = createNode(data);
    if (l->head == NULL || pos == 0)
    {
        newNode->next = l->head;
        l->head = newNode;
    }
    else
    {
        node *temp = l->head;
        for (int i = 0; i < pos - 1 && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    l->size++;
}

void insertNodeintoTail(int data, StackList1 *l)
{
    node *newNode = createNode(data);
    if (l->head == NULL)
    {
        l->head = newNode;
    }
    else
    {
        node *temp = l->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    l->size++;
}

type retrieveAtPosition(StackList1 *l, int pos)
{
    if (isEmpty(l))
    {
        printf("List is empty\n");
        return -1;
    }

    node *temp = l->head;
    type item;

    if (pos == 0)
    {
        l->head = l->head->next;
        item = temp->value;
        free(temp);
    }
    else
    {
        node *prev = NULL;
        for (int i = 0; i < pos && temp->next != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL)
            prev->next = temp->next;
        item = temp->value;
        free(temp);
    }

    l->size--;
    return item;
}

type retrieveTail(StackList1 *l)
{
    if (isEmpty(l))
    {
        printf("List is empty\n");
        return -1;
    }

    node *temp = l->head;
    type item;

    if (temp->next == NULL) // only one node
    {
        item = temp->value;
        free(temp);
        l->head = NULL;
    }
    else
    {
        node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        item = temp->value;
        free(temp);
        prev->next = NULL;
    }

    l->size--;
    return item;
}

void clearList(StackList1 *l)
{
    node *temp;
    while (temp != NULL)
    {
        temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
    l->head = NULL;
    l->size = 0;
}

void displayStackList1(StackList1 *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }

    else
    {
        node *temp = s->head;
        while (temp != NULL)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}
void traverseStackList(StackList1 *l, void (*func)(type *))
{
    node *temp = l->head;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}
