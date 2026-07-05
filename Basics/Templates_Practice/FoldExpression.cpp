#include<iostream>
using namespace std;

//exmaple 1 
template<typename... Args>
void print(Args... args)
{
    ((std::cout<<args<<" "),...);
}

template<typename... Args> // left fold
int leftfoldSubtract(Args... args)
{
    return (... - args); // ((5-2)-1)
}

template<typename... Args> //right fold
int rightfoldSubtract(Args... args)
{
    return (args - ...); // (5-(2-1))
}

int init = 10;
template<typename... Args> //binary right fold
int binaryrightfold(Args... args)
{
    return (args - ... - init); // 5-(2-(1-10))
}

template<typename... Args> //binary left fold
int binaryleftfold(Args... args)
{
    return (init - ... - args); // ((10-5)-2)-1
}

int main()
{
    return 0;
}
