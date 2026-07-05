#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    std::string data = "100 ruppee note";
    std::istringstream iss(data);
    int a;string b,c;
    iss>>a>>b>>c;
    cout<<"istream example : "<<a<<" "<<b<<" "<<c<<endl;

    int x =10;string y ="chips";int z=100;
    std::ostringstream oss;
    oss<<x<<" "<<y<<" "<<z;
    cout<<oss.str()<<endl;

    std::stringstream ss;
    ss<<10<<" "<<20<<endl;
    int p,q;
    ss>>p>>q;
    cout<<"p = "<<p<<"q = "<<q<<endl;

    return 0;
    
}