#include <stdio.h>

int count_even(int a[], int n)
{
    int s=0;
    for (int i=0; i!=n; ++i)
    {
        if (a[i]%2==0)
        {
            ++s;
        }
    }
    return s;
}

int main()
{
    int n, el;
    scanf("%i", &n);
    int a[n];

    for (int i=0; i!=n; ++i)
    {
        scanf("%i", &el);
        a[i] = el;
    }

    printf("%i", count_even(a, n));
    return 0;
}