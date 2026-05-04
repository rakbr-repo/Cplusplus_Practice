#include <iostream>
using namespace std;

bool steppingNum(int num)
{
    int prevDig = -1;
    while(num)
    {
        int currDig = num%10;
        if(prevDig == -1)
        {
            prevDig = currDig;
        }
        else
        {
            if(std::abs(currDig-prevDig)!=1)
            {
                return false;
            }
        }
        prevDig = currDig;
        num/=10;
    }
    return true;
}
void displayNum(int n,int m)
{
    for(int i=n;i<=m;i++)
    {
        if(steppingNum(i))
        {
            std::cout<<i<<" ";
        }
    }
}
int main()
{
    displayNum(0,21);
    return 0;
}