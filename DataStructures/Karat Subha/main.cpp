#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Karatsuba multiplication
long long karat(long long x, long long y)
{
    // Base case
    if (x < 10 && y < 10){
         return x * y;
    }
    
    long long n = max((long long)to_string(x).length(), (long long)to_string(y).length());
    long long m = n / 2;
    long long power = pow(10, m);

    // Split x and y
    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long z0 = karat(a, c);
    long long z1 = karat(b, d);
    long long z2 = karat(a + b, c + d);

    //formula: ac*10^(2m) + ((a+b)(c+d) - ac - bd)*10^m + bd
    return z0 * pow(10, 2 * m) + (z2 - z0 - z1) * power + z1;
}

int main()
{
    long long x = 123456, y = 234567;
    cout << "Product: " << karat(x, y) << endl;
    return 0;
}
