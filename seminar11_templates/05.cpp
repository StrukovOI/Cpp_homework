#include <iostream>

template<typename T>
void swapEndianness(T& value)
{
    unsigned char* bts = reinterpret_cast<unsigned char*>(&value);
    
    for (std::size_t i = 0; i < sizeof(T) / 2; ++i)
    {
        unsigned char it = bts[i];
        bts[i] = bts[sizeof(T) - 1 - i];
        bts[sizeof(T) - 1 - i] = it;
    }
}

int main()
{
    std::cout << std::hex;
    
    int a = 0x1a2b3c4d; 
    std::cout << a << std::endl;  // Должен напечатать 1a2b3c4d
    swapEndianness(a);             
    std::cout << a << std::endl;  // Должен напечатать 4d3c2b1a
    swapEndianness(a);             
    std::cout << a << std::endl;  // Должен напечатать 1a2b3c4d
    
    short b = 0x1a2b;   
    std::cout << b << std::endl;  // Должен напечатать 1a2b
    swapEndianness(b);
    std::cout << b << std::endl;  // Должен напечатать 2b1a
}