#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int KaratSuba(int x, int y) {
    // Base case
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Find the maximum length of digits
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;  

    // Split numbers
    int highX = x / (int)pow(10, m);
    int lowX  = x % (int)pow(10, m);
    int highY = y / (int)pow(10, m);
    int lowY  = y % (int)pow(10, m);

    // Recursive multiplications
    int z0 = KaratSuba(lowX, lowY);
    int z2 = KaratSuba(highX, highY);
    int z1 = KaratSuba(highX + lowX, highY + lowY);

    // Karatsuba formula: ac*10^2m + (a+b)(c+d)*10^m + bd
    return z2 * pow(10, 2 * m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

int main() {
    int a = 1234, b = 5678;
    cout << "Karatsuba multiplication: " << KaratSuba(a, b) << endl;
    cout << "Normal multiplication:    " << (a * b) << endl;
    return 0;
}
