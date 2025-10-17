#include <iostream>
using namespace std;

long long POW(long long a, long long b) {
    if (b == 0) return 1;
    long long half = POW(a, b / 2);
    long long result = half * half;
    if (b % 2 == 1) result *= a;
    return result;
}

long long CountGood(long long n) {
    long long evenI = (n + 1) / 2;
    long long oddI = n / 2;
    // Even index: 0,2,4,6,8 → 5 choices
    // Odd index: 2,3,5,7 → 4 choices
    long long x = POW(5, evenI) * POW(4, oddI);
    return x;
}

int main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of good numbers: " << CountGood(n) << endl;
    return 0;
}
