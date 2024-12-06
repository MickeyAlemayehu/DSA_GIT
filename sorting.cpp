#include <iostream>
using namespace std;

void insertion_sorting_ascending (int arr[], int size);
void insertion_sorting_descending (int arr[], int size);
void simple_sorting(int arr[], int size);
void bubble_sorting (int arr[], int size);
void selection_sorting(int arr[], int size);

int main(){
    return 0;
}

void insertion_sorting_ascending (int arr[], int size){
    for (int i = 1; i < size; i++){
        int j = i - 1;
        while (j >= 0 && arr[i] <= arr[j]){
                    arr[j] = arr[j + 1];
                    j--;
                }
            arr[j + 1] = arr[i];    
    }
}

void insertion_sorting_descending (int arr[], int size){
        for (int i = 1; i < size; i++){
        int j = i - 1;
        while (j >= 0 && arr[i] >= arr[j]){
                    arr[j] = arr[j + 1];
                    j--;
                }
            arr[j + 1] = arr[i];    
    }
}

void simple_sorting(int arr[], int size){
    for (int i = 0; i < size; i++){
         int min = arr[i];
        for(int j = i + 1; i < size; j++){
            if (arr[j] < min){
                int temp = arr[j];
                arr[j] = min;
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sorting(int arr[], int size){
    for(int i = 0 ; i <= size - 2; i++){
        int min = i;
        for(int j = i + 1 ; j < size; j++){
            if (arr[j] < arr[min]){
               min = j;
            }
        }
        if (min != i){
         int temp = arr[i];
         arr[i] = arr[min];
         arr[min] = temp;
        }
    }
}

void bubble_sorting (int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}




