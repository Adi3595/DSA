// Q3. Implement collision resolution using linked lists.
//     This is a menu-driven hash table using separate chaining.
//     Operations: Insert, Search, Delete, Display, Exit.

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 7;

// Node for linked list
struct Node {
    int id;
    string name;
    Node* next;

    Node(int i, string n) {
        id = i;
        name = n;
        next = nullptr;
    }
};

// Hash table (array of pointers)
Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int id) {
    return id % TABLE_SIZE;
}

// Initialize table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

// Insert record
void insertRecord(int id, string name) {
    int index = hashFunction(id);

    Node* newNode = new Node(id, name);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    cout << "\nInserted (" << id << ", " << name 
         << ") into bucket " << index << ".\n";
}

// Search record by ID
Node* searchRecord(int id) {
    int index = hashFunction(id);

    Node* temp = hashTable[index];
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Delete record by ID
void deleteRecord(int id) {
    int index = hashFunction(id);

    Node* temp = hashTable[index];
    Node* prev = nullptr;

    while (temp != nullptr) {

        if (temp->id == id) {
            if (prev == nullptr) {
                hashTable[index] = temp->next;  // delete head
            } else {
                prev->next = temp->next;       // delete middle/end
            }

            delete temp;
            cout << "\nRecord deleted successfully.\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "\nRecord not found.\n";
}

// Display hash table
void displayTable() {
    cout << "\n=========== HASH TABLE (Linked Lists) ===========\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << " → ";

        Node* temp = hashTable[i];

        if (!temp) {
            cout << "EMPTY\n";
            continue;
        }

        while (temp != nullptr) {
            cout << "(" << temp->id << ", " << temp->name << ") -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

// Cleanup memory
void cleanup() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];

        while (temp != nullptr) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
}

// Main menu
int main() {
    int choice, id;
    string name;

    initialize();

    do {
        cout << "\n============== LINKED LIST COLLISION ==============\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nEnter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                insertRecord(id, name);
                break;

            case 2:
                cout << "\nEnter ID to search: ";
                cin >> id;
                {
                    Node* result = searchRecord(id);
                    if (result)
                        cout << "\nFound: " << result->name << "\n";
                    else
                        cout << "\nRecord not found.\n";
                }
                break;

            case 3:
                cout << "\nEnter ID to delete: ";
                cin >> id;
                deleteRecord(id);
                break;

            case 4:
                displayTable();
                break;

            case 5:
                cout << "\nExiting program...\n";
                cleanup();
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
