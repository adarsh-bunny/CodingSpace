/* A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13 */
#include <bits/stdc++.h>

using namespace std;

int knapsack(int k, int *wt, int *val, int n)
{
    if (k == 0 || n == 0)
        return 0;

    int option1 = knapsack(k, wt + 1, val + 1, n - 1);
    int option2 = 0;
    if (wt[0] <= k)
    {
        option2 = val[0] + knapsack(k - wt[0], wt + 1, val + 1, n - 1);
    }
    return max(option1, option2);
}

int knapsack2(int W, int *wt, int *val, int n, int **dp)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] > j) // check for weight
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }

    return dp[n][W];

    // return max(option1, option2);
}
int main()
{
    int wt[100004];
    int val[10004];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int k;
    cin >> k;

    cout << "knapsack maximum value naive method " << knapsack(k, wt, val, n) << endl;

    int **dp = new int *[k + 1];

    for (int i = 0; i < k + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "knapsack maximum value dp method recursive " << knapsack2(k, wt, val, n, dp) << endl;

    for (int i = 0; i < k + 1; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;
}