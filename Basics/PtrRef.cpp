#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *myPtr = &x;
    std::cout<<"x val is : "<<x<<" myPtr val is : "<<*myPtr<<std::endl;
    *myPtr = 20;
    std::cout<<"x val is : "<<x<<" myPtr val is : "<<*myPtr<<std::endl;

    int &myRef = x;
    myRef = 30;
    std::cout<<"x val is : "<<x<<" myPtr val is : "<<*myPtr<<" myRef val is : "<<myRef<<std::endl;

    int *myArr;
    myArr = new int[5]{1,2,3,4,5};

    for(int i=0;i<5;i++)
    {
        std::cout<<*(myArr+i)<<std::endl;
    }

    int x1 =10;
    int *p1 = &x1;
    int **r1 = &p1;//pointer to pointer
    cout << "x1 value: " << x1 << ", address: " << &x1 << endl;

    cout << "p1 value (address of x1): " << p1 
         << ", *p1 (value of x1): " << *p1
         << ", address of p1: " << &p1 << endl;

    cout << "r1 value (address of p1): " << r1 
         << ", *r1 (value of p1): " << *r1 
         << ", **r1 (value of x1): " << **r1
         << ", address of r1: " << &r1 << endl;

}