#include<iostream>
using namespace std;

bool numPalindrome(int ipInt)
{
    int n = ipInt;
    int rev_num = 0;
    while(n>0)
    {
        int last_dig = n%10;
        rev_num = (rev_num*10)+last_dig;
        n/=10;
    }
    return ipInt==rev_num;
}

bool strPalindrome(string ipStr)
{
    int i=0,j=ipStr.length()-1;
    while(i<j)
    {
        if(ipStr[i]!=ipStr[j]){
            cout<<"Not palindrome"<<endl;
            return false;
        }
        i++;j--;
    }
    cout<<"Palidrome!"<<endl;
    return true;
}

int main()
{
    if(numPalindrome(121))
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}