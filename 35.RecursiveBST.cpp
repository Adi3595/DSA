// Write a Program to create a Binary Tree and perform the following Recursive operations on it. a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes 

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

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int countLeafNodes(Node* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, val, n;

    do {
        cout << "\n1. Create Tree\n";
        cout<<"2. Inorder Traversal\n";
        cout<<"3. Preorder Traversal\n";
        cout<<"4. Count Leaf Nodes\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of nodes: ";
                cin >> n;
                cout << "Enter values: ";
                for (int i = 0; i < n; i++) {
                    cin >> val;
                    root = insert(root, val);
                }
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Number of Leaf Nodes: " << countLeafNodes(root) << endl;
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

        }

    } while (choice != 5);

    return 0;
}
