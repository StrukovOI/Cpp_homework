#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void print(const int* a, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

char& get(std::string& str, std::size_t ind)
{
    if (ind >= str.length())
    {
        std::cout << "Ошибка: индекс " << ind << " выходит за границы строки" << std::endl;
        std::exit(1);
    }
    return str[ind];
}

int& get(std::vector<int>& vec, std::size_t ind)
{
    if (ind >= vec.size())
    {
        std::cout << "Ошибка: индекс " << ind << " выходит за границы вектора" << std::endl;
        std::exit(1);
    }
    return vec[ind];
}

int& get(int* arr, std::size_t size, std::size_t ind)
{
    if (ind >= size)
    {
        std::cout << "Ошибка: индекс " << ind << " выходит за границы массива" << std::endl;
        std::exit(1);
    }
    return arr[ind];
}

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    get(v, 2) += 1;
    print(v);                     // Напечатает 10 20 31 40 50
    
    std::string s = "Cat";
    get(s, 0) = 'B';
    std::cout << s << std::endl;  // Напечатает Bat
    
    int a[5] = {10, 20, 30, 40, 50};
    get(a, 5, 2) += 1;
    print(a, 5);                  // Напечатает 10 20 31 40 50
    
    get(v, 10) = 0;               // Должен напечатать сообщение об ошибке и выйти из программы
}