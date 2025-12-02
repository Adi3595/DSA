//WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases) 2. Delete (all cases).

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

Node* head = nullptr;

void display() {

    Node* temp = head;
    cout<<"Doubly Linked List: ";
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int val, int pos) {
    if (pos <= 1) {
        insertAtBeginning(val);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp || !temp->next) { 
        insertAtEnd(val);
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtBeginning() {
    
    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    delete temp;
}

void deleteAtEnd() {
    Node* temp = head;
    if (!temp->next) { 
        delete temp;
        head = nullptr;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPosition(int pos) {
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < pos; i++)
        temp = temp->next;

    if (!temp) {
        cout<<"Position out of range!\n";
        return;
    }
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next;
    delete temp;
}

int main() {
    int choice, val, pos;
    do {
        cout<<"\n===== MENU =====\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Insert at Position\n";
        cout<<"4. Delete from Beginning\n";
        cout<<"5. Delete from End\n";
        cout<<"6. Delete from Position\n";
        cout<<"7. Display\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter value: ";
            cin>>val;
            insertAtBeginning(val);
            break;
        case 2:
            cout<<"Enter value: ";
            cin>>val;
            insertAtEnd(val);
            break;
        case 3:
            cout<<"Enter value: ";
            cin>>val;
            cout<<"Enter position: ";
            cin>>pos;
            insertAtPosition(val, pos);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            cout<<"Enter position: ";
            cin>>pos;
            deleteAtPosition(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            cout<<"Exiting...\n";
            break;
        }
    } while (choice != 8);

    return 0;
}
