#include <stdio.h>
#include "tree.h"
void printNode(int *x)
{
    printf("%d  ", *x);
}
int main()
{
    tree *t = create();
    insert(&t, 45);
    insert(&t, 15);
    insert(&t, 79);
    insert(&t, 90);
    insert(&t, 10);
    insert(&t, 55);
    insert(&t, 12);
    insert(&t, 20);
    insert(&t, 50);
    printf("Preorder: ");
    Preorder(t, printNode);
    printf("\n");

    printf("Inorder: ");
    Inorder(t, printNode);
    printf("\n");

    printf("Postorder: ");
    Postorder(t, printNode);
    printf("\n");

    if (search(t, 40))
        printf("40 Found!\n");
    else
        printf("40 Not Found!\n");

    printf("Min = %d\n", findMin(t)->data);
    printf("Max = %d\n", findMax(t)->data);

    printf("Leaves = %d\n", countLeaves(t));
    printf("Internal Nodes = %d\n", countInternalNodes(t));

    printf("Size = %d\n", size(t));
    printf("Height = %d\n", height(t));

    t = deleteNode(t, 10);
    printf("Inorder after deleting 10: ");
    Inorder(t, printNode);
    printf("\n");

    clear(&t);

    printf("Size = %d\n", size(t));
    printf("Height = %d\n", height(t));
    return 0;
}