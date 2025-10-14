#include <stdio.h>
#include "stack.h"
#include <math.h>
#include <string.h>

void fun(int n)
{
    if (n <= 0)
    {
        printf("log(%d) is undefined\n", n);
        return;
    }
    Stack S1, S2, S3;
    createStack(&S1);
    createStack(&S2);
    createStack(&S3);
    int temp = n;
    while (temp > 0)
    {
        push((temp % 2) + '0', &S1);
        temp /= 2;
    }
    printf("\nBinary representation (order): ");
    while (!isstackempty(S1))
    {
        char bit = pop(&S1);
        printf("%c", bit);
        push(bit, &S2);
    }
    printf("\n");

    printf("Binary representation (reverse): ");
    while (!isstackempty(S2))
    {
        printf("%c", pop(&S2));
    }
    printf("\n");

    printf("\nValue of log(n): %.4f\n", log(n));

    char str[50];
    sprintf(str, "%.4f", log(n));
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i], &S3);
    }

    printf("Digits of log(n) in reverse: ");
    while (!isstackempty(S3))
    {
        printf("%c", pop(&S3));
    }
    printf("\n");
}
// 1 Prints binary representation of n in reverse order
// 2 Prints binary representation of n
// 3 Prints the value of Logn
// 4 Prints the value of Logn in reverse order
// What does the above function do in general?
// prob1

int main()
{
    fun(11);
    return 0;
}
