#include <iostream>
#include <string>
using namespace std;

//Product class
class Computer
{
    private:
    string cpu_;
    string storage_;
    public:
    void setCpu(string &cpu)
    {
        cpu_ = cpu;
    }
    void setStorage(string &storage)
    {
        storage_ = storage;
    }
};

//Builder Interface
class ComputerBuilder
{
    public:
    virtual void buildCpu(string &cpu) = 0;
    virtual void buildStorage(string &storage) = 0;
    virtual Computer getComputer() = 0;
};

//Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder
{
    public:
    void buildCpu(string &cpu) override
    {
        computer_.setCpu(cpu);
    }
    void buildStorage(string &storage) override
    {
        computer_.setStorage(storage);
    }
    Computer getComputer() override
    {
        return computer_;
    }
    private:
    Computer computer_;
};

//Director
class ComputerAssembler 
{
    public:
    Computer assemble(ComputerBuilder &compBuild)
    {
        string cpu = "Intel";
        compBuild.buildCpu(cpu);
        string storage = "256 GB";
        compBuild.buildStorage(storage);
        return compBuild.getComputer();
    }
};

int main()
{
    DesktopComputerBuilder deskBuild; 
    ComputerAssembler ComputerAssembler;
    Computer comp1 = ComputerAssembler.assemble(deskBuild);
    return 0;
}