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


Node* ConvertArr2DLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev= temp;
    }
    return head;
}

void print(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    vector<int>arr={12,5,8,7};
    Node* head  = ConvertArr2DLL(arr);
    print(head);
    return 0;
}