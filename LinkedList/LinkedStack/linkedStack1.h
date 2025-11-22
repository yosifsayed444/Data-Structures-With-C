#include "linkedlist_with_C.h"
void createStack1(StackList1 *s){
    createList(s);
}
int isEmpty1(StackList1 *s){
    return isEmpty(s);
}
int isFull1(StackList1 *s){
    return isFull(s);
}
void push1(type data, StackList1 *s){
    insertNodeAtPosition(0, data, s);
}
type pop1(StackList1 *s){
    return retrieveAtPosition(s,0);
}
void displayStack1(StackList1 *s){
    displayStackList1(s);
}
void clearStack1(StackList1 *s){
    clearList(s);
}
type peek1(StackList1 *s){
    if (isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->head->value;
}
type stackSize1(StackList1 *s){
    return s->size;
}
void traverseStackList1(StackList1 *s,void (*func)(type*)){
    node *temp = s->head;
    while (temp != NULL)
    {
        func(&temp->value);
        temp = temp->next;
    }
}