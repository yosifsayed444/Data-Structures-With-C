#include <stdio.h>
#include "linkedStack1.h"
//#include "linkedStack2.h"

// Function used with traverse
void print(type *x)
{
    printf("Value: %d ", *x);
}

int main()
{
    StackList1 s1;
    createStack1(&s1);
    printf("============= Testing StackList1 ============\n");
    printf("=== Testing push ===\n");
    push1(10, &s1);
    push1(20, &s1);
    push1(30, &s1);
    push1(40, &s1);
    push1(50, &s1);
    push1(60, &s1);
    push1(70, &s1);
    displayStack1(&s1);
    printf("\n=== Testing peek ===\n");
    printf("Top element = %d\n", peek1(&s1));

    printf("\n=== Testing pop ===\n");
    printf("Popped = %d\n", pop1(&s1));
    displayStack1(&s1);

    printf("\n=== Testing traverse ===\n");
    traverseStackList1(&s1, print);

    printf("\n=== Testing clearStack ===\n");
    clearStack1(&s1);
    displayStack1(&s1);
    // printf("\n============= Testing StackList2 ============\n");  
    // StackList2 s2;
    // createStack(&s2);
    // printf("=== Testing push ===\n");
    // push(10, &s2);
    // push(20, &s2);
    // push(30, &s2);
    // push(40, &s2);
    // push(50, &s2);
    // push(60, &s2);
    // push(70, &s2);
    // displayStack(&s2);
    // printf("\n=== Testing peek ===\n");
    // printf("Top element = %d\n", peek(&s2));

    // printf("\n=== Testing pop ===\n");
    // printf("Popped = %d\n", pop(&s2));
    // displayStack(&s2);

    // printf("\n=== Testing traverse ===\n");
    // traverseStackList(&s2, print);

    // printf("\n=== Testing clearStack ===\n");
    // clearStack(&s2);
    // displayStack(&s2);
    // return 0;
}
