// Write a C++ program to store a binary number using a doubly linked list. Implement the following functions:
// a) Calculate and display the 1’s complement and 2’s complement of the stored binary number.
// b) Perform addition of two binary numbers represented using doubly linked lists and display the result.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    void init() { 
        head = tail = nullptr; 
    }

    void insertEnd(int val) {
        Node* newNode = new Node{val, nullptr, tail};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Empty\n";
        } else {
            while (temp != nullptr) {
                cout << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void onesComplement() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data = 1 - temp->data;
            temp = temp->next;
        }
    }

    void twosComplement() {
        onesComplement();
        Node* temp = tail;
        int carry = 1;
        while (temp != nullptr && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }
        if (carry) {
            Node* newNode = new Node{1, head, nullptr};
            head->prev = newNode;
            head = newNode;
        }
    }
};

DoublyLinkedList addBinary(DoublyLinkedList &A, DoublyLinkedList &B) {
    DoublyLinkedList result; result.init();
    Node* t1 = A.tail;
    Node* t2 = B.tail;
    int carry = 0;

    while (t1 != nullptr || t2 != nullptr || carry) {
        int sum = carry;
        if (t1 != nullptr) { 
            sum += t1->data; t1 = t1->prev; 
        }
        if (t2 != nullptr) { 
            sum += t2->data; t2 = t2->prev; 
        }
        result.insertEnd(sum % 2);
        carry = sum / 2;
    }

    DoublyLinkedList final; final.init();
    Node* temp = result.tail;
    while (temp != nullptr) {
        final.insertEnd(temp->data);
        temp = temp->prev;
    }
    return final;
}

int main() {
    DoublyLinkedList bin1, bin2;
    bin1.init(); bin2.init();

    int n;
    cout << "Enter number of bits for first binary number: ";
    cin >> n;
    cout << "Enter bits (MSB to LSB): ";
    for (int i = 0; i < n; i++) {
        int bit; 
        cin >> bit;
        bin1.insertEnd(bit);
    }

    int m;
    cout << "Enter number of bits for second binary number: ";
    cin >> m;
    cout << "Enter bits (MSB to LSB): ";
    for (int i = 0; i < m; i++) {
        int bit; 
        cin >> bit;
        bin2.insertEnd(bit);
    }

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. 1's Complement of first binary number\n";
        cout << "2. 2's Complement of first binary number\n";
        cout << "3. Addition of two binary numbers\n";
        cout << "4. Display first binary number\n";
        cout << "5. Display second binary number\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            DoublyLinkedList temp = bin1;
            temp.onesComplement();
            cout << "1's Complement: ";
            temp.display();

        } else if (choice == 2) {
            DoublyLinkedList temp = bin1;
            temp.twosComplement();
            cout << "2's Complement: ";
            temp.display();

        } else if (choice == 3) {
            DoublyLinkedList sum = addBinary(bin1, bin2);
            cout << "Sum: ";
            sum.display();

        } else if (choice == 4) {
            cout << "First binary number: "; 
            bin1.display();
        } else if (choice == 5) {
            cout << "Second binary number: "; 
            bin2.display();
        } else if (choice == 6) {
            cout << "Exiting...\n";
        }

    } while (choice != 6);

    return 0;
}
