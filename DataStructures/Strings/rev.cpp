#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> chars = {'s','s','s','a','s','m','e','e','r','r','r','r','r'};

    int index = 0;
    int count = 1;

    for (int i = 1; i <= chars.size(); i++)
    {
        if (i < chars.size() && chars[i] == chars[i - 1])
        {
            count++;
        }
        else
        {
            chars[index++] = chars[i - 1];

            if (count > 1)
            {
                string c = to_string(count);
                for (char ch : c)
                    chars[index++] = ch;
            }

            count = 1;
        }
    }

    for (int i = 0; i < index; i++)
        cout << chars[i] << " ";

    return 0;
}
