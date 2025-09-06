#include <iostream>
#include <cmath>

int main()
{
    int a, b, s=0;
    std::cin>>a>>b;
    for (int i=1; i<=a; ++i)
    {
        for (int j=1; j<=b; ++j)
        {
            s+=i*j*pow(-1, i+j);
        }
    }
    std::cout<<s;

    return 0;
}