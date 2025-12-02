// Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete,Levelwise display )

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node() {
        left=right=NULL;
    }
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
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
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data <<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
}

int main() {
    Node* root = nullptr;
    int choice, value, n;

    do {
        cout << "\n--- Binary Search Tree ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Node\n";
        cout << "3. Inorder Display\n";
        cout << "4. Preorder Display\n";
        cout << "5. Postorder Display\n";
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
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
