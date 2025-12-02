#include <iostream>
#include <string>
using namespace std;

struct Faculty {
    int id;
    string name;
    bool occupied = false;
};

class FacultyDB2 {
    int TABLE_SIZE;
    Faculty *table;

public:
    FacultyDB2(int size) {
        TABLE_SIZE = size;
        table = new Faculty[TABLE_SIZE];
    }

    int hashFunction(int id) {
        return id % TABLE_SIZE; // MOD method
    }

    void insert(Faculty f) {
        int index = hashFunction(f.id);

        if (!table[index].occupied) {
            table[index] = f;
            table[index].occupied = true;
        } else {
            if (hashFunction(table[index].id) != index) {
                Faculty temp = table[index];
                table[index] = f;
                insert(temp); // Reinsert displaced faculty
            } else {
                int i = (index + 1) % TABLE_SIZE;
                while (table[i].occupied) i = (i + 1) % TABLE_SIZE;
                table[i] = f;
                table[i].occupied = true;
            }
        }
    }

    void search(int id) {
        int index = hashFunction(id);
        int start = index;
        do {
            if (table[index].occupied && table[index].id == id) {
                cout << "Faculty Found: " << table[index].name << " (ID: " << table[index].id << ")\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        } while (index != start);
        cout << "Faculty Not Found!\n";
    }

    void display() {
        cout << "\nFaculty Database 2 (MOD Method, With Replacement):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied)
                cout << i << " --> (" << table[i].id << ", " << table[i].name << ")\n";
            else
                cout << i << " --> Empty\n";
        }
    }
};

int main() {
    FacultyDB2 db(10);
    db.insert({101, "Dr. Sharma"});
    db.insert({102, "Dr. Gupta"});
    db.insert({113, "Dr. Singh"});
    db.insert({104, "Dr. Mehta"});

    int choice, id;
    string name;
    do {
        cout << "\n1. Display\n2. Search Faculty\n3. Insert Faculty\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: db.display(); break;
            case 2:
                cout << "Enter ID to search: ";
                cin >> id;
                db.search(id);
                break;
            case 3:
                cout << "Enter Faculty ID and Name: ";
                cin >> id >> ws;
                getline(cin, name);
                db.insert({id, name});
                break;
        }
    } while (choice != 4);

    return 0;
}
