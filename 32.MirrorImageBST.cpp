// Write a program to perform Binary Search Tree (BST) operations (Count the total number of nodes, Compute the height of the BST, Mirror Image ).

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

int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void mirror(Node* root) {
    if (root == nullptr)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, value, n;

    do {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Node\n";
        cout << "3. Count Total Nodes\n";
        cout << "4. Compute Height of BST\n";
        cout << "5. Mirror Image of BST\n";
        cout << "6. Display Inorder Traversal\n";
        cout << "7. Exit\n";
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
            cout << "Total number of nodes: " << countNodes(root) << endl;
            break;

        case 4:
            cout << "Height of BST: " << height(root) << endl;
            break;

        case 5:
            mirror(root);
            cout << "Mirror image created successfully!\n";
            break;

        case 6:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        }

    } while (choice != 7);

    return 0;
}
