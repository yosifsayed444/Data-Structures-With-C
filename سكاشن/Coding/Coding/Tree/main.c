#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Utility.h"

int mainBT()
{
    TreeType myTree;
    CreateTree(&myTree);
    treeNode node1 = {1, NULL, NULL};
    treeNode node2 = {2, NULL, NULL};
    treeNode node3 = {3, NULL, NULL};
    treeNode node4 = {4, NULL, NULL};
    treeNode node5 = {5, NULL, NULL};
    myTree = &node1;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    printf("Preorder traversal: ");
    Preorder(myTree, print);
    printf("\n");

    printf("Inorder traversal: ");
    Inorder(myTree, print);
    printf("\n");

    printf("Postorder traversal: ");
    Postorder(myTree, print);
    printf("\n");

    printf("Size:%d ",Size(myTree));
    printf("\n");

    printf("Height:%d ",Height(myTree));
    printf("\n");
    return 0;
}


