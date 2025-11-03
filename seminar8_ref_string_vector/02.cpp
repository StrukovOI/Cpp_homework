#include <iostream>

void cube(int &n)
{
    n = n * n * n;
}

int main()
{
    int a = 5;
    cube(a);
    std::cout << a << std::endl;
}