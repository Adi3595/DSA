//Implement Bubble sort using Doubly Linked List

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

void insertEnd(Node*& head, int val) {
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

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout<<temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout<<endl;
}

void bubbleSort(Node* head) {
    if (!head) return;

    bool swapped;
    Node* end = nullptr;

    do {
        swapped = false;
        Node* curr = head;

        while (curr->next != end) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
        }
        end = curr;
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    int n, val;
    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(head, val);
    }

    cout<<"\nOriginal Doubly Linked List:\n";
    display(head);

    bubbleSort(head);

    cout<<"\nSorted Doubly Linked List:\n";
    display(head);

    return 0;
}
