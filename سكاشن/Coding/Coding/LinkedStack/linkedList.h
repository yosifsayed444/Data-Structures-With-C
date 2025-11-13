#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int Type;
typedef struct NodeT {
    Type data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

void createLinkedList(LinkedList *list);
int isLinkedListEmpty(LinkedList list);
int isLinkedListFull(LinkedList list);
void insertElement(LinkedList *list, Type value, int position);
Type retrieveElement(LinkedList *list, int position);
void clearLinkedList(LinkedList *list);
void traverseLinkedList(LinkedList *list,void (*f)(Type*));
void traverseLinkedListCallByValue(LinkedList list,void (*f)(Type*));
#endif  /* LINKEDLIST_H */
