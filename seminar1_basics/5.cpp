#include <iostream>

int main()
{
    int a, m=1, l=1;
    std::cin>>a;
    std::cout<<a<<' ';

    while (a!=1)
    {
        if (a>m)
        {
            m=a;
        }
        if (a%2==0)
        {
            a/=2;
        }
        else
        {
            a=3*a+1;
        }
        ++l;
        std::cout<<a<<' ';
    }

    std::cout<<std::endl<<"Length = "<<l<<", Max = "<<m;
    return 0;
}