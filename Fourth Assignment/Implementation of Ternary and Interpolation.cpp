#include <iostream>
using namespace std;

// Iterative Ternary Search
int ternarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;
        
        if (target < arr[mid1]) right = mid1 - 1;
        else if (target > arr[mid2]) left = mid2 + 1;
        else left = mid1 + 1, right = mid2 - 1;
    }
    return -1;
}

// Recursive Ternary Search
int ternarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == target) return mid1;
    if (arr[mid2] == target) return mid2;

    if (target < arr[mid1]) return ternarySearchRecursive(arr, left, mid1 - 1, target);
    if (target > arr[mid2]) return ternarySearchRecursive(arr, mid2 + 1, right, target);
    return ternarySearchRecursive(arr, mid1 + 1, mid2 - 1, target);
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int pos = left + (right - left) * (target - arr[left]) / (arr[right] - arr[left]);
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    cout << "Iterative Ternary Search: " << ternarySearchIterative(arr, n, target) << endl;
    cout << "Recursive Ternary Search: " << ternarySearchRecursive(arr, 0, n - 1, target) << endl;
    cout << "Interpolation Search: " << interpolationSearch(arr, n, target) << endl;

    return 0;
}
