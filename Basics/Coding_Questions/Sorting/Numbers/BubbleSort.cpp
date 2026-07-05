#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(std::vector<int> vec)
{
    for(int i=0;i<vec.size()-1;i++)
    {
        for(int j=0;j<vec.size()-i-1;j++)
        {
            if(vec[j]>vec[j+1])
            {
                swap(vec[j],vec[j+1]);
            }
        }
        cout<<"After pass "<<i+1<<" Arr looks like this : "<<endl;
        for(int k=0;k<vec.size();k++)
        {
            cout<<vec[k]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> vec = {10,2,5,1,7,8,1};
    bubbleSort(vec);
    return 0;
}