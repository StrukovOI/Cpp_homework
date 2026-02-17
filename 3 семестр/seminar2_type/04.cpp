#include <stdio.h>

double pi(int n)
{
    double s = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i%2 == 0)
        {
            s -= (float)1/(2 * i - 1);
        }
        else
        {
            s += (float)1/(2 * i - 1);
        }
    }
    return s * 4;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%lf", pi(n));

    return 0;
}