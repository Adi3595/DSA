// Write a program to implement a product inventory management system for a shop using a search tree data structure. Each product must store the following information:
// ●	Unique Product Code
// ●	Product Name
// ●	Price
// ●	Quantity in Stock
// ●	Date Received
// ●	Expiration Date
// Implement the following operations:
// 1.	Insert a product into the tree ( organized by product name).
// 2.	Display all items in the inventory using inorder traversal.
// 3.	List expired items in prefix (preorder) order of their names.

#include <iostream>
#include <string>
using namespace std;

class Product {
    public:
    string code;
    string name;
    float price;
    int quantity;
    string dateReceived;
    string expiryDate;
    Product* left;
    Product* right;

    Product(string c, string n, float p, int q, string dr, string ed) {
        code = c;
        name = n;
        price = p;
        quantity = q;
        dateReceived = dr;
        expiryDate = ed;
        left = right = nullptr;
    }
};

Product* insert(Product* root, string code, string name, float price, int quantity, string dateReceived, string expiryDate) {
    if (root == nullptr)
        return new Product(code, name, price, quantity, dateReceived, expiryDate);
    if (name < root->name)
        root->left = insert(root->left, code, name, price, quantity, dateReceived, expiryDate);
    else if (name > root->name)
        root->right = insert(root->right, code, name, price, quantity, dateReceived, expiryDate);
    return root;
}

void inorder(Product* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << "-------------------------------------------\n";
    cout << "Product Code   : " << root->code << endl;
    cout << "Product Name   : " << root->name << endl;
    cout << "Price          : " << root->price << endl;
    cout << "Quantity       : " << root->quantity << endl;
    cout << "Date Received  : " << root->dateReceived << endl;
    cout << "Expiration Date: " << root->expiryDate << endl;
    inorder(root->right);
}

bool isExpired(string expiryDate, string currentDate) {
    return expiryDate < currentDate;
}

void listExpired(Product* root, string currentDate) {
    if (root == nullptr)
        return;
    if (isExpired(root->expiryDate, currentDate)) {
        cout << "-------------------------------------------\n";
        cout << "Expired Product: " << root->name << endl;
        cout << "Code           : " << root->code << endl;
        cout << "Expiry Date    : " << root->expiryDate << endl;
    }
    listExpired(root->left, currentDate);
    listExpired(root->right, currentDate);
}

int main() {
    Product* root = nullptr;
    int choice;
    string code, name, dateReceived, expiryDate, currentDate;
    float price;
    int quantity;

    cout << "Enter Current Date (YYYY-MM-DD): ";
    cin >> currentDate;

    do {
        cout << "\n--- PRODUCT INVENTORY MANAGEMENT ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Products (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product Code: ";
                cin >> code;
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Date Received (YYYY-MM-DD): ";
                cin >> dateReceived;
                cout << "Enter Expiration Date (YYYY-MM-DD): ";
                cin >> expiryDate;
                root = insert(root, code, name, price, quantity, dateReceived, expiryDate);
                break;

            case 2:
                if (root == nullptr)
                    cout << "No products in inventory.\n";
                else {
                    cout << "\n--- INVENTORY LIST (Inorder Traversal) ---\n";
                    inorder(root);
                }
                break;

            case 3:
                if (root == nullptr)
                    cout << "No products in inventory.\n";
                else {
                    cout << "\n--- EXPIRED PRODUCTS (Preorder Traversal) ---\n";
                    listExpired(root, currentDate);
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

        }

    } while (choice != 4);

    return 0;
}

