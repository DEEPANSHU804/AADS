#include<bits/stdc++.h>
using namespace std;

 void selection_sort(int arr[],int N)
{
    for(int i=0;i<N;i++)
    {int min=i;
        for(int j=i;j<N;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
return;
}




int main()
 
 {
   
    int N;
    
     int arr[100];
    cin>>N;
     cout<<"ENTER THE ARRAY TO BE SORTED ";
    for(int i=0;i<N;i++)
    {
     cin>>arr[i];

    }
    selection_sort(arr,N);
cout<<"sorted array is"<<endl;
    for(int i=0;i<N;i++)
    { 

        cout<<arr[i]<<endl;
    }
    return 0;


 }
