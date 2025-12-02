// You are given a string containing only parentheses characters: '(', ')', '{', '}', '[', and ']'. Your task is to check whether the parentheses are balanced or not. A string is considered balanced if: 1.Every opening bracket has a corresponding closing bracket of the same type Brackets are closed in the correct order.

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { 
        top = -1; 
    }

    void push(char ch) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) {
            return '\0';
        }   
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    Stack st;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) return false;

            char top = st.pop();
            if (!isMatching(top, ch))
                return false;
        }
    }

    return st.isEmpty();
}

int main() {
    string expr;
    cout<<"Enter parentheses string: ";
    cin>>expr;

    if (isBalanced(expr))
        cout<<"Balanced\n";
    else
        cout<<"Not Balanced\n";

    return 0;
}
