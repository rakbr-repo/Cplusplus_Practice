#include<iostream>
using namespace std;

//S - Single responsibilty principle:
/**A class should only have one reason to change 
 * Example : Employee Class shouldnt have calculate salary, print report, save to database functions all in one class.
 * Sepearte classes should be there for each
 * */ 

class Employee
{
public:
    void calculateSalary()
    {
        cout << "Salary calculated\n";
    }
};

class EmployeePrinter
{
public:
    void print(const Employee&)
    {
        cout << "Printing employee\n";
    }
};

class EmployeeRepository
{
public:
    void save(const Employee&)
    {
        cout << "Saving employee\n";
    }
};

//O - Open/Closed Principle
/**
 * Open for extension , closed for modification
 * BAD Example : class Payment
{
public:
    void pay(string type)
    {
        if(type=="Card")
            cout<<"Card Payment\n";

        else if(type=="UPI")
            cout<<"UPI Payment\n";

        else if(type=="Cash")
            cout<<"Cash Payment\n";
    }
};
Adding a new payment method: Bitcoin means editing the class.
Every new feature changes old code.

Solution have seperate classes for each payment method
 * 
 */

class Payment
{
    public:
    virtual void pay() = 0;
    virtual ~Payment(){}
};

class UPIPayment : public Payment
{
    public:
    void pay() override
    {
        cout<<"UPI Payment"<<endl;
    }
};

class CardPayment : public Payment
{
    public:
    void pay() override
    {
        cout<<"Card Payment"<<endl;
    }
};


//L - Liskov Substitution Principle
/*Derived classes should be replaceable for their base class without changing program correctness.
class Bird
{
public:
    virtual void fly()
    {
        cout<<"Flying\n";
    }
};

class Penguin : public Bird
{
public:
    void fly() override
    {
        throw runtime_error("Penguins can't fly");
    }
};

The base class promised something the derived class can't honor.
If u ignore fly() in penguin and dont implement it , the penguin obj->fly() will call base class fly so its still wrong
*/

class Bird
{};

class FlyingBird : public Bird
{
    public:
    virtual void fly()
    {
        cout<<"Flying bird"<<endl;
    }
};

class Sparrow : public FlyingBird
{
};

class Penguin : public Bird
{};

//I - Interface Segregation Principle
/*Clients should not depend on interfaces they don't use
*BAD Example : 
class Machine
{
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

class Printer : public Machine
{
public:
    void print() override
    {
        cout<<"Printing\n";
    }

    void scan() override
    {
    }

    void fax() override
    {
    }
};
Printer doesn't support scan/fax.
Still forced to implement them.

Solution : Split interfaces 
*/

class IPrinter
{
    public:
    virtual void print()=0;
    virtual ~IPrinter()=default;
};

class IScanner
{
    public:
    virtual void scan()=0;
    virtual ~IScanner(){}
};

class IFax
{
    public:
    virtual void fax()=0;
    virtual ~IFax(){}
};

class MyPrinter : public IPrinter
{
    public:
    void print() override
    {
        cout<<"My printer is printing"<<endl;
    }
};

//D - Dependency Inversion Principle
/*High level modules should not depend on low level modules, both should depend on abstractions
High-level modules should depend on abstractions, not concrete implementations.
BAD Example : 

class Keyboard
{
public:
    void type()
    {
        cout<<"Typing\n";
    }
};

class Computer
{
    Keyboard keyboard;

public:
    void use()
    {
        keyboard.type();
    }
};

Computer is tightly coupled to Keyboard.
*/

class InputDevice
{
    public:
    virtual void input() = 0;
    virtual ~InputDevice() = default;
};

class Keyboard : public InputDevice
{
    public:
    void input() override
    {
        cout<<"Keyboard input"<<endl;
    }
};

class TouchScreen : public InputDevice
{
    public:
    void input() override
    {
        cout<<"TouchScreen input"<<endl;
    }
};

class Computer
{
    private:
    InputDevice& device;
    public:
    Computer(InputDevice& dev):device(dev){}

    void use()
    {
        device.input();
    }
    /*
    Keyboard keyboard;
    Computer comp(keyboard);
    */
};




