#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return max(s.size(), t.size());
    int res;
    if (s[0] == t[0])
        return editDistance(s.substr(1), t.substr(1));
    else
    {
        int a = 1 + editDistance(s.substr(1), t);           // delete
        int b = 1 + editDistance(s, t.substr(1));           // insert
        int c = 1 + editDistance(s.substr(1), t.substr(1)); // update
        res = min(a, min(b, c));
    }

    return res;
}

int editDistance_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();
    if (s.size() == 0 || t.size() == 0)
        return max(s.size(), t.size());
    int res;
    if (output[m][n] != -1)
        return output[m][n];

    if (s[0] == t[0])
        return editDistance_mem(s.substr(1), t.substr(1), output);
    else
    {
        int a = 1 + editDistance_mem(s.substr(1), t, output);
        int b = 1 + editDistance_mem(s, t.substr(1), output);
        int c = 1 + editDistance_mem(s.substr(1), t.substr(1), output);
        res = min(a, min(b, c));
    }

    output[m][n] = res;

    return output[m][n];
}

int editDistance_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    // fill 1st row
    for (int i = 0; i <= n; i++)
        output[0][i] = i;

    // fill 1st col
    for (int j = 1; j <= m; j++)
        output[j][0] =j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // check 1st character
            if (s[m - i] == t[n - j]) // important observation
            {
                output[i][j] =  output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = min(a, min(b, c))+1;
            }
        }
    }

    return output[m][n];
}
int main()
{
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];

    for (int i = 0; i <= s.size(); i++)
    {
        output[i] = new int[t.size() + 1];
        for (int j = 0; j <= t.size(); j++)
            output[i][j] = -1;
    }

    cout << "Brute force " << editDistance(s, t) << endl;
    cout << "Memorization method " << editDistance_mem(s, t, output) << endl;
     cout << "dp method " << editDistance_dp(s, t) << endl;
}