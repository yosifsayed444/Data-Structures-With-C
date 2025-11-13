#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"


void print(Type *value)
{
    printf("value is: %d\n", *value);
}
void Increment(Type* value)
{
    (*value)++;
}


