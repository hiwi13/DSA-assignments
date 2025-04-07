#include <iostream>
using namespace std;

int main() {
    int arr[] = {34, 2, 45, 67, 1, 89, 23, 10};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 3) {
        cout << "Array must have at least three elements to find the second and third largest." << endl;
        return 1;
    }

    int first = arr[0], second = arr[0], third = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    cout << "The second largest number is: " << second << endl;
    cout << "The third largest number is: " << third << endl;

    return 0;
}
