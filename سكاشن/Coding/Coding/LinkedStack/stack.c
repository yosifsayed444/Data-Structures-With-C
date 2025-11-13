#include <stdio.h>
#include "stack.h"

void createStack(Stack *stack)
{
    stack->top=NULL;
}

int isStackEmpty(Stack stack)
{
    return stack.top==NULL;
}

int isStackFull(Stack stack)
{
    return 0;
}

void push(Stack *stack, Type value)
{
    if (isStackFull(*stack))
    {
        printf("Stack overflow. Cannot push.\n");
        return;
    }
      Node *newNode = (Node*)malloc(sizeof(Node));
      newNode->data=value;
      newNode->next=stack->top;
      stack->top=newNode;

}

Type pop(Stack *stack)
{
    if (isStackEmpty(*stack))
    {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }
    Node* temp=stack->top;
    Type item=temp->data;
    stack->top=stack->top->next;
    free(temp);
    return item;
}

Type peek(Stack stack)
{
    return stack.top->data;
}
void displayStack(Stack stack)
{
    if (isStackEmpty(stack))
    {
        printf("null\n");
        return;
    }

    Node* current = stack.top;
    while (current != NULL)
    {
        printf("%d >> ",current->data);
        current = current->next;
    }

}
void clearStack(Stack *s){
    Node* temp;
    while (s->top!=NULL)
    {
        temp = s->top;
        printf("Item deleted %d",s->top->data);
        s->top = temp->next;
        free(temp);
    }
 }
