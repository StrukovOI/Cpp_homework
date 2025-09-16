#include <iostream>

int sumd(int a)
{
    int s=0;
    while (a!=0)
    {
        s+=a%10;
        a/=10;
    }
    return s;
}

int main()
{
    int n, temp;
    std::cin>>n;
    int a[n], b[n];

    for (int i=0; i!=n; ++i)
    {
        std::cin>>temp;
        a[i] = temp;
        b[i] = sumd(temp);
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n - 1 - j; i += 1)
        {
            if (b[i] > b[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                temp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp;
            }
        }
    }

    for (int i=0; i!=n; ++i)
    {
        std::cout<<a[i]<<' ';
    }

    return 0;
}