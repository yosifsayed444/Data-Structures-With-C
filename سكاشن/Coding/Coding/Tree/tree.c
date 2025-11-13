#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "tree.h"
#include "stack.h"

void CreateTree(TreeType *T)
{
    *T= NULL;
}

int  EmptyTree(TreeType   T)
{
    return (T==NULL);
}

int FullTree(TreeType  T)
{
    return 0;
}
void Inorder(TreeType T, void (*f)(Type*))
{
    if (T != NULL)
    {
        Inorder(T->left, f);
        (*f)(&(T->info));
        Inorder(T->right, f);
    }
}
void Preorder(TreeType T, void(*f)(Type*))
{
    if (T != NULL)
    {
        (*f)(&(T->info));
        Preorder(T->left, f);
        Preorder(T->right, f);
    }
}

void Postorder(TreeType T, void(*f)(Type*))
{
    if (T != NULL)
    {
        Postorder(T->left, f);
        Postorder(T->right, f);
        (*f)(&(T->info));
    }
}

int Size(TreeType t)
{
    if (!t)
        return 0;
    return (1+Size(t->left)+Size(t->right));
}

int Height(TreeType t)
{
    if (!t)
        return 0;
    int a=Height(t->left);
    int b=Height(t->right);
    return (a>b)? 1+a : 1+b;
}

void ClearTree(TreeType *t)
{
    if (*t)
    {
        ClearTree(&(*t)->left);
        ClearTree(&(*t)->right);
        free(*t);
        *t=NULL;
    }
}
void  insertEle(TreeType *t, Type  item)
{
    treeNode *p = (treeNode *)malloc(sizeof(treeNode));
    p->info = item;
    p->left=NULL;
    p->right=NULL;
    if (!(*t))      *t= p;
    else
    {
        treeNode *pre,*cur;
        cur=*t;
        while(cur)
        {
            pre=cur;
            if(item < cur->info)  cur=cur->left;
            else  cur=cur->right;
        }
        if(item < pre->info)    pre->left=p;
        else  pre->right=p;
    }

}
int Delete(TreeType *t,Type k)
{
    int found=0;
    treeNode *cur=*t;
    treeNode *prev=NULL;
    while(cur && !(found=(k==cur->info)))
    {
        prev=cur;
        if(k<cur->info)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if (found)
    {
        if(!prev)//Case of deleting the root
            DeleteNode(t);
        else if((k< prev->info))
            DeleteNode(&prev->left);
        else
            DeleteNode(&prev->right);
    }
    return found;
}
void DeleteNode(TreeType *pt)
{
    treeNode *cur=*pt;
    if(!(cur)->left)
        *pt=(cur)->right;
    else if(!(cur)->right)
        *pt=(cur)->left;
    else //third case
    {
        cur=(cur)->left;
        treeNode *prev=NULL;
        while(cur->right)
        {
            prev=cur;
            cur=cur->right;
        }
        (*pt)->info=cur->info;
        if(prev)
            prev->right=cur->left;
        else
            (*pt)->left=cur->left;
    }
    free(cur);


}

