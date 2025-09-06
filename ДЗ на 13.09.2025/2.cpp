#include <iostream>

int main()
{
    int a;
    std::cin>>a;
    if (a%2==0 and (a>=0 and a<=20 or a>100 and a<200))
    {
        std::cout<<"Yes";
    }
    else
    {
        std::cout<<"No";
    }
    return 0;
}