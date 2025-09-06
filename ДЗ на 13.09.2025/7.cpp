#include <iostream>
#include <cmath>

int main()
{
    int a, b, c, p;
    std::cin>>a>>b>>c;
    for (int i=a; i<=b; ++i)
    {
        if (i%c==0)
        {
            std::cout<<i;
            p=i;
            break;
        }
    }
    
    while (p<=(b-c))
    {
        p+=c;
        std::cout<<' '<<p;
    }

    return 0;
}