#include <iostream>
#include <vector>

int main()
{
    int a, c;
    std::cin>>a;
    if (a!=0)
    {
        std::vector<int> v;
        for (int i=0; i!=a; ++i)
        {
            std::cin>>c;
            v.push_back(c);
        }

        for (int u : v) 
        {
            std::cout<<u<<" ";
        }
        
        for (int u : v) 
        {
            std::cout<<u<<" ";
        }        
    }

    return 0;
}