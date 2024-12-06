#include <iostream>
using namespace std;

struct queue {
    int data;
    queue *next;
};

queue *front = NULL;
queue *rear = NULL;

void enqueue() {
    queue *temp = new queue;
    cout << "Enter the value: ";
    cin >> temp->data;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    cout << "Value successfully added\n";
}

void dequeue() {
    if (front != NULL) {
        queue *temp = front;
        int value = front->data;
        front = front->next;
        cout << "Dequeued value: " << value << endl;
        delete temp;

        if (front == NULL) {
            rear = NULL;
        }
    } 
    else {
        cout << "Underflow\n";
    }
}

void display() {
    if (front == NULL) {
        cout << "The queue is empty.\n";
        return;
    }
    queue *temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void menu() {
    int choice;
    do {
        cout << "\n---------- Menu ----------\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}
