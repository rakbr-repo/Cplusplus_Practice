#include<iostream>
#include<vector>
using namespace std;

int partition(std::vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i= low-1;
    for(int j=0;j<vec.size()-1;j++)
    {
        if(vec[j]<pivot)
        {
            i++;
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i+1],pivot);
    return i+1;
}

void quickSort(std::vector<int> &vec,int low, int high)
{
    if(low<high)
    {
        int pi = partition(vec,low,high);
        quickSort(vec,low,pi-1);
        quickSort(vec,pi+1,high);
    }
}

int main() {
    vector<int> vec = {10, 7, 8, 9, 1, 5};
    int n = vec.size();
    quickSort(vec, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}