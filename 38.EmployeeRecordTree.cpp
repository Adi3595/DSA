// Write a program to efficiently search a particular employee record by using Tree data structure. Also sort the data on emp­id in ascending order.

#include <iostream>
#include <string>
using namespace std;

class Employee {
    public : 
    int empID;
    string name;
    float salary;
    Employee* left;
    Employee* right;

    Employee(int id, string n, float s) {
        empID = id;
        name = n;
        salary = s;
        left = right = nullptr;
    }
};

Employee* insert(Employee* root, int id, string name, float salary) {
    if (root == nullptr)
        return new Employee(id, name, salary);

    if (id < root->empID)
        root->left = insert(root->left, id, name, salary);
    else if (id > root->empID)
        root->right = insert(root->right, id, name, salary);
    else
        cout << "Employee ID " << id << " already exists!\n";

    return root;
}

Employee* search(Employee* root, int id) {
    if (root == nullptr || root->empID == id)
        return root;
    if (id < root->empID)
        return search(root->left, id);
    else
        return search(root->right, id);
}

void inorder(Employee* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << "EmpID: " << root->empID 
         << ", Name: " << root->name 
         << ", Salary: " << root->salary << endl;
    inorder(root->right);
}

int main() {
    Employee* root = nullptr;
    int choice, id;
    string name;
    float salary;

    do {
        cout << "\n--- Employee Management using BST ---\n";
        cout << "1. Insert Employee Record\n";
        cout << "2. Search Employee by ID\n";
        cout << "3. Display All Employees (Sorted by ID)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Salary: ";
                cin >> salary;
                root = insert(root, id, name, salary);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                {
                    Employee* emp = search(root, id);
                    if (emp)
                        cout << "\nRecord Found:\nEmpID: " << emp->empID
                             << ", Name: " << emp->name
                             << ", Salary: " << emp->salary << endl;
                    else
                        cout << "Employee with ID " << id << " not found.\n";
                }
                break;

            case 3:
                cout << "\nEmployees Sorted by ID:\n";
                inorder(root);
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

        }

    } while (choice != 4);

    return 0;
}
