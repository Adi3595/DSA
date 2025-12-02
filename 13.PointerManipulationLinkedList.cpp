// Develop a C++ program to store and manage an appointment schedule for a single day. Appointments should be scheduled randomly using a 
// linked list. The system must define the start time, end time, and specify the minimum and maximum duration allowed for each appointment slot.
// The program should include the following operations:
// a) Display the list of currently available time slots.
//  b) Book a new appointment within the defined time limits.
//  c) Cancel an existing appointment after validating its time, availability, and correctness.
//  d) Sort the appointment list in order of appointment times.
//  e) Sort the list based on appointment times using pointer manipulation (without swapping data values).

#include <iostream>
using namespace std;

struct Appointment {
    int start;
    int end;
    Appointment* next;
};

Appointment* head = NULL;
int dayStart = 9;    
int dayEnd = 17;    
int minDuration = 1; 
int maxDuration = 3; 

void displayAppointments() {
    if (!head) {
        cout << "No appointments booked.\n";
        return;
    }
    Appointment* p = head;
    cout << "\nAppointments:\n";
    while (p) {
        cout << p->start << ":00 - " << p->end << ":00\n";
        p = p->next;
    }
}

void displayAvailable() {
    cout << "\nAvailable slots:\n";
    if (!head) {
        cout << dayStart << ":00 - " << dayEnd << ":00\n";
        return;
    }
    int curStart = dayStart;
    Appointment* p = head;
    while (p) {
        if (curStart < p->start)
            cout << curStart << ":00 - " << p->start << ":00\n";
        curStart = p->end;
        p = p->next;
    }
    if (curStart < dayEnd)
        cout << curStart << ":00 - " << dayEnd << ":00\n";
}

bool isAvailable(int start, int end) {
    if (start < dayStart || end > dayEnd || start >= end) return false;
    int dur = end - start;
    if (dur < minDuration || dur > maxDuration) return false;

    Appointment* p = head;
    while (p) {
        if (!(end <= p->start || start >= p->end)) return false;
        p = p->next;
    }
    return true;
}

void bookAppointment(int start, int end) {
    if (!isAvailable(start, end)) {
        cout << "Invalid slot or conflict.\n";
        return;
    }
    Appointment* temp = new Appointment{start, end, NULL};
    if (!head || start < head->start) {
        temp->next = head;
        head = temp;
    } else {
        Appointment* p = head;
        while (p->next && p->next->start < start) p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    cout << "Appointment booked.\n";
}

void cancelAppointment(int start, int end) {
    if (!head) {
        cout << "No appointments to cancel.\n";
        return;
    }
    if (head->start == start && head->end == end) {
        Appointment* t = head;
        head = head->next;
        delete t;
        cout << "Cancelled.\n";
        return;
    }
    Appointment* p = head;
    while (p->next && !(p->next->start == start && p->next->end == end))
        p = p->next;
    if (!p->next) cout << "Appointment not found.\n";
    else {
        Appointment* t = p->next;
        p->next = t->next;
        delete t;
        cout << "Cancelled.\n";
    }
}

void sortByData() {
    if (!head) return;
    for (Appointment* i = head; i && i->next; i = i->next) {
        for (Appointment* j = i->next; j; j = j->next) {
            if (i->start > j->start) {
                swap(i->start, j->start);
                swap(i->end, j->end);
            }
        }
    }
    cout << "Sorted by swapping data.\n";
}

void sortByPointers() {
    if (!head || !head->next) return;
    Appointment* sorted = NULL;
    Appointment* cur = head;
    while (cur) {
        Appointment* next = cur->next;
        if (!sorted || cur->start < sorted->start) {
            cur->next = sorted;
            sorted = cur;
        } else {
            Appointment* p = sorted;
            while (p->next && p->next->start < cur->start) p = p->next;
            cur->next = p->next;
            p->next = cur;
        }
        cur = next;
    }
    head = sorted;
    cout << "Sorted by pointer manipulation.\n";
}

int main() {
    int choice, start, end;
    while (true) {
        cout << "\n--- Appointment Scheduler ---\n";
        cout << "1. Display Available Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display Appointments\n";
        cout << "5. Sort by Data Swap\n";
        cout << "6. Sort by Pointer Manipulation\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: displayAvailable(); break;
            case 2: cout << "Enter start and end time: "; cin >> start >> end; bookAppointment(start, end); break;
            case 3: cout << "Enter start and end time to cancel: "; cin >> start >> end; cancelAppointment(start, end); break;
            case 4: displayAppointments(); break;
            case 5: sortByData(); break;
            case 6: sortByPointers(); break;
            case 7: return 0;
        }
    }
}
