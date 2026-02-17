#include <iostream>

int main()
{
    int n;
    std::cin>>n;
    int a[n][n], b[n][n], c[n][n];

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cin>>a[i][j];
            c[i][j] = 0;
        }
    }

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            std::cin>>b[i][j];
        }
    }

    for (int i=0; i!=n; ++i)
    {
        for (int j=0; j!=n; ++j)
        {
            for (int k=0; k!=n; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

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