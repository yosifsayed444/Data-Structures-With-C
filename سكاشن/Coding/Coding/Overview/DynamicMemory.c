
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


int mainDM() {
    int n;
    printf("Enter the number of integers to allocate dynamically: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n integers
    int* dynamicArray = (int*)malloc(n * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assigning values to the elements of the dynamically allocated array
    for (int i = 0; i < n; i++) {
        printf("Enter an integer %d: ",i+1);
        scanf("%d",&dynamicArray[i]);
    }

    printf("Dynamically Allocated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Freeing the dynamically allocated memory
    free(dynamicArray);

    return 0;
}
