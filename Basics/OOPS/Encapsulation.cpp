#include <iostream>
using namespace std;

class Fruit
{
private:
string fname;
public:
string getFruitName()
{
    return fname;
}
void setFruitName(string setFName)
{
    fname = setFName;
}
};

int main()
{
    Fruit f1;
    f1.setFruitName("Orange");
    std::cout<<f1.getFruitName();
    return 0;
}