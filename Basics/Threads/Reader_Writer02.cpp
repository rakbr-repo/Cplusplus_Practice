#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<chrono>
#include<atomic>
#include<unordered_map>
using namespace std;

std::unordered_map<int,string> editionBook;
std::mutex mtx;
std::condition_variable cv;
int current_version = 0;
bool finish = false;

void writer()
{
    for(int i=0;i<3;i++)
    {
        std::unique_lock<std::mutex> lck(mtx);
        std::string str = "Adding a new edition which is "+std::to_string(i)+" to the book";
        editionBook[i] = str;
        current_version++;
        lck.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::unique_lock<std::mutex> lck(mtx);
    finish = true;
    lck.unlock();
    cv.notify_one();
}

void reader()
{
    int local_version = 0;
    while(true)
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[&]{return current_version>local_version || finish;});
        if(finish){break;}
        cout<<"Reader latest version : "<<editionBook[local_version]<<endl;
        local_version=current_version;
        lck.unlock();
    }
}

int main()
{
    thread th1(writer);
    thread th2(reader);

    th1.join();
    th2.join();

    return 0;
}