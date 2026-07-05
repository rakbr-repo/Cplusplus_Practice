#include<iostream>
using namespace std;

class Vehicle
{
    public:
    virtual void start()=0;
    virtual ~Vehicle(){}
};

class Car : public Vehicle
{
    public:
    void start() override
    {
        cout<<"Car starts"<<endl;
    }
};

class Bike : public Vehicle
{
    public:
    void start() override
    {
        cout<<"Bike starts"<<endl;
    }
};

class VehicleFactory
{
    public:
    static Vehicle* createVehicles(string nameOfVehicle)
    {
        if(nameOfVehicle=="Car")
        {
            return new Car();
        }
        else if(nameOfVehicle=="Bike")
        {
            return new Bike();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    Vehicle* v1 = VehicleFactory::createVehicles("Car");
    v1->start();
    return 0;
}