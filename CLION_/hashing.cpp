#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Hashing using map
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;  // automatically initializes freq[arr[i]] to 0 if not present
    }

    // Output frequency
    cout << "\nElement frequencies:\n";
    for (auto pair : freq) {
        cout << "Number " << pair.first << " appears " << pair.second << " times.\n";
    }

    return 0;
}
