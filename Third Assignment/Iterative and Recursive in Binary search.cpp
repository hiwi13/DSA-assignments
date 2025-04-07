#include <iostream>
using namespace std;

// Iterative Binary Search function
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Recursive Binary Search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int indexIterative = binarySearchIterative(arr, n, target);
    if (indexIterative != -1)
        cout << "Iterative Binary Search: Element " << target << " found at index " << indexIterative << endl;
    else
        cout << "Iterative Binary Search: Element " << target << " not found." << endl;

    int indexRecursive = binarySearchRecursive(arr, 0, n - 1, target);
    if (indexRecursive != -1)
        cout << "Recursive Binary Search: Element " << target << " found at index " << indexRecursive << endl;
    else
        cout << "Recursive Binary Search: Element " << target << " not found." << endl;

    return 0;
}
