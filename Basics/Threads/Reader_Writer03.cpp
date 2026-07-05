#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
#include<atomic>
using namespace std;

std::string book;
std::atomic_flag bookSpinLck = ATOMIC_FLAG_INIT;

std::atomic<int> activeWriters{2};
std::atomic<int> currentVersion{0};

void safe_append(const std::string& data)
{
    while(bookSpinLck.test_and_set(std::memory_order_acquire))
    {}
    book+=data;
    bookSpinLck.clear(std::memory_order_release);
}

std::string safe_read()
{
    while(bookSpinLck.test_and_set(std::memory_order_acquire)){}
    std::string copy = book;
    bookSpinLck.clear(std::memory_order_release);
    return copy;
}

void writerA()
{
    for(int i=0;i<2;i++)
    {
        safe_append("Writer A update -> "+std::to_string(i+1));
        currentVersion.fetch_add(1,std::memory_order_release);
        currentVersion.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    activeWriters.fetch_sub(1,std::memory_order_release);
    currentVersion.notify_all();
}

void writerB()
{
    for(int i=0;i<2;i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        safe_append("Writer B update -> "+std::to_string(i+1));
        currentVersion.fetch_add(1,std::memory_order_release);
        currentVersion.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    activeWriters.fetch_sub(1,std::memory_order_release);
    currentVersion.notify_all();
}

void readerA()
{
    int localVer = 0;
    while(true)
    {
        int snapshotVer = currentVersion.load(std::memory_order_acquire);

        while(snapshotVer==localVer && activeWriters.load(memory_order_acquire)>0)
        {
            currentVersion.wait(snapshotVer);
            snapshotVer = currentVersion.load(std::memory_order_acquire);
        }

        if(activeWriters.load(memory_order_acquire) == 0){break;}

        cout<<"Read A : "<<safe_read()<<endl;
        localVer = snapshotVer;
    }

}

int main()
{
    thread wr1(writerA);
    thread wr2(writerB);
    thread rd1(readerA);

    wr1.join();
    wr2.join();
    rd1.join();
}
