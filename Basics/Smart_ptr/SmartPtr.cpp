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

    //weak ptr
    shared_ptr<UniqueCls> cl = make_shared<UniqueCls>();
    weak_ptr<UniqueCls> wk = cl;
    std::cout<<"count of ref count : "<<wk.use_count()<<std::endl;
    if(auto sp = wk.lock())
    {
        sp->display();
    }

    //unique_ptr2
    std::unique_ptr<int> unq1 = std::make_unique<int>(10);
    std::unique_ptr<int> unq2 = move(unq1);
    cout<<"unq1 : "<<unq1.get()<<endl;

    //shared ptr2
    std::shared_ptr<int> shr1 = make_shared<int>(20);
    std::shared_ptr<int> shr2 = shr1;
    cout<<"count of shared ptrs : "<<shr1.use_count()<<endl;
    cout<<"addr of sh1 and sh2 : "<<shr1.get()<<" "<<shr2.get()<<endl;
    shr1.reset();
    cout<<"addr of sh1 and sh2 : "<<shr1.get()<<" "<<shr2.get()<<endl;


    return 0 ;
}