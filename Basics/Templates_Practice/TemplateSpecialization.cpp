#include<iostream>
using namespace std;

//function template specialization
template<typename T>
void display(T x)
{
    cout<<x<<endl;
}

template<>
void display(const char* c)
{
    cout<<"String : "<<c<<endl;
}

//class template
//Primary Template
template<typename T>
class Printer
{
    public:
    void print()
    {
        cout<<"Generic Printer"<<endl;
    }
};

//Full template Specialization
template<>
class Printer<std::string>
{
    public:
    void print()
    {
        cout<<"String printer"<<endl;
    }
};

//Partial template Specialization - works only for classes
template<typename T,typename U>
class KeyVal
{
    private:
    T x; U y;
    public:
    void display()
    {
        cout<<"Generic Key"<<x<<"Value"<<y<<endl;
    }
};

template<typename T>
class KeyVal<T,int>
{
    private:
    T x; int y;
    public:
    void display()
    {
        cout<<"Int Partial specialized Key"<<x<<"Value"<<y<<endl;
    }
};

int main()
{
    //func
    display(10);
    display("Hello");
    //class
    Printer<int> p1;
    p1.print();
    Printer<string> p2;
    p2.print();

    KeyVal<string, string> kv1;
    kv1.display();
    KeyVal<string,int> kv2;
    kv2.display();
    return 0;
}