#include<iostream>
#include<memory>
using namespace std;

class UniqueCls
{
    public:
    void display()
    {
        cout<<"unique cls"<<std::endl;
    }
};

int main()
{
    //unique ptr
    unique_ptr<UniqueCls> p1 = make_unique<UniqueCls>();
    p1->display();
    std::cout<<p1.get()<<std::endl;
    unique_ptr<UniqueCls> p2 = move(p1);
    p2->display();
    std::cout<<p1.get()<<std::endl;

    //shared ptr
    shared_ptr<int> sh1 = make_shared<int>(10);
    shared_ptr<int> sh2 = sh1;
    shared_ptr<int> sh3 = make_shared<int>(30);
    std::cout<<"sh1 owners count : "<<sh1.use_count()<<std::endl;
    cout<<"sh1 : "<<*sh1<<" sh2 : "<<*sh2<<" sh3 : "<<*sh3<<endl;

    return 0 ;
}