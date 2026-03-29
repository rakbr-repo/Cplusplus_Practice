#include <iostream>
using namespace std;

class Shape
{
    public:
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Circle : public Shape
{
    public:
    void draw() override
    {
        std::cout<<"Circle drawn"<<std::endl;
    }
};

class Rectangle : public Shape
{
    public:
    void draw() override
    {
        std::cout<<"Rectangle drawn"<<std::endl;
    }
};

class ShapeFactory
{
    public:
    virtual Shape* getShapeFactory() = 0;
    virtual ~ShapeFactory(){}
};

class CircleFactory : public ShapeFactory
{
    public:
    Shape* getShapeFactory() override
    {
        return new Circle();
    }
};

class RectangleFactory : public ShapeFactory
{
    public:
    Shape* getShapeFactory() override
    {
        return new Rectangle();
    }
};

ShapeFactory* getFactory(char ch)
{
    if(ch == 'r'){return new RectangleFactory();}
    else{return new CircleFactory();}
}

int main()
{
    char ch;
    std::cout<<"Rectangle or Circle : (r/s) : ";
    std::cin>>ch;
    ShapeFactory* shapeFactory = getFactory(ch);
    if(shapeFactory!=nullptr)
    {
        Shape* deriveShape = shapeFactory->getShapeFactory();
        deriveShape->draw();
        delete deriveShape;
        delete shapeFactory;
    }
    return 0;
}
