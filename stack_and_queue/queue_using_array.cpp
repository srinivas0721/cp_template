#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int size;
    int front, back, count;

public:
    Queue() {   // default size 1000
        size = 1000;
        arr = new int[size];
        front = 0;
        back = -1;
        count = 0;
    }

    void push(int x) {  // renamed from enqueue
        if (count == size) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        back = (back + 1) % size;  // move back circularly
        arr[back] = x;
        count++;
    }

    int pop() {  // renamed from dequeue
        if (count == 0) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % size; // move front circularly
        count--;
        return x;
    }

    int Front() {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int back() {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[back];
    }

    int Size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q(5); // queue of size 5

    // push elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.Front() << endl; // 10
    cout << "back: " << q.back() << endl;   // 30
    cout << "Size: " << q.Size() << endl;   // 3

    // pop elements
    cout << "Popped: " << q.pop() << endl; // 10
    cout << "Popped: " << q.pop() << endl; // 20

    cout << "Front: " << q.Front() << endl; // 30
    cout << "Size: " << q.Size() << endl;   // 1

    return 0;
}
