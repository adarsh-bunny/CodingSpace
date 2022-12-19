#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[],int low,int high,int x){
int mid=low + (high-low)/2;
if(arr[mid]==x)
return mid;

if(arr[mid]>x)
{
    high=mid-1;
    binarySearch(arr,low,high,x);
}
else if(arr[mid]<x)
{
    low=mid+1;
    binarySearch(arr,low,high,x);
}
return -1;
}

int main(){
    int arr[]={1,2,3,6,9,11,15,16,17,19,22};

    int size=sizeof(arr)/sizeof(arr[0]);
    int index= binarySearch(arr,0,size,11);
    if(index!=-1)
    cout<<"element is at index= "<<index<<endl;
    else
    cout<<"element is not present "<<endl;
}