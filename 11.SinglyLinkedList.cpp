// Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
// The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. The first member is the President and the last member is the Secretary. Write a C++ program to:
// ●Add/delete members (including President/Secretary)
// ●Count members
// ●Display members
// Concatenate two division lists
// Also implement: reverse, search by PRN, and sort by PRN operations.

#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

Node* head = NULL;

void addPresident(int prn, string name) {
    Node* temp = new Node;
    temp->prn = prn;
    temp->name = name;
    temp->next = head;
    head = temp;
}

void addSecretary(int prn, string name) {
    Node* temp = new Node;
    temp->prn = prn;
    temp->name = name;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
}

void addMember(int prn, string name) {
    if (head == NULL) {
        cout<<"Add President first!\n";
        return;
    }

    Node* temp = new Node;
    temp->prn = prn;
    temp->name = name;
    Node* p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;
}

void deleteMember(int prn) {
    
    if (head->prn == prn) {
        Node* t = head;
        head = head->next;
        delete t;
    }

    Node* p = head;
    while (p->next != NULL && p->next->prn != prn)  {
        p = p->next;
    }

    if (p->next == NULL) {
        return;
    }

    Node* t = p->next;
    p->next = t->next;
    delete t;
}

void display() {

    Node* p = head;
    cout<<"Club Members:\n";
    while (p != NULL) {
        cout << "PRN: " << p->prn << "  Name: " << p->name << endl;
        p = p->next;
    }
}

int countMembers() {
    int c = 0;
    Node* p = head;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

void reverseList() {
    Node* prev = NULL, *cur = head, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

Node* searchByPRN(int prn) {
    Node* p = head;
    while (p != NULL) {
        if (p->prn == prn) return p;
        p = p->next;
    }
    return NULL;
}

void sortByPRN() {
    if (head == NULL) return;
    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->prn > j->prn) {
                swap(i->prn, j->prn);
                swap(i->name, j->name);
            }
        }
    }
}

int main() {
    int choice, prn;
    string name;

    while (true) {
        cout<<"\n~~~~~~~~~~ Vertex Club Menu ~~~~~~~~~~~~~\n";
        cout<<"1. Add President\n";
        cout<<"2. Add Secretary\n";
        cout<<"3. Add Member\n";
        cout<<"4. Delete Member\n";
        cout<<"5. Display Members\n";
        cout<<"6. Count Members\n";
        cout<<"7. Reverse List\n";
        cout<<"8. Search by PRN\n";
        cout<<"9. Sort by PRN\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter PRN and Name: ";
                cin>>prn>>name;
                addPresident(prn, name);
                break;
            case 2:
                cout<<"Enter PRN and Name: ";
                cin>>prn>>name;
                addSecretary(prn, name);
                break;
            case 3:
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                addMember(prn, name);
                break;
            case 4:
                cout<<"Enter PRN to delete: ";
                cin>>prn;
                deleteMember(prn);
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"Total Members: " <<countMembers()<<endl;
                break;
            case 7:
                reverseList();
                cout<<"List reversed.\n";
                break;
            case 8:
                cout<<"Enter PRN to search: ";
                cin>>prn;
                {
                    Node* f = searchByPRN(prn);
                    if (f) {
                        cout<<"Found: " << f->name << endl;
                    }
                    else {
                        cout<<"Not found.\n";
                    }
                }
                break;
            case 9:
                sortByPRN();
                cout<<"Sorted by PRN.\n";
                break;
            case 0:
                return 0;
        }
    }
}
