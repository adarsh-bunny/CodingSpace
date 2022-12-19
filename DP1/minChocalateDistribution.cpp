#include <bits/stdc++.h>

using namespace std;

int getMin(int *arr, int n)
{
   
    int curr_max=1;
    int prev=1,count=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            count++;
            curr_max+=count*1; 
            prev=1;
        }
        else if(arr[i]>arr[i-1])
        {
           prev++;
           count=1;
           curr_max+=prev;
        }
        else
        {
            curr_max++;
            count=1;
            prev=1;
        }
        
    }

    return curr_max;
}

int getMin2(int *arr, int n)
{
    int *dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i + 1] < arr[i] && dp[i] <= dp[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dp[i];
    }
    delete[] dp;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    // vector<int>> arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
  

    int *dp = new int[n] ;
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    cout<<endl;
    cout << "max loot " << getMin(arr, n)<<endl;
   cout << "max loot dp method " << getMin2(arr, n)<<endl;
   // cout << "max loot dp method with iterative soln " << maxLoot3(arr, n, dp)<<endl;
    delete[] arr;
}