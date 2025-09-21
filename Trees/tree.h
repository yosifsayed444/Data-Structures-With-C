#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree;

tree *CreateNewnode(int item)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
tree *create()
{
    return NULL;
}
int isEmpty(tree *t)
{
    return t == NULL;
}

void Inorder(tree *t, void (*pvisit)(int *))
{
    if (t)
    {
        Inorder(t->left, pvisit);
        (*pvisit)(&(t->data));
        Inorder(t->right, pvisit);
    }
}

void Preorder(tree *t, void (*pvisit)(int *))
{
    if (t)
    {
        (*pvisit)(&(t->data));
        Preorder(t->left, pvisit);
        Preorder(t->right, pvisit);
    }
}

void Postorder(tree *t, void (*pvisit)(int *))
{
    if (t)
    {
        Postorder(t->left, pvisit);
        Postorder(t->right, pvisit);
        (*pvisit)(&(t->data));
    }
}

int size(tree *t)
{
    if (t)
    {
        return 1 + size(t->left) + size(t->right);
    }
    return 0;
}

int height(tree *t)
{
    if (t)
    {
        int a = height(t->left);
        int b = height(t->right);
        return (a > b ? a : b) + 1;
    }
    return 0;
}

void clear(tree **t)
{
    if (*t == NULL)
        return;

    clear(&((*t)->left));
    clear(&((*t)->right));

    free(*t);
    *t = NULL;
}
void insert(tree **t, int item)
{
    if (*t == NULL)
    {
        *t = CreateNewnode(item);
    }
    else if (item < (*t)->data)
    {
        insert(&((*t)->left), item);
    }
    else
    {
        insert(&((*t)->right), item);
    }
}
tree *search(tree *t, int key)
{
    if (t == NULL)
        return NULL;
    if (t->data == key)
        return t;
    if (key < t->data)
        return search(t->left, key);
    else
        return search(t->right, key);
}
tree *findMin(tree *t)
{
    if (t == NULL)
        return NULL;

    while (t && t->left != NULL)
        t = t->left;
    return t;
}

tree *findMax(tree *t)
{
    if (t == NULL)
        return NULL;
    while (t && t->right != NULL)
        t = t->right;
    return t;
}

// delete node
tree *deleteNode(tree *t, int key)
{
    if (t == NULL)
        return NULL;

    if (key < t->data)
        t->left = deleteNode(t->left, key);
    else if (key > t->data)
        t->right = deleteNode(t->right, key);
    else
    {
        // node with no child
        if (t->left == NULL && t->right == NULL)
        {
            free(t);
            return NULL;
        }
        // node with one child (right only)
        else if (t->left == NULL)
        {
            tree *temp = t->right;
            free(t);
            return temp;
        }
        // node with one child (left only)
        else if (t->right == NULL)
        {
            tree *temp = t->left;
            free(t);
            return temp;
        }
        // node with two children
        else
        {
            tree *temp = findMin(t->right);
            t->data = temp->data;
            t->right = deleteNode(t->right, temp->data);
        }
    }
    return t;
}
int countLeaves(tree *t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;
    return countLeaves(t->left) + countLeaves(t->right);
}

int countInternalNodes(tree *t)
{
    return size(t) - countLeaves(t);
}
