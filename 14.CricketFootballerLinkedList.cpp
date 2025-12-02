// In the Second Year Computer Engineering class, there are two groups of students based on their favorite sports:
// ●Set A includes students who like Cricket.
// ●Set B includes students who like Football.
// Write a C++ program to represent these two sets using linked lists and perform the following operations:
// a) Find and display the set of students who like both Cricket and Football.
// b) Find and display the set of students who like either Cricket or Football, but not both.
// c) Display the number of students who like neither Cricket nor Football.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

struct LinkedList {
    Node* head;
    void init() { head = nullptr; }

    void insert(string name) {
        Node* newNode = new Node{name, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
    }

    bool search(string name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Empty\n";
        } else {
            while (temp != nullptr) {
                cout << temp->name << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

LinkedList intersection(LinkedList& A, LinkedList& B) {
    LinkedList result; result.init();
    Node* temp = A.head;
    while (temp != nullptr) {
        if (B.search(temp->name)) {
            result.insert(temp->name);
        }
        temp = temp->next;
    }
    return result;
}

LinkedList symmetricDifference(LinkedList& A, LinkedList& B) {
    LinkedList result; result.init();
    Node* temp = A.head;
    while (temp != nullptr) {
        if (!B.search(temp->name)) result.insert(temp->name);
        temp = temp->next;
    }
    temp = B.head;
    while (temp != nullptr) {
        if (!A.search(temp->name)) result.insert(temp->name);
        temp = temp->next;
    }
    return result;
}

int countNeither(LinkedList& all, LinkedList& A, LinkedList& B) {
    int count = 0;
    Node* temp = all.head;
    while (temp != nullptr) {
        if (!A.search(temp->name) && !B.search(temp->name)) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    LinkedList all, cricket, football;
    all.init(); cricket.init(); football.init();

    int n;
    cout << "Enter total number of students: ";
    cin >> n;
    cout << "Enter names of all students:\n";
    for (int i = 0; i < n; i++) {
        string name; cin >> name; all.insert(name);
    }

    int c;
    cout << "Enter number of Cricket players: ";
    cin >> c;
    cout << "Enter names of Cricket players:\n";
    for (int i = 0; i < c; i++) {
        string name; cin >> name; cricket.insert(name);
    }

    int f;
    cout << "Enter number of Football players: ";
    cin >> f;
    cout << "Enter names of Football players:\n";
    for (int i = 0; i < f; i++) {
        string name; cin >> name; football.insert(name);
    }

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Students who like both Cricket and Football\n";
        cout << "2. Students who like either Cricket or Football but not both\n";
        cout << "3. Number of students who like neither Cricket nor Football\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            LinkedList both = intersection(cricket, football);
            cout << "Both Cricket and Football: ";
            both.display();
        } 
        else if (choice == 2) {
            LinkedList either = symmetricDifference(cricket, football);
            cout << "Either but not both: ";
            either.display();
        } 
        else if (choice == 3) {
            int neitherCount = countNeither(all, cricket, football);
            cout << "Number of students who like neither: " << neitherCount << endl;
        } 
        else if (choice == 4) {
            cout << "Exiting...\n";
        } 

    } while (choice != 4);

    return 0;
}
