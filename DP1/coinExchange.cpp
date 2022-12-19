#include <bits/stdc++.h>
using namespace std;
int output[10000][10005];

long int waysToMakeChange(int n, int arr[], int k)
{
    if (k == 0)
        return 1;

    if (n == 0)
        return 0;
    int a = 0, b = 0;
    if (k - arr[0] >= 0)
    {
        a = waysToMakeChange(n, arr, k - arr[0]);
        b = waysToMakeChange(n - 1, arr + 1, k);
    }
    return a + b;
}

long int waysToMakeChangeOptimize(int n, int arr[], int k)
{
    if (k == 0)
        return 1;

    if (n == 0)
        return 0;
    if (k < 0)
    {
        return 0;
    }
    if (output[k][n]> -1)
    {
        return output[k][n];
    }

    int a = waysToMakeChange(n, arr, k - arr[0]);
   int  b = waysToMakeChange(n - 1, arr + 1, k);
   
    output[k][n] = a + b;
     cout<<output[k][n]<<" ";
    return output[k][n];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j <= n; j++)
            output[i][j] = -1;
    }
    cout << "=================" << endl;
    cout << waysToMakeChange(n, arr, k) << endl;
    cout << waysToMakeChangeOptimize(n, arr, k) << endl;

      for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j <= n; j++)
            cout<<output[i][j]<<" ";
            cout<<endl;
    }
}