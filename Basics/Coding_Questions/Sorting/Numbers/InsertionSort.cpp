#include<iostream>
#include<vector>
using namespace std;

void insertionSort(std::vector<int> &vec)
{
    for(int i=1;i<vec.size();i++)
    {
        int key = vec[i];
        int j = i-1;
        while(j>=0 && vec[j]>key)
        {
            cout<<"Comapre bw : "<<key<<" "<<vec[j]<<endl;
            vec[j+1]=vec[j];
            j--;
        }
        cout<<"Array after before inserting cuurent key: "<<key<<endl;
        for(int k=0;k<vec.size();k++)
        {
            cout<<vec[k]<<" ";
        }
        vec[j+1]=key;

        cout<<"Array after each pass : "<<i<<endl;
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
    insertionSort(vec);
    return 0;
}