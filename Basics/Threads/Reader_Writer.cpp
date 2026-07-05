#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<chrono>
#include<atomic>
using namespace std;

std::string book = "";
std::mutex mtx;
std::condition_variable cv;
int current_version = 0;
int active_writers = 2;

void writerA()
{
    for(int i=0; i<3;i++)
    {
        std::unique_lock<std::mutex> lck(mtx);
        book+="Writer A has written his "+std::to_string(current_version+1)+" edition.";
        lck.unlock();
        current_version++;
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::unique_lock<std::mutex> lck(mtx);
    active_writers--;
    lck.unlock();
    cv.notify_all();
}


void writerB()
{
    for(int i=0; i<3;i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lck(mtx);
        book+="Writer B has written his "+std::to_string(current_version+1)+" edition.";
        lck.unlock();
        current_version++;
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::unique_lock<std::mutex> lck(mtx);
    active_writers--;
    lck.unlock();
    cv.notify_all();
}

void readerA()
{
    int local_version = 0;
    while(true)
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[&]{return current_version>local_version || active_writers==0;});
        if(active_writers==0){
            break;
        }
        cout<<"Reader A reading the writer book : "<<book<<endl;
        local_version = current_version;
    }
}
void readerB()
{
    int local_version = 0;
    while(true)
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[&]{return current_version>local_version || active_writers==0;});
        if(active_writers==0){break;}
        cout<<"Reader B reading the writer book : "<<book<<endl;
        local_version = current_version;
    }
}

int main()
{
    thread wr1(writerA);
    thread wr2(writerB);
    thread rd1(readerA);
    thread rd2(readerB);

    wr1.join();
    wr2.join();
    rd1.join();
    rd2.join();
}