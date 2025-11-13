#include <stdio.h>
#include "stack.h"

void createStack(Stack *stack) {
//    (*STACK).DATA=-1
    stack->top = -1;
}

int isStackEmpty(Stack stack) {
    return stack.top == -1;
}

int isStackFull(Stack stack) {
    return stack.top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, Type value) {
    if (isStackFull(*stack)) {
        printf("Stack overflow. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

Type pop(Stack *stack) {
    if (isStackEmpty(*stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }

    Type value = stack->data[stack->top--];
    return value;
}

Type peek(Stack stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack.data[stack.top];
}

void displayStack(Stack stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.data[i]);
    }
}
