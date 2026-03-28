#include <iostream>
#include <thread>
using namespace std;

void task1()
{
    std::cout<<"Thread 1 executing : "<<this_thread::get_id<<std::endl;
}

void task2()
{
    std::cout<<"Thread 2 executing : "<<this_thread::get_id<<std::endl;
}

int main()
{
    thread t1(task1);
    thread t2(task2);

    std::cout<<"t1 id is : "<<t1.get_id()<<std::endl;
    std::cout<<"t2 id is : "<<t2.get_id()<<std::endl;

    if(t1.joinable())
    {
        t1.join();
        std::cout<<"t1 joined"<<std::endl;
    }

    if(t2.joinable())
    {
        t2.detach();
        std::cout<<"t2 detached"<<std::endl;
    }

    cout << "Main thread sleeping for 1 second...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Main thread awake.\n";

    return 0;
}