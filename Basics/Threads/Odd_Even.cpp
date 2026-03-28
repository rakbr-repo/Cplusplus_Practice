#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
std::mutex mtx;
std::condition_variable cv;
int number = 0;

void even()
{
    while(true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]{
            return number%2 == 0;
        });

        if(number > 20)
        {
            number++;
            cv.notify_all();
            break;
        }
        std::cout<<number++<<" ";
        cv.notify_all();
    }
}

void odd()
{
    while(true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]{
            return number%2 != 0;
        });
        if(number > 20)
        {
            number++;
            cv.notify_all();
            break;
        }
        std::cout<<number++<<" ";
        cv.notify_all();
    }
}

int main()
{
    thread t1(even);
    thread t2(odd);

    t1.join();
    t2.join();
    return 0;

}