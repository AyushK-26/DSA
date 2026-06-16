#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

Node* convertToLL(vector<int> arr) {
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

    cout<<endl;
}

void deleteHead(Node* &head) {
    if(head == nullptr) return; 

    Node* temp = head;
    head = head->next;
    
    delete temp;
}

void deleteTail(Node* &head) {
    if(head == nullptr) return;
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nullptr;
    delete nodeToDelete;
}

void deletePos(Node* &head, int k) {
    if(head == nullptr) return;
    if(k == 1) {
        deleteHead(head);
        return; 
    }

    int count = 1;
    Node* temp = head;
    //traverse either till the end of list or reached the node before nodeToDelete
    while(temp != nullptr && count < k-1) {
        temp = temp->next;
        count++;
    }

    //end of list or the last node: nodeToDelete doesn't exist
    //ALWAYS CHECK PTRS and NOT VARIABLES
    if(temp == nullptr || temp->next == nullptr) return;

    //delete the correct node
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void deleteElement(Node* &head, int element) {
    if(head == nullptr) return;
    if(head->data == element) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    //stops at temp->next == nullptr because accessing temp->next->data value
    while(temp->next != nullptr) {
        if(temp->next->data == element) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;

            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
}

void insertHead(Node* &head, int data) {
    Node* nodeToInsert = new Node(data);

    nodeToInsert->next = head;
    head = nodeToInsert;
}

void insertTail(Node* &head, int data) {
    Node* nodeToInsert = new Node(data);
    
    if(head == nullptr) {
        head = nodeToInsert;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = nodeToInsert;
}

void insertPos(Node* &head, int data, int k) {
    if(k == 1) {
        insertHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(temp != nullptr && count < k-1) {
        temp = temp->next;
        count++;
    }

    if(temp == nullptr) return;

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void insertAfter(Node* &head, int data, int element) {
    if(head == nullptr) return;

    Node* temp = head;

    while(temp != nullptr) {
        if(temp->data == element) {
            Node* nodeToInsert = new Node(data);
            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;

            return;
        }
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {1,2,3};

    Node* head = convertToLL(arr);

    traverseLL(head);

    deleteHead(head);
    traverseLL(head);

    deleteTail(head);
    traverseLL(head);

    deletePos(head, 1);
    traverseLL(head);

    insertHead(head, 10);
    traverseLL(head);

    insertTail(head, 20);
    traverseLL(head);

    insertPos(head, 30, 2);
    traverseLL(head);

    insertAfter(head, 40, 10);
    traverseLL(head);

    return 0;
}