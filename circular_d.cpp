#include <iostream>
using namespace std;

struct node{
    int value;
    node *prev;
    node *next;
};
struct node *start = NULL;

void menu();
void add_beginning();
void add_end();
void add_somewhere();
void delete_node_beginnning();
void delete_node_end();
void delete_any_value();
void display();

int main(){
    menu();
    return 0;
}

void add_beginning(){
    node *temp = new node;
    cout << "Enter the value: ";
    cin >> temp->value;
    if (start == NULL){
        temp->next = temp;
        temp->prev = temp;
        start = temp;
    }
    else {
        temp->next = start;
        temp->prev = start->prev;
        start->prev = temp;
        start = temp;
    }
    cout << "Value added at the beginning of the list successfully\n";
}

void add_end(){
node *temp = new node;
cout << "Enter the value: ";
cin >> temp->value;
if (start == NULL){
   temp->next = temp;
   temp->prev = temp; 
   start = temp;
}
else {
node *temp2 = start;
while (temp2->next != start){
    temp2 = temp2->next;
}
temp2->next = temp;
temp->prev = temp2;
temp->next = start;
start->prev = temp;
}
  cout << "Value added at the end of the list successfully\n";
}

void add_somewhere(){
    node *temp2 = start;
   int pos, counter = 0;
   cout << "At what position do you want to add the node: ";
   cin >> pos;
   do{
            temp2 = temp2->next;
            counter++;
        } while (temp2 != start);
 if (pos == 1){
    add_beginning();
    }
 else if (pos == counter + 1){
    add_end();
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

void delete_node_beginnning(){
 if (start == NULL){
    cout << "List is empty\n";
    return;
}
else  if (start->next == start && start->prev == start){
    delete start;
    start = NULL;
}
else {
    node *temp = start;
    temp->prev->next = start->next;
    temp->next->prev = temp->prev;
    delete temp;
    start = start->next;
}  
cout << "Element deleted successfully\n"; 
}

void delete_node_end(){
if (start == NULL){
    cout << "List is empty\n";
    return;
}
else  if (start->next == start && start->prev == start){
    delete start;
    start = NULL;
}
else {
    node *temp;
    temp = start->prev;
    temp->prev->next = start;
    start->prev = temp->prev;
    delete temp;  
  }
  cout << "Element deleted successfully\n"; 
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
    delete_node_beginnning();
    return;
}
else {
        do{
            if (temp->value == value){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                cout << "Value deleted successfully from the list\n";
                return;
            }
            else 
            temp = temp->next;
        }while (temp != start);
        cout << "Value not found in the list\n";
    }
}

void display(){
    if (start  == NULL){
        cout << "List is empty\n";
    }
    else{
        node *temp = start;
        cout << "Circular Linked List: ";
        do{
          cout << temp->value << "\t";
          temp = temp->next;   
        } while(temp != start);
        cout << endl;
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Add Node at Beginning\n";
        cout << "2. Add Node at End\n";
        cout << "3. Add Node at a Specific Position\n";
        cout << "4. Delete Node from Beginning\n";
        cout << "5. Delete Node from End\n";
        cout << "6. Delete Node with a Specific Value\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_beginning();
                break;
            case 2:
                add_end();
                break;
            case 3:
                add_somewhere();
                break;
            case 4:
                delete_node_beginnning();
                break;
            case 5:
                delete_node_end();
                break;
            case 6:
                delete_any_value();
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Exiting the program.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
