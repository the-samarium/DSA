#include <iostream>
using namespace std;
// encapsulation
class Car
{
    // access modifiers
private:
    // Private data members (cannot be accessed directly outside the class)
    int price;
    int milage;
    string name;

public:
    int wheeler;
    string nationality;
    // parameterized constructor
    Car(string name, int price, int milage,string nationality,int wheeler)
    {
        this->name = name;
        this->price = price;
        this->milage = milage;
        this->nationality=nationality;
        this->wheeler=wheeler;
    }
    // getter functions to access private values
    string getName()
    {
        return name;
    }
    int getPrice()
    {
        return price;
    }
    int getMilage()
    {
        return milage;
    }

    string setName(string name){
        this->name=name;
        return name;
    }
    
    int setPrice(int price){
        this->price=price;
        return price;
    }
    // member function
    void BookCar(string pickupDate)
    {
        cout << "Your car (" << name << ") is booked and can be collected on "
             << pickupDate << endl;
    }
    void getInfo()
    {
        string name = getName();
        int price = getPrice();
        int milage = getMilage();

        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Mileage: " << milage << " km/l" << endl;
        cout << "Nationality: " << nationality << endl;
        cout<<"Wheels:"<< wheeler<<endl;
    }
    //Copy constructor doing SHALLOW COPY
    Car(Car &object){
        this->name=object.name;
        this->price=object.price;
        this->milage=object.milage;
        this->nationality=object.nationality;
        this->wheeler=object.wheeler;
    }
};

class Bike:public Car{
    public:
    string name;
    int price;
    int milage;

    Bike(string name, int price, int milage, string nationality, int wheeler)
        : Car(name, price, milage, nationality, wheeler)
    {
        this->name = name;
        this->price = price;
        this->milage = milage;
        this->nationality = nationality;
        this->wheeler = wheeler;
    }
     // member function
    void BookBike(string pickupDate)
    {
        cout << "Your bike (" << name << ") is booked and can be collected on "
             << pickupDate << endl;
    }
    void getBikeInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Mileage: " << milage << " km/l" << endl;
        cout << "Nationality: " << nationality << endl;
        cout<<"Wheels:"<< wheeler<<endl;
    }
};

int main()
{
    // object 1
    // Car car1("Wagnor", 400000, 35,"Indian",4);
    // car1.getInfo();
    // car1.BookCar("20-Aug-2025");

    // object 2
    // Car car2("Scrpio", 1200000, 30,"Indian",4);
    // car2.getInfo();
    // car2.BookCar("20-Jan-2026");
    // //copying car2 object in car3 using copy constructor
    // Car car3(car2);
   
    // car3.setName("Maruti");
    // car3.setPrice(800000);
    // car3.getInfo();

    Bike bike1("Pulsar",80000,55,"American",2);
    bike1.getBikeInfo();
    bike1.nationality; //This throws error when we inherit Car class as private

    return 0;
}
