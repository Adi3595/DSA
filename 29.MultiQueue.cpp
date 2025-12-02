// Write a program to implement multiple queues i.e. two queues using array and perform following operations on it. A. Add Queue, B. Delete from Queue, C. Display Queue

#include <iostream>
using namespace std;

#define MAX 10   

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full! Cannot add element.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << "Inserted " << x << " into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to delete.\n";
            return;
        }
        cout << "Deleted element: " << arr[front++] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q1, q2;
    int choice, queueNo, value;

    while (true) {
        cout << "\n--- Multiple Queue System ---\n";
        cout << "1. Add (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }

        cout << "Select Queue (1 or 2): ";
        cin >> queueNo;

        Queue *selectedQueue;
        if (queueNo == 1)
            selectedQueue = &q1;
        else if (queueNo == 2)
            selectedQueue = &q2;
        else {
            cout << "Invalid Queue Number!\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            selectedQueue->enqueue(value);
            break;

        case 2:
            selectedQueue->dequeue();
            break;

        case 3:
            selectedQueue->display();
            break;
        }
    }

    return 0;
}
