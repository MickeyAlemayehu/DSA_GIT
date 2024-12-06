#include <iostream>
using namespace std;

struct Node {
    string name;
    int age;
    Node* next;
};

Node* start = NULL;

void addNode();
void deleteNodeStart();
void deleteNodeEnd();
void display();
void nodeForwardTraversing();
void nodeBackwardTraversing();
void deleteNodeAfterCurrent();
void addNodeAfterCurrent();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Node\n";
        cout << "2. Delete Node at Start\n";
        cout << "3. Delete Node at End\n";
        cout << "4. Display List\n";
        cout << "5. Forward Traversal\n";
        cout << "6. Backward Traversal\n";
        cout << "7. Delete Node After Current\n";
        cout << "8. Add Node After Current\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNode();
                break;
            case 2:
                deleteNodeStart();
                break;
            case 3:
                deleteNodeEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                nodeForwardTraversing();
                break;
            case 6:
                nodeBackwardTraversing();
                break;
            case 7:
                deleteNodeAfterCurrent();
                break;
            case 8:
                addNodeAfterCurrent();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);
}

void addNode() {
    Node* temp = new Node;
    cout << "Enter your name: ";
    cin >> temp->name;
    cout << "Enter your age: ";
    cin >> temp->age;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        Node* temp2 = start;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    cout << "Node added successfully.\n";
}

void display() {
    if (start == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    Node* temp = start;
    cout << "\nList contents:\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Age: " << temp->age << endl;
        temp = temp->next;
    }
}

void deleteNodeStart() {
    if (start == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    Node* temp = start;
    start = start->next;
    delete temp;
    cout << "Node at start deleted successfully.\n";
}

void deleteNodeEnd() {
    if (start == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    if (start->next == NULL) {
        delete start;
        start = NULL;
    } else {
        Node* temp1 = start;
        Node* temp2 = NULL;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        delete temp1;
        temp2->next = NULL;
    }
    cout << "Node at end deleted successfully.\n";
}

void nodeForwardTraversing() {
    if (start == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    Node* current = start;
    while (current != NULL) {
        cout << "Name: " << current->name << ", Age: " << current->age << endl;
        current = current->next;
    }
}

void nodeBackwardTraversing() {
    if (start == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    Node* current = start;
    Node* prev = NULL;
    Node* next = NULL;

    // Reverse the list
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current = prev;

    // Display reversed list
    cout << "\nList in reverse order:\n";
    while (current != NULL) {
        cout << "Name: " << current->name << ", Age: " << current->age << endl;
        current = current->next;
    }

    // Restore original order
    current = prev;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void deleteNodeAfterCurrent() {
    if (start == NULL || start->next == NULL) {
        cout << "No node to delete after current.\n";
        return;
    }
    Node* current = start;
    current = current->next;
    Node* temp = current->next;
    if (temp != NULL) {
        current->next = temp->next;
        delete temp;
        cout << "Node after current deleted successfully.\n";
    } else {
        cout << "No node exists after current.\n";
    }
}

void addNodeAfterCurrent() {
    if (start == NULL) {
        cout << "The list is empty. Adding at start.\n";
        addNode();
        return;
    }
    Node* current = start;
    cout << "Enter name for new node: ";
    string name;
    cin >> name;
    cout << "Enter age for new node: ";
    int age;
    cin >> age;

    Node* temp = new Node;
    temp->name = name;
    temp->age = age;
    temp->next = current->next;
    current->next = temp;
    cout << "Node added after current node successfully.\n";
}
