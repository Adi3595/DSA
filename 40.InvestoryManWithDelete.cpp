// Write a program to implement deletion operations in the product inventory system using a search tree.
//  Each product must store the following information:
// ●	Unique Product Code
// ●	Product Name
// ●	Price
// ●	Quantity in Stock
// ●	Date Received
// ●	Expiration Date
// Implement the following operations:
// 1.	Delete a product using its unique product code.

// 2.	Delete all expired products based on the current date.

#include <iostream>
#include <string>
using namespace std;

// Struct for Date
struct Date {
    int day, month, year;

    // Compare dates: true if this < other
    bool operator<(const Date& other) const {
        if(year != other.year) return year < other.year;
        if(month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator==(const Date& other) const {
        return day==other.day && month==other.month && year==other.year;
    }

    void input() {
        cout << "Enter Date (DD MM YYYY): ";
        cin >> day >> month >> year;
    }

    void display() {
        cout << day << "/" << month << "/" << year;
    }
};

// Struct for Product
struct Product {
    int code;
    string name;
    double price;
    int quantity;
    Date received;
    Date expiry;
};

// Node for BST
struct Node {
    Product product;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(Product p) {
    Node* newNode = new Node;
    newNode->product = p;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert into BST based on product code
Node* insert(Node* root, Product p) {
    if(!root) return createNode(p);
    if(p.code < root->product.code)
        root->left = insert(root->left, p);
    else if(p.code > root->product.code)
        root->right = insert(root->right, p);
    else
        cout << "Product code already exists!\n";
    return root;
}

// Find minimum node (for deletion)
Node* minValueNode(Node* node) {
    Node* current = node;
    while(current && current->left) current = current->left;
    return current;
}

// Delete product by code
Node* deleteByCode(Node* root, int code) {
    if(!root) return root;
    if(code < root->product.code)
        root->left = deleteByCode(root->left, code);
    else if(code > root->product.code)
        root->right = deleteByCode(root->right, code);
    else {
        // Node found
        if(!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with 2 children
        Node* temp = minValueNode(root->right);
        root->product = temp->product;
        root->right = deleteByCode(root->right, temp->product.code);
    }
    return root;
}

// Delete all expired products
Node* deleteExpired(Node* root, Date current) {
    if(!root) return nullptr;

    root->left = deleteExpired(root->left, current);
    root->right = deleteExpired(root->right, current);

    if(root->product.expiry < current) {
        cout << "Deleting expired product: " << root->product.name << " (Code: " << root->product.code << ")\n";
        root = deleteByCode(root, root->product.code);
    }
    return root;
}

// Inorder traversal to display products
void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << "-------------------------------------------\n";
    cout << "Product Code   : " << root->product.code << endl;
    cout << "Product Name   : " << root->product.name << endl;
    cout << "Price          : " << root->product.price << endl;
    cout << "Quantity       : " << root->product.quantity << endl;
    cout << "Date Received  : "; root->product.received.display(); cout << endl;
    cout << "Expiration Date: "; root->product.expiry.display(); cout << endl;
    inorder(root->right);
}

// Input product details
Product inputProduct() {
    Product p;
    cout << "Enter Product Code: "; cin >> p.code;
    cin.ignore();
    cout << "Enter Product Name: "; getline(cin, p.name);
    cout << "Enter Price: "; cin >> p.price;
    cout << "Enter Quantity: "; cin >> p.quantity;
    cout << "Enter Date Received:\n"; p.received.input();
    cout << "Enter Expiration Date:\n"; p.expiry.input();
    return p;
}

int main() {
    Node* root = nullptr;
    int choice, code;
    Date currentDate;

    cout << "Enter Current Date:\n"; currentDate.input();

    do {
        cout << "\n--- PRODUCT INVENTORY MANAGEMENT ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Delete Product by Code\n";
        cout << "3. Delete All Expired Products\n";
        cout << "4. Display Products\n";
        cout << "5. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1:
                root = insert(root, inputProduct());
                break;
            case 2:
                cout << "Enter Product Code to Delete: "; cin >> code;
                root = deleteByCode(root, code);
                break;
            case 3:
                root = deleteExpired(root, currentDate);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
