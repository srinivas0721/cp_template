#include <bits/stdc++.h>
using namespace std;

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

// Convert array to DLL
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

// Print forward
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print backward
void printReverse(Node* head) {
    if (!head) return;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (tail) {
        cout << tail->data << " ";
        tail = tail->back;
    }
    cout << endl;
}

// Delete head
Node* DeleteHead(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head) head->back = nullptr;
    delete temp;
    return head;
}

// Delete tail
Node* DeleteTail(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->back) temp->back->next = nullptr;
    else head = nullptr;
    delete temp;
    return head;
}

// Delete k-th element
Node* DeleteKthElement(Node* head, int pos) {
    if (!head) return nullptr;
    if (pos == 0) return DeleteHead(head);

    Node* temp = head;
    int cnt = 0;
    while (temp && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    if (!temp || !temp->next) return head;

    Node* remNode = temp->next;
    temp->next = remNode->next;
    if (remNode->next) remNode->next->back = temp;
    delete remNode;
    return head;
}

// Delete given element by value
Node* DeleteGivenElement(Node* head, int val) {
    if (!head) return nullptr;
    if (head->data == val) return DeleteHead(head);

    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) return head;

    Node* remNode = temp->next;
    temp->next = remNode->next;
    if (remNode->next) remNode->next->back = temp;
    delete remNode;
    return head;
}

// Insert before head
Node* InsertBeforeHead(Node* head, int val) {
    Node* newNode = new Node(val, head, nullptr);
    if (head) head->back = newNode;
    return newNode;
}

// Insert before tail
Node* InsertBeforeTail(Node* head, int val) {
    if (!head) return new Node(val);

    Node* temp = head;
    while (temp->next) temp = temp->next;

    Node* newNode = new Node(val, temp, temp->back);
    if (temp->back) temp->back->next = newNode;
    else head = newNode;

    temp->back = newNode;
    return head;
}

// Insert before the value given
Node* InsertBeforeValue(Node* head, int newVal, int targetVal) {
    if (!head) return new Node(newVal);
  
    if (head->data == targetVal) {
        Node* newNode = new Node(newVal, head, nullptr);
        head->back = newNode;
        return newNode; // new head
    }
    Node* temp = head;
    while (temp->next && temp->next->data != targetVal) {
        temp = temp->next;
    }
    if (!temp->next) {
        return head;
    }
    Node* newNode = new Node(newVal, temp->next, temp);
    temp->next->back = newNode;
    temp->next = newNode;

    return head;
}
//Insert before the kth element:
Node* InsertBeforeKthElement(Node* head, int k, int val) {
    if (head == NULL) return new Node(val);

    // Insert before head (k == 0)
    if (k == 0) {
        Node* newNode = new Node(val, head, nullptr);
        head->back = newNode;
        head = newNode;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    while (temp && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) return head; // position out of range

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}


// Insert after tail
Node* InsertAfterTail(Node* head, int val) {
    if (!head) return new Node(val);

    Node* temp = head;
    while (temp->next) temp = temp->next;

    Node* newNode = new Node(val, nullptr, temp);
    temp->next = newNode;
    return head;
}



// Main function
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = ConvertArr2DLL(arr);

    cout << "Forward: ";
    print(head);
    cout << "Backward: ";
    printReverse(head);

    head = InsertBeforeHead(head, 1);
    cout << "\nAfter inserting 1 before head: ";
    print(head);

    head = InsertBeforeTail(head, 6);
    cout << "After inserting 6 before tail: ";
    print(head);

    head = InsertAfterTail(head, 15);
    cout << "After inserting 15 after tail: ";
    print(head);

    head = DeleteHead(head);
    cout << "After deleting head: ";
    print(head);

    head = DeleteTail(head);
    cout << "After deleting tail: ";
    print(head);

    head = DeleteKthElement(head, 2);
    cout << "After deleting 3rd element (index 2): ";
    print(head);

    head = DeleteGivenElement(head, 8);
    cout << "After deleting element with value 8: ";
    print(head);

    cout << "Final backward: ";
    printReverse(head);

    return 0;
}
