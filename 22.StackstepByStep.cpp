// Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and show the operations step by step.

#include <iostream>
using namespace std;

#define SIZE 50

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }

    void push(char x) {
        if (top < SIZE - 1)
            arr[++top] = x;
    }

    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }

    char peek() {
        if (top >= 0)
            return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i];
    }
};

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(string expr) {
    Stack st;
    string postfix = "";

    cout << "Step-by-step:\n";
    cout << "Token Stack Postfix\n";

    for (int i = 0; expr[i] != '\0'; i++) {
        char token = expr[i];
        if (token == ' ') continue;

        if (isalnum(token)) {
            postfix += token;
            cout << token << " ";
            st.display();
            cout << " " << postfix << "\n";
        }
        else if (isOperator(token)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(token)) {
                postfix += st.pop();
            }
            st.push(token);
            cout << token << " ";
            st.display();
            cout << " " << postfix << "\n";
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
        cout << "END ";
        st.display();
        cout << " " << postfix << "\n";
    }

    cout << "\nPostfix Expression: " << postfix << endl;
}

int main() {
    string expr = "a-b*c-d/e+f";
    cout << "Infix Expression: " << expr << "\n\n";
    infixToPostfix(expr);
    return 0;
}
