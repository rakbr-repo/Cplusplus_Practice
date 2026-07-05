#include<iostream>
#include<cstring>
using namespace std;

class String
{
    private:
    char* data;

    public:
    //constructor
    String(const char* str="")
    {
        data = new char[strlen(str)+1];
        strcpy(data,str);
        cout<<"Constructor"<<endl;
    }
    //Destructor
    ~String()
    {
        delete[] data;
        cout<<"Destructor called"<<std::endl;
    }
    //copy constructor
    String(const String& obj)
    {
        data = new char[strlen(obj.data)+1];
        strcpy(data,obj.data);
        cout<<"Copy const called"<<endl;
    }
    //Copy Assignment operator
    String& operator=(String& obj)
    {
        if(this!=&obj)
        {
            delete[] data;
            data = new char[strlen(obj.data)+1];
            strcpy(data,obj.data);
            cout<<"Copy assignment constructor"<<std::endl;
        }
        return *this;
    }
    //Move constructor
    String(String&& obj)
    {
        data = obj.data;
        obj.data = nullptr;
        cout<<"Move constructor"<<std::endl;
    }
    //Move assignment
    String& operator=(String&& obj)
    {
        if(this!=&obj)
        {
            delete[] data;
            data = obj.data;
            obj.data = nullptr;
            cout<<"move assignment"<<std::endl;
        }
        return *this;
    }
};

int main()
{
    String s1("Hello");

    //Copy
    String s2 = s1;

    //Copy assign
    String s3;
    s3 = s1;

    //move 
    String s4 = std::move(s1);

    //move assign
    String s5;
    s5 = std::move(s2);
}