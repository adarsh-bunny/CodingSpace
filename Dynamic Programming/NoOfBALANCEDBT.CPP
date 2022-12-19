#include<bits/stdc++.h>
using namespace std;


int balancedBT(int h )
{
    if(h<=1)
    return 1;

int mod= (int) pow(10,9)+7;
    int x=balancedBT(h-1);
    int y= balancedBT(h-2);
   

   int temp=(int)(((long)(x)*x)%mod);
   int temp1= (int)((2*(long)(x)*y)%mod);
   int ans=(temp+temp1)%mod;
   //int ans= (x*x+ 2*y*x)%mod;
    return ans;
}


int balancedBT1(int h,int *arr )
{
    if(h<=1)
    return 1;
    if(arr[h]!=-1)
     return arr[h];
int mod= (int) pow(10,9)+7;
    int x=balancedBT1(h-1,arr);
    int y= balancedBT1(h-2,arr);
   

   int temp= (int)(((long)(x)*x)%mod) ;
   int temp1= (int)((2*(long)(x)*y)%mod) ;
   int ans=(temp+temp1)%mod;

   arr[h]=ans;
    //int ans= (x*x+ 2*y*x)%mod;
    return ans;
}

int balancedBT2(int h )
{
    if(h<=1)
    return 1;
   int dp[h];
    dp[0]=0;
    dp[1]=1;
    dp[2]=3;
    int mod= (int) pow(10,9)+7;
for(int i=3;i<=h;i++)
{
      dp[i]=(int)(((long)(dp[i-1])*dp[i-1])%mod + (2*(long)(dp[i-1])*dp[i-2])%mod) % mod;  
}
    return dp[h];
}
int main()
{
    int h;
    cin>>h;
   int *arr=new int[h+1];
   for(int i=0;i<=h;i++)
       arr[i]=-1;
   
    cout<<balancedBT(h)<<endl;
    cout<<balancedBT1(h,arr)<<endl;
      cout<<balancedBT2(h)<<endl;
    //  for(int i=0;i<=h;i++)
    //    cout<<arr[i]<<endl;
}