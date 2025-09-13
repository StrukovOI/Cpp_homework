#include <stdio.h>

void reverse(int a[], int n)
{
    int el;
    for (int i = 0; i < n / 2; ++i)
    {
        el = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = el;
    }
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

    reverse(a, n);

    for (int i=0; i<n; ++i)
    {
        printf("%i ", a[i]);
    }
    return 0;
}