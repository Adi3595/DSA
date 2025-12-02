// Write a program to keep track of patients as they checked into a medical clinic, assigning patients to doctors on a first-come, first-served basis.

#include <iostream>
#include <string>
using namespace std;

#define MAX_PATIENTS 100

struct Patient {
    int id;
    string name;
};

struct Doctor {
    string name;
    bool available;
};

class PatientQueue {
    Patient patients[MAX_PATIENTS];
    int front, rear;

public:
    PatientQueue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX_PATIENTS - 1;
    }

    void enqueue(Patient p) {
        if (isFull()) {
            cout<<"Queue is full! Cannot add more patients.\n";
            return;
        }
        patients[++rear] = p;
    }

    Patient dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty! No patients.\n";
            return Patient{-1, ""};
        }
        return patients[front++];
    }

    void display() {
        if (isEmpty()) {
            cout<<"No patients waiting.\n";
            return;
        }
        cout<<"Waiting patients: ";
        for (int i = front; i <= rear; i++) {
            cout<<patients[i].name<<"("<<patients[i].id<<") ";
        }
        cout<<endl;
    }
};

int main() {
    PatientQueue pq;

    int numDoctors = 3;
    Doctor doctors[numDoctors] = {
        {"Dr. Smith", true},
        {"Dr. Johnson", true},
        {"Dr. Lee", true}
    };

    int choice, pid = 1;
    string pname;

    while (true) {
        cout<<"\n--- Medical Clinic System ---\n";
        cout<<"1. Check-in patient\n";
        cout<<"2. Assign patients to doctors\n";
        cout<<"3. Show waiting patients\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if (choice == 1) {
            cout << "Enter patient name: ";
            cin >> pname;
            pq.enqueue(Patient{pid++, pname});
            cout << "Patient checked in successfully!\n";
        }
        else if (choice == 2) {
            for (int i = 0; i < numDoctors; i++) {
                if (!pq.isEmpty() && doctors[i].available) {
                    Patient p = pq.dequeue();
                    cout<<p.name<<" (ID: " << p.id << ") is assigned to "<<doctors[i].name<<endl;
                    doctors[i].available = false;
                }
            }
            for (int i = 0; i < numDoctors; i++) {
                doctors[i].available = true;
            }
        }
        else if (choice == 3) {
            pq.display();
        }
        else if (choice == 4) {
            cout<<"Exiting system...\n";
            break;
        }
    }

    return 0;
}
