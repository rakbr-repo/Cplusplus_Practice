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

//method2
void evenThread()
{
    for(int i=0;i<51;i++)
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[]{return number%2==0;});
        cout<<number<<endl;
        number++;
        cv.notify_all();
    }
}

void oddThread()
{
    for(int i=0;i<50;i++)
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[]{return number%2!=0;});
        cout<<number<<endl;
        number++;
        cv.notify_all();
    }
}

int main()
{
    thread t1(evenThread);
    thread t2(oddThread);

    t1.join();
    t2.join();
    return 0;

}