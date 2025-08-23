#include <bits/stdc++.h> 
using namespace std;

 

int partition(vector<int> &arr,int low,int high){

 

    int pivot = arr[low];

    int i = low;

    int j = high;

    while (i < j) {

      while (arr[i] <= pivot && i <= high-1 ){

          i++;

      }

      while(arr[j]>pivot && j>=low+1){

          j--;

      }

      if(i<j){

          swap(arr[i],arr[j]);

      }

    }

    swap(arr[low],arr[j]);

    return j;

}

 

void qs(vector<int> &arr,int low,int high){

    if(low<high){

        int pivot_Index = partition(arr,low,high);

        qs(arr,low,pivot_Index-1);

        qs(arr,pivot_Index+1,high);

    }

}

 

vector<int> quickSort(vector<int> &arr)

{


    qs(arr,0,arr.size()-1);

    return arr;

}


int main()
 
 {
   
vector<int> arr={1,4,2,6,4,7};
quickSort(arr);

cout<<"sorted array is"<<endl;
    for(int i=0;i<arr.size();i++)
    { 

        cout<<arr[i]<<endl;
    }
    return 0;


 }
