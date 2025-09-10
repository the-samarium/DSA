#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data, Node* next = nullptr, Node* back = nullptr) {
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};

  
    Node* head = new Node(arr[0]);
    Node* prev = head;

    // Build the doubly linked list
    for (int i = 1; i < 5; i++) {
        Node* curr = new Node(arr[i], nullptr, prev);
        prev->next = curr;
        prev = curr;
    }

    cout << "Forward traversal: ";
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
