#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};
Node* ConvertArr2DLL(vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* ReverseDLL(Node* head) {
    if(head==NULL||head->next==NULL)
    return head;

    
    Node* last = nullptr;

    while (head) {
        last = head;                   // keep track of last seen node
        Node* rem = head->back;        // swap logic
        head->back = head->next;
        head->next = rem;
        head = head->back;             // move "forward" (was next)
    }

    return head;  // last processed node is new head
}



void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    vector<int>arr={12,5,8,7};
    Node* head = ConvertArr2DLL(arr);
    head = ReverseDLL(head);
    print(head);
    return 0;
}