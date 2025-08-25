#include <iostream>
using namespace std;

                                  
void heapify(int arr[], int n, int i)// i is the node to be heapified
 {
    int largest = i;         
    int left = 2 * i + 1;   
    int right = 2 * i + 2;   

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

   
    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
  
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

  
    for (int i = n - 1; i > 0; i--) {
       
        swap(arr[0], arr[i]);//swapping maxx with the last element,hence the maxx element is it its right position
       
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}