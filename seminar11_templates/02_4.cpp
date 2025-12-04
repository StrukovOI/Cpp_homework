#include <iostream>
#include <string>

template<typename T>
T triple(const T& x)
{
    return 3 * x;
}

template<>
std::string triple<std::string>(const std::string& x)
{
    return x + x + x;
}

int main()
{
    int a = 10;
    std::cout << triple(a) << std::endl;  // 30
    
    std::string b = "Cat";
    std::cout << triple(b) << std::endl;  // CatCatCat
    // При вызове triple(b) с std::string будет выбрана перегрузка
}