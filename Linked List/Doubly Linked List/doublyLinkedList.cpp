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

void deleteHead(Node* &head) {
    if(head == nullptr) return;
    
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* nodeToDelete = head;
    head = head->next;
    head->prev = nullptr;

    delete nodeToDelete;
}

void deleteTail(Node* &head) {
    if(head == nullptr) return;
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void deletePos(Node* &head, int k) {
    if(head == nullptr) return;
    if(k == 1) {
        deleteHead(head);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while(temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    if(temp == nullptr) return;
    
    if(temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    temp->prev->next = temp->next;
    delete temp;
}

void deleteElement(Node* &head, int element) {
    if(head == nullptr) return;
    if(head->data == element) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == element) {
            if(temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }

            temp->prev->next = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

void insertHead(Node* &head, int data) {
    Node* nodeToInsert = new Node(data);

    if(head == nullptr) {
        head = nodeToInsert;
        return;
    }

    head->prev = nodeToInsert;
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
    nodeToInsert->prev = temp;
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

    if(temp->next != nullptr) {
        temp->next->prev = nodeToInsert;
        nodeToInsert->next = temp->next;
    }
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void insertAfter(Node* &head, int data, int element) {
    if(head == nullptr) return;
    
    Node* temp = head;

    while(temp != nullptr) {
        if(temp->data == element) {
            Node* nodeToInsert = new Node(data);
            if(temp->next != nullptr) {
                temp->next->prev = nodeToInsert;
                nodeToInsert->next = temp->next;
            }
            temp->next = nodeToInsert;
            nodeToInsert->prev = temp;
            return;
        }
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {1,2,3,4};
    Node* head = convertToDLL(arr);
    traverseDLL(head);

    deleteHead(head);    
    traverseDLL(head);

    deleteTail(head);
    traverseDLL(head);

    deletePos(head, 1);
    traverseDLL(head);

    deleteElement(head, 3);
    traverseDLL(head);

    insertHead(head, 10);
    traverseDLL(head);

    insertTail(head, 20);
    traverseDLL(head);

    insertPos(head, 30, 2);
    traverseDLL(head);

    insertAfter(head, 40, 10);
    traverseDLL(head);

    return 0;
}