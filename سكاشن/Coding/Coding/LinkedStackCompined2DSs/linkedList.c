#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void createLinkedList(LinkedList* list)
{

    list->head = NULL;
    list->size = 0;
}

int isLinkedListEmpty(LinkedList list)
{
    return list.size == 0; // or list.head==NULL
}

int isLinkedListFull(LinkedList list)
{
    // Typically, linked lists don't have a "full" state,
    // so we'll return 0 (not full) for demonstration purposes
    return 0;
}

void insertElement(LinkedList *list, Type value, int position)
{
    if (position < 0 || position > list->size)
    {
        printf("Invalid position. Cannot insert.\n");
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;

    if (position == 0)
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;
}

Type retrieveElement(LinkedList* list, int position)
{
    if (position < 0 || position >= list->size)
    {
        printf("Invalid position. Cannot retrieve and delete.\n");
        return -1;
    }

    Type value;

    if (position == 0)
    {
        Node* temp = list->head;
        value = temp->data;
        list->head = temp->next;
        free(temp);
    }
    else
    {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        Node* temp = current->next;
        value = temp->data;
        current->next = temp->next;
        free(temp);
    }

    list->size--;
    return value;
}

void clearLinkedList(LinkedList* list)
{
    Node* temp;
    while (list->head!=NULL)
    {
        temp = list->head;
        printf("Item deleted %d",list->head->data);
        list->head = temp->next;
        free(temp);
    }

}

void traverseLinkedList(LinkedList *list,void (*f)(Type*))
{
    if (isLinkedListEmpty(*list))
    {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = list->head;
    while (current != NULL)
    {
        (*f)(&current->data);
        current = current->next;
    }
}

void traverseLinkedListCallByValue(LinkedList list,void (*f)(Type*))
{
    if (isLinkedListEmpty(list))
    {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = list.head;
    while (current != NULL)
    {
        (*f)(&current->data);
        current = current->next;
    }
}
