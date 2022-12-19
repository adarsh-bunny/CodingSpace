#include<bits/stdc++.h>
using namespace std;
int minCount(int n)
{
    if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    if(n<=0)
    return 0;
     int x=sqrt(n);
  int res=INT_MAX;
    for(int i=1;i<=x;i++)
    {
        int ans=INT_MAX;
        if(n-(i*i)>=0)
        ans= minCount(n-(i*i))+1;
        res= min(ans,res);
    }
    return res;
}


int minCount2(int n,int *arr)
{
        if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    if(n<=0)
    return 0;
     int x=sqrt(n);
     if(arr[n]!=-1)
     return arr[n];
  int res=INT_MAX;
    for(int i=1;i<=x;i++)
    {
        int ans=INT_MAX;
        if(n-(i*i)>=0)
        ans= minCount2(n-(i*i),arr)+1;
        res= min(ans,res);
    }
    arr[n]=res;
    return res;

}



//dynamic programming
int minCountO ( int n)
{
    if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    
      int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
 //   arr[3]=3;
    
    for(int i=3 ;i<=n ;i++)
    {
      	  
        arr[i] = i; 
  
        for (int x = 1; x <= ceil(sqrt(i)); x++) { 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
                arr[i] = min(arr[i], 1 + arr[i - temp]); 
           }
    }
    return arr[n];
    
}

int main()
{
    int n;
    cin>>n;
   
   // cout<<" sqrt of n="<<n<<endl;
    cout<<"Method 1:"<<minCount(n)<<endl;
    int *arr=new int[n+1];
   for(int i=0;i<=n;i++)
   {
       arr[i]=-1;
   }
   cout<<"Method 2:"<<minCount2(n,arr)<<endl;
    for(int i=0;i<=n;i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
     cout<<"Method 3:"<<minCountO(n);
}