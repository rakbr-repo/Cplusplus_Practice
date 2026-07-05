#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack
{
    private:
    vector<T> data;
    public:
    void push(T val)
    {
        data.push_back(val);
    }
    T top()
    {
        return data.back();
    }
};

template<typename T1,typename T2>
class Pair
{
    private:
    T1 key;
    T2 value;
    public:
    Pair(T1 k,T2 v) : key(k),value(v){}
    void setValue(T2 val){value=val;}
};

int main()
{
    Stack<int> st1;st1.push(1);
    Stack<string> st2;st2.push(std::string("Rak"));
}