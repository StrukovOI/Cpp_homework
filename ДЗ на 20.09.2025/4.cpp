#include <stdio.h>

int sum_of_digits(int a)
{
    int s=0;
    while (a!=0)
    {
        s+=(a%10);
        a/=10;
    }
    return s;
}

int main()
{
    int a;
    scanf("%i", &a);

    printf("%i", sum_of_digits(a));
    return 0;
}