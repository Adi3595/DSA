// Q5. WAP to simulate a faculty database as a hash table.
//     Search a particular faculty using MOD as hash function
//     and collision handling using LINEAR PROBING.
//     Menu-driven: Insert, Search, Delete, Display, Exit.
//     -1 = EMPTY, -2 = DELETED.

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

// Arrays for Faculty ID and Name
int facultyID[TABLE_SIZE];
string facultyName[TABLE_SIZE];

// Hash function using MOD
int hashFunction(int id) {
    return id % TABLE_SIZE;
}

// Initialize table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        facultyID[i] = -1;      // EMPTY
        facultyName[i] = "";
    }
}

// Insert into hash table
void insertRecord(int id, string name) {
    int index = hashFunction(id);
    int start = index;

    while (facultyID[index] != -1 && facultyID[index] != -2 && facultyID[index] != id) {
        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            cout << "\nHash table is full! Cannot insert record.\n";
            return;
        }
    }

    facultyID[index] = id;
    facultyName[index] = name;

    cout << "\nInserted (" << id << ", " << name 
         << ") at index " << index << ".\n";
}

// Search for a faculty ID
int searchRecord(int id) {
    int index = hashFunction(id);
    int start = index;

    while (facultyID[index] != -1) {
        if (facultyID[index] == id) {
            return index;
        }

        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            break;
        }
    }

    return -1;
}

// Delete a record
void deleteRecord(int id) {
    int pos = searchRecord(id);

    if (pos == -1) {
        cout << "\nRecord not found. Cannot delete.\n";
    } 
    else {
        facultyID[pos] = -2;        // Mark as DELETED
        facultyName[pos] = "";
        cout << "\nRecord deleted successfully.\n";
    }
}

// Display hash table contents
void displayTable() {
    cout << "\n========== FACULTY HASH TABLE ==========\n";
    cout << "Index\tID\tName\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << "\t";

        if (facultyID[i] == -1) {
            cout << "EMPTY\n";
        } 
        else if (facultyID[i] == -2) {
            cout << "DELETED\n";
        } 
        else {
            cout << facultyID[i] << "\t" << facultyName[i] << "\n";
        }
    }
}

// Main menu
int main() {
    int choice, id;
    string name;

    initialize();

    do {
        cout << "\n============== FACULTY DATABASE ==============\n";
        cout << "1. Insert Faculty Record\n";
        cout << "2. Search Faculty\n";
        cout << "3. Delete Faculty\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nEnter Faculty ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                insertRecord(id, name);
                break;

            case 2:
                cout << "\nEnter Faculty ID to search: ";
                cin >> id;
                {
                    int pos = searchRecord(id);

                    if (pos == -1)
                        cout << "\nRecord not found.\n";
                    else
                        cout << "\nFound: " << facultyName[pos] 
                             << " at index " << pos << ".\n";
                }
                break;

            case 3:
                cout << "\nEnter Faculty ID to delete: ";
                cin >> id;
                deleteRecord(id);
                break;

            case 4:
                displayTable();
                break;

            case 5:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
