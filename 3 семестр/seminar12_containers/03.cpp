#include <iostream>
#include <set>

int main()
{
    int n, num;
    std::cin >> n;
    std::multiset<int> s;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> num;
        s.insert(num);
    }
    
    for (int num : s)
    {
        std::cout << num << " ";
    }
}