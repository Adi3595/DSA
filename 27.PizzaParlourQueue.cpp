// Pizza parlour accepting maximum n orders. Orders are served on an FCFS basis. Order once placed can’t be cancelled. Write C++ program to simulate the system using circular QUEUE

#include <iostream>
#include <string>
using namespace std;

#define MAX 5   

class CircularQueue {
    int front, rear, count;
    string orders[MAX];

public:
    CircularQueue() {
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

    void placeOrder(string order) {
        if (isFull()) {
            cout<<"Order queue is full!\n";
            return;
        }
        rear = (rear + 1) % MAX;
        orders[rear] = order;
        count++;
        cout<<"Order placed: "<<order<<endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout<<"Order served: "<<orders[front] << endl;
        front = (front + 1) % MAX;
        count--;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout<<"Pending Orders: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << orders[i] << " ";
            i = (i + 1) % MAX;
        }
        cout<<endl;
    }
};

int main() {
    CircularQueue cq;
    int choice;
    string order;

    while (true) {
        cout<<"\n--- Pizza Parlour System ---\n";
        cout<<"1. Place Order\n";
        cout<<"2. Serve Order\n";
        cout<<"3. Display Pending Orders\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout << "Enter order name: ";
            cin >> order;
            cq.placeOrder(order);
            break;

        case 2:
            cq.serveOrder();
            break;

        case 3:
            cq.displayOrders();
            break;

        case 4:
            cout<<"Exiting system...!\n";
            return 0;
        }
    }
}
