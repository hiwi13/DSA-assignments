#include <iostream>
using namespace std;

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = *(arr + i); 
        int* j = arr + i - 1; 
        
        while (j >= arr && *j > key) {
            *(j + 1) = *j;
            j--; 
        }
        *(j + 1) = key; 
    }
}

void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int* minPtr = arr + i; 
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *minPtr) {
                minPtr = arr + j; 
            }
        }
        
        if (minPtr != arr + i) {
            int temp = *minPtr;
            *minPtr = *(arr + i);
            *(arr + i) = temp;
        }
    }
}

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {

                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
void displayArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " "; 
    cout << endl;
}
}
int main() {
   
    int arr[] = {34, 2, 45, 67, 1, 89, 23, 10};
    int n = sizeof(arr) / sizeof(arr[0]);  

    cout << "Original Array: ";
    displayArray(arr, n);

    insertionSort(arr, n);
    cout << "Array after Insertion Sort: ";
    displayArray(arr, n);
    
    selectionSort(arr, n);
    cout << "Array after Selection Sort: ";
    displayArray(arr, n);
    
    bubbleSort(arr, n);
    cout << "Array after Bubble Sort: ";
    displayArray(arr, n);

    return 0;
}
