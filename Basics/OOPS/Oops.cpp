#include<iostream>
using namespace std;

//abstraction
class Shape
{
    private:
    string color;
    public:
    Shape(string color) : color(color){}
    virtual double getArea()=0;
};

class Rectangle : public Shape
{
    private:
    double length;
    double breadth;
    public:
    Rectangle(double l,double b,string color) : Shape(color){length=l;breadth=b;}
    double getArea() override
    {
        return length * breadth;
    }
};

//polymorphism
//compile time
//operator overloading
class Complex
{
    private:
    int real;
    int imag;
    public:
    Complex(int real,int imag):real(real),imag(imag){}
    Complex operator+(Complex& c)
    {
        return Complex(real+c.real,imag+c.imag);
    }
};

//Function overriding
class Base
{
    public:
    virtual void display()
    {
        cout<<"Display for base"<<endl;
    }
};

class Derived : public Base
{
    public:
    void display() override
    {
        cout<<"Derived display"<<endl;
    }
};

//encapsulation
class EncapEx
{
    private:
    int num;
    public:
    int getNum(){return num;}
    void setNum(int n){num=n;}
};

//diamond problem
class Base1
{
    public:
    void fun(){cout<<"Base class"<<endl;}
};

class Parent1 : virtual public Base1{};
class Parent2 : virtual public Base1{};

class Child : public Parent1, public Parent2{};


int main()
{
    Shape* s = new Rectangle(2.0,3.0,std::string("red"));
    cout<<"rect area : "<<s->getArea()<<endl;

    Complex c1(2,3);
    Complex c2(5,6);
    Complex c3 = c1+c2;

    Base *d = new Derived();
    d->display();

    return 0;
}