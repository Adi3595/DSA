// Write a program that maintains a queue of passengers waiting to see a ticket agent. The program user should be able to insert a new passenger at the rear of the queue, Display the passenger at the front of the Queue, or remove the passenger at the front of the queue. The program will display the number of passengers left in the queue just before it terminates.

#include <iostream>
#include <string>
using namespace std;

#define MAX 50  

class PassengerQueue {
    string passengers[MAX];
    int front, rear, count;

public:
    PassengerQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == MAX;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertPassenger(string name) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more passengers.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        passengers[rear] = name;
        count++;
        cout << "Passenger " << name << " added to the queue.\n";
    }

    void displayFront() {
        if (isEmpty()) {
            cout << "Queue is empty! No passengers waiting.\n";
            return;
        }
        cout << "Passenger at front: " << passengers[front] << endl;
    }

    void removePassenger() {
        if (isEmpty()) {
            cout << "Queue is empty! No passengers to remove.\n";
            return;
        }
        cout << "Passenger " << passengers[front] << " has been served and removed.\n";
        front = (front + 1) % MAX;
        count--;
    }

    int getCount() {
        return count;
    }
};

int main() {
    PassengerQueue pq;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Ticket Agent Queue System ---\n";
        cout << "1. Insert Passenger\n";
        cout << "2. Display Front Passenger\n";
        cout << "3. Remove Front Passenger\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            cin >> name;
            pq.insertPassenger(name);
            break;

        case 2:
            pq.displayFront();
            break;

        case 3:
            pq.removePassenger();
            break;

        case 4:
            cout << "Number of passengers left in the queue: " << pq.getCount() << endl;
            cout << "Exiting system...\n";
            return 0;
        }
    }
}
