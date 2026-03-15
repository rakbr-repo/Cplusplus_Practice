#include <iostream>
using namespace std;

//Function Template
template <typename T> 
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

//Class Template
template <typename T1, typename T2, typename T3> 
class PracticeTemp
{
    public:
    T1 x; T2 y; T3 z;
    PracticeTemp(T1 valX, T2 valY, T3 valZ) : x(valX), y(valY), z(valZ){}
    void getVal()
    {
        std::cout<<"x : "<<x<<" y : "<<y<<" z : "<<z<<std::endl;
    } 
};

//Template Variables
template <typename T> T myVar = T(3.145790876);

//Default templates
template <typename T1, typename T2=string>
class DefTemplate
{
    public:
    T1 x;
    T2 y;
    DefTemplate(T1 valX, T2 valY) : x(valX) , y(valY){}
    void getFunc()
    {
        std::cout<<"x is : "<<x<<" y is : "<<y<<std::endl;
    }
};

//Template Non-Type arg
template <typename T, int max> 
int arrMin(T arr[],int n)
{
    int m = max;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<m)
        {
            m = arr[i];
        }
    }
    return m;
}



int main()
{
    //function templates
    std::cout<<"int version : "<<myMax<int>(3,4)<<std::endl;
    std::cout<<"double version : "<<myMax<double>(3.2,4.4)<<std::endl;

    //class templates
    PracticeTemp<int , double, string> p1(3,5.2,"pratice");
    p1.getVal();

    //template variables
    std::cout<<"temp var example : "<<myVar<int><<std::endl;

    //def template
    DefTemplate<int> def1(3,"rak");
    def1.getFunc();

    //function non type arg
    int arr[] = {10,20,5,1,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"min arr : "<<arrMin<int,INT_MAX>(arr,n);

    //Function template arguement deduction 
    std::cout<<"myMax without using arg deduction : "<<myMax(2,5)<<std::endl;


    return 0;
}