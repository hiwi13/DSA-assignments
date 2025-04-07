#include <iostream>
using namespace std;

int main() {
    int arr[] = {34, 2, 45, 67, 1, 89, 23, 10};

    int n = sizeof(arr) / sizeof(arr[0]); 

    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "The smallest number in the array is: " << smallest << endl;

    return 0;
}

