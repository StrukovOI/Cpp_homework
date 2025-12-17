#include <iostream>
#include <map>

int main()
{
    int n, num;
    std::cin >> n;
    std::map<int, int> m;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> num;
        m[num]++;
    }
    
    for (const auto& p : m)
    {
        std::cout << p.first << ' ';
    }
    std::cout << std::endl;
    
    for (const auto& p : m)
    {
        std::cout << p.second << ' ';
    }
}