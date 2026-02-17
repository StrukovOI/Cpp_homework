#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& s)
{
    std::vector<std::string> v;
    for (size_t i = 0; i < s.length(); ++i)
    {
        v.push_back(s.substr(0, i+1));
    }

    return v;
}

int main()
{
    std::vector<std::string> v = prefixes("Mouse");
    print(v);  // Должно напечатать M Mo Mou Mous Mouse
}