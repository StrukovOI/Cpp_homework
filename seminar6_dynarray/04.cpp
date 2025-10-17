#include <stdio.h>

int main()
{
#if defined(COUNT)
    #if COUNT > 100
        printf("Count is too large!\n");
    #else
        #if defined(REVERSE)
            for (int i = COUNT; i >= 1; --i)
            {
                printf("%d ", i);
            }
        #else
            for (int i = 1; i <= COUNT; ++i)
            {
                printf("%d ", i);
            }
        #endif
        printf("\n");
    #endif

#else
    printf("No count!\n");
#endif

}