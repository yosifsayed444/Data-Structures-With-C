#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  
typedef struct {
    int arr[MAX_SIZE];
    int size;  
} ArrayList;
void CreateList(ArrayList *list) {
    list->size = 0;
}

int isEmpty(ArrayList *list) {
    return list->size == 0;
}


int isFull(ArrayList *list) {
    return list->size == MAX_SIZE;
}

void insert(ArrayList *list, int element, int pos) {
    if (isFull(list)) {
        printf("Error: List is full!\n");
        return;
    }
    if (pos < 0 || pos > list->size) {
        printf("Error: Invalid position!\n");
        return;
    }

    for (int i = list->size - 1; i >= pos; i--) {
        list->arr[i + 1] = list->arr[i];
    }
    list->arr[pos] = element;
    list->size++;
}

void deleteAtpostion(ArrayList *list, int pos) {
    if (isEmpty(list)) {
        printf("Error: List is empty!\n");
        return;
    }
    if (pos < 0 || pos >= list->size) {
        printf("Error: Invalid position!\n");
        return;
    }
    for (int i = pos; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
}
void traverse(ArrayList *list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

