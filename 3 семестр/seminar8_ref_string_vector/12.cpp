#include <iostream>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& v)
{
    std::string res;
    for (const std::string& s : v)
    {
        res += s;
    }
    return res;
}

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
    std::cout << concatenate(v) << std::endl;
    return 0;
}