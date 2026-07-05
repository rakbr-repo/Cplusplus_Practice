#include<iostream>
using namespace std;

int add(int a,int b)
{
    cout<<"add called through fp : "<<a+b<<endl;
    return a+b;
}

void execute(int (*operation)(int,int))//callbacks
{
    cout<<"execute fn call made : "<<operation(3,4)<<endl;
}

int main()
{
    int (*fp)(int,int); //func ptr
    fp = add;
    cout<<fp(3,4);
    execute(add);

    int x =5;
    void *ptr = &x;
    cout<<*(int*)ptr<<endl;
}