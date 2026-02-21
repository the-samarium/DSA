#include <iostream>
using namespace std;
//A namespace is a way to group related code together under a name. It helps you avoid naming conflicts when your code grows or when you use code from multiple sources.
class ClassA
{
public:
    // constructor is a special method that is automatically called when an object of a class is created. Has same name as Class and has no return type
    ClassA()
    {
        cout << "I am A constructor" << endl;
    }
    // Constructors run by themselves when you create an object. They set things up so everything is ready right away.
    int num;
    string name;
    // class methds
    void Sayhola();
};

void ClassA::Sayhola()
{
    cout << "Hola" << endl;
}

class Employee
{
    //demonstration of encapsuation
private:
    int salary;

public:
    // setter
    void setSal(int s)
    {
        salary = s;
    }
    // getter
    void getSal()
    {
        return salary;
    }
}


int main()
{
    ClassA c;
    c.name = "Stranger Things";
    c.num = 5;
    c.Sayhola();

    Employee myObj;
    myObj.setSalary(50000);
    cout << myObj.getSalary();
    return 0;
}