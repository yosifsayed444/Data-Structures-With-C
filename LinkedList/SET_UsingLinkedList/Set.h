#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct node
{
    type value;
    struct node *next;
} node;

typedef struct Set
{
    node *head;
    int size;
} Set;

node *createNode(type data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}
void createSet(Set *s)
{
    s->head = NULL;
    s->size = 0;
}
int is_in_set(Set *s, type value)
{
    node *temp = s->head;
    while (temp)
    {
        if (temp->value == value)
            return 1;

        temp = temp->next;
    }
    return 0;
}
void addElement(Set *s, type value)
{
    if (is_in_set(s, value))
        return; 

    node *newNode = createNode(value);
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
}

void removeElement(Set *s, type value)
{
    node *temp = s->head;
    node *prev = NULL;
    while (temp)
    {
        if (temp->value == value)
        {
            if (prev == NULL)
                s->head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            s->size--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void addSet(Set *dest, Set *src)
{
    node *temp = src->head;
    while (temp != NULL)
    {
        addElement(dest, temp->value);
        temp = temp->next;
    }
}

void subtractSet(Set *dest, Set *src)
{
    node *temp = src->head;
    while (temp != NULL)
    {
        removeElement(dest, temp->value);
        temp = temp->next;
    }
}

Set unionSet(Set *a, Set *b)
{
    Set result;
    createSet(&result);

    addSet(&result, a);
    addSet(&result, b);

    return result;
}

Set intersectionSet(Set *a, Set *b)
{
    Set result;
    createSet(&result);

    node *temp = a->head;
    while (temp)
    {
        if (is_in_set(b, temp->value))
            addElement(&result, temp->value);
        temp = temp->next;
    }

    return result;
}


int cardinality(Set *s)
{
    return s->size;
}

void printSet(Set *s)
{
    node *temp = s->head;
    printf("{ ");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("}\n");
}


