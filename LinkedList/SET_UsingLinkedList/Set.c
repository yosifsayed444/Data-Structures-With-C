
#include "Set.h"
int main()
{
    Set A, B;
    createSet(&A);
    createSet(&B);

    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 3);

    addElement(&B, 3);
    addElement(&B, 4);
    addElement(&B, 5);

    printf("A = ");
    printSet(&A);

    printf("B = ");
    printSet(&B);

    Set U = unionSet(&A, &B);
    printf("Union = ");
    printSet(&U);

    Set I = intersectionSet(&A, &B);
    printf("Intersection = ");
    printSet(&I);

    subtractSet(&A, &B);
    printf("A - B = ");
    printSet(&A);

    return 0;
}