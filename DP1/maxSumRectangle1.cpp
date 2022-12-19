#include <bits/stdc++.h>

using namespace std;
int kadane_sum(int *temp, int r)
{
    int sum = INT_MIN;
    int curr_sum = 0;

 /* for (int i = 0; i < r; i++)
    {
        cout<<i<<"="<<temp[i]<<" ";    
    }
     cout<<endl; */
    for (int i = 0; i < r; i++)
    {
        curr_sum += temp[i];
          cout<<i<<" i "<<curr_sum<<" temp[i] "<<temp[i]<<endl;
         if (sum < curr_sum)
        {
            sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return sum;
}
int max_sum(int **arr, int r, int c)
{

    int sum =INT_MIN;
    for (int left = 0; left < c; left++)
    {
        int *sumArr = new int[r]();
        for (int right = left; right < c; right++)
        {
            for (int j = 0; j < r; j++)
            {
                sumArr[j] = sumArr[j]+ arr[j][right];
                //cout<<j<<","<<right<<"="<<arr[j][right]<<" sum = "<<sumArr[j]<<" endl ";
            }
           // cout<<endl;

            if(sum< kadane_sum(sumArr, r))
            {
                sum=kadane_sum(sumArr, r);
            }
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