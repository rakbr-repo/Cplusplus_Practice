#include<iostream>
using namespace std;

//Prototype interface
class Shape
{
    public:
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
    virtual ~Shape(){}
};

//Concrete Prototype
class Circle : public Shape
{
    private:
    int radius_;
    public:
    Circle(int r) : radius_(r){}
    Shape* clone() override
    {
        return new Circle(*this);
    }
    void draw() override
    {
        std::cout<<"Drawing a circle"<<std::endl;
    }
};

class Rectangle : public Shape
{
    private:
    int len,wid;
    public:
    Rectangle(int l,int w) : len(l),wid(w){}
    Shape* clone() override
    {
        return new Rectangle(*this);
    }
    void draw() override
    {
        std::cout<<"Drawing a Rectangle"<<std::endl;
    }
};

int main()
{
    Circle circlePrototype(3);
    Rectangle rectPrototype(2,4);

    Shape* shape1 = circlePrototype.clone();
    shape1->draw();

    delete shape1;

    return 0;
}
