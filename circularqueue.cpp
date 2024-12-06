#include <iostream>
using namespace std;

const int maxsize = 5;
int arr[maxsize]; 
int queue_size = 0;
int front = -1, rear = -1;

void enqueue(int value) {
    if (queue_size == maxsize) {
        cout << "Overflow\n";
        return;
    }

    if (rear == maxsize - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    arr[rear] = value;

    if (front == -1) {
        front = 0;
    }

    queue_size++;
    cout << "Enqueued value: " << value << endl;
}

void dequeue() {
    if (queue_size == 0) {
        cout << "Underflow\n";
        return;
    }

    int x = arr[front];
    queue_size--;

    if (front == rear) {
        front = rear = -1;
    } else if (front == maxsize - 1) {
        front = 0; 
    } else {
        front++;
    }

    cout << "Dequeued value: " << x << endl;
}

void display() {
    if (queue_size == 0) {
        cout << "The queue is empty.\n";
        return;
    }

    cout << "Queue elements: ";
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = front; i < maxsize; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void menu() {
    int choice, value;
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
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
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
