#include <bits/stdc++.h>
using namespace std;
void kLargestArray(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    int j = 0;
    int ans[k];
    for (int i = 4; i < n; i++)
    {
        int temp = pq.top();
        if (temp < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
        else
            continue;
    }

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        ;
        pq.pop();
    }
}

int main()
{
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int k = 4;
    int n = 13;
    kLargestArray(arr, n, k);
}