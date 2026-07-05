#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::cout<<"Give a numbered string : ";
    string ip;
    cin>>ip;

    string op = "";
    int j = 0;
    int currCount = 0;
    for(int i=0;i<ip.length() || j<ip.length();i++)
    {
        char currChar = ip[j];
        if(currChar == ip[i])
        {
            currCount++;
        }
        else
        {
            op.append(std::to_string(currCount));
            op+=currChar;
            j = i;
            i--;
            currCount = 0;
        }
    }
    std::cout<<"Result is : "<<op<<std::endl;
}