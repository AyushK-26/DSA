#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data, Node* prev = nullptr, Node* next = nullptr ) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node* convertToDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* nodeToInsert = new Node(arr[i]);

        nodeToInsert->prev = mover;
        mover->next = nodeToInsert;

        mover = mover->next;
    }

    return head;
}

void traverseDLL(Node* &head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteHead(Node* head) {
    if(!head) return head;

    if(!head->next) {
        delete head;
        return nullptr;
    }

    Node* nodeToDelete = head;
    head = head->next;
    head->prev = nullptr;
    delete nodeToDelete;

    return head;
}


//      TC = O(n)       SC = O(1)
Node* deleteAllOccurences(Node* head, int k) {
    Node* temp = head;
    while(temp) {
        if(temp->data == k) {
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            
            if(prevNode) prevNode->next = nextNode;
            if(nextNode) nextNode->prev = prevNode;
            
            if(temp == head) head = head->next;
            
            delete temp;
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    Node* head = convertToDLL(arr);

    head = deleteAllOccurences(head, k);
    traverseDLL(head);
    
    return 0;
}