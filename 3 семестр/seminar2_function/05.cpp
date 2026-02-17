#include <stdio.h>

void print_binary(unsigned int n)
{
    int a=n%2;
    n/=2;
    if (n)
    {
        print_binary(n);
    }
    printf("%i", a);
}

int main()
{
    int a;
    scanf("%i", &a);

    print_binary(a);
    return 0;
}