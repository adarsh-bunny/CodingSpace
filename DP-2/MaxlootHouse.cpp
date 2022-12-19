#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int maxLoot(int *arr,int n)
{
    if(n<=0)
    return 0;

    int x= maxLoot(arr+2,n-2);
    int y=maxLoot(arr+1,n-1);

    return max(x+arr[0],y);
}
int maxLoot_dp(int *arr,int n)
{
    if(n<=0)
    return 0;
int dp[n];
 dp[0]=arr[0];
 dp[1]=max(arr[1],arr[0]);

 for(int i=2;i<n;i++)
 dp[i]=max(arr[i],arr[i-2]);


    return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

     cout << "Brute force " << maxLoot(arr,n) << endl;

     cout << "dp method " << maxLoot_dp( arr,n) << endl;
}