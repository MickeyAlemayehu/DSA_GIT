#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top; 
};

void initializeStack(Stack& stack) {
    stack.top = nullptr;
}

void push(Stack& stack, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

int pop(Stack& stack) {
    if (stack.top == nullptr) { 
        cout << "Stack underflow!" << endl;
        return -1;
    }
    Node* temp = stack.top;
    int value = temp->data;
    stack.top = stack.top->next;
    delete temp;
    return value;
}

bool isEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

void decimalToBinary() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
   if (n == 0) {
        cout << "Binary representation: 0" << endl;
        return;
    }
    Stack stack;
    initializeStack(stack);
    while (n > 0) {
        push(stack, n % 2);
        n /= 2;
    }
    cout << "Binary representation: ";
    while (!isEmpty(stack)) {
        cout << pop(stack);
    }
    cout << endl;
}

int main(){
    decimalToBinary();
    return 0;
}

