#include<iostream>
#include<optional>
#include<variant>
#include<string>

using namespace std;

using DataValue = std::variant<int , double, string>;
std::optional<std::string> getUser(int n)
{
    if(n==1){return "Alice";}
    return std::nullopt;
}



int main()
{
    auto str = getUser(1);
    if(str.has_value())
    {
        cout<<"user is : "<<str.value()<<endl;
    }

    DataValue data = 20;
    data = 3.14;
    data = std::string("Hello");

    if(auto pStr = std::get_if<std::string>(&data))
    {
        cout<<"ptr string : "<<*pStr<<endl;
    }
}