#include <iostream>
#include <string>

void addBrackets(std::string& s)
{
    s.insert(0, "[");
    s.push_back(']');
}

int main()
{
	std::string a = "Cat";
	addBrackets(a);
	std::cout << a << std::endl;  // Должно напечатать [Cat]
	
	addBrackets(a);
	std::cout << a << std::endl;  // Должно напечатать [[Cat]]
}