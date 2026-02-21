#include <iostream>
#include <queue>
using namespace std;

void addTask(queue<string>& q)
{
    string task;
    cout << "Enter a task: ";
    cin >> task;
    q.push(task);
}

void doTask(queue<string>& q)
{
    if (q.empty())
    {
        cout << "No tasks left\n";
        return;
    }
    cout << "Doing task: " << q.front() << endl;
    q.pop();
}

int main()
{
    queue<string> q;
    int choice;

    while (true)
    {
        cout << "\n1. Add task\n2. Do task\n3. Exit\n";
        cin >> choice;

        if (choice == 1)
            addTask(q);
        else if (choice == 2)
            doTask(q);
        else
            break;
    }

    return 0;
}
