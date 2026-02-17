#include <stdio.h>

int main()
{
    int a[1000];
    int n, j=0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i<n; ++i)
        if (a[i]>=0)
        {
            a[j] = a[i];
            ++j;
        }
        
    
    for (int i = 0; i < j; ++i)
        printf("%i ", a[i]);

    printf("\n");
    
    return 0;
}