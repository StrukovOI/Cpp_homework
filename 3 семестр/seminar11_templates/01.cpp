#include <iostream>

template<typename T>
T cube(T a)
{
    return a * a * a;
}

template<>
char cube<char>(char a)
{
    return static_cast<char>(a * a * a);
}

int main()
{
    auto a = cube(5);
    std::cout << a << " " << sizeof(a) << std::endl;

    auto b = cube(5.0);
    std::cout << b << " " << sizeof(b) << std::endl;

    char x = 5;
    auto c = cube(x);
    std::cout << static_cast<int>(c) << " " << sizeof(c) << std::endl;
}