#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct B
    {
        int x;
        float y;
        char z;
        double a;
    };

    struct D
    {
        char x;
        float a;
        struct B y;
    };

    printf("size of structure : %d", sizeof(struct D));
}
