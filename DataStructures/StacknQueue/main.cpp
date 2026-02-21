#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Stack
{
public:
    int topIndex = -1;
    int capacity = 10;
    vector<int> stk;

    // Adds an element to the top
    void push(int x)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        topIndex++;
        stk.push_back(x);
    }

    // Removes the top element
    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        stk.pop_back(); // Removes the last element from vector
        topIndex--;
    }

    // Displays the top element
    void displayTop()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top element is: " << stk[topIndex] << endl;
        }
    }
};

class Queue
{
private:
    int start = -1;
    int end = -1;
    int currsize = 0;
    int limit = 10;
    vector<int> q;

public:
    void enqueue(int x)
    {
        if (currsize == limit)
        {
            cout << "Queue full" << endl;
            return;
        }
        if (currsize == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % limit; // Move end forward circularly
        }
        q[end] = x;
        currsize++;
    }

    void dequeue()
    {
        if (currsize == 0)
        {
            cout << "Empty queue" << endl;
            return;
        }
        cout << "Dequeued: " << q[start] << endl;
        if (currsize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % limit; // Move start forward
        }
        currsize--;
    }
};

// stack using ll
struct Node
{
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class StkLL
{
    int size = 0;
    int limit = 10;
    Node *top = nullptr; // Start with nothing

public:
    void pushll(int x)
    {
        if (size == limit)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        // 1. Create node
        // 2. Point its next to the CURRENT top
        // 3. Update top to be this NEW node
        Node *newNode = new Node(x, top);
        top = newNode;

        size++;
    }

    void popLL()
    {
        if (top == nullptr)
        {
            cout << "Stack empty" << endl;
            return;
        }

        Node *temp = top; // Hold the current top to delete it
        top = top->next;  // Move top to the next node down
        delete temp;      // Free the memory
        size--;
    }

    void topLL()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top: " << top->data << endl;
        }
    }
};

class QLL
{
    int size = 0;
    int limit = 10;
    Node *top = nullptr; // Start with nothing
    Node *start = nullptr;
    Node *end = nullptr;
    void enqueue(int x)
    {
        if (size == limit)
        {
            cout << "Limit reached";
        }
        else if (start == nullptr)
        {
            // meaning first node
            Node *temp = new Node(x, nullptr);
            start = temp;
            end = temp;
            size++;
        }
        else
        {
            // mening not a start node
            Node *temp = new Node(x, nullptr);
            end->next = temp;
            end = end->next;
            size++;
        }
    }
    void dequeue()
    {
        if(size==0){
            cout<<"Empty queue";
        }
        else{
            Node * ptr = start;
            start=start->next;
            delete ptr;
            size--;

            if (start == nullptr) {
                end = nullptr;
            }
        }
    }
};

#include <iostream>
#include <queue>

class StackUsingQ {
    queue<int> q; 

public:
    void push(int x) {
        int current_size = q.size();
        q.push(x);
        for (int i = 0; i < current_size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) return;
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main()
{
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.displayTop(); // Should print 20

    myStack.pop();
    myStack.displayTop(); // Should print 10

    return 0;
}