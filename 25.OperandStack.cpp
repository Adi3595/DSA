// You are given a postfix expression (also known as Reverse Polish Notation) consisting of single-digit operands and binary operators (+, -, *, /). Your task is to evaluate the expression using stack and return its result

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int val) {
        if (top >= MAX - 1) {
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (top == -1) {
            cout<<"Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string expr) {
    Stack st;

    for (char ch : expr) {
        if (ch == ' ') {
            continue;
        }

        if (isdigit(ch)) {
            st.push(ch - '0'); 
        }
        else {
            int val2 = st.pop();
            int val1 = st.pop();

            switch (ch) {
                case '+': 
                st.push(val1 + val2); 
                break;

                case '-': 
                st.push(val1 - val2); 
                break;

                case '*': 
                st.push(val1 * val2); 
                break;

                case '/': 
                st.push(val1 / val2); 
                break;

            }
        }
    }

    return st.pop();
}

int main() {
    string expr;
    cout<<"Enter postfix expression: ";
    getline(cin, expr);

    int result = evaluatePostfix(expr);
    cout<<"Result: "<<result<<endl;

    return 0;
}
