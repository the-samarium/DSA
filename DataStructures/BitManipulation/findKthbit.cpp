#include <iostream>
using namespace std;
int main()
{
    // finding if kth bit of a number is zero or one in 32bit integers
    int num = 7;
    int k = 4;
    int n = 1 << k;
    if ((num & n) == 0)
    {
        cout << "Kth bit of 7 is zero";
    }
    else
    {
        cout << "Kth bit of 7 is one";
    }
    return 0;
}