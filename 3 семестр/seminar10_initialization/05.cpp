#include <iostream>

int main()
{
    std::string stackString = "Cat";
    std::cout << "Stack string: " << stackString << std::endl;

    std::string* heapString = new std::string("Dog");
    std::cout << "Heap string: " << *heapString << std::endl;
    delete heapString;

    char x[sizeof(std::string)];
    std::string* placementString = new (x) std::string("Elephant");
    std::cout << "Placement string: " << *placementString << std::endl;
    
    placementString->~basic_string();
}