#include <stdio.h>
#include <stdlib.h>

typedef int type;
typedef struct node
{
    type value;
    struct node *next;
} node;
typedef struct linkedQueue1 
{
    node *head;
    int size;
} linkedQueue1;
typedef struct linkedQueue2
{
    int data;
    node *rear;
    node *front;
    int size;
} linkedQueue2;