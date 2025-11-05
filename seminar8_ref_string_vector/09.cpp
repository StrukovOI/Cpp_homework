#include <iostream>
#include <string>

std::string repeat(int n)
{
    if(n < 0)
    {
        return "";
    }
    
    std::string str = std::to_string(n);
    std::string res;
    
    for (int i = 0; i < n; ++i)
    {
        res += str;
    }
    
    return res;
}

int main()
{
    std::cout << repeat(5)  << std::endl;
    std::cout << repeat(10) << std::endl;
    std::cout << repeat(-1) << std::endl;
    
    return 0;
}