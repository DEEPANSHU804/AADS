#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr) {
    int n = arr.size();

   
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];


    vector<int> count(maxVal + 1, 0);

    
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    countSort(arr);

    cout << "Sorted array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
