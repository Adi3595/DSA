// The ticket reservation system for Galaxy Multiplex is to be implemented using a C++ program. The multiplex has 8 rows, 
// with 8 seats in each row. A doubly circular linked list will be used to track the availability of seats in each row.Initially, 
// assume that some seats are randomly booked. An array will store head pointers for each row’s linked list.The system should support the following operations:
// a) Display the current list of available seats.
// b) Book one or more seats as per customer request.
// c) Cancel an existing booking when requested.

#include <iostream>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

Seat* rows[8];

void initialize() {
    for (int i = 0; i < 8; i++) {
        Seat* head = NULL, *last = NULL;
        for (int j = 1; j <= 8; j++) {
            Seat* temp = new Seat;
            temp->seatNo = j;
            temp->booked = false;
            temp->next = NULL;
            temp->prev = NULL;

            if (head == NULL) {
                head = temp;
                last = temp;
            } else {
                last->next = temp;
                temp->prev = last;
                last = temp;
            }
        }
        last->next = head;
        head->prev = last;
        rows[i] = head;
    }

    rows[0]->booked = true;
    rows[2]->next->next->booked = true;
    rows[5]->next->booked = true;
}

void display() {
    cout<<"\n--- Seat Layout (X=Booked, O=Available) ---\n";
    for (int i = 0; i < 8; i++) {
        cout<< "Row "<<i + 1<<" : ";
        Seat* p = rows[i];
        for (int j = 0; j < 8; j++) {
            if (p->booked)  {
                cout<<"X ";
            }
            else  {
                cout<<"O ";
            }
            p = p->next;
        }
        cout<<endl;
    }
}

void bookSeat(int row, int seat) {
    
    Seat* p = rows[row - 1];
    for (int i = 1; i < seat; i++) {
        p = p->next;
    }
    if (p->booked) {
        cout<<"Seat already booked!\n";
    }
    else {
        p->booked = true;
        cout<<"Seat booked successfully.\n";
    }
}

void cancelSeat(int row, int seat) {
    if (row < 1 || row > 8 || seat < 1 || seat > 8) {
        cout<<"Invalid row or seat.\n";
        return;
    }
    Seat* p = rows[row - 1];
    for (int i = 1; i < seat; i++) {
        p = p->next;
    }
    if (!p->booked) {
        cout<<"Seat is not booked!\n";
    }
    else {
        p->booked = false;
        cout << "Booking cancelled.\n";
    }
}

int main() {
    initialize();
    int choice, row, seat;

    do {
        cout<<"\n--- Galaxy Multiplex Menu ---\n";
        cout<<"1. Display Seats\n";
        cout<<"2. Book Seat\n";
        cout<<"3. Cancel Booking\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                cout<<"Enter Row (1-8): ";
                cin>>row;
                cout<<"Enter Seat (1-8): ";
                cin>>seat;
                bookSeat(row, seat);
                break;
            case 3:
                cout<<"Enter Row (1-8): ";
                cin>>row;
                cout<<"Enter Seat (1-8): ";
                cin>>seat;
                cancelSeat(row, seat);
                break;
            case 4:
                return 0;
        }
    }while(choice!=4);
}
