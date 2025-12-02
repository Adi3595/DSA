#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    bool occupied = false;
};

class EmployeeDB {
    int TABLE_SIZE;
    Employee *table;

public:
    EmployeeDB(int size) {
        TABLE_SIZE = size;
        table = new Employee[TABLE_SIZE];
    }

    int hashFunction(int id) {
        int sq = id * id;
        int mid = (sq / 10) % 100; // Mid-square method
        return mid % TABLE_SIZE;
    }

    void insert(Employee e) {
        int index = hashFunction(e.id);
        int i = index;
        while (table[i].occupied) {
            i = (i + 1) % TABLE_SIZE;
            if (i == index) { cout << "Hash Table Full!\n"; return; }
        }
        table[i] = e;
        table[i].occupied = true;
    }

    void search(int id) {
        int index = hashFunction(id);
        int start = index;
        do {
            if (table[index].occupied && table[index].id == id) {
                cout << "Employee Found: " << table[index].name << " (ID: " << table[index].id << ")\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        } while (index != start);
        cout << "Employee Not Found!\n";
    }

    void display() {
        cout << "\nEmployee Database (Mid-Square Hashing):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied)
                cout << i << " --> (" << table[i].id << ", " << table[i].name << ")\n";
            else
                cout << i << " --> Empty\n";
        }
    }
};

int main() {
    EmployeeDB db(10);
    db.insert({101, "Alice"});
    db.insert({102, "Bob"});
    db.insert({113, "Charlie"});
    db.insert({104, "David"});

    int choice, id;
    string name;
    do {
        cout << "\n1. Display\n2. Search Employee\n3. Insert Employee\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: db.display(); break;
            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                db.search(id);
                break;
            case 3:
                cout << "Enter Employee ID and Name: ";
                cin >> id >> ws;
                getline(cin, name);
                db.insert({id, name});
                break;
        }
    } while (choice != 4);

    return 0;
}

