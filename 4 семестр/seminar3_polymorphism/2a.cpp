#include <iostream>
#include <vector>

class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
    virtual int getId() const = 0;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
    int getId() const override { return 0; }
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
    int getId() const override { return 1; }
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
    int getId() const override { return 2; }
};

// #1
std::vector<Individual*> createIndividuals()
{
    std::vector<Individual*> v;
    for (int i = 0; i < 3; i++)
        v.push_back(new Alice());

    for (int i = 0; i < 2; i++)
        v.push_back(new Bob());

    for (int i = 0; i < 4; i++)
        v.push_back(new Casper());
    
    return v;
}

// #2
void letThemSpeak(std::vector<Individual*>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->speak();
    }
}

// #3
void deleteIndividuals(std::vector<Individual*>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        delete v[i];
    }
}

// #4a
// int identification(Individual* p)
// {
//     return p->getId();
// }

// #4b
int identification(Individual* p)
{
    if (dynamic_cast<Alice*>(p) != nullptr)
        return 0;
    if (dynamic_cast<Bob*>(p) != nullptr)
        return 1;
    if (dynamic_cast<Casper*>(p) != nullptr)
        return 2;
}

// #4c
int identification_typeid(Individual* p)
{
    if (typeid(*p) == typeid(Alice))
        return 0;
    if (typeid(*p) == typeid(Bob))
        return 1;
    if (typeid(*p) == typeid(Casper))
        return 2;
}



int main()
{
    std::vector<Individual*> v = createIndividuals();
    letThemSpeak(v);
    deleteIndividuals(v);
    Alice a;
    std::cout << "Alice id: " << identification(&a) << std::endl;
}