#include<bits/stdc++.h>
using namespace std;


int staircase(int n,int *arr)
{
    if(n<=1)
    return 1;
 
  if(arr[n]!=-1)
       return arr[n];
int a=0,b=0,c=0;

if(n-1>=0)  
 a =staircase(n-1,arr);
if(n-2>=0)  
 b=staircase(n-2,arr);
if(n-3>=0)  
 c=staircase(n-3,arr);

arr[n]=a+b+c;

return arr[n];
}

long staircase(int n){
    
    long a[n+1];
     
    a[0]=1;a[1]=1;a[2]=2;a[3]=4;
 
        
        for(int i=4 ;i<=n ;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
    
    return a[n];
    
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1];
   for(int i=0;i<=n;i++)
       arr[i]=-1;
   
   cout<<"staircase m1: "<<staircase(n,arr)<<endl;
   cout<<"staircase m2: "<<staircase(n)<<endl;
}