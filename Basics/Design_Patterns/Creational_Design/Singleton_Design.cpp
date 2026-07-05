#include<iostream>
using namespace std;

class Singleton
{
    private:
    Singleton(){}
    Singleton(Singleton& obj)=delete;
    Singleton& operator=(Singleton& obj)=delete;
    public:
    static Singleton& getInstance()//singleton meyers
    {
        static Singleton instance;
        return instance;
    }
    void showMessage()
    {
        cout<<"Message showed"<<endl;
    }
};

int main()
{
    Singleton& s1 = Singleton::getInstance();
    s1.showMessage();
    return 0;
}