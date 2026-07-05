#include<iostream>
#include<memory>
using namespace std;

class Singleton
{
    private:
    static std::unique_ptr<Singleton> singlePtr;
    //throw an compiler error of constructor cant be accesed
    Singleton()=default;
    public:
    //delete the copy and copy assignment so no objects can be created, throw an error of copy deleted
    Singleton(Singleton& obj) = delete;
    Singleton& operator=(Singleton& obj) = delete;
    // Delete Moving (Good practice to be explicit)
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    
    int x = 10;
    static Singleton* getInstance()
    {
        if(singlePtr==nullptr)
        {
            singlePtr = make_unique<Singleton>();
        }
        return singlePtr.get();
    }
};

int main()
{
    Singleton::getInstance()->x;
    return 0;
}