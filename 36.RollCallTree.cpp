// Write a program, using trees, to assign the roll nos. to the students of your class as per their previous years result. i.e topper will be roll no. 1

#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    string name;
    int marks;
    Node* left;
    Node* right;

    Node(string n, int m) {
        name = n;
        marks = m;
        left = right = nullptr;
    }
};

Node* insert(Node* root, string name, int marks) {
    if (root == nullptr)
        return new Node(name, marks);
    if (marks < root->marks)
        root->left = insert(root->left, name, marks);
    else
        root->right = insert(root->right, name, marks);
    return root;
}

void assignRollNumbers(Node* root, int& roll) {
    if (root == nullptr)
        return;
    assignRollNumbers(root->right, roll);
    cout << "Roll No. " << roll++ << " : " << root->name<<endl;
    cout<<"Marks : "<<root->marks<< endl;
    assignRollNumbers(root->left, roll);
}

int main() {
    Node* root = nullptr;
    int choice;
    string name;
    int marks;
    int n;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Roll Numbers (Topper = Roll No. 1)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter marks: ";
                cin >> marks;
                root = insert(root, name, marks);
                break;

            case 2:
                if (root == nullptr) {
                    cout << "No students added yet!\n";
                } else {
                    cout << "\n--- Roll Numbers Assigned Based on Marks ---\n";
                    int roll = 1;
                    assignRollNumbers(root, roll);
                }
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

        }

    } while (choice != 3);

    return 0;
}
