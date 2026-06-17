#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node* convertToDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }

    return head;
}

void traverseDLL(Node* &head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverseDLL(Node* &head) {
    if(head == nullptr || head->next == nullptr) return;

    Node* curr = head;
    Node* temp = nullptr;

    while(curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    head = temp->prev;
}

int main() {
    vector<int> arr = {1,2,3,4};
    Node* head = convertToDLL(arr);
    traverseDLL(head);

    reverseDLL(head);
    traverseDLL(head);
    
    return 0;
}