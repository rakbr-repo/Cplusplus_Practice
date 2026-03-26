#include <iostream>

using namespace std;


//Abstraction example
class Shape
{
    protected:
    string color;

    public:
    Shape(string color)
    {
        this->color = color;
    }

    virtual double getArea() = 0;

    string getColor()
    {
        return color;
    }

    virtual ~Shape(){}
};

class Rectangle : public Shape
{
    double length;
    double width;

    public:
    Rectangle(string color , double length , double width) : Shape(color)
    {
        this->length = length;
        this->width = width;
    }

    double getArea() override
    {
        return length * width;
    }

    ~Rectangle(){}

};


//Pure virtual class example : 
class Printable
{
    public:
    virtual void print()=0;

    virtual ~Printable(){}
};

class Document : public Printable
{
    public:
    void print() override
    {
        cout<<"Print doc "<<endl;
    }
};

class Photo : public Printable
{
    public:
    void print() override
    {
        cout<<"Print pic"<<endl;
    }
}
;

int main()
{
    Shape *s1 = new Rectangle("Red", 4 ,3);
    cout<<"Area is : "<<s1->getArea()<<" "<<"Color is : "<<s1->getColor()<<endl;

    //pure virtual example:
    Printable *p1 = new Document();
    Printable *p2 = new Photo();

    p1->print();p2->print();
    return 0;
}