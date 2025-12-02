// WAP to perform addition o f two polynomials using singly linked list.

#include <iostream>
using namespace std;

struct Node {
    int coef;   
    int pow;    
    Node* next;
};

Node* createNode(int coef, int pow) {
    Node* node = new Node;
    node->coef = coef;
    node->pow = pow;
    node->next = nullptr;
    return node;
}

void insertNode(Node*& head, int coef, int pow) {
    Node* newNode = createNode(coef, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

Node* createPolynomial() {
    Node* poly = nullptr;
    int n;
    cout<<"Enter number of terms in the polynomial: ";
    cin>>n;

    cout << "Enter terms in descending order of power:\n";
    for (int i = 0; i < n; i++) {
        int coef, pow;
        cout<<"Term "<<i + 1 <<" => Coefficient: ";
        cin >> coef;
        cout<<"Power: ";
        cin>>pow;
        insertNode(poly, coef, pow);
    }
    return poly;
}

void display(Node* head) {
    if (!head) {
        cout << "0";
        return;
    }
    while (head) {
        cout << head->coef << "x^" << head->pow;
        if (head->next && head->next->coef >= 0)
            cout<<" + ";
        else if (head->next)
            cout<<" ";
        head = head->next;
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sumCoef = poly1->coef + poly2->coef;
            if (sumCoef != 0) 
                insertNode(result, sumCoef, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            insertNode(result, poly1->coef, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            insertNode(result, poly2->coef, poly2->pow);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insertNode(result, poly1->coef, poly1->pow);
        poly1 = poly1->next;
    }
    
    while (poly2) {
        insertNode(result, poly2->coef, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    Node* sum = nullptr;

    cout<<"Enter Polynomial 1:\n";
    poly1 = createPolynomial();

    cout<<"\nEnter Polynomial 2:\n";
    poly2 = createPolynomial();

    int choice;
    do {
        cout<<"\n===== MENU =====\n";
        cout<<"1. Display Polynomials\n";
        cout<<"2. Add Polynomials\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout << "Polynomial 1: ";
                display(poly1);
                cout << endl;
                cout << "Polynomial 2: ";
                display(poly2);
                cout << endl;
                break;

            case 2:
                sum = addPolynomials(poly1, poly2);
                cout << "Sum: ";
                display(sum);
                cout << endl;
                break;

            case 3:
                cout << "Exiting...\n";
                break;

        }
    } while (choice != 3);

    return 0;
}
