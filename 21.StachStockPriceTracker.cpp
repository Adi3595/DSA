// WAP to build a simple stock price tracker that keeps a history of daily stock prices entered by the user. To allow users to go back and view or remove the most recent price, implement a stack using a linked list to store these integer prices.
// Implement the following operations:
// 1.record(price) – Add a new stock price (an integer) to the stack.
// 2.remove() – Remove and return the most recent price (top of the stack).
// 3.latest() – Return the most recent stock price without removing it.
// isEmpty() – Check if there are no prices recorded.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StockStack {
private:
    Node* top; 

public:
    StockStack() { top = nullptr; }

    bool isEmpty() {
        return top == nullptr;
    }

    void record(int price) {
        Node* newNode = new Node;
        newNode->data = price;
        newNode->next = top;
        top = newNode;
        cout << "Price " << price << " recorded successfully.\n";
    }

    int remove() {
        if (isEmpty()) {
            cout << "No prices to remove! Stack is empty.\n";
            return -1;
        }
        Node* temp = top;
        int removedPrice = temp->data;
        top = top->next;
        delete temp;
        cout << "Removed latest price: " << removedPrice << endl;
        return removedPrice;
    }

    int latest() {
        if (isEmpty()) {
            cout << "No prices recorded yet.\n";
            return -1;
        }
        cout << "Latest recorded price: " << top->data << endl;
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "No prices recorded yet.\n";
            return;
        }
        cout << "Stock Price History (latest first): ";
        Node* curr = top;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    StockStack tracker;
    int choice, price;

    do {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record new price\n";
        cout << "2. Remove latest price\n";
        cout << "3. Show latest price\n";
        cout << "4. Check if empty\n";
        cout << "5. Display price history\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter price to record: ";
                cin>>price;
                tracker.record(price);
                break;

            case 2:
                tracker.remove();
                break;

            case 3:
                tracker.latest();
                break;

            case 4:
                if (tracker.isEmpty())
                    cout<<"No prices recorded. Stack is empty.\n";
                else
                    cout<<"Prices are recorded. Stack is not empty.\n";
                break;

            case 5:
                tracker.display();
                break;

            case 6:
                cout<<"Exiting program...\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
