#include <bits/stdc++.h>
using namespace std;

int min_point2(int **input, int r, int c)
{
    int **dp = new int *[r];
    for (int i = 0; i < r; i++)
        dp[i] = new int[c];
    
    dp[r - 1][c - 1] = 1;
    dp[r - 1][c - 2] = 1;
    dp[r - 2][c - 1] = 1;

    for (int i = r - 3; i >= 0; i--) //last col fill
    { 
            dp[i][c - 1] = max(1, dp[i + 1][c - 1] - input[i + 1][c - 1]);    
    }
    for (int j = c - 3; j >= 0; j--)
    {
        dp[r-1][j]=max(1,dp[r-1][j+1]-input[r-1][j+1]); //last row fill
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = c - 2; j >= 0; j--)
        {   
            int right;
            int down;  
            down = max(1, dp[i + 1][j] - input[i + 1][j]);  //down

         right = max(1, dp[i][j+1] - input[i][j+1]);  //right
         dp[i][j] = min(down, right);
        }
    }
    int ans = dp[0][0];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < r; i++)
        delete[] dp[i];
    
    delete[] dp;
 
        return ans;
}
int min_point(int **input, int si, int sj, int ei, int ej)
{
    if (si == ei || sj == ej)
        return 1;
    
    
    if (si > ei || sj > ej)
        return -10;
    
    int option1 = max(1,min_point(input, si + 1, sj, ei, ej)-input[si + 1][sj]); //DOWN
    int option2 = max(1,min_point(input, si, sj + 1, ei, ej)-input[si][sj+1]); //right
   
    int ans = min(option1,option1);
   
    //ans= max(1,ans);
  //  HM[si][sj]=ans;
    return  ans;
}
int main()
{

    int r, c;
    cin >> r >> c;
    int **input = new int *[r];
    for (int i = 0; i < r; i++)
    {
        input[i] = new int[c];
        for (int j = 0; j < c; j++)
            cin >> input[i][j];
    }
    cout <<"Dp method = "<< min_point2(input, r, c) << endl;

    cout << "recursive method = "<< min_point(input, 0, 0, r-1, c-1) << endl;
 
    for (int i = 0; i < r; i++)
    {
        delete[] input[i];
    }
    delete[] input;
}
