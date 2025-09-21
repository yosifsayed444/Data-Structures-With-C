#include <stdlib.h>
#include <stdio.h>
typedef int type;
typedef struct nodeS
{
    type value;
    struct nodeS *next;
} nodeS;
typedef struct
{
    nodeS *head;
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
    nodeS *newNode = (nodeS *)malloc(sizeof(nodeS));
    newNode->value = item;
    newNode->next = s->head;
    s->head = newNode;
}
type pop(Stack *s)  //delete last e
{ 
    type item;
    nodeS *temp = s->head;
    s->head = s->head->next;
    item = temp->value;
    free(temp);
    return item;
}
type peek(Stack s)
{
    return s.head->value;
}