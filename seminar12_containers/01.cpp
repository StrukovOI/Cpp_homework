#include <iostream>
#include <list>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::list<int> l;

    for (int i = 1; i <= n; ++i)
    {
        l.push_back(i);
    }

    std::list<int>::iterator it = l.begin();

    while (l.size() > 1)
    {
        for (int i = 1; i < m; ++i)
        {
            ++it;
            if (it == l.end())
            {
                it = l.begin();
            }
        }
        
        std::cout << *it << ' ';
        std::list<int>::iterator it2 = l.erase(it);
        
        if (it2 == l.end())
        {
            it = l.begin();
        }
        else
        {
            it = it2;
        }
    }
    std::cout << std::endl << l.front();
}