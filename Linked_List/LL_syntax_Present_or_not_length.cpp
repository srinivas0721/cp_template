#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF (LLONG_MAX>>1)
const int MOD = 1e9 +7;

struct Node{
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;      
    }
};

Node* ConvertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next  = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkifprezent(Node* head,int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

signed main (){
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<int> v = {2,5,3,4};

    Node* y = new Node(v[0]);
    cout << y->data << endl;

    Node* head = ConvertArr2LL(v);
    cout << head->data << endl;

    // Iterate in LL
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    cout << endl;

    // Length
    cout << "Length: " << lengthofLL(head) << endl; 

    // Check if an element is present
    cout << "Is 15 present? " << checkifprezent(head,15) << endl;
    cout << "Is 3 present? " << checkifprezent(head,3) << endl;

    return 0;
}
