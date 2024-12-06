#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

int queue_size = 0; 
node *front = NULL;
node *rear = NULL;

void front_enqueue( node *temp){
    if (queue_size == 0){
        front = rear = temp;
    }
    else{
    temp->next = front;
    temp->prev = NULL;
    front->prev = temp;
    front = temp;
    }
      queue_size++;
}
int front_dequeue(){
    if (queue_size == 0){
        cout << "Underflow\n";
        return -1;
    }
    node *temp2 = front;
    int value = temp2->data;
    front = front->next;
    if(front != NULL){
       front->prev = NULL;
    }
    else{
        rear = NULL;
    }
    delete temp2;
    queue_size--;
    return value;
}
void end_enqueue(node *temp){
    if (queue_size == 0){
        front = rear = temp;
    }
    else{
    rear->next = temp;
    temp->prev = rear;
    temp->next = NULL;
    rear = temp;
    }
    queue_size++;
}
int end_dequeue(){
    if (queue_size == 0){
        cout << "Underflow\n";
        return -1;
    }
    node *temp2 = rear;
    int value = temp2->data;
    rear = rear->prev;
    if(rear != NULL)
    rear->next = NULL;
    else{
        front = NULL;
    }
    delete temp2;
    queue_size--;
    return value;
}
node* newnode(){
    node *temp = new node;
    cout << "Enter the value: ";
    cin >> temp->data;
    temp->next = NULL;
    temp->prev = NULL; 
    return temp;
} 
void menu(){
     int choice;
    do{
    cout << "\n-------------------Menu-----------------------\n";
    cout << "1. To add an element at the beginning of your queue.\n";
    cout << "2. To remove an element at the beginning of your queue.\n";
    cout << "3. To add an element at the end of your queue.\n";
    cout << "4. To remove an element at the end of your queue.\n";
    cout << "5. To exit from the program\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    front_enqueue(newnode());
        break;
    case 2:
    if (queue_size == 0) {
    cout << "Queue is empty.\n";
} else {
    cout << "Dequeued element: " << front_dequeue() << endl;
}
        break;
    case 3:
    end_enqueue(newnode());
        break;
    case 4:
    if (queue_size == 0) {
    cout << "Queue is empty.\n";
} else {
    cout << "Dequeued element: " << end_dequeue() << endl;
}
        break;
    case 5:
    cout << "Exiting from the program\n";
    exit(0);
        break;
    default:
    cout << "Invalid choice. Try again.\n";
    }
}while(choice != 5);
}
int main(){
    menu();
    return 0;
}