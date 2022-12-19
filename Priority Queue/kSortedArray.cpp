#include <bits/stdc++.h>
using namespace std;
void kSortedArray(int arr[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    int j=0;
    for(int k=3;k<n;k++)
    {
        arr[j]=pq.top();
        pq.pop();
        pq.push(arr[k]);
        j++;

    }

    while(!pq.empty())
    {
        arr[j]=pq.top();
        pq.pop();
        j++;

    }
}

int main()
{
    int arr[]={10,12,6,7,9};
    int k=3;
    int n=5;
    kSortedArray(arr,n,k);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}