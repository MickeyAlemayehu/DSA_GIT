#include <iostream>
using namespace std;

struct node {
    int data;
    node * left = NULL;
    node * right = NULL;
};
node * root = NULL;

void insertion (node * root,int value){
    node * temp = new node;
    temp->data = value;
    if (root == NULL){
        root = temp;
        return;
    }
    if (value < temp->data){
        insertion (temp->left, value);
    }
    else if (value > temp->data){
        insertion(temp->right, value);
    }
    else{
        cout << "Dublicate Item";
        return ;
    }
    cout << "Node successfully inserted\n";
}

void insertIF(int value){
    node * temp = root;
    node * temp2 = new node;
    temp2->data = value;
    if (root == NULL){
        root = temp;
        return;
    }

    bool inserted = false;
    while (!inserted){
        if  (value < temp->data){
            if (temp->left == NULL){
                temp->left = temp2;
                inserted = true;
            }
            else
            temp = temp->left;
        }
        else if (value > temp->data){
            if (temp->right == NULL){
                temp->right = temp2;
                inserted = true;
            }
            else
            temp = temp->right;
        }
        else{
            cout << "Duplicate item\n";
            return;
        }
    }
}

node * deletionCopy (node * root, int value){
    if(root == NULL){
        return root;
    } 
    if (value < root->data){
        root->left = deletionCopy(root->left, value);
    }
    else if (value > root->data){
        root->right = deletionCopy(root->right, value);
    }
    else {
        if (root->left == NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            node * temp = root->left;
            delete root;
            return root;
        }
        else {
            node *temp = root->left;
            while (temp->right != NULL){
                temp = temp->right;
            }
            root->data = temp->data;
            root -> left = deletionCopy(root->left, temp->data);
        }
    }
    return root;
}

node * deletionMerge (node * root, int value){
    if(root == NULL){
        return root;
    } 
    if (value < root->data){
        root->left = deletionMerge(root->left, value);
    }
    else if (value > root->data){
        root->right = deletionMerge(root->right, value);
    }
    else {
        if (root->left == NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            node * temp = root->left;
            delete root;
            return root;
        }
        else {
            node *temp = root;
            node * leftSubtree = root->left;
            node * rightSubtree = root->right;
            node * rightmost = leftSubtree;
            while (rightmost->right != NULL){
                rightmost = rightmost->right;
            }
            rightmost->right = rightSubtree;
            root = rightmost; 
            delete temp; 
        }
    }
    return root;
}