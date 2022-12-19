#include <bits/stdc++.h>
using namespace std;

int knapsack(int *w, int *v, int n, int W)
{
    if (W <= 0 || n == 0)
        return 0;
    if (w[0] > W)
        return knapsack(w + 1, v + 1, n - 1, W);

    int res = -1, a, b;
    a = knapsack(w + 1, v + 1, n - 1, W - w[0]) + v[0];
    b = knapsack(w + 1, v + 1, n - 1, W);

    res = max(a, b);

    return res;
}

int knapsack_mem(int *w, int *v, int n, int W, int **output)
{
    if (W <= 0 || n == 0)
        return 0;

    if (w[0] > W)
        return knapsack_mem(w + 1, v + 1, n - 1, W, output);

    if (output[W][n] != -1)
        return output[W][n];

    int res = -1, a, b;
    a = knapsack_mem(w + 1, v + 1, n - 1, W - w[0], output) + v[0];
    b = knapsack_mem(w + 1, v + 1, n - 1, W, output);

    res = max(a, b);
    output[W][n] = res;
    return output[W][n];
}

int knapsack_dp(int *wt, int *v, int n, int W)
{
    int dp[n + 1][W + 1];
     for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(v[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    map<int, int> mp;
    int n;
    cin >> n;
    int w[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        mp[w[i]] = v[i];
    }
    int W;
    cin >> W;
    cout << "Brute force Value " << knapsack(w, v, n, W) << endl;
    int **output = new int *[W + 1];
    for (int i = 0; i <= W; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
            output[i][j] = -1;
    }
    cout << "Memorization  Value " << knapsack_mem(w, v, n, W, output) << endl;
    cout << "dp  Value " << knapsack_dp(w, v, n, W) << endl;
    for (auto it : mp)
    {
        cout << " First: " << it.first << " " << it.second << " ";
    }
}