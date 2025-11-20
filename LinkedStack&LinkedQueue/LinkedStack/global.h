#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct node
{
    type value;
    struct node *next;
} node;
typedef struct StackList1
{
    node *head;
    int size;
} StackList1;

typedef struct StackList2
{
    node *top;
    int size;
} StackList2;