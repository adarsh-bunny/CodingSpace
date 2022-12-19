#include<bits/stdc++.h>
using namespace std;

int helper(int x,int n,int cur_num,int *dp)
{
    if(x<0)
    return 0;
    if(x==0)
    return 1;

    int ans=0;

    for(int i=cur_num;pow(i,n)<=x;i++)
    {
        ans+=helper(x-pow(i,n),n,i+1,dp);
    }
      dp[x]=ans;
    return ans; 

}



int allPossibleWays(int x, int n)
{
    int *dp=new int[100000];
    for(int i=0;i<100000;i++)
    {
        dp[i]=-1;
    }

    int ans=helper(x,n,1,dp);
    return  ans;
}

int main()
{
    int  x,n;

    cin>>x>>n;

   cout<< allPossibleWays(x,n)<<endl;
}