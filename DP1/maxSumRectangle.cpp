#include <bits/stdc++.h>

using namespace std;
int kadane_sum(int *temp, int r)
{
    int sum = 0;
    int curr_sum = INT_MIN;

    for (int i = 0; i < r; i++)
    {
        curr_sum += temp[i];

        sum = max(sum, curr_sum);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return sum;
}
int max_sum(int **arr, int r, int c)
{

    int sum = 0;
    for (int left = 0; left < c; left++)
    {
        int *sumArr = new int[r]();
        for (int i = 0; i < r; i++)
        {
            cout << i << "=" << sumArr[i] << " ";
        }
        for (int right = left; right < c; right++)
        {
            for (int j = 0; j < r; j++)
            {
                sumArr[j] += arr[j][right];
            }
            sum = max(sum, kadane_sum(sumArr, r));
        }
    }
    return sum;
}
int main()
{
    int r, c;
    cin >> r >> c;
    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << " result= " << max_sum(arr, r, c) << endl;
}