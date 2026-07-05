#include <iostream>
using namespace std;

class Example
{
    private:
    mutable int x =10;
    public:
    void updateAndShow() const
    {
        x++;
        std::cout<<"x val is : "<<x<<endl;
    }
};

int main()
{
    //mutable on const
    const Example e;
    e.updateAndShow();

    //Array of pointers , pointer to array
    int a = 10, b = 20, c=30;
    int *arrOfPointers[] = {&a,&b,&c};

    int  (*PtrToArr)[3] = new int[1][3];
    (*PtrToArr)[0]=1, (*PtrToArr)[1]=2, (*PtrToArr)[2]=3;

    
    return 0;
}