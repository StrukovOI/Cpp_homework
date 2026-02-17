#include <stdio.h>
#include <stdlib.h>

void print(int* a, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}

int less(int x, int y)
{
    if (x < y)
    {
        return 1;
    }
    return 0;
}

int greater(int x, int y)
{
    if (x > y)
    {
        return 1;
    }
    return 0;
}

int last_digit_less(int x, int y)
{
    if (x == y)
    {
        return 0;
    }
    while (x && y)
    {
        if (x % 10 < y % 10)
        {
            return 1;
        }
        else if (x % 10 > y % 10)
        {
            return 0;
        }
        x /= 10;
        y /= 10;
    }
    if (x == 0)
    {
        return 1;
    }
    return 0;
}


void sort(int* a, size_t n, int (*com)(int a, int b))
{
    for (size_t j = 0; j < n; ++j)
    {
        size_t min_index = j;
        for (size_t i = j + 1; i < n; ++i)
        {
            if (com(a[i], a[min_index]))
                min_index = i;
        }

        int temp = a[j];
        a[j] = a[min_index];
        a[min_index] = temp;
    }
}

int main()
{
    int a[] = {32, 63, 29, 54, 81};
    
    sort(a, 5, less);
    print(a, 5); // Должен напечатать 29 32 54 63 81 
        
    sort(a, 5, greater);
    print(a, 5); // Должен напечатать 81 63 54 32 29
    
    sort(a, 5, last_digit_less);
    print(a, 5); // Должен напечатать 81 32 63 54 29
}