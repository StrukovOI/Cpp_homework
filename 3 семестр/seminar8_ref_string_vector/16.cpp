#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> split(const std::string& str, char del)
{
    std::vector<std::string> res;
    size_t start = 0;
    size_t pos = str.find(del);
    
    while(pos < str.length())
    {
        std::string part = str.substr(start, pos - start);
        res.push_back(part);
        
        start = pos + 1;
        
        pos = str.find(del, start);
    }

    if(start < str.length())
    {
        res.push_back(str.substr(start));
    }
    
    return res;
}

int main()
{
    std::string data = "apple,banana,cherry,durian";
    char delimiter = ',';
    
    std::vector<std::string> parts = split(data, delimiter);
    for (std::size_t i = 0; i < parts.size(); ++i)
        std::cout << parts.at(i) << std::endl;
}