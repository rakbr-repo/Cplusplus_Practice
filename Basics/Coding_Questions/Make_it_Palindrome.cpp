#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPal(string s)
{
    string s1=s;
    reverse(s1.begin(),s1.end());
    return s1==s;
}
int main()
{
    string ipString;
    std::cout<<"Give a string : ";
    getline(cin,ipString);
    int i;
    for(i=0;i<ipString.length()-1;i++)
    {
        if(isPal(ipString.substr(i,ipString.length()-i)))
        {
            break;
        }
    }
    string op = ipString.substr(0,i);
    reverse(op.begin(),op.end());
    std::cout<<"output is : "<<op<<std::endl;

    return 0;
}