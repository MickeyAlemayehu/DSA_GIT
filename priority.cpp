#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};

Node* head = NULL;

Node* newNode(int data, int priority) {
    Node* temp = new Node();
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

void enqueue(int data, int priority) {
    Node* temp = newNode(data, priority);
    if (head == NULL || priority < head->priority) {
        temp->next = head;
        head = temp;
    } else {
        Node* curr = head;
        while (curr->next != NULL && curr->next->priority <= priority) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    cout << "Enqueued: " << data << " with priority: " << priority << endl;
}

void dequeue() {
    if (head == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = head;
    int value = head->data;
    head = head->next;
    delete temp;
    cout << "Dequeued element: " << value << endl;
}

int peek() {
    if (head == NULL) {
        cout << "Queue is empty\n";
        return -1;
    }
    return head->data;
}

bool isEmpty() {
    return head == NULL;
}

void displayQueue() {
    if (head == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = head;
    cout << "Queue elements (data:priority): ";
    while (temp != NULL) {
        cout << temp->data << ":" << temp->priority << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, data, priority;

    while (true) {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter priority: ";
            cin >> priority;
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            cout << "Top element: " << peek() << endl;
            break;
        case 4:
            cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;
        case 5:
            displayQueue();
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
