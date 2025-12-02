// Write a program to implement multiple stack i.e more than two stack using array and perform following operations on it. A. Push B. Pop C. Stack Overflow D. Stack Underflow E. Display

#include <iostream>
using namespace std;

class MultiStack {
    int *arr;       
    int *top;       
    int *next;      
    int n, k;       
    int freeTop;    

public:
    MultiStack(int k1, int n1) {
        k = k1;
        n = n1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++)
            top[i] = -1;

        freeTop = 0;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    } 

    bool isFull() {
        return (freeTop == -1);
    }

    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }

    void push(int item, int sn) {
        if (isFull()) {
            cout<<"Stack Overflow\n";
            return;
        }

        int i = freeTop;     
        freeTop = next[i];    
        arr[i] = item;        
        next[i] = top[sn];   
        top[sn] = i;          

        cout<<"Pushed "<<item <<" into stack "<<sn <<endl;
    }

    int pop(int sn) {
        if (isEmpty(sn)) {
            cout<<"Stack Underflow\n";
            return -1;
        }

        int i = top[sn];      
        top[sn] = next[i];    
        next[i] = freeTop;   
        freeTop = i;

        return arr[i];
    }

    void display(int sn) {
        if (isEmpty(sn)) {
            cout<<"Stack "<<sn<<" is empty\n";
            return;
        }
        cout<<"Stack "<< sn<<": ";
        int i = top[sn];
        while (i != -1) {
            cout << arr[i] << " ";
            i = next[i];
        }
        cout<<endl;
    }
};

int main() {
    int n, k;
    cout<<"Enter total size of array: ";
    cin>>n;
    cout<<"Enter number of stacks: ";
    cin>>k;

    MultiStack ms(k, n);

    int choice, sn, value;

    do {
        cout<<"\n--- MENU ---\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display Stack\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter stack number (0 to " << k-1 << "): ";
                cin>>sn;
                cout<<"Enter value to push: ";
                cin>>value;
                ms.push(value, sn);
                break;

            case 2:
                cout<<"Enter stack number (0 to " << k-1 << "): ";
                cin>>sn;
                value = ms.pop(sn);
                if (value != -1)
                    cout<<"Popped " <<value <<" from stack "<<sn<<endl;
                break;

            case 3:
                cout<<"Enter stack number (0 to " <<k-1<< "): ";
                cin>>sn;
                ms.display(sn);
                break;

            case 4:
                cout<<"Exiting program...\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
