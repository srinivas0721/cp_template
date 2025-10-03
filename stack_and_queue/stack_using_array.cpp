#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF LLONG_MAX >> 1
const int MOD = 1e9 + 7;

class Queue {
    int size;
    int* arr;
    int top;
public: 
    Stack() {
        size = 1000;
        top = -1;
        arr = new int[size];
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1; // handle empty stack
        }
        return arr[top];
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top = top + 1;
        arr[top] = x;
    } 

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1; // handle empty pop
        }
        int x = arr[top];
        top = top - 1;
        return x;
    }

    int Size() {
        return top + 1;
    }

    bool empty() {
        return top == -1;
    }
};

signed main() {
    ios::sync_with_stdio(false);trtr
    cin.tie(NULL);

    Stack st;

    // push entries
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Current size: " << st.Size() << endl;   // 3
    cout << "Top element: " << st.Top() << endl;     // 30

    // pop entries
    cout << "Popped: " << st.pop() << endl;          // 30
    cout << "Popped: " << st.pop() << endl;          // 20

    cout << "Current size: " << st.Size() << endl;   // 1
    cout << "Top element: " << st.Top() << endl;     // 10

    return 0;
}
