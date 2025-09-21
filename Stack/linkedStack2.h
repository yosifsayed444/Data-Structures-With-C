#include <stdlib.h>
#include <stdio.h>
typedef int type;
typedef struct node
{
    type value;
    struct node *next;
} node;
typedef struct
{
    node *head;
} Stack;
void createStack(Stack *s)
{
    s->head = NULL;
}
int isstackempty(Stack s)
{
    return s.head == NULL;
}
void push(type item, Stack *s)  //insert first
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = item;
    newNode->next = s->head;
    s->head = newNode;
}
type pop(Stack *s)  //delete last e
{ 
    type item;
    node *temp = s->head;
    s->head = s->head->next;
    item = temp->value;
    free(temp);
    return item;
}
type peek(Stack s)
{
    return s.head->value;
}