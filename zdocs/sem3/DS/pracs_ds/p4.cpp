#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    // Push an element onto the stack
    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};
// Function to perform an operation
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                cout << "Error: Division by zero\n";
                return 0;
            }
            return a / b;
        case '^': return (int)round(pow(a, b));
        default: return 0;
    }
}
// Function to evaluate postfix expression
int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '^') {

            int b = s.pop();
            int a = s.pop();

            int result = applyOperation(a, b, ch);
            s.push(result);
        }
    }

    return s.pop();
}
int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}