#include <bits/stdc++.h>
using namespace std;

int subset(int input[], int n, int output[][8])
{

    if (n < 1)
    {
        output[0][0] = 0;
        return 1;
    }

    int smallOutput = subset(input + 1, n - 1, output);
    for (int i = 0; i < smallOutput; i++)
    {
        // cout << output[i][0] << "output val " << endl;
        int col = output[i][0] + 1;
        // cout << col << "col val " << endl;
        output[i + smallOutput][0] = col;
        output[i + smallOutput][1] = input[0];
        for (int j = 2; j < col + 1; j++)
        {
            output[i + smallOutput][j] = output[i][j - 1];
        }
    }

    return 2 * smallOutput;
}

int main()
{
    int arr[] = {7, 8, 9};
    int l = sizeof(arr) / sizeof(arr[0]);
    cout << l << endl;
    //int n = pow(2, l);
    int output[8][8];
    int res = subset(arr, l, output);
    for (int i = 0; i < res; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
