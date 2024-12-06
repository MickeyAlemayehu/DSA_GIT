#include <iostream>
using namespace std;
int counter = 0;
int linear_searching(int arr[], int size, int value);
int binary_searching(int arr[], int size, int  value, int high, int low);

int main(){
    int arr[] = {8,6,2,5,9};
    cout << linear_searching(arr, 5, 10) << endl;
    int arr1[] = {1, 2, 3, 4, 5};
    cout << binary_searching (arr1, 5, 4, 5 - 1, 0) << endl;
    cout << binary_searching (arr1, 5, 6, 5 - 1, 0) << endl;
    return 0;
}

int linear_searching(int arr[], int size, int value){
    int i= 0;
    while (arr[i] != value && i < size){
        i++;
    }
    if(arr[i] == value)
    return 1;
    return -1;
}

int binary_searching(int arr1[], int size, int value, int high, int low) {
    if (high >= low) {
        counter++; 
        int mid = low + (high - low) / 2;

        if (arr1[mid] == value) {
            cout << "Counter: " << counter << endl;
            return mid;
        } else if (arr1[mid] < value) {
            return binary_searching(arr1, size, value, high, mid + 1);
        } else {
            return binary_searching(arr1, size, value, mid - 1, low);
        }
    }

    cout << "Counter: " << counter << endl;
    return -1;
}