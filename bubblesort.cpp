#include<bits/stdc++.h>
using namespace std;




void bubble(int arr[],int N)
{
for(int i=N-1;i>=0;i--)
{int ds=0;
    for(int j=0;j<i;j++)
{
    if(arr[j]>arr[j+1])
    {
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        ds=1;
    }
   
}
 if(ds==0)
    break;
}
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
    bubble(arr,N);
cout<<"sorted array is"<<endl;
    for(int i=0;i<N;i++)
    { 

        cout<<arr[i]<<endl;
    }
    return 0;


 }
