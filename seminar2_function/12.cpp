#include <iostream>
#define MAX 100

void multiply(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int n)
{
    int d[MAX][MAX] = {0};
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<n; ++k)
            {
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            c[i][j] = d[i][j];
        }
    }
}

void assign(int a[MAX][MAX], int b[MAX][MAX], int n)
{
    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            a[i][j] = b[i][j];
        }
    }
}

void power(int a[MAX][MAX], int c[MAX][MAX], int n, int k)
{
    if (k==1)
    {
        assign(c, a, n);
        return;
    }
    int b[MAX][MAX];
    assign(b, a, n);
    for (int i=0; i<k-1; ++i)
    {
        multiply(a, b, c, n);
        assign(b, c, n);
    }
}

int main()
{
    int n, k;
    std::cin>>n>>k;
    int a[MAX][MAX], c[MAX][MAX];

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cin>>a[i][j];
            c[i][j] = 0;
        }
    }

    power(a, c, n, k);

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cout<<c[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

    return 0;
}