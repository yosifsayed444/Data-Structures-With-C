#ifndef STACK_H
#define STACK_H
typedef int Type;
typedef struct NodeT {
    Type data;
    struct Node* next;
} Node;


typedef struct stack{
   Node* top;
}Stack;

void createStack(Stack *stack);
int isStackEmpty(Stack stack);
int isStackFull(Stack stack);
void push(Stack *stack, Type value);
Type pop(Stack *stack);
Type peek(Stack stack);
void displayStack(Stack stack);
void clearStack(Stack *s);

#endif  /* STACK_H */
