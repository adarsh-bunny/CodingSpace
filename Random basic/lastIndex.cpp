#include <bits/stdc++.h>
using namespace std;
int lastIndex(int a[], int s, int x)
{
    if (s < 1)
        return -1;

    //  cout << s << "size" << endl;
    int ans = lastIndex(a + 1, s - 1, x);
    //cout << ans + 1 << "answer " << endl;
    if (ans == -1)
    {
        if (a[0] == x)
        {
            cout << "if1" << ans << endl;
            return 0;
        }
        else
        {
            cout << "if2" << ans << endl;
            return -1;
        }
    }
    else
    {
        cout << ans + 1 << "else" << endl;
        return ans + 1;
    }
}
int main()
{
    int x;
    cin >> x;
    int a[]{6, 5, 4, 5, 6};
    int s = sizeof(a) / sizeof(a[0]);
    //cout << s << "size" << endl;
    cout << "Ans " << lastIndex(a, s, x) << endl;
}
