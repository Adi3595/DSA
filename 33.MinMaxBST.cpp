// Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST 

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val) {
        data=val;
        left=right=NULL;
    }
};

Node* createNode(int value) {
    Node* newNode = new Node(value);
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if(root!=nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int findMin(Node* root) {
    
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

int findMax(Node* root) {

    while (root->right != nullptr)
        root = root->right;
    return root->data;
}

int main() {
    Node* root = nullptr;
    int choice, value, n;

    do {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Node\n";
        cout << "3. Display Inorder Traversal\n";
        cout << "4. Find Minimum Value\n";
        cout << "5. Find Maximum Value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of nodes: ";
            cin >> n;
            cout << "Enter values: ";
            for (int i = 0; i < n; i++) {
                cin >> value;
                root = insert(root, value);
            }
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Minimum value in BST: " << findMin(root) << endl;
            break;

        case 5:
            cout << "Maximum value in BST: " << findMax(root) << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
