#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<atomic>

using namespace std;

int temp = 0;
std::mutex mtx;
std::condition_variable cv;
std::atomic<bool> execute = false;
bool running = true;
void sensor()
{
    while(running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        {
            std::lock_guard<mutex> lck(mtx);
            temp++;
            execute.store(true);
        }
        cv.notify_all();
    }
}

void logger()
{
    while(running)
    {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck,[]{
            return execute.load();
        });
        cout<<"Temperature is : "<<temp<<endl;
        execute.store(false);
        if(temp==20){running=false;}
    }
}

int main()
{
    thread t1(sensor);
    thread t2(logger);

    t1.join();
    t2.join();
    return 0;
}