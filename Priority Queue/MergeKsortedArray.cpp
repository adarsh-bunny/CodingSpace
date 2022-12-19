#include<bits/stdc++.h>
using namespace std;

int main()
{
   priority_queue<int,vector<int>, greater<int>> pq; 
   int arr1[]={1,5,9};
   int arr2[]={45,90};
   int arr3[]={2, 6, 78, 100, 234};
   int arr4[]={0};
   int n1=3,n2=2,n3=5,n4=1;
  
  int t= n1+n2+n3+n4;

  for(int i=0;i<n1;i++)
  {
      pq.push(arr1[i]);
  }
  for(int i=0;i<n2;i++)
  {
      pq.push(arr2[i]);
  }
  for(int i=0;i<n3;i++)
  {
      pq.push(arr3[i]);
  }
  for(int i=0;i<n4;i++)
  {
      pq.push(arr4[i]);
  }
  
 
      while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
  

}