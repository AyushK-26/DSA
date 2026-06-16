#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

Node* convertArrToLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void traverseLL(Node* &head) {
    Node* temp = head;

    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int lengthOfLL(Node* &head) {
    int count = 0;
    Node* temp = head;

    while(temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

bool checkIfPresent(Node* &head, int val) {
    Node* temp = head;
    
    while(temp) {
        if(temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    
    Node* head = convertArrToLL(arr);
    traverseLL(head);
    cout<<endl;
    cout<<lengthOfLL(head);
    cout<<endl;
    cout<<checkIfPresent(head, 6);

    return 0;
}