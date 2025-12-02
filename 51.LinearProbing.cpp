// Q1. Implement a hash table with collision resolution using linear probing.
//      Menu-driven program using only <iostream> and <string>.
//      Operations: Insert, Search, Delete, Display, Exit.
//      -1  → EMPTY slot
//      -2  → DELETED slot

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 11;

int hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;   // mark all as EMPTY
    }
}

// Insert key using linear probing
void insertKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1 && hashTable[index] != -2 && hashTable[index] != key) {
        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            cout << "\nHash table is full. Cannot insert.\n";
            return;
        }
    }

    hashTable[index] = key;
    cout << "\nInserted key " << key << " at index " << index << ".\n";
}

// Search key
int searchKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }

        index = (index + 1) % TABLE_SIZE;

        if (index == start) break;
    }

    return -1;
}

// Delete key
void deleteKey(int key) {
    int pos = searchKey(key);

    if (pos == -1) {
        cout << "\nKey not found. Cannot delete.\n";
    } else {
        hashTable[pos] = -2;   // mark as DELETED
        cout << "\nKey " << key << " deleted from index " << pos << ".\n";
    }
}

// Display hash table
void displayTable() {
    cout << "\nIndex\tValue\n";
    cout << "----------------\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << "\t";

        if (hashTable[i] == -1)
            cout << "EMPTY\n";
        else if (hashTable[i] == -2)
            cout << "DELETED\n";
        else
            cout << hashTable[i] << "\n";
    }
}

// Main menu
int main() {
    int choice, key;

    initialize();

    do {
        cout << "\n========== LINEAR PROBING HASH TABLE ==========\n";
        cout << "1. Insert Key\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertKey(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                {
                    int pos = searchKey(key);
                    if (pos == -1)
                        cout << "\nKey not found.\n";
                    else
                        cout << "\nKey found at index " << pos << ".\n";
                }
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;

            case 4:
                displayTable();
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
