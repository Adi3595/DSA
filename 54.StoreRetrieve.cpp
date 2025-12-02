// Q4. Store and retrieve student records using roll numbers.
//     Implement a hash table using linear probing.
//     Menu-driven: Insert, Search, Delete, Display, Exit.
//     -1 = EMPTY, -2 = DELETED

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 11;

int rollNo[TABLE_SIZE];
string studentName[TABLE_SIZE];

// Hash function
int hashFunction(int roll) {
    return roll % TABLE_SIZE;
}

// Initialize table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        rollNo[i] = -1;
        studentName[i] = "";
    }
}

// Insert record
void insertRecord(int roll, string name) {
    int index = hashFunction(roll);
    int start = index;

    while (rollNo[index] != -1 && rollNo[index] != -2 && rollNo[index] != roll) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            cout << "\nHash table is full. Cannot insert.\n";
            return;
        }
    }

    rollNo[index] = roll;
    studentName[index] = name;

    cout << "\nInserted (" << roll << ", " << name << ") at index " << index << ".\n";
}

// Search record
int searchRecord(int roll) {
    int index = hashFunction(roll);
    int start = index;

    while (rollNo[index] != -1) {
        if (rollNo[index] == roll) {
            return index;
        }

        index = (index + 1) % TABLE_SIZE;

        if (index == start)
            break;
    }

    return -1;
}

// Delete record
void deleteRecord(int roll) {
    int pos = searchRecord(roll);

    if (pos == -1) {
        cout << "\nRecord not found.\n";
    } else {
        rollNo[pos] = -2;        // mark deleted
        studentName[pos] = "";
        cout << "\nRecord deleted successfully.\n";
    }
}

// Display hash table
void displayTable() {
    cout << "\n========== STUDENT HASH TABLE ==========\n";
    cout << "Index\tRoll\tName\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << "\t";

        if (rollNo[i] == -1)
            cout << "EMPTY\n";

        else if (rollNo[i] == -2)
            cout << "DELETED\n";

        else
            cout << rollNo[i] << "\t" << studentName[i] << "\n";
    }
}

// Main menu
int main() {
    int choice, roll;
    string name;

    initialize();

    do {
        cout << "\n============== STUDENT DATABASE ==============\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nEnter Roll No: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin >> name;
                insertRecord(roll, name);
                break;

            case 2:
                cout << "\nEnter Roll No to search: ";
                cin >> roll;
                {
                    int pos = searchRecord(roll);
                    if (pos == -1)
                        cout << "\nRecord not found.\n";
                    else
                        cout << "\nFound: " << studentName[pos] 
                             << " at index " << pos << ".\n";
                }
                break;

            case 3:
                cout << "\nEnter Roll No to delete: ";
                cin >> roll;
                deleteRecord(roll);
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
