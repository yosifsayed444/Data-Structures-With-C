#ifndef STACK_H
#define STACK_H
#include "linkedList.h"
#define MAX_STACK_SIZE 100

typedef int Type;
typedef struct stack{
    LinkedList list
}Stack;

void createStack(Stack *stack);
int isStackEmpty(Stack stack);
int isStackFull(Stack stack);
void push(Stack *stack, Type value);
Type pop(Stack *stack);
Type peek(Stack stack);
void displayStack(Stack stack);

#endif  /* STACK_H */
