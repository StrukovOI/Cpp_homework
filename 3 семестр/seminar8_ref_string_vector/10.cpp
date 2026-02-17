#include <iostream>
#include <string>

bool isDomainName(std::string s)
{
    if(s.length() > 7 && s.starts_with("www.") && s.ends_with(".com"))
    {
        return true;
    }
    return false;
} 

int main()
{
	std::cout << isDomainName("www.google.com") << std::endl;         // Напечатает 1
	std::cout << isDomainName("abc") << std::endl;                    // Напечатает 0
	std::cout << isDomainName("hello.com") << std::endl;              // Напечатает 0
}