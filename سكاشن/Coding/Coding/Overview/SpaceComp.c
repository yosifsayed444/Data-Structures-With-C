#include <stdio.h>

// Function to calculate the sum of two integers
int calculateSum(int num1, int num2) {
    int sum = num1 + num2;
    return sum;
}

int mainSC() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    int s =  calculateSum(num1, num2);
    printf("Sum of %d and %d is: %d\n", num1, num2, s);
    return 0;
}
