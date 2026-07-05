#include<iostream>
using namespace std;

class Cpu
{
    public:
    void startCpu()
    {
        cout<<"Cpu started"<<endl;
    }
};

class Memory
{
    public:
    void MemoryLoaded()
    {
        cout<<"Memory Loaded"<<endl;
    }
};

class HardDisk
{
    public:
    void hardDiskRead()
    {
        cout<<"Hard disk read"<<endl;
    }
};

class ComputerFacade
{
    private:
    Cpu cpu;
    Memory mem;
    HardDisk hdd;
    public:
    void startComputer()
    {
        cpu.startCpu();
        mem.MemoryLoaded();
        hdd.hardDiskRead();
        cout<<"Computer started"<<endl;
    }
};

int main()
{
    ComputerFacade comp;
    comp.startComputer();
    return 0;
}