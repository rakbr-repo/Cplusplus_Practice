#include<iostream>
#include<vector>
using namespace std;



int main()
{
    vector<int> v1,v2;

    auto byRef = [&](int m) {
        v1.push_back(m);
        v2.push_back(m);
    };

    auto byVal = [=](int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
    };

    auto byComb = [&v1,v2](int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
    };

    auto printVec = [](vector<int> loc){
        for(int i=0;i<loc.size();i++)
        {
            std::cout<<loc[i]<<" ";
        }
        std::cout<<std::endl;
    };

    byRef(10);
    byVal(20);
    byComb(30);

    printVec(v1);
    printVec(v2);

    return 0;
}