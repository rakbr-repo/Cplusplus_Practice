#include<iostream>
using namespace std;

//Default copy ctor
class Demo1
{
    private:
    public:
    int x;
    Demo1(int y){
        x = y;
    }
};

//User defined copy ctor
class Demo2
{
    private:
    public:
    int *x;
    Demo2(int val)
    {
        x = new int(val);
    }
    Demo2(Demo2 &obj)
    {
        x = new int(*obj.x);
    }
    ~Demo2()
    {
        delete x;
    }
};

int main()
{
    //default copy ctor(shallow copy)
    Demo1 d(10);
    Demo1 def_d = d;
    std::cout<<"d obj val : "<<d.x<<" def_d obj val : "<<def_d.x<<std::endl;

    //user defined copy ctor
    Demo2 d2(10);
    Demo2 user_def_d = d2;
    std::cout<<"d2 obj val : "<<*d2.x<<" user_def_d val : "<<*user_def_d.x<<std::endl;
    *user_def_d.x=40;
    std::cout<<"after update d2 obj val : "<<*d2.x<<" user_def_d val : "<<*user_def_d.x<<std::endl;
    return 0;
}