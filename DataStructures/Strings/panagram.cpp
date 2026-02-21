#include <iostream>
using namespace std;
int main()
{
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    
    int arr[26] = {0};
    int num =0;
    for (int i = 0; i < sentence.size(); i++)
    {
        num = sentence[i]-'a';
        arr[num]++;
    }
    for(int itr : arr){
        if(itr ==0){
            return false;
        }
    }
    return true;
    return 0;
}