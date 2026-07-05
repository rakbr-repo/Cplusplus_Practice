#include <iostream>
using namespace std;

//Unions
union demoUnions
{
    int demoInt;
    float demoFloat;
};

//Nested Unions
struct Student
{
    string name;
    int rollno;

    union fees
    {
        int totalFees;
        int classesOneHasTaken;
    }feeStructure;

    union //anonymous union
    {
        char grade;
    };
};

int main()
{
    demoUnions u1;
    //can't chnage both values back to back and read it and same memory location is used. Only 1 memeber can be used at a time.
    u1.demoInt = 1;
    std::cout<<"int val is : "<<u1.demoInt<<std::endl;
    u1.demoFloat = 2;
    std::cout<<"float val is : "<<u1.demoFloat<<std::endl;

    //Nested Unions
    Student s1;
    s1.feeStructure.classesOneHasTaken = 8;
    std::cout<<"Amount of classes taken : "<<s1.feeStructure.classesOneHasTaken<<std::endl;
    s1.feeStructure.totalFees = 200000;
    std::cout<<"Total fees : "<<s1.feeStructure.totalFees<<std::endl;
    //anonymous union
    s1.grade = 'A';
    std::cout<<"print grade : "<<s1.grade<<std::endl;

    return 0;
}