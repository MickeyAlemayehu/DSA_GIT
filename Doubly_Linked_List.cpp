#include <iostream>
using namespace std;

struct node{
int value;
node *prev;
node *next;
};
node *start = NULL;

void add_node_beginning();
void add_node_end();
void add_node_somewhere();
void delete_node_beginning();
void delete_node_end();
void node_display_forward();
void node_display_backward();
void display_menu();

int main(){
    int choice;
    do {
        display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                add_node_beginning();
                break;
            case 2:
                add_node_end();
                break;
            case 3:
                add_node_somewhere();
                break;    
            case 4:
                delete_node_beginning();
                break;
            case 5:
                delete_node_end();
                break;
            case 6:
                delete_any_value();
                break;
            case 7:
                node_display_forward();
                break;
            case 8:
                node_display_backward();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void display_menu() {
    cout << "\n----- Doubly Linked List Menu -----\n";
    cout << "1. Add node at the beginning\n";
    cout << "2. Add node at the end\n";
    cout << "3. Add node at a certain position\n";
    cout << "4. Delete node from the beginning\n";
    cout << "5. Delete node from the end\n";
    cout << "6. Delete an element of your choice from the list\n";
    cout << "7. Display list forward\n";
    cout << "8. Display list backward\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void add_node_beginning(){
    node *temp = new node;
    cout << "Enter the value\n";
    cin >> temp->value;
    if(start == NULL){
        cout << "This is your first element in the list\n";
        temp->prev = NULL;
        temp->next = NULL;
        start = temp;
    }
    else {
    temp->prev = NULL;
    temp->next = start; 
    start->prev = temp; 
    }
    cout << "Node added to the list successfully\n";
}

void add_node_end(){
 node *temp2 = start;
 node *temp = new node;
    cout << "Enter the value\n";
    cin >> temp->value;
    if(start == NULL){
        cout << "This is your first element in the list\n";
        temp->prev = NULL;
        temp->next = NULL;
        start = temp;
    }
    else {
      while(temp2->next != NULL){
        temp2 = temp2->next;
      }
     temp->prev = temp2;
     temp->next = NULL;
     temp2->next = temp;
    }
    cout << "Node added to the list successfully\n";
}

void delete_node_beginning(){
    if (start == NULL)
    cout << "List is empty!\n";
    else {
        node *temp = start;
        start = start->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        delete temp;
        cout << "Node at beginning of the list deleted successfully\n";
    }
}

void delete_node_end(){
  if (start == NULL)
    cout << "List is empty!\n";
  else {
    node *temp, *temp2;
    temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
   temp2 = temp->prev;
   temp2->next = NULL;
   delete temp;
   cout << "Last node of the list deleted successfully\n";
  }
}

void node_display_forward(){
 if (start == NULL)
 cout << "List is empty!\n";
 else {
   node *temp = start;
   cout << "Here is the list: ";
   while (temp != NULL){
    cout << temp->value << "\t";
    temp = temp->next;
   }
 }
}

void node_display_backward(){
    if (start == NULL)
    cout << "List is empty!\n";
    else {
        node *temp = start;
        while (temp->next != NULL){
            temp = temp->next;
        }
        cout << "Here is the list in reverse: ";
        while (temp != NULL){
           cout << temp->value << "\t";
           temp = temp->prev;
        }
    }
}

void add_node_somewhere(){
   node *temp2 = start;
   int pos, counter = 0;
   cout << "At what position do you want to add the node: ";
   cin >> pos;
    while (temp2 != NULL){
            temp2 = temp2->next;
            counter++;
        }
 if (pos == 1){
    add_node_beginning();
    }
 else if (pos == counter + 1){
    add_node_end();
   }
 else if (pos <= counter){
    node *temp = start, *temp1 = new node;
    cin >> temp1->value;
      for (int i = 1; i < pos - 1; i++){
         temp = temp->next;
        }
    temp1->next = temp->next;
    temp->next->prev = temp1;
    temp->next = temp1;
    temp1->prev = temp;
    cout << "Node successfully added to the position of your choice.\n";
     }
 else{
    cout << "Position out of bound can't add node there!!\n"; 
   }
  }

void delete_any_value(){
int value;
 cout << "What value do you want to delete from the list: ";
cin >> value;
node *temp = start;
if (start == NULL){
    cout << "List is empty\n";
    return;
}
else if (start->value == value){
    delete_node_beginning();
    return;
}
else {
        while (temp != NULL){
            if (temp->value == value){
                node *temp2 = temp->prev;
                temp2->next = temp->next;
                if(temp->next != NULL){
                temp->next->prev = temp2;
                }
                delete temp;
                cout << "Value deleted successfully from the list\n";
                return;
            }
            else 
            temp = temp->next;
        }
        cout << "Value not found in the list\n";
    }
} 