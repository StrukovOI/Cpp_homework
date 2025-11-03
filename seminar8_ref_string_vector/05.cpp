#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(Book& b)
{
    if(b.price > 1000)
    {
        return true;
    }
    return false;
}

int main()
{
    Book buch = {"Сивухин: Электричество и магнетизм", 999999, 5000};
    Book& b = buch;
    
    if(isExpensive(b))
    {
        std::cout << "Придётся взять книгу в библиотеке";
    }
}