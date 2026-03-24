#include <iostream>
using namespace std;
//A) Compile time overloading
//1. Function overloading
class FuncOverload
{
    public:
    void add(int a,int b)
    {
        std::cout<<a+b;
    }
    void add(double a,double b)
    {
        std::cout<<a+b;
    }
};

//2.operator overloading
class NameAttach
{
    public:
    string personName;
    NameAttach(string name):personName(name){}
    NameAttach operator+(NameAttach &otherperson)
    {
        return NameAttach(personName+otherperson.personName);
    }
};

//B) Runtime polymorphism

class Base
{
    public:
    virtual void op()
    {
        std::cout<<"This is Base Class"<<std::endl;
    }
};

class Derived : public Base
{
    public:
    void op() override
    {
        std::cout<<"This is derived class"<<std::endl;
    }
};

int main()
{
    //A) Compile time polymorphism
    //Func overloading
    FuncOverload f1;
    f1.add(3,1);
    f1.add(3.2,4.3);

    //operator overloading
    NameAttach p1("Shree");
    NameAttach p2("Lord");
    NameAttach p3 = p1+p2;
    std::cout<<p3.personName<<std::endl;

    //runtime polymorphism
    Base* baseCl;
    Derived derivedCl;
    baseCl = &derivedCl;
    baseCl->op();
    return 0;
}