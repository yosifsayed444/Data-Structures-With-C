#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct node {
    type value;
    struct node *next;
} node;

typedef node* StackList;

void createStack(StackList *s) {
    *s = NULL;
}

int isEmpty(StackList *s) {
    return *s == NULL;
}

void push(StackList *s, type data) {
    node *newNode = (node *) malloc(sizeof(node));
    if (!newNode) return;
    newNode->value = data;
    newNode->next = *s;
    *s = newNode;
}

type pop(StackList *s) {
    if (isEmpty(s)) {
        printf("Stack empty\n");
        return -1;
    }

    node *temp = *s;
    type val = temp->value;
    *s = temp->next;
    free(temp);
    return val;
}

void displayStack(StackList *s) {
    node *temp = *s;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    StackList s;
    createStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    displayStack(&s);
    return 0;
}
