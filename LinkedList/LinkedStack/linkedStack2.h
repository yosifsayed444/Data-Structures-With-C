#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct node
{
    type value;
    struct node *next;
} node;
typedef struct StackList2
{
    node *top;
    int size;
} StackList2;

node *createNode(type data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void createStack(StackList2 *s)
{
    s->top = NULL;
    s->size = 0;
}

int isEmpty(StackList2 *s)
{
    return s->top == NULL;
}

int isFull(StackList2 *s)
{
    return 0;
}

void push(type data, StackList2 *s)
{
    node *newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}
type pop(StackList2 *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    node *temp = s->top;
    type item;
    s->top = s->top->next;
    item = temp->value;
    free(temp);
    s->size--;
    return item;
}
type peek(StackList2 *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->value;
}
void clearStack(StackList2 *s)
{
    node *temp;
    while (s->top)
    {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->top = NULL;
    s->size = 0;
}

void displayStack(StackList2 *s)
{

    if (!isEmpty(s))
    {
        node *temp = s->top;
        while (temp != NULL)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty\n");
        return;
    }
}
void traverseStackList(StackList2 *s, void (*func)(type *))
{
    node *temp = s->top;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}
