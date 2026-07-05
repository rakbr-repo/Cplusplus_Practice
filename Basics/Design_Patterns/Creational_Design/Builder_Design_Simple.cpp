#include<iostream>
using namespace std;

class Computer
{
    private:
    string cpu,gpu;
    public:
    void setCpu(string c)
    {
        cpu = c;
    }
    void setGpu(string g)
    {
        gpu = g;
    }
};

class ComputerBuilder
{
    private:
    Computer comp;
    public:
    ComputerBuilder& addCpu(string cpuName)
    {
        comp.setCpu(cpuName);
        return *this;
    }
    ComputerBuilder& addGpu(string gpuName)
    {
        comp.setGpu(gpuName);
        return *this;
    }
    Computer build()
    {
        return comp;
    }
};

int main()
{
    Computer comp1 = ComputerBuilder().addCpu("cpu").addGpu("gpu").build();
    
}