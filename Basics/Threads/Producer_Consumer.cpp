#include<iostream>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<chrono>
#include<thread>
using namespace std;

std::queue<int> q;
const int BUFFER_SIZE = 5;
std::mutex mtx;
std::condition_variable cv,cv2;
int generate_num = 0;

void producer()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        unique_lock<mutex> lck(mtx);
        cv.wait(lck,[]{
            return q.size()<BUFFER_SIZE;
        });
        std::cout<<"Producer pushed : "<<generate_num<<std::endl;
        q.push(generate_num++);
        lck.unlock();
        cv2.notify_one();
    }
}

void consumer()
{
    while(true)
    {
        unique_lock<mutex> lck(mtx);
        cv2.wait(lck,[]{
            return !q.empty();
        });
        std::cout<<"Consumer popped : "<<q.front()<<std::endl;
        q.pop();
        lck.unlock();

        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}