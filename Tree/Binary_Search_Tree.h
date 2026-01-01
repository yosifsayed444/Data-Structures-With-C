#include <stdio.h>
#include <stdlib.h>
typedef int Entry;
typedef struct node
{
    Entry data;
    struct node *left;
    struct node *right;
} node;

typedef node *Tree;
void createTree(Tree *t)
{
    *t = NULL;
}

int isEmpty(Tree *t)
{
    return !*t;
}
int isFull(Tree *t)
{
    return 0;
}

void Inorder(Tree t, void (*pvisit)(Entry *))
{
    if (t)
    {
        Inorder(t->left, pvisit);
        (*pvisit)(&(t->data));
        Inorder(t->right, pvisit);
    }
}

void Preorder(Tree t, void (*pvisit)(Entry *))
{
    if (t)
    {
        (*pvisit)(&(t->data));
        Preorder(t->left, pvisit);
        Preorder(t->right, pvisit);
    }
}

void Postorder(Tree t, void (*pvisit)(Entry *))
{
    if (t)
    {

        Postorder(t->left, pvisit);
        Postorder(t->right, pvisit);
        (*pvisit)(&(t)->data);
    }
}
int height(Tree t)
{
    if (t)
    {
        int a = height(t->left);
        int b = height(t->right);
        return (a > b) ? a + 1 : b + 1;
    }
    return 0;
}

void clear(Tree *t)
{
    if (*t)
    {
        clear(&((*t)->left));
        clear(&((*t)->right));
        free(*t);
        *t = NULL;
    }
}
void insertItereative(Tree *t, Entry item)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    if (!(*t))
        *t = newNode;
    else
    {
        node *pre, *cur;
        cur = *t;
        while (cur)
        {
            pre = cur;
            if (item < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (item < pre->data)
            pre->left = newNode;
        else
            pre->right = newNode;
    }
}
void insertRecursive(Tree *t, Entry item)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    if (!*t)
        *t = newNode;
    
    else if (item < (*t)->data)
        insertRecursive(&(*t)->left, item);
    else
        insertRecursive(&(*t)->right, item);
}
int search(Tree t, int key)
{
    if (!t)
        return 0;
    if (t->data == key)
        return t->data;

    if (key < t->data)
        return search(t->left, key);
    else
        return search(t->right, key);
}
int findMin(Tree t)
{
    if (t == NULL)
        return 0;

    while (t->left != NULL)
        t = t->left;

    return t->data;
}

int findMax(Tree t)
{
    if (t == NULL)
        return 0;

    while (t->right != NULL)
        t = t->right;

    return t->data;
}
int countNodes(Tree t)
{
    if (t)
        return 1 + countNodes(t->left) + countNodes(t->right);
    return 0;
}

int countLeaves(Tree t)
{
    if (!t)
        return 0;
    if (!t->left && !t->right)
        return 1;
    return countLeaves(t->left) + countLeaves(t->right);
}

int countInternalNodes(Tree t)
{
    return countNodes(t) - countLeaves(t);
}
int sumNodes(Tree t)
{
    if (!t)
        return 0;
    return t->data + sumNodes(t->left) + sumNodes(t->right);
}
void deleteSmallestNode(Tree *t)
{
    if (!*t)
        return;
    node *curr = *t;
    node *pre = NULL;

    while (curr->left)
    {
        pre = curr;
        curr = curr->left;
    }
    if (!pre)
        *t = curr->right;
    else
        pre->left = curr->right;

    free(curr);
}
void deleteLargestNode(Tree *t)
{
    if (!*t)
        return;
    node *curr = *t;
    node *pre = NULL;

    while (curr->right)
    {
        pre = curr;
        curr = curr->right;
    }
    if (!pre)
        *t = curr->left;
    else
    {
        pre->right = curr->left;
    }
    free(curr);
}
void deleteLeavesNode(Tree *t)
{

    if (!(*t))
        return;

    if (!(*t)->left && !(*t)->right)
    {
        free(*t);
        *t = NULL;
        return;
    }

    deleteLeavesNode(&(*t)->left);
    deleteLeavesNode(&(*t)->right);
}
int AreIdentical(Tree *t1, Tree *t2)
{
    if (!t1 && !t2)
        return 1;
    if (!t1 || !t2)
        return 0;
    return ((*t1)->data == (*t2)->data &&
            AreIdentical((*t1)->left, (*t2)->left) &&
            AreIdentical((*t1)->right, (*t2)->right));
}
int isBalanced(Tree t)
{
    if (!t)
        return 1;
    return (abs(height(t->left) - height(t->right)) <= 1 &&
            isBalanced(t->left) && isBalanced(t->right));
}
int CountFullNodes(Tree t)
{
    if (!t)
        return 0;
    if (t->left && t->right)
        return 1 + CountFullNodes(t->left) + CountFullNodes(t->right);
    return CountFullNodes(t->left) + CountFullNodes(t->right);
}
void DeleteNode(Tree *t)
{
    node *cur = *t;
    node *prev = NULL;
    if (!(cur)->left) // First case
        *t = cur->right;

    else if (!(cur)->right) // Second case
        *t = cur->left;

    else
    { // third case
        cur = cur->left;
        while (cur->right)
        {
            prev = cur;
            cur = cur->right;
        }
        (*t)->data = (cur)->data;
        if (prev)
            prev->right = cur->left;
        else
            (*t)->left = cur->left;
    }
    free(cur);
}
int Delete(Tree *t, Entry k)
{
    int found = 0;
    node *cur = *t;
    node *prev = NULL;
    while (cur && !(found = (k == cur->data)))
    {
        prev = cur;
        if (k < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (found)
    {   
        if (!prev) // Case of deleting the root
            DeleteNode(t);
        else if ((k < prev->data))
            DeleteNode(&prev->left);
        else
            DeleteNode(&prev->right);
    }
    return found;
}
