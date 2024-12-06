#include  <iostream>
using namespace std;
struct node{
    int value;
    node * next;
};

struct node * start = NULL;

void add_begin();
void add_end();
void add_at_some_position();
void delete_begin();
void delete_end();
void delete_any_value();
void display_list();
void menu();

int main(){
    menu();
    return 0;
}

void add_begin(){
    node *temp = new node;
    cout << "Enter the value you want to insert: ";
    cin >> temp->value;
if (start == NULL){
      start = temp;
      start->next = start;
    }
else {
    temp->next = start;
    node *current = start;
    do{
        current = current->next;
    }while (current->next != start);
    current->next = temp;
    start = temp;
    }
    cout << "Node added succesfully at the beginning\n";
}

void add_end(){
    node *temp = new node;
    cout << "Enter the value you want to insert: ";
    cin >> temp->value;
if (start == NULL){
      start = temp;
      start->next = start;
    }
else {
    node *current = start;
    do{
        current = current->next;
    }while (current->next != start);
    current->next = temp;
    temp->next = start;
    }
cout << "Node added succesfully at the end\n";
}

void add_at_some_position(){
    int pos, counter = 0;
    node *temp  = start;
    cout << "At what position do you want to insert the value: ";
    cin >> pos;
    do{
        temp = temp->next;
        counter++;
    }while (temp != start);
 if (pos == 1)
 add_begin();
 else if (pos == counter + 1)
 add_end();
 else if (pos <= counter){
    node *current = start, *temp1 = new node;
    cout << "Enter the value you want to insert: ";
    cin >> temp1->value;
   for (int i = 1; i < pos - 1; i++){
      current = current->next;
   } 
   temp1->next = current->next;
   current->next = temp1;
   cout << "Node successfully added to the position of your choice.\n";
 }
 else
 cout << "Position out of bound can't add node there!!\n"; 
}

void delete_begin(){
if (start == NULL){
cout << "List is empty\n";
return;
}
else if (start->next == start){
    delete start;
    start = NULL;
}
else {
    node *temp = start;
    node *temp2 = start;
    do{
        temp2 = temp2->next;
    }while (temp2->next != start);
    temp2->next = temp->next;
    delete temp;
    start = temp2->next;
 }
    cout << "Element at the beginning deleted successfully\n";
}

void delete_end(){
  node *temp;
if (start == NULL){
cout << "List is empty\n";
return;
}
else if (start->next == NULL){
    delete start;
    start = NULL;
}
else {
    node *temp2 = start;
    do{
        temp2 = temp2->next;
    }while (temp2->next->next != start);
    temp = temp2->next;
    delete temp;
    temp2->next = start;
 }
     cout << "Element at the beginning deleted successfully\n";
}  

void delete_any_value(){
int value;
 cout << "What value do you want to delete from the list: ";
cin >> value;
node *temp = start;
if (start == NULL)
    cout << "List is empty\n";
else if (start->value == value)
    delete_begin();
else {
        do{
            if (temp->next->value == value){
                node *temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                cout << "Value deleted successfully from the list\n";
                return;
            }
            else 
            temp = temp->next;
        }while (temp != start);
        cout << "Value not found in the list\n";
    }
}

void display_list() {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node* temp = start;
    cout << "Circular Linked List: ";
    do {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
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
                add_begin();
                break;
            case 2:
                add_end();
                break;
            case 3:
                add_at_some_position();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_any_value();
                break;
            case 7:
                display_list();
                break;
            case 8:
                cout << "Exiting the program.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
