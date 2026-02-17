#include <iostream>
#include <string>
#include <vector>

int main()
{
	int* p1 = new int(123);
	std::string* p2 = new std::string("Cats and Dogs");
	int* p3 = new int[5]{10, 20, 30, 40, 50};
	std::vector<int>* p4 = new std::vector<int>{10, 20, 30, 40, 50};
	std::string* p5 = new std::string[3]{"Cat", "Dog", "Mouse"};

	std::cout << *p1 << std::endl << *p2 << std::endl;
	
	for (size_t i = 0; i < p4->size(); ++i)
	{
        std::cout << (*p4)[i] << " ";
    }

    std::cout << std::endl;
	for (int i = 0; i < 3; ++i)
	{
        std::cout << p5[i] << " ";
    }
    std::cout << std::endl;

	delete p1; delete p2; delete[] p3; delete p4; delete[] p5;
}