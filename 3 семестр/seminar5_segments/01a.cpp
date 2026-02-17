#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t* p = (size_t*)malloc(sizeof(size_t));
    *p = 123;
    printf("%lli", *p);
    free(p);
}