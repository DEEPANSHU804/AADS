#include<bits/stdc++.h>
using namespace std;

// THIS THE COPY OF THE CODE THAR I HAVE SUBMITTED IN ONLINE PLATFORM


void merge(vector<int>&arr,int low , int mid , int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
        


    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}




void mergesort_util(vector<int>&arr,int low , int high){
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergesort_util(arr, low, mid);  // left half
    mergesort_util(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}


void mergeSort(vector < int > & arr, int n) {
   
   mergesort_util(arr, 0, n - 1);


}

int main()
 
 {
   
vector<int> arr={1,4,2,6,4,7};
mergeSort(arr,arr.size());

cout<<"sorted array is"<<endl;
    for(int i=0;i<arr.size();i++)
    { 

        cout<<arr[i]<<endl;
    }
    return 0;


 }
