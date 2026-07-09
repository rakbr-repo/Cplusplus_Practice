#include<iostream>
#include<thread>
#include<semaphore>

std::binary_semaphore evenSem{1};
std::binary_semaphore oddSem{0};
int counter = 0;

void even()
{
    for(int i=0;i<51;i++)
    {
        evenSem.acquire(); //waits for permission , which we have already given by setting 1
        std::cout<<counter++<<std::endl;
        oddSem.release();//signal odd thread
    }
}

void odd()
{
    for(int i=0;i<50;i++)
    {
        oddSem.acquire();//waits for permission
        std::cout<<counter++<<std::endl;
        evenSem.release();//signals even thread
    }
}

int main()
{
    std::thread t1(even);
    std::thread t2(odd);
    t1.join();
    t2.join();
    return 0;
}