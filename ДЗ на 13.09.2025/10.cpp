#include <iostream>
#include <vector>

int main()
{
    int a, b, el;
    std::cin>>a>>b;
    std::vector<int> v(b);
    for (int i=0; i!=a; ++i)
    {
        for (size_t j=0; j!=b; ++j)
        {
            std::cin>>el;
            v[j]+=el;
        }
    }

    for (size_t i=0; i!=b; ++i)
    {
        std::cout<<v[i]<<' ';
    }

    return 0;
}