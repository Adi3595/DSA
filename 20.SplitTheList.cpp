// Given a list, split it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}. Getting this right for all the cases is harder than it looks. You should check your solution against a few cases (length = 2, length = 3, length=4) to make sure that the list gets split correctly near the shortlist boundary conditions. If it works right for length=4, it probably works right for length=1000. You will probably need special case code to deal with the (length <2) cases.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void insertEnd(Node*& head, int data) {
    Node* temp = newNode(data);
    if (!head) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout<<endl;
}

void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
    if (!source) { 
        frontRef = nullptr;
        backRef = nullptr;
        return;
    }
    if (!source->next) { 
        frontRef = source;
        backRef = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    frontRef = source;
    backRef = slow->next;
    slow->next = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* front = nullptr;
    Node* back = nullptr;

    int choice, val;

    do {
        cout<<"\n--- MENU ---\n";
        cout<<"1. Insert element\n";
        cout<<"2. Display original list\n";
        cout<<"3. Split into Front and Back halves\n";
        cout<<"4. Display Front list\n";
        cout<<"5. Display Back list\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>val;
                insertEnd(head, val);
                break;

            case 2:
                cout<<"Original List: ";
                printList(head);
                break;

            case 3:
                FrontBackSplit(head, front, back);
                cout<<"List has been split.\n";
                break;

            case 4:
                cout<<"Front List: ";
                printList(front);
                break;

            case 5:
                cout<<"Back List: ";
                printList(back);
                break;

            case 6:
                cout<<"Exiting program...\n";
                break;

        }
    } while (choice != 6);

    return 0;
}
