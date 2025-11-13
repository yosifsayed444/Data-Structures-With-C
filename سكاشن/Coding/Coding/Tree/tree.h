#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
typedef  int Type;
typedef struct tnode
{
    Type 	info;
    struct tnode  *left;
    struct tnode  *right;
} treeNode;

typedef treeNode *	TreeType;

void CreateTree(TreeType *);

int  EmptyTree(TreeType);

int FullTree(TreeType);

void Inorder(TreeType, void (*f)(Type*) );
void Preorder(TreeType,  void (*f)(Type*) );
void Postorder(TreeType,  void (*f)(Type*) );

int Size(TreeType t);
int Height(TreeType t);
void ClearTree(TreeType *t);
void  insertEle(TreeType *, Type );
int deleteNode(TreeType *, int k);
#endif // TREE_H_INCLUDED
