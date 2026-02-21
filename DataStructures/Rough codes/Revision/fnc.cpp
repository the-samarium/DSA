#include<iostream>
using namespace std;
//passed by value
int add(int a , int b){
    return a+b;
}
// passed by refrence
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
//pasing structures in functons
struct Car{
    int milage;
    int price;
};
void myFunc(Car c){
    cout<<"Price is "<<c.price<<" and milage is "<<c.milage<<endl;
}
//function overloading
int func(int a, int b){
    return a +b;
}
float func(float x , float y){
    return x + y;
}
doublr func(double l,double m ){
    return l + m;
}
int main(){
    cout<<add(1,2)<<endl;
    Car c1 = {10,678909};
    myFunc(c1);
    return 0;
}