#include<iostream>
#include<cstring>
using namespace std;

class String
{
    public:
    char* data;
    //constructor
    String(const char* str = "")
    {
        data = new char[strlen(str)+1];
        strcpy(data,str);
    }
    //destructor
    ~String()
    {
        delete[] data;
    }
    //copy constructor
    String(const String& str)
    {
        data = new char[strlen(str.data)+1];
        strcpy(data,str.data);
    }
    //copy assignement
    String& operator=(String& str)
    {
        if(this != &str)
        {   
            //delete whatever was there previously, create new char* data from what we passed as paaremeter
            delete[] data; 
            data = new char[strlen(str.data)+1];
            strcpy(data,str.data);
        }
        return *this;
    } 

    //move constructor
    String(String&& str)
    {
        data = str.data;
        str.data = nullptr;
    }

    //move assignment
    String& operator=(String&& str)
    {
        if(this!=&str)
        {
            delete[] data;
            data = str.data;
            str.data = nullptr;
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