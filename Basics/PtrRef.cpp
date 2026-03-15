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
}