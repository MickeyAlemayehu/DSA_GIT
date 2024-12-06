#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};
Node *head = NULL;

bool isPalindrome(Node* head);

int main(){
    Node *insert = new Node;
    string value;
    cout << "Enter your string: ";
    cin >> value;
head = insert;
for (int i = 0; i < value.size(); i++) {
    insert->data = value[i];
    if (i < value.size() - 1) {  
        insert->next = new Node;
        insert = insert->next;
    } else {
        insert->next = nullptr; 
    }
}

    if (isPalindrome(head))
    cout << "String is palindrome";
    else
   cout << "String is not palindrome";
    return 0;
}


bool isPalindrome(Node* head) {
    string original = "", reversed = "";
    Node* temp = head;

    while (temp != nullptr) {
        original += temp->data;
        reversed = temp->data + reversed;
        temp = temp->next;
    }

    return original == reversed;
}
