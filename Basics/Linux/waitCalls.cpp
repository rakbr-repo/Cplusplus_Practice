#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        cout<<"Child process running"<<endl;
        sleep(3);
        cout<<"Child process exited"<<endl;
        return 5;
    }
    else
    {
        int status;
        wait(&status);//waits for a child to exit 
        cout<<"Child exited and status recieved by parent: "<<WEXITSTATUS(status)<<endl;
    }
    return 0;
}
