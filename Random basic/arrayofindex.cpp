#include <bits/stdc++.h>
using namespace std;

int lastIndex(int a[], int s, int x, vector<int> &arr)
{
    if (s < 1)
        return 0;

    //  cout << s << "size" << endl;
    int ans = lastIndex(a + 1, s - 1, x, arr);
    //cout << ans << "answer" << endl;
    for (int i = 0; i < arr.size(); i++)
    {

        arr[i] = arr[i] + 1;
        //cout << arr[i] << " value";
    }

    if (a[0] == x)
    {
        arr.push_back(0);
        sort(arr.begin(), arr.end());
        // cout << ans + 1 << arr.size() << " if1 " << endl;
        int n = ans + 1;
        return n;
    }
    else
    {
        //cout << ans << " if2 " << endl;
        return ans;
    }
}

int main()
{
    int x;
    cin >> x;
    int a[]{9, 8, 10, 8, 8};
    int s = sizeof(a) / sizeof(a[0]);
    vector<int> arr;
    int n = lastIndex(a, s, x, arr);
    if (n > 0)
        for (int i = 0; i < n; i++)
        {
            cout << " " << arr[i];
        }
    else
        cout << "not found";
}
