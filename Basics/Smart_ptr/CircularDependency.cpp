#include<iostream>
#include<memory>
using namespace std;

class B;
class A
{
    public:
    std::shared_ptr<B> Bptr;
};

class B
{
    public:
    std::weak_ptr<A> Aptr;
};

int main()
{
    std::shared_ptr<A> aPtr = make_shared<A>();
    std::shared_ptr<B> bPtr = make_shared<B>();

    aPtr->Bptr = bPtr;
    bPtr->Aptr = aPtr;

    
    return 0;
}