#include<iostream>
using namespace std;

//Abstract Factory Interface
class Pizza
{
    public:
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual ~Pizza(){}
};

//Concrete Factories
class NewYorkCheesePizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout<<"Baking NY Cheese Pizza"<<std::endl;
    }
    void cut() override
    {
        std::cout<<"Cutting NY Cheese Pizza"<<std::endl;
    }
};

class NewYorkVegPizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout<<"Baking NY Veg Pizza"<<std::endl;
    }
    void cut() override
    {
        std::cout<<"Cutting NY Veg Pizza"<<std::endl;
    }
};

class ChicagoCheesePizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout<<"Baking Chicago Cheese Pizza"<<std::endl;
    }
    void cut() override
    {
        std::cout<<"Cutting Chicago Cheese Pizza"<<std::endl;
    }
};

class ChicagoVegPizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout<<"Baking Chicago Veg Pizza"<<std::endl;
    }
    void cut() override
    {
        std::cout<<"Cutting Chicago Veg Pizza"<<std::endl;
    }
};

//Abstract Product Interfacae
class PizzaFactory
{
    public:
    virtual Pizza* createCheesePizza() = 0;
    virtual Pizza* createVegPizza() = 0;
    virtual ~PizzaFactory(){}
};

//Concrete Products

class NewYorkPizzaFactory : public PizzaFactory
{
    Pizza* createCheesePizza() override
    {
        return new NewYorkCheesePizza();
    }

    Pizza* createVegPizza() override
    {
        return new NewYorkVegPizza();
    }
};

class ChicagoPizzaFactory : public PizzaFactory
{
    Pizza* createCheesePizza() override
    {
        return new ChicagoCheesePizza();
    }

    Pizza* createVegPizza() override
    {
        return new ChicagoVegPizza();
    }
};

int main()
{
    PizzaFactory* nyFactory = new NewYorkPizzaFactory();
    Pizza* nyCheesePizza = nyFactory->createCheesePizza();
    nyCheesePizza->bake();
    nyCheesePizza->cut();

    PizzaFactory* chiFactory = new ChicagoPizzaFactory();
    Pizza* chiVegPizza = chiFactory->createVegPizza();
    chiVegPizza->bake();
    chiVegPizza->cut();

    return 0;
}
