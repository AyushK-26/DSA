#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = -1;
        this->next = nullptr;
    }

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

Node* convertToLL(vector<int> arr) {
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* nodeToInsert = new Node(arr[i]);
        temp->next = nodeToInsert;
        temp = temp->next;
    }

    return head;
}

void traverseLL(Node* &head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* optimal(Node* head) {
    if(!head || !head->next) return head;

    Node fakeHead0, fakeHead1, fakeHead2;

    Node* zeroMover = &fakeHead0;
    Node* oneMover = &fakeHead1;
    Node* twoMover = &fakeHead2;

    Node* temp = head;
    while(temp) {
        if(temp->data == 0) {
            zeroMover->next = temp;
            zeroMover = temp;
        } else if(temp->data == 1) {
            oneMover->next = temp;
            oneMover = temp;
        }else {
            twoMover->next = temp;
            twoMover = temp;
        }

        temp = temp->next;
    }

    zeroMover->next = fakeHead1.next ? fakeHead1.next : fakeHead2.next;
    oneMover->next = fakeHead2.next;
    twoMover->next = nullptr;

    return fakeHead0.next;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    Node* head = convertToLL(arr);
    
    head = optimal(head);
    traverseLL(head);
    
    return 0;
}