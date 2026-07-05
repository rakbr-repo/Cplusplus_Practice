#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//Example 1
template<typename T>
void print(T x)
{
    cout<<x<<endl;
}

template<typename T, typename... Args>
void print(T x, Args... args)
{
    cout<<"Unpacking : "<<x<<endl;
    print(args...);
}

//Example 2
template<typename T>
string to_string_helper(const T& val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

template<typename T, typename... Args>
string join_string_with_commas(T first,Args... args)
{
    std::string result = to_string_helper(first);

    if constexpr (sizeof...(args) > 0)
    {
        ((result += "," + to_string_helper(args)),...);
    }
    return result;
}

int main()
{
    print(1,2.5,"hello");

    std::string s1 = join_string_with_commas(1,"hello",2.5);
    cout<<s1<<endl;
}