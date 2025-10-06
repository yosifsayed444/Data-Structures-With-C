#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct B
    {
        char c1;
        char c2;
        int n;
    };

    struct D
    {
        char x;
        struct B y;
        float z;
    };

    printf("size of structure : %d", sizeof(struct D));

    
}
