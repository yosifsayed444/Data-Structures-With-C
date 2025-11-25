#include <stdio.h>
#include <stdlib.h>

typedef int typeL;
typedef struct node
{
    typeL value;
    struct node *next;
} node;
typedef struct linkedlist
{
    node *head;
    int size;
} linkedlist;

node *createNode(typeL data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void createList(linkedlist *l)
{
    l->head = NULL;
    l->size = 0;
}

int isEmpty(linkedlist *l)
{
    return l->head == NULL;
}

int isFull(linkedlist *l)
{
    return 0;
}
void insertNodeAtPosition(int pos, int value,linkedlist *l)
{
    node *newNode = createNode(value);

    if (l->head == NULL)
    {
        l->head = newNode;
        l->head->next = NULL;
        l->size++;
        return;
    }
    node *temp = l->head;
    if (pos == 0)
    {
        newNode->next = temp;
        l->head = newNode;
        l->size++;
        return;
    }

    for (int i = 0; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {

        temp->next = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    l->size++;
}
typeL retrieveAtPosition(linkedlist *l, int pos)
{
    if (isEmpty(l))
    {
        printf("List is empty\n");
        return -1;
    }

    node *temp = l->head;
    typeL item;

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
void clearList(linkedlist *l)
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
void traverseLinkedlist(linkedlist *l, void (*func)(typeL *))
{
    node *temp = l->head;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}
