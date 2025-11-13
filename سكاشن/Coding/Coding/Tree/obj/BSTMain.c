#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Utility.h"

int main()
{
    TreeType myTree;
    CreateTree(&myTree);
    insertEle(&myTree,1);
    insertEle(&myTree,2);
    insertEle(&myTree,3);
    insertEle(&myTree,4);
    insertEle(&myTree,5);

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
    int k=5;
    printf("Found and delete:%d \n",Delete(&myTree,k));
    printf("Inorder traversal After Delete: ");
    Inorder(myTree, print);
    printf("\n");
    return 0;
}
