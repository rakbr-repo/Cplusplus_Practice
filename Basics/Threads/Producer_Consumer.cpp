#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<queue>
using namespace std;

std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;

// void producer()
// {
//     for(int i=0;i<=5;i++)
//     {
//         std::lock_guard<std::mutex> lck(mtx);
//         q.push(i);
//         cout<<"Pushing : "<<i<<" as producer"<<endl;
//         cv.notify_all();
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));
//     }
// }

// void consumer()
// {
//     while(true)
//     {
//         std::unique_lock<std::mutex> lck(mtx);
//         cv.wait(lck,[]{return !q.empty();});
//         int data = q.front();
//         cout<<"Consumer got : "<<data<<endl;
//         q.pop();
//         lck.unlock();
//         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     }
// }

void producer()
{
    for(int i=0;i<5;i++)
    {
        std::lock_guard<std::mutex> lck(mtx);
        q.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cv.notify_all();
    }
}

void consumer()
{
    std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
    while(true)
    {
        lck.lock();
        cv.wait(lck,[]{return !q.empty();});
        cout<<"consumer got : "<<q.front()<<endl;
        q.pop();
        lck.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::thread pThread(producer);
    std::thread cThread(consumer);

    pThread.join();
    cThread.join();

    return 0;
}