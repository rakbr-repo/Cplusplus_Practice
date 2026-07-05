#include<iostream>
using namespace std;

class PtrEx
{
    public:
    int* ptr;

    PtrEx(int val)
    {
        cout<<"Constructor called"<<endl;
        ptr = new int(val);
    }

    PtrEx(PtrEx&& obj)
    {
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    ~PtrEx()
    {
        delete ptr;
    }

    void display()
    {
        if(ptr!=nullptr)
        {
            cout<<"Display of ptr val : "<<*ptr<<endl;
        }
        else
        {
            cout<<"No ptr"<<endl;
        }
    }
};

int main()
{
    PtrEx obj(3);
    PtrEx obj2 = std::move(obj);

    cout<<"obj display"<<std::endl;
    obj.display();

    cout<<"obj2 display"<<std::endl;
    obj2.display();

}