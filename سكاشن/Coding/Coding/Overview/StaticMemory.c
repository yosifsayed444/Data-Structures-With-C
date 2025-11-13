#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int mainST() {
    int staticArray[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter an integer %d: ",i+1);
        scanf("%d",&staticArray[i]);
    }
    printf("The static Array variable contains : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", staticArray[i]);
    }
    printf("\n");
    return 0;
}
