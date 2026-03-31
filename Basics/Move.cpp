#include <iostream>
#include <vector>
using namespace std;

void takeRval(std::vector<int>&& r)
{
    for(int i=0;i<r.size();i++)
    {
        std::cout<<r[i]<<std::endl;
    }
}
int main()
{
    vector<int> ex = {3,4,5,6};
    vector<int> ex2 = std::move(ex);
    takeRval(std::move(ex2));
    for(int i=0;i<ex.size();i++)
    {
        //will not execute , ex.size() == 0
        std::cout<<ex[i]<<std::endl;
    }

    //lvalue
    int x =10;
    int& lval = x;
    std::cout<<"lval , x val : "<<lval<<" , "<<x<<" its addresses : "<<&x<<" , "<<&lval<<std::endl;

    //rvalue
    int&& rv = 5;
    int a =5;
    int&& rv2 = rv+2+x;
    std::cout<<"rv, a, rv2 val : "<<rv<<" , "<<a<<" , "<<rv2<<" addresses : "<<&rv<<" , "<<&rv<<std::endl;
    return 0;

}