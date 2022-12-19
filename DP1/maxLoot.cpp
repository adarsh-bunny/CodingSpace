#include <bits/stdc++.h>

using namespace std;

int maxLoot(int *arr, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int option1 = arr[0] + maxLoot(arr + 2, n - 2);

    int option2 = 0;
    if (n >= 2)
        option2 = arr[1] + maxLoot(arr + 3, n - 3);

    int ans = max(option1, option2);

    return ans;
}

int maxLoot2(int *arr, int n, int i, int *dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i] > -1)
    {
        return dp[i];
    }

    int include = arr[i] + maxLoot2(arr, n, i + 2, dp);

    int notInclude = 0;

    notInclude = maxLoot2(arr, n, i + 1, dp);

    int ans = max(include, notInclude);
    dp[i] = ans;
    return ans;
}
int maxLoot3(int *arr, int n, int *dp)
{
   
   dp[0]=arr[0];
   dp[1]=max(arr[0],arr[1]);

   for(int i=2;i<n;i++)
   {
    dp[i]= max(arr[i]+dp[i-2],dp[i-1]);
   }
     
    
    return dp[n-1];
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
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int *dp = new int[n] ;
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    cout<<endl;
    cout << "max loot " << maxLoot(arr, n)<<endl;
    cout << "max loot dp method " << maxLoot2(arr, n, 0, dp)<<endl;
    cout << "max loot dp method with iterative soln " << maxLoot3(arr, n, dp)<<endl;
    delete[] arr;
}