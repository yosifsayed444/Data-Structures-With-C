#include <stdio.h>
#include <stdlib.h>

void X()
{
    printf("Hello world!\n");
}
void Y()
{
    X();
}

void Z()
{
   Y();
}

int main()
{
    Z();
    return 0;
}
