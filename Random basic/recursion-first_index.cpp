#include <bits/stdc++.h>
using namespace std;
int firstIndex(int a[], int s, int x)
{
    if (s < 1)
        return -1;
    if (a[0] == x)
        return 0;
    cout << s << "size" << endl;
    int ans = firstIndex(a + 1, s - 1, x);
    cout << ans + 1 << "answer" << endl;
    if (ans == -1)
    {
        return -1;
    }
    else
        return ans + 1;
}
int main()
{
    int x;
    cin >> x;
    int a[]{6, 5, 4, 5, 6};
    int s = sizeof(a) / sizeof(a[0]);
    cout << s << "size" << endl;
    cout << "Answer" << firstIndex(a, s, x) << endl;
}
