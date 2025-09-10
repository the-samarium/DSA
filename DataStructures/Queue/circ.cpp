#include <iostream>
using namespace std;

#define CAPACITY 5   // max size of circular queue

class CircularQueue {
    int arr[CAPACITY];
    int front, rear, size;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Enqueue
    void enqueue(int x) {
        if (size == CAPACITY) {
            cout << "Queue is full!\n";
            return;
        }
        rear = (rear + 1) % CAPACITY;
        arr[rear] = x;
        size++;
        cout << "Added " << x << "\n";
    }

    // Dequeue
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Removed " << arr[front] << "\n";
        front = (front + 1) % CAPACITY;
        size--;
    }

    // Front element
    void getFront() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front = " << arr[front] << "\n";
    }

    // Print queue
    void printQueue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % CAPACITY;
            cout << arr[index] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.printQueue();

    cq.dequeue();
    cq.dequeue();

    cq.printQueue();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.printQueue();

    cq.getFront();

    return 0;
}
