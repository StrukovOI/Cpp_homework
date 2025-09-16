#include <iostream>
#define MAX 100

void assign(float a[MAX][MAX], float b[MAX][MAX], int n)
{
    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            a[i][j] = b[i][j];
        }
    }
}

int main()
{
    int n;
    std::cin>>n;
    float a[MAX][MAX], b[MAX][MAX];

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cin>>a[i][j];
        }
    }

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cin>>b[i][j];
        }
    }

    multiply(a, b, n);

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cout<<a[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

    return 0;
}