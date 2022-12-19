#include <bits/stdc++.h>

using namespace std;

void maxSquare(int n, int m, int **arr, int **dp)
{
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = ((arr[0][i] == 0) ? 1 : 0);
    }
    for (int i = 0; i <n ; i++)
    {
        dp[i][0] = (arr[i][0] == 0) ? 1 : 0;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < m; j++)
        {
            if(dp[i][j-1]>=1 && dp[i-1][j]>=1 && dp[i-1][j-1]>=1){
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else
            dp[i][j]=(arr[i][j] == 0) ? 1 : 0;
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **dp = new int *[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    maxSquare(n, m, arr, dp);
    cout << " dp array output" << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
            ans = max(ans, dp[i][j]);
        }
        cout << endl;
    }

    cout << "max square length matrix " << ans << endl;

    for (int j = 0; j < n; j++)
    {
        delete[] dp[j];
    }

    delete[] dp;
}