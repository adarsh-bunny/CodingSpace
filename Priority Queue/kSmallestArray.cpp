#include <bits/stdc++.h>
using namespace std;
void kSmallestArray(int arr[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    int j=0;
    int ans[k];
    for(int i=k;i<n;i++)
    {
        int temp=pq.top();
        if(temp>arr[i])
           {pq.pop();
        pq.push(arr[i]);
           }
           else 
           continue;

    }

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;;
        pq.pop();
      

    }
}

int main()
{
    int arr[]={2, 12 ,9 ,16 ,10, 5 ,3, 20, 25, 11, 1, 8, 6 };
    int k=4;
    int n=13;
    kSmallestArray(arr,n,k);
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";
}