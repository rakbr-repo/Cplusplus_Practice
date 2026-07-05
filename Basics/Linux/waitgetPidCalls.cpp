#include<iostream>
#include<sys/wait.h>
#include<windows.h>

using namespace std;

int main()
{
    pid_t pid = fork();
    if(pid==0)
    {
        return 0;
    }
    cout<<"Parent waiting for child completion"<<endl;
    waitpid(pid,NULL,0);
    cout<<"child execution done"<<endl;
}