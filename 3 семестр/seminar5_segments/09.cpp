#include <stdio.h>
#include <stdlib.h>

int adder(int a)
{
    static int s = 0;
    s += a;
    return s;
}

int main()
{
    printf("%i\n", adder(10));  // Должен напечатать 10
    printf("%i\n", adder(15));  // Должен напечатать 25
    printf("%i\n", adder(70));  // Должен напечатать 95
}