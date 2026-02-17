#include <stdio.h>

int main()
{
#if defined(DOG)
    printf("Dog!\n");
#else
    printf("No dog!\n");
#endif
}