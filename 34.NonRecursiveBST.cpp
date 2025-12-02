// Write a Program to create a Binary Tree and perform following Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int data) {
    if (root == nullptr)
        return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Manual stack implementation using array
class Stack {
public:
    Node* arr[100];
    int top;
    Stack() { top = -1; }
    void push(Node* n) { arr[++top] = n; }
    Node* pop() { return arr[top--]; }
    Node* peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

// Non-recursive inorder traversal
void inorderNonRecursive(Node* root) {
    Stack s;
    Node* curr = root;
    while (curr != nullptr || !s.isEmpty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Non-recursive preorder traversal
void preorderNonRecursive(Node* root) {
    if (root == nullptr) return;
    Stack s;
    s.push(root);
    while (!s.isEmpty()) {
        Node* curr = s.pop();
        cout << curr->data << " ";
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

// Count leaf nodes non-recursively
int countLeafNodes(Node* root) {
    if (root == nullptr) return 0;
    int count = 0;
    Stack s;
    s.push(root);
    while (!s.isEmpty()) {
        Node* curr = s.pop();
        if (!curr->left && !curr->right) count++;
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
    return count;
}

int main() {
    Node* root = nullptr;
    int choice, val, n;

    do {
        cout << "\n--- BINARY TREE OPERATIONS ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Count Leaf Nodes\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
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
                inorderNonRecursive(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorderNonRecursive(root);
                cout << endl;
                break;

            case 4:
                cout << "Number of Leaf Nodes: " << countLeafNodes(root) << endl;
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
