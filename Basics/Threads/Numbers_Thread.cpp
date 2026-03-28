#include <iostream>
#include <thread>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex mtx;
int threadTurn = 0;

void print1()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<i<<" ";
    }
    threadTurn =1;
    cv.notify_all();
}

void print2()
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock,[]{
        return threadTurn==1;
    });
    for(int i=5;i<10;i++)
    {
        std::cout<<i<<" ";
    }
    threadTurn=2;
    cv.notify_all();
}

void print3()
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock,[]{
        return threadTurn==2;
    });
    for(int i=10;i<15;i++)
    {
        std::cout<<i<<" ";
    }
}

int main()
{
    thread t1(print1);
    thread t2(print2);
    thread t3(print3);

    if(t1.joinable()){t1.join();}
    if(t2.joinable()){t2.join();}
    if(t3.joinable()){t3.join();}
}