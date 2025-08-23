#include<bits/stdc++.h>
using namespace std;



int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target)
            return i;  // Target found at index i
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}