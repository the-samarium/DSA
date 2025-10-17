#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long karatsuba(long long x, long long y)
{
    //
    if (x < 10 && y < 10)
    {
        return x * y;
    }
    long long n = max((long long)to_string(x).length(), (long long)to_string(y).length());
    long long m = n / 2;
    long long power = pow(10, m);

    long long a = x / power;  
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long bracket = karatsuba(a + b, c + d);

    return ac * pow(10, 2 * m) + bracket * pow(10, m) + bd;
}

int main()
{
    long long x = 123456, y = 234567;
    long long res = karatsuba(x, y);
    cout << "Product is: " << res << endl;
    return 0;
}