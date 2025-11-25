#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef struct DoublySortedLinkedList
{
    node *head;
    int size;
} DoublySortedLinkedList;

void CreateDoublySortedLinkedList(DoublySortedLinkedList *l)
{
    l->head = NULL;
    l->size = 0;
}

node *createNode(int key, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int isEmpty(DoublySortedLinkedList *l)
{
    return l->head == NULL;
}

int getSize(DoublySortedLinkedList *l)
{
    return l->size;
}
int isFull(DoublySortedLinkedList *l)
{
    return 0;
}

void insertUniquelySortedByKey(DoublySortedLinkedList *l, int key, int value)
{
    node *curr = l->head;
    while (curr != NULL)
    {
        if (curr->value == value)
        {
            return;
        }
        else if (curr->key == key)
        {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
    node *newNode = createNode(key, value);
    if (l->head == NULL)
    {
        l->head = newNode;
        l->size++;
        return;
    }

    node *temp = l->head;
    if (key < temp->key)
    {
        newNode->next = temp;
        temp->prev = newNode;
        l->head = newNode;
        l->size++;
        return;
    }

    while (temp->next != NULL && temp->next->key < key)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    l->size++;
}

int retrieveByKey(DoublySortedLinkedList *l, int key)
{
    if (l->head == NULL)
        return -999;

    node *temp = l->head;

    while (temp != NULL && temp->key != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return -999;

    int value = temp->value;

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

void traverseListforward(DoublySortedLinkedList *l, void (*func)(int, int))
{
    node *temp = l->head;
    while (temp != NULL)
    {
        func(temp->key, temp->value);
        temp = temp->next;
    }
}

void traverseListbackward(DoublySortedLinkedList *l, void (*func)(int, int))
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
        func(temp->key, temp->value);
        temp = temp->prev;
    }
}
void freeList(DoublySortedLinkedList *l)
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
int search(DoublySortedLinkedList *l, int key)
{
    node *temp = l->head;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}