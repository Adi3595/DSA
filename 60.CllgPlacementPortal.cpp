#include <iostream>
#include <string>
using namespace std;

struct Placement {
    int id;
    string name;
    string company;
    bool occupied = false;
};

class PlacementPortal {
    int TABLE_SIZE;
    Placement *table;

public:
    PlacementPortal(int size) {
        TABLE_SIZE = size;
        table = new Placement[TABLE_SIZE];
    }

    int hashFunction(int id) {
        return id % TABLE_SIZE; // Simple MOD hashing
    }

    void insert(Placement p) {
        int index = hashFunction(p.id);
        int i = index;
        while (table[i].occupied) {
            i = (i + 1) % TABLE_SIZE;
            if (i == index) { cout << "Hash Table Full!\n"; return; }
        }
        table[i] = p;
        table[i].occupied = true;
    }

    void search(int id) {
        int index = hashFunction(id);
        int start = index;
        do {
            if (table[index].occupied && table[index].id == id) {
                cout << "Student: " << table[index].name << ", Placed at: " << table[index].company << "\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        } while(index != start);
        cout << "Student Not Found!\n";
    }

    void display() {
        cout << "\nPlacement Portal Database:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied)
                cout << i << " --> (" << table[i].id << ", " << table[i].name << ", " << table[i].company << ")\n";
            else
                cout << i << " --> Empty\n";
        }
    }
};

int main() {
    PlacementPortal portal(10);

    int choice, id;
    string name, company;
    do {
        cout << "\n1. Display\n2. Search Student\n3. Insert Student\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: portal.display(); break;
            case 2:
                cout << "Enter Student ID to search: ";
                cin >> id;
                portal.search(id);
                break;
            case 3:
                cout << "Enter ID, Name, Company: ";
                cin >> id >> ws;
                getline(cin, name);
                getline(cin, company);
                portal.insert({id, name, company});
                break;
        }
    } while(choice != 4);

    return 0;
}

