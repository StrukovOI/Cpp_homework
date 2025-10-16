#include <stdio.h>

int main()
{
#if defined(COUNT)
    for (int i = 1; i <= COUNT; ++i)
    {
        printf("%i ", i);
    }
    printf("\n");

#else
    printf("No Count!\n");
#endif
}