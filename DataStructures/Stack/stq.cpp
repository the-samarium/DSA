#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x)
    {
        // Step 1: Push new element into q2
        q2.push(x);

        // Step 2: Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    int pop()
    {
        int temp = q1.front();
        q1.pop();
        return temp;
        // removes front of queue i.e. top of stack
    }

    int top() { return q1.front(); }

    bool empty()
    {
        if (!q1.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack *obj = new MyStack();
    obj->push(10);
    int param_2 = obj->pop(); 
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    return 0;
}