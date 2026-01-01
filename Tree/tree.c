#include <stdio.h>
#include "Binary_Search_Tree.h"
void printNode(int *x)
{
    printf("%d  ", *x);
}
int main()
{
    Tree t;
    createTree(&t);

    insertItereative(&t, 20);
    insertItereative(&t, 25);
    insertItereative(&t, 10);
    insertItereative(&t, 30);
    insertItereative(&t, 28);
    insertItereative(&t, 34);
    insertItereative(&t, 59);
    insertItereative(&t, 39);
    insertItereative(&t, 22);
    insertItereative(&t, 11);
    insertItereative(&t, 33);
    insertRecursive(&t, 17);
    insertRecursive(&t, 18);
    insertRecursive(&t, 67);
    insertRecursive(&t, 21);
    printf("Inorder: ");
    Inorder(t, printNode);
    printf("\n");

    printf("Preorder: ");
    Preorder(t, printNode);
    printf("\n");

    printf("Postorder: ");
    Postorder(t, printNode);
    printf("\n");

    printf("Size = %d\n", countNodes(t));
    printf("Height = %d\n", height(t));

    int key = 32;
    if (search(t, key))
        printf("%d Found!\n", key);
    else
        printf("%d Not Found!\n", key);

    int min = findMin(t);
    int max = findMax(t);

    printf("Min = %d\n", min);
    printf("Max = %d\n", max);

    printf("Leaves = %d\n", countLeaves(t));
    printf("Internal Nodes = %d\n", countInternalNodes(t));

    printf("sum = %d\n", sumNodes(t));

    Delete(&t, 25);
    Delete(&t, 20);

    printf("Inorder after deletion: ");
    Inorder(t, printNode);
    printf("\n");
    printf("Size = %d\n", size(t));
    printf("Height = %d\n", height(t));

    clear(&t);

    printf("Size = %d\n", size(t));
    printf("Height = %d\n", height(t));
    return 0;
}