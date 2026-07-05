#include<iostream>
#include<type_traits>
using namespace std;

template<typename T>
std::enable_if_t<std::is_integral_v<T>>
//template<std::integral T>
foo(T x)
{
    cout<<"Integral"<<endl;
}

template<typename T>
std::enable_if_t<std::is_floating_point_v<T>>
//template<std::floating_point T>
foo(T y)
{
    cout<<"Floating"<<endl;
}

int main()
{
    foo(10);
    foo(3.14);
}