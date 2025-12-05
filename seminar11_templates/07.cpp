#include <iostream>
#include <string>
using namespace std::string_literals;

template<typename T>
class Manager
{
private:
    T* ptr;

public:
    Manager() : ptr(nullptr) {}

    void allocate()
    {
        ptr = static_cast<T*>(std::malloc(sizeof(T)));
    }
    
    void construct(const T& t)
    {
        new (ptr) T(t);
    }
    
    void destruct()
    {  
        ptr->~T();
    }
    
    void deallocate()
    {
        std::free(ptr);
    }
    
    T& get()
    {
        return *ptr;
    }
    
    const T& get() const
    {
        return *ptr;
    }
    
    ~Manager()
    {
        deallocate();
    }
};



int main()
{
	Manager<std::string> a;
	a.allocate();

	a.construct("Cats and dogs"s);
	a.get() += " and elephant";
	std::cout << a.get() << std::endl;  // Должен напечатать Cats and dogs and elephant
	a.destruct();

	a.construct("Sapere Aude"s);
	std::cout << a.get() << std::endl;  // Должен напечатать Sapere Aude
	a.destruct();

	a.deallocate();
}