#include <iostream>
using namespace std;

/*struct generic{
    int data;
    generic *next;
    generic *child;
}*parent = NULL;*/

struct node{
    int data;
    node *left;
    node *right;
};

struct node2{
    int data;
    node2 *left;
    node2 *right;
};

 node *root = NULL;
 node2 *parent = NULL;
int min(node *root){
    if(root == NULL){
    cout << "Empty Tree\n";
    return -1;
    }
    else {
    node *temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    cout << "Minimum Element: " << temp->data << endl;
    return temp->data;
    }
}

node *max(node *root){
    if(root == NULL){
    cout << "Empty Tree\n";
    return root;
    }
    else {
    node *temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    cout << "Maximum Element: " << temp->data << endl;
    return temp;
    }
}

node2 *max(node2 *root){
    if(root == NULL){
    cout << "Empty Tree\n";
    return root;
    }
    else {
    node2 *temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    cout << "Maximum Element: " << temp->data << endl;
    return temp;
    }
}

void insertion(int value) {
    node* temp = root;  node2 *temp3 = parent;
    node* temp2 = new node; node2 *temp4 = new node2;
    temp2->data = value;  temp4->data = value;
    temp2->left = NULL;  temp4->left = NULL;
    temp2->right = NULL;  temp4->right = NULL;
    if (root == NULL) {
        root = temp2; parent = temp4; 
        cout << "Successfully inserted\n";
        return;
    }
    while (true) {
        if (temp->data > value) {
            if (temp->left == NULL) {
                temp->left = temp2; temp3->left = temp4;
                cout << "Successfully inserted\n";
                return;
            } else {
                temp = temp->left; temp3 = temp3->left;
            }
        }
        else if (temp->data < value) {
            if (temp->right == NULL) {
                temp->right = temp2; temp3->right = temp4;
                cout << "Successfully inserted\n";
                return;
            } else {
                temp = temp->right;  temp3 = temp3->right;
            }
        }
        else {
            cout << "Can't be inserted there\n";
            return;
        }
    }
}


void preorder_traversing(node *temp){
    if(temp == NULL){
        return;
    }
    else{
       cout << temp->data <<"\t";
        preorder_traversing(temp->left);
        preorder_traversing(temp->right);
    }
}

void inorder_traversing(node2 *temp){
    if(temp == NULL){
        return;
    }
    else{
        inorder_traversing(temp->left);
        cout << temp->data <<"\t";
        inorder_traversing(temp->right);
    }
}

void postorder_traversing(node *temp){
    if(temp == NULL){
        return;
    }
    else{
        postorder_traversing(temp->left);
        postorder_traversing(temp->right);
        cout << temp->data <<"\t";
    }
}

node* delete_copy(node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (root->data < value) {
        root->right = delete_copy(root->right, value);
    }
    else if (root->data > value) {
        root->left = delete_copy(root->left, value);
    }
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = root->right;
        while (temp && temp->left) {
            temp = temp->left;  
        }
        root->data = temp->data;
        root->right = delete_copy(root->right, temp->data);
    }

    return root;
}


node2* delete_merge(node2* root, int value) {
    node2* temp;

    if (root == NULL) {
        return root; 
    }
    if (root->data < value) {
        root->right = delete_merge(root->right, value);  
    }
    else if (root->data > value) {
        root->left = delete_merge(root->left, value);  
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;  
            return NULL;  
        }
        else if (root->left == NULL) {
            temp = root->right;  
            delete root;
            return temp;  
        }
        else if (root->right == NULL) {
            temp = root->left; 
            delete root;
            return temp;  
        }
        else {
            node2* temp2 = root->left;
            while (temp2->right != NULL) {
                temp2 = temp2->right;
            }
            root->data = temp2->data;
            root->left = delete_merge(root->left, temp2->data);
        }
    }
    return root;  
}


int main() {
    int choice, value;
    while (true) {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete using copying\n";
        cout << "3. Delete using merging\n";
        cout << "4. Find Minimum\n";
        cout << "5. Find Maximum\n";
        cout << "6. Preorder Traversal\n";
        cout << "7. Inorder Traversal\n";
        cout << "8. Postorder Traversal\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertion(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = delete_copy(root, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                parent = delete_merge(parent, value);
                break;   
            case 4:
                cout << "Minimum value: " << min(root) << endl;
                break;
            case 5:
                cout << "Maximum value: " << max(parent) << endl;
                break;
            case 6:
                cout << "Preorder traversal: ";
                preorder_traversing(root);
                cout << endl;
                break;
            case 7:
                cout << "Inorder traversal: ";
                inorder_traversing(parent);
                cout << endl;
                break;
            case 8:
                cout << "Postorder traversal: ";
                postorder_traversing(root);
                cout << endl;
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
