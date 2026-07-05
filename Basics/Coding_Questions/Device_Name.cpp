#include<iostream>
#include<string>
#include<vector>
#include<unordered_map> 

using namespace std;

int main()
{
    vector<string> ip = {"docs","first","first","other"};
    unordered_map<string,int> track;
    vector<string> op;

    for(int i=0;i<ip.size();i++)
    {
        auto it = track.find(ip[i]);
        if(it == track.end())
        {
            op.push_back(ip[i]);
            track[ip[i]] = 1;
        }
        else
        {
            op.push_back(ip[i]+std::to_string(track[ip[i]]));
            track[ip[i]]++;
        }
    }
    for(int i=0;i<op.size();i++)
    {
        std::cout<<op[i]<<" ";
    }
}