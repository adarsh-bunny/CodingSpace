#include <bits/stdc++.h>

using namespace std;

int editDistance(string s1, string s2)
{
    if (s1.size() == 0)
        return s1.length();
    if (s2.size() == 0)
        return s2.length();

    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    else
    {
        int option1 = 1 + editDistance(s1.substr(1), s2.substr(1));
        int option2 = 1 + editDistance(s1.substr(1), s2);
        int option3 = 1 + editDistance(s1, s2.substr(1));

        return min(option1, min(option2, option3));
    }
}

int editDistance2(string s1, string s2, int m, int n, int **dp)
{
    if (s1.size() == 0)
        return s1.length();
    if (s2.size() == 0)
        return s2.length();
    if (dp[m][n] > -1)
        return dp[m][n] ;
        int ans = -1;
    if (s1[0] == s2[0])
    {
        ans = editDistance2(s1.substr(1), s2.substr(1), m - 1, n - 1, dp);
    }
    else
    {
        int option1 = 1 + editDistance2(s1.substr(1), s2.substr(1), m - 1, n - 1, dp);
        int option2 = 1 + editDistance2(s1.substr(1), s2, m - 1, n, dp);
        int option3 = 1 + editDistance2(s1, s2.substr(1), m, n - 1, dp);

        ans = min(option1, min(option2, option3));
    }

    dp[m][n] = ans;

    return dp[m][n];
}

int editDistance3(string s1, string s2, int m, int n, int **dp)
{
    if (s1.size() == 0)
        return s1.length();
    if (s2.size() == 0)
        return s2.length();
   
     for(int i=0;i<=m;i++)
     {
        dp[0][i]=i; //row fill->s1 lenght in row
     }
      for(int i=0;i<=n;i++)
     {
        dp[i][0]=i;//col fill->s2 lenght in col
     }
      
      for(int i=1;i<=n;i++)
      {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
      }

    

    return dp[m][n];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << "naive method " << editDistance(s1, s2) << endl;

    // making dp array of length m and n ie size of two string respectively
    int m = s1.length();
    int n = s2.length();
    int **dp = new int *[m + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "DP method " << editDistance2(s1, s2, m, n, dp) << endl;
     cout << "DP method with tabular form/no recursion " << editDistance3(s1, s2, m, n, dp) << endl;

    for (int j = 0; j <= m; j++)
    {
        delete[] dp[j];
    }
    delete[] dp;
}