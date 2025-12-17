#include <iostream>
#include <set>

int main()
{
    int n, k, cut;
    std::cin >> n >> k;
    std::set<int> cs;
    cs.insert(0);
    cs.insert(n);
    
    std::multiset<int> s;
    s.insert(n);
    
    for (int i = 0; i < k; ++i)
    {
        std::cin >> cut;
        
        std::multiset<int>::iterator it = cs.insert(cut).first;
        std::multiset<int>::iterator itl = std::prev(it);
        std::multiset<int>::iterator itr = std::next(it);
        
        int l = *itl;
        int r = *itr;
        int old = r - l;

        std::multiset<int>::iterator itln = s.find(old);

        if (itln != s.end())
        {
            s.erase(itln);
        }
        
        s.insert(cut - l);
        s.insert(r - cut);
        std::cout << *s.rbegin() << ' ';
    }
}