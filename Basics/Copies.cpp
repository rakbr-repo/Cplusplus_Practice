#include <iostream>
using namespace std;

int main()
{
    //shallow copy
    int* a = new int(10);
    int* b = a;

    *b = 30;
    std::cout<<"a value is : "<<*a<<" b value is : "<<*b<<std::endl;

    //deep copy
    int *x = new int(20);
    int *y = new int(*x);
    *y = 40;
    std::cout<<"x value is : "<<*x<<" y value is : "<<*y<<std::endl;
    return 0;
}