#include <stdio.h>

bool is_negative(int a)
{
    if (a < 0)
    {
        return true;
    }
    return false;
}

bool is_even(int a)
{
    if (a % 2 == 0)
    {
        return true;
    }
    return false;
}

bool is_square(int a)
{
    if (a > 0)
    {
        for (int i = 1; i != a/2 + 1; ++i)
        {
            if (i * i == a)
            {
                return true;
            }
        }
    }
    return false;
}

int count_if(int a[], int n, bool (*pred)(int))
{
    int k = 0;
    for (int i = 0; i != n; ++i)
    {
        if (pred(a[i]))
        {
            k++;
        }
    }

    return k;
}

int main()
{
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};

    printf("%i\n", count_if(a, 10, is_negative));  // Должен напечатать 2
    printf("%i\n", count_if(a, 10, is_even));      // Должен напечатать 6
    printf("%i\n", count_if(a, 10, is_square));    // Должен напечатать 3
}
