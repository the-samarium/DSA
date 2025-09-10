// Example that implements all oops concepts together
// Ex:Design a C++ program to manage different types of employees in a company using the four pillars of OOP.
#include <iostream>
using namespace std;
//base abstract class
class Employee{
protected:
    int id;
    string name;
public:
    Employee(int id,string name){
        this->id=id;
        this->name=name;
    }

    virtual void calSalary()=0;
    virtual void displayInfo()=0;
    
};

//fulltime employee
class FulltimeE : public Employee{ 
private:
    double monthlySalary;
public:
    FulltimeE(int id,string name,double monthlySalary):Employee(id,name){
        this->monthlySalary=monthlySalary;
    }

    void calSalary(){
        cout<<"Monthly Salary of "<<name<<" is: "<<monthlySalary<<endl;
    }

    void displayInfo(){
        cout<<"Id: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Monthly Salary: "<<monthlySalary<<endl;
    }
};

//parttime employee
class ParttimeE : public Employee{
private:
    double hourlyRate;
    int hoursWorked;
public:
    ParttimeE(int id,string name,double hourlyRate,int hoursWorked):Employee(id,name){
        this->hourlyRate=hourlyRate;
        this->hoursWorked=hoursWorked;
    }

    void calSalary(){
        cout<<"Monthly Salary of "<<name<<" is: "<<hourlyRate*hoursWorked<<endl;
    }

    void displayInfo(){
        cout<<"Id: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Hourly Rate: "<<hourlyRate<<endl;
        cout<<"Hours Worked: "<<hoursWorked<<endl;
    }

};


int main(){
    

    FulltimeE e1(10,"Sam",80000);
    ParttimeE e2(100,"Andy",500,50);

    
    e1.displayInfo();
    e1.calSalary();
    e2.displayInfo();
    e2.calSalary();
    return 0;
}