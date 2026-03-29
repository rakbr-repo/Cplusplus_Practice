#include <iostream>
using namespace std;

class Singleton
{
    private:
    static Singleton* g_singleton;
    //private c_tor
    Singleton()
    {
        std::cout<<"Constructor called"<<std::endl;
    }

    public:
    static Singleton* getInstance()
    {
        if(g_singleton==nullptr)
        {
            g_singleton = new Singleton();
        }
        return g_singleton;
    }

    void print()
    {
        std::cout<<"Singleton used"<<std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

Singleton* Singleton::g_singleton = nullptr;
int main()
{
    Singleton* sg = Singleton::getInstance();
    sg->print();

    Singleton* sg2 = Singleton::getInstance();
    std::cout<<(sg2 == sg);
    return 0;
}