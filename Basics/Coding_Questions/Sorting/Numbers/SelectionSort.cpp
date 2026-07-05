#include<iostream>
#include<vector>
using namespace std;

void selectionSort(std::vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        int min_ele_idx = i;
        for(int j=i+1;j<vec.size();j++)
        {
            if(vec[j]<vec[min_ele_idx])
            {
                min_ele_idx = j;
            }
        }
        swap(vec[i],vec[min_ele_idx]);
    }
    for(int k=0;k<vec.size();k++)
    {
        cout<<vec[k]<<" ";
    }
}

int main()
{
    vector<int> vec = {10,2,7,8,0,1,3};
    selectionSort(vec);
    return 0;
}