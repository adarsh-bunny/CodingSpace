#include<bits/stdc++.h>
using namespace std;

// RECURSIVE
int minStep(int n)
{
    if(n<=1)
    return 0;
 
   
   int y=INT_MAX,z=INT_MAX,x=INT_MAX;
    if(n!=0)
     x= minStep(n-1);
  if(n%2==0)
    y=minStep(n/2);
  if(n%3==0)
     z=minStep(n/3);
  

  int ans= min(x,min(y,z))+1;
  return ans;
}


// OPTIMISED SOLUTION -DP

int minStepO(int n,int *arr)
{
    if(n<=1)
    return 0;
   
   if(arr[n]!=-1)
   {
       return arr[n];
   }
   int y=INT_MAX,z=INT_MAX,x=INT_MAX;
    if(n!=0)
     x= minStepO(n-1,arr);
  if(n%2==0)
    y=minStepO(n/2,arr);
  if(n%3==0)
     z=minStepO(n/3,arr);
   
   

  int ans= min(x,min(y,z))+1;
   arr[n]=ans;
  return ans;
}
int main()
{
    int n;
    cin>>n;

    cout<<"Method 1: "<<minStep(n)<<endl;

int *arr=new int[n+1];
   for(int i=0;i<=n;i++)
   {
       arr[i]=-1;
   }
   cout<<"Method 2 optimised: "<<minStepO(n,arr)<<endl;
}