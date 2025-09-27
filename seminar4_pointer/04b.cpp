#include <stdio.h>

void mult2 (int* p, size_t n)
{
    for (size_t i = 0; i != n; ++i)
    {
        p[i] *= 2;
    }
}

int main() 
{
    int el, n;
    scanf("%i", &n);
    int a[n];

    for (int i = 0; i != n; ++i)
    {
        scanf("%i", &el);
        a[i] = el;
    }

    int* p = &a[0];
    mult2(p, n);

    for (int i = 0; i != n; ++i)
    {
        printf("%i ", a[i]);
    }
}