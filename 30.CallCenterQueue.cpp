// In a call center, customer calls are handled on a first-come, first-served basis. Implement a queue system using Linked list where:
// ●Each customer call is enqueued as it arrives.
// ●Customer service agents dequeue calls to assist customers.
// If there are no calls, the system waits.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string callID;
    Node* next;
    Node(string id) {
        callID = id;
        next = nullptr;
    }
};

class CallQueue {
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string callID) {
        Node* temp = new Node(callID);
        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Incoming call added: " << callID << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No calls waiting. Agents are idle.\n";
            return;
        }
        Node* temp = front;
        cout << "Call served: " << temp->callID << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending calls.\n";
            return;
        }
        cout << "Pending calls: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->callID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CallQueue cq;
    int choice;
    string callID;

    while (true) {
        cout << "\n--- Call Center Queue System ---\n";
        cout << "1. New Incoming Call (Enqueue)\n";
        cout << "2. Serve Next Call (Dequeue)\n";
        cout << "3. Show Pending Calls\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Call ID/Name: ";
            cin >> callID;
            cq.enqueue(callID);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting system...\n";
            return 0;

        }
    }
}
