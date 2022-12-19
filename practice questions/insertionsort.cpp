#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertionSort(int arr[],int size)
{
    int k=-1,j;
    for(int i=1;i<size-1;i++)
    {        int key=arr[i];
    j=i-1;
           while(key<arr[j] && j>0)
           {
               arr[j+1]=arr[j];
               j--;

           }
           arr[j+1]=key;
 
        
        
    }
}

int main()
{
    int arr[]={5,9,7,12,8,10,20,13};
     int s = sizeof(arr) / sizeof(arr[0]);
     insertionSort(arr,s);
     for(int i=0;i<s;i++)
     {
         cout<<arr[i]<<endl;
     }
}