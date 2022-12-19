#include<bits/stdc++.h>
using namespace std;

//recursively => o(2^n)
int fib(int n)
{
    if(n<=1)
    return n;
    return (fib(n-1)+fib(n-2));
}

// top down approach =>recursively =>o(n)
int fib_o(int n,int *arr)
{
    if(n<=1)
    return n;
    
    if(arr[n]!=-1)
     return arr[n];

     int a=fib_o(n-1,arr);
     int b=fib_o(n-2,arr);
     arr[n]=a+b;
     return a+b;
}


//bottom up approach => iterative approach =>o(n)
int fibo_3(int n)
{
     int *ans=new int[n+1];
    
   ans[0]=0;
   ans[1]=1;
   for(int i=2;i<=n;i++)
   {
       ans[i]=ans[i-1]+ans[i-2];
   }
   return ans[n];

}



int main()
{

    int n;
    cin>>n;
        int *arr=new int[n+1];
   for(int i=0;i<=n;i++)
   {
       arr[i]=-1;
   }
    cout<<" Method 1 - :"<<fib(n)<<endl;
    cout<<" Method 2 - :"<<fib_o(n,arr)<<endl;
//     for(int i=0;i<=n;i++)
//    {
//        cout<<arr[i]<<" ";
//    }
   cout<<endl;
    cout<<" Method 3 - :"<<fibo_3(n)<<endl;

}