#include <stdio.h>
#include "stack.h" 

void printItem(int *x)
{
    printf("%d ", *x);
}

int main()
{
    Stack s1, s2, merged;
    createStack(&s1);
    createStack(&s2);

    printf("=== Push & Print ===\n");
    for (int i = 1; i <= 5; i++)
        push(i, &s1);
    printStack(s1);

    printf("\n=== Copy Stack ===\n");
    copyStack(s1, &s2);
    printStack(s2);

    printf("\n=== Reverse Stack ===\n");
    reverseStack(&s1);
    printStack(s1);

    printf("\n=== Sort Stack ===\n");
    push(9, &s1);
    push(3, &s1);
    push(7, &s1);
    printStack(s1);
    SortStack(&s1);
    printStack(s1);

    printf("\n=== Check if Equal ===\n");
    printf(isStackEqual(s1, s2) ? "Equal\n" : "Not Equal\n");

    printf("\n=== Search for element 3 ===\n");
    int pos = searchStack(s1, 3);
    if (pos != -1)
        printf("Found 3 at index %d\n", pos);
    else
        printf("3 not found\n");

    printf("\n=== Max & Min ===\n");
    printf("Max = %d\n", maxInStack(s1));
    printf("Min = %d\n", minInStack(s1));

    printf("\n=== Traverse Stack (apply function to each element) ===\n");
    traverseStack(s1, printItem);
    printf("\n");

    printf("\n=== Merge Two Stacks ===\n");
    merged = mergeStacks(s1, s2);
    printStack(merged);

    printf("\n=== Size of Stack ===\n");
    printf("s1 size = %d\n", size(s1));

    printf("\n=== Peek Top & Bottom ===\n");
    printf("Top = %d\n", peekTop(s1));
    printf("Bottom = %d\n", peekBottom(s1));

    printf("\n=== Destroy Stack ===\n");
    distroyStack(&s1);
    printf("s1 size after destroy = %d\n", size(s1));

    printf("\n=== All Tests Done Successfully ===\n");

    return 0;
}
