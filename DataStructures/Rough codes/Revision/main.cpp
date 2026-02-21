#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Hello world" << endl;

    // vector
    vector<int> array = {1, 2, 3, 4, 5};
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << endl;
    }

    // variables
    int a = 12;
    double b = 3.14;
    char c = 'x';
    string d = "sameer";
    bool e = false;
    auto g = 56.7;
    int size = d.length();

    // declaring multiple variables
    int x = 5, y = 10, z = 15;
    int l, m, n;
    l = m = n = 20;

    cout << x + y + z << endl;
    cout << l << endl;

    // math functions
    cout << max(12, 43) << endl;
    cout << min(12, 43) << endl;
    cout << sqrt(144) << endl;
    cout << round(2.5) << endl;
    cout << log(4) << endl;

    // boolean statements
    cout << (x < y) << endl;

    // shorthand if-else
    int time = 23;
    string day = (time < 18) ? "Good day" : "Good evening";
    cout << day << endl;

    // array operations
    int arr[] = {10, 20, 30, 40, 50};
    cout << sizeof(arr) / sizeof(arr[0]) << endl;

    int multi[][2] = {{1, 2}, {3, 4}};
    for (int i = 0; i < 2; i++)
    {
        cout << multi[i][0] << " " << multi[i][1] << endl;
    }

    // 2D boolean grid
    bool ships[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };

    // struct
    struct Car
    {
        int price;
        double mileage;
        string name;
    };

    Car car1;
    car1.name = "Scorpio";
    car1.price = 1500000;
    car1.mileage = 35;

    Car car2 = {200000, 45, "Honda Civic"};

    struct Student
    {
        string name;
        int age;
        string grade;
    };

    Student st1 = {"Aniket", 17, "A+"};

    // memory address & references
    int num = 34;
    cout << &num << endl;

    // pointers
    string food = "pizza";
    string *ptr = &food;

    cout << food << endl;
    cout << ptr << endl;
    cout << *ptr << endl; //prints value of pointer i.e. derefrencing
    

    return 0;
}
