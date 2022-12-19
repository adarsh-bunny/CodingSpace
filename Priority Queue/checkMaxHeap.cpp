#include<bits/stdc++.h>
using namespace std;

bool checkMaxheap(int *arr, int n)
{
   for(int i=1;i<n;i++)
   { 
       int parent= (i-1)/2;
       if(arr[parent]<arr[i])
       return 0;
   }
   return 1;
}

int main()
{
    int arr[]={42, 20, 18, 6, 14, 15, 9, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
   bool res= checkMaxheap(arr,n);
   cout<<boolalpha<<res;
}