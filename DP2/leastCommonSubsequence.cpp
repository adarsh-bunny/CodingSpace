#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0)
        return 0;

    if (s1[0] == s2[0])
    {
        return 1 + lcs(s1.substr(1), s2.substr(1));
    }
    else
    {
        int option1 = lcs(s1, s2.substr(1));
        int option2 = lcs(s1.substr(1), s2);

        return max(option1, option2);
    }
}

int lcs2(string s1, string s2, int m, int n, int **dp)
{
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] > -1)
        return dp[m][n];
   int ans=-1;

    if (s1[0] == s2[0])
    {
        ans= 1 + lcs2(s1.substr(1), s2.substr(1), m-1, n-1, dp);
    }
    else
    {
        int option1 = lcs2(s1, s2.substr(1), m, n-1, dp);
        int option2 = lcs2(s1.substr(1), s2, m-1, n, dp);

        ans= max(option1, option2);
    }

    dp[m][n]=ans;

    return dp[m][n];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << "naive method " << lcs(s1, s2) << endl;

    // making dp array of length m and n ie size of two string respectively
    int m = s1.length();
    int n = s2.length();
    int **dp = new int *[m+1];

    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n+1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "DP method " << lcs2(s1, s2, m, n, dp) << endl;

    for (int j = 0; j <= m; j++)
    {
        delete[] dp[j];
    }
    delete[] dp;
}