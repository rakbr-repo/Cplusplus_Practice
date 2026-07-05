#include <iostream>
using namespace std;

class Vehicle
{
    public:
    Vehicle()
    {
        std::cout<<"This is a Vehicle"<<std::endl;
    }
};

class Windows
{
    public:
    Windows()
    {
        std::cout<<"This has Windows"<<std::endl;
    }
};

class FourWheeler : public Vehicle, public Windows
{
    public:
    FourWheeler()
    {
        std::cout<<"This is FourWheeler Vehicle"<<std::endl;
    }
};

class SpecialVehicle : public FourWheeler
{
    public:
    SpecialVehicle()
    {
        std::cout<<"This is special vechile too"<<std::endl;
    }
};

int main()
{
    FourWheeler f4;
    SpecialVehicle s1;
    return 0;
}