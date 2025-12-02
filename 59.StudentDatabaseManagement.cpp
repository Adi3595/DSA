#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    bool occupied = false;
};

class StudentDB {
    int TABLE_SIZE;
    Student *table;

public:
    StudentDB(int size) {
        TABLE_SIZE = size;
        table = new Student[TABLE_SIZE];
    }

    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

    void insert(Student s) {
        int index = hashFunction(s.id);
        int i = index;
        while (table[i].occupied) i = (i + 1) % TABLE_SIZE;
        table[i] = s;
        table[i].occupied = true;
    }

    void search(int id) {
        int index = hashFunction(id);
        int start = index;
        do {
            if (table[index].occupied && table[index].id == id) {
                cout << "Student Found: " << table[index].name << " (ID: " << table[index].id << ")\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        } while (index != start);
        cout << "Student Not Found!\n";
    }

    void remove(int id) {
        int index = hashFunction(id);
        int start = index;
        do {
            if (table[index].occupied && table[index].id == id) {
                table[index].occupied = false;
                cout << "Student Deleted!\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        } while (index != start);
        cout << "Student Not Found!\n";
    }

    void display() {
        cout << "\nStudent Database:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied)
                cout << i << " --> (" << table[i].id << ", " << table[i].name << ")\n";
            else
                cout << i << " --> Empty\n";
        }
    }
};

int main() {
    StudentDB db(10);

    int choice, id;
    string name;
    do {
        cout << "\n1. Display\n2. Search Student\n3. Insert Student\n4. Delete Student\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: db.display(); break;
            case 2:
                cout << "Enter ID to search: ";
                cin >> id;
                db.search(id);
                break;
            case 3:
                cout << "Enter ID and Name to insert: ";
                cin >> id >> ws;
                getline(cin, name);
                db.insert({id, name});
                break;
            case 4:
                cout << "Enter ID to delete: ";
                cin >> id;
                db.remove(id);
                break;
        }
    } while(choice != 5);

    return 0;
}
