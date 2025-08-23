#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[],int N)
{
    for (int i=1;i<=N-1;i++)
    {cout<<"hey";
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;

        }

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
    insertion(arr,N);
cout<<"sorted array is"<<endl;
    for(int i=0;i<N;i++)
    { 

        cout<<arr[i]<<endl;
    }
    return 0;


 }
