// Q2. Implement collision handling using separate chaining.
//     Menu-driven hash table using manually created linked lists.
//     Operations: Insert, Search, Delete, Display, Exit.

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 7;

// Node structure for linked list
struct Node {
    int key;
    string name;
    Node* next;

    Node(int k, string n) {
        key = k;
        name = n;
        next = nullptr;
    }
};

// Hash table buckets
Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

// Insert into hash table (head insertion)
void insertRecord(int key, string name) {
    int index = hashFunction(key);

    Node* newNode = new Node(key, name);
    newNode->next = hashTable[index];  // insert at start
    hashTable[index] = newNode;

    cout << "\nInserted (" << key << ", " << name 
         << ") in bucket " << index << ".\n";
}

// Search for key
Node* searchRecord(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != nullptr) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Delete key
void deleteRecord(int key) {
    int index = hashFunction(key);

    Node* temp = hashTable[index];
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->key == key) {

            if (prev == nullptr) {
                hashTable[index] = temp->next;  // delete first node
            } else {
                prev->next = temp->next;
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
    cout << "\n========= HASH TABLE =========\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << " → ";

        Node* temp = hashTable[i];
        if (!temp) {
            cout << "EMPTY\n";
            continue;
        }

        while (temp != nullptr) {
            cout << "(" << temp->key << ", " << temp->name << ") -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

// Free memory before exit
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
    int choice, key;
    string name;

    initialize();

    do {
        cout << "\n=========== SEPARATE CHAINING ===========\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nEnter key: ";
                cin >> key;
                cout << "Enter name: ";
                cin >> name;
                insertRecord(key, name);
                break;

            case 2:
                cout << "\nEnter key to search: ";
                cin >> key;
                {
                    Node* result = searchRecord(key);
                    if (result)
                        cout << "\nFound: " << result->name << "\n";
                    else
                        cout << "\nRecord not found.\n";
                }
                break;

            case 3:
                cout << "\nEnter key to delete: ";
                cin >> key;
                deleteRecord(key);
                break;

            case 4:
                displayTable();
                break;

            case 5:
                cout << "\nExiting...\n";
                cleanup();
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
