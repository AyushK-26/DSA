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

Node* reverseList(Node* head) {
    if(!head || !head->next) return head;

    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}


//      TC = O(3n)      SC = O(n): Recursion/Call stack
Node* optimal1(Node* head) {
    head = reverseList(head);

    Node* prev = nullptr;
    Node* temp = head;
    int carry = 1;

    while(temp && carry) {
        int plusOne = temp->data + carry;

        if(plusOne >= 10) {
            temp->data = plusOne % 10;
            carry = 1;
        } else {
            temp->data = plusOne;
            carry = 0;
        }

        prev = temp;
        temp = temp->next;
    }
    
    if(carry) {
        Node* nodeToInsert = new Node(carry);
        prev->next = nodeToInsert;
    }
    
    head = reverseList(head);

    return head;
}


//      TC = O(3n)      SC = O(n): Recursion/Call stack
Node* optimal2(Node* head) {
    head = reverseList(head);

    Node* temp = head;
    while(temp) {
        if(temp->data != 9) {
            temp->data += 1;
            break;
        }
        temp->data = 0;
        temp = temp->next;
    }

    head = reverseList(head);
    if(!temp) {
        Node* nodeToInsert = new Node(1);
        nodeToInsert->next = head;
        head = nodeToInsert;
    }

    return head;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    Node* head = convertToLL(arr);
    
    head = optimal2(head);
    traverseLL(head);
    
    return 0;
}