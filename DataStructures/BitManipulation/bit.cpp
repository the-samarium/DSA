#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string DecToBin(int x)
{
    if (x == 0) return "0";  

    string res;
    while (x >= 1)
    {
        if (x % 2 == 1)
        {
            res = res + '1';  
        }
        else
        {
            res = res + '0';  
        }
        x = x / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int BinToDec(string x)
{
    int n = x.length();
    int res = 0;
    int multi = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (x[i] == '1')
        {
            res = res + multi;
        }
        multi = multi * 2;   
    }
    return res;
}

int main()
{
    int dec = 13;
    string bin = "1101";

    cout << DecToBin(dec) << " AND " << BinToDec(bin) << endl;
    return 0;
}
