#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;


int stack[MAX];
int top = -1;


string stackStr[MAX];
int topStr = -1;

char operators[MAX];
int topOp = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

void pushStr(const string& value) {
    if (topStr == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stackStr[++topStr] = value;
}

string popStr() {
    if (topStr == -1) {
        cout << "Stack Underflow!" << endl;
        return "";
    }
    return stackStr[topStr--];
}

void pushOp(char value) {
    if (topOp == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    operators[++topOp] = value;
}

char popOp() {
    if (topOp == -1) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return operators[topOp--];
}

bool isOperatorStackEmpty() {
    return topOp == -1;
}

char peekOp() {
    return operators[topOp];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void prefixToPostfix() {
    string prefix;
    cout << "Enter a prefix expression: ";
    cin >> prefix;

    int n = prefix.length();
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            pushStr(string(1, c));
        } else {
            if (topStr < 1) {
                cout << "Error: Invalid prefix expression!" << endl;
                return;
            }
            string op1 = popStr();
            string op2 = popStr();
            string result = op1 + op2 + c;
            pushStr(result);
        }
    }

    if (topStr == 0) {
        cout << "Postfix expression: " << popStr() << endl;
    } else {
        cout << "Error: Invalid prefix expression!" << endl;
    }
}

void evaluatePostfix() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(c - '0');
        } else {
            if (top < 1) {
                cout << "Error: Invalid postfix expression!" << endl;
                return;
            }
            int op2 = pop();
            int op1 = pop();
            switch (c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/':
                    if (op2 == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return;
                    }
                    push(op1 / op2);
                    break;
                default:
                    cout << "Error: Invalid operator '" << c << "' in postfix expression!" << endl;
                    return;
            }
        }
    }

    if (top == 0) {
        cout << "Result of postfix evaluation: " << pop() << endl;
    } else {
        cout << "Error: Invalid postfix expression!" << endl;
    }
}

void infixToPostfix() {
    string infix, postfix = "";
    cout << "Enter an infix expression: ";
    cin >> infix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            pushOp(c);
        } else if (c == ')') {
            while (!isOperatorStackEmpty() && peekOp() != '(') {
                postfix += popOp();
            }
            if (!isOperatorStackEmpty() && peekOp() == '(') {
                popOp();
            } else {
                cout << "Error: Mismatched parentheses!" << endl;
                return;
            }
        } else {
            while (!isOperatorStackEmpty() && precedence(peekOp()) >= precedence(c)) {
                postfix += popOp();
            }
            pushOp(c);
        }
    }

    while (!isOperatorStackEmpty()) {
        if (peekOp() == '(') {
            cout << "Error: Mismatched parentheses!" << endl;
            return;
        }
        postfix += popOp();
    }

    cout << "The postfix expression is: " << postfix << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Prefix to Postfix Conversion\n";
        cout << "2. Evaluate Postfix Expression\n";
        cout << "3. Infix to Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                prefixToPostfix();
                break;
            case 2:
                evaluatePostfix();
                break;
            case 3:
                infixToPostfix();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
