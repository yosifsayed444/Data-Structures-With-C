#include <stdio.h>
#include <stdlib.h>
#include "linkedStack2.h"
typedef int type;
typedef struct node
{
    type value;
    struct node *next;
} node;
typedef struct linkedlist
{
    node *head;
} linkedlist;

void createList(linkedlist *l)
{
    l->head = NULL;
}
int isEmpty(linkedlist *l)
{
    return l->head == NULL;
}
void insertNode(int pos, type data, linkedlist *l)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    if (pos == 0)
    {
        newNode->next = l->head;
        l->head = newNode;
    }
    else
    {
        node *temp = l->head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
type retrieveList(linkedlist *l, int pos)
{
    type item;
    node *temp = l->head;
    node *prev = NULL;
    if (pos == 0)
    {
        l->head = l->head->next;
        item = temp->value;
        free(temp);
        return item;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        item = temp->value;
        free(temp);
        return item;
    }
}
void clearList(linkedlist *l)
{
    node *temp = l->head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(temp);
    }
}
void displayLinkedlist(linkedlist *l){
    node *temp = l->head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
void reverseLinkedlist(linkedlist *l){
    Stack s;
    createStack(&s);
    node *temp = l->head;
    while (temp != NULL)
    {
        push(temp->value, &s);
        temp = temp->next;
    }
    while (!isstackempty(s))
    {
        type item = pop(&s);
        printf("%d ", item);
    }
}