#include <iostream>
#include <vector>
#include <stdexcept>

int sum(std::string str)
{
	if (str.length() < 2)
	{
		throw std::invalid_argument("Некорректная строка");
	}
	if (str[0] != '[' && str[str.length() - 1] != ']')
	{
		throw std::invalid_argument("Некорректная строка");
	}

	int s = 0, it = 0, r = 1;
	for (size_t i = str.length() - 2; i > 0; --i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			it += (str[i] - '0') * r;
			r *= 10;
		}

		else if ((str[i] == ' ' && str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i] == ',' && str[i + 1] == ' '))
		{
			s += it;
			it = 0;
			r = 1;
		}

		else
		{
		throw std::invalid_argument("Некорректная строка");
		}
	}
	
	s += it;

	return s;
}

int main()
{
	std::cout << sum("[10, 20, 30, 40, 50]") << std::endl;
	std::cout << sum("[4, 8, 15, 16, 23, 42]") << std::endl;
	std::cout << sum("[20]") << std::endl;
	std::cout << sum("[]") << std::endl;
	std::cout << sum("[1, x, 2]") << std::endl;
}