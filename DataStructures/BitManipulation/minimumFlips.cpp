#include <iostream>
using namespace std;
int main()
{
    int flip = 0;
    int a=2;
    int b=6;
    int c=5;
    while (a != 0 || b != 0 || c != 0)
    {
        int abit = a & 1;
        int bbit = b & 1;
        int cbit = c & 1;

        if (cbit == 1)
        {
            if (abit == 0 && bbit == 0)
            {
                flip += 1;
            }
        }
        else
        { // cbit == 0
            if (abit == 1)
            {
                flip += 1;
            }
            if (bbit == 1)
            {
                flip += 1;
            }
        }

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    cout<<flip<<endl;
    return 0;
}