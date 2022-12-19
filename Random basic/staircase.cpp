#include <bits/stdc++.h>
using namespace std;
int staircount(int n)
{

    if (n == 0 || n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return staircount(n - 1) + staircount(n - 2) + staircount(n - 3);
    // cout << a << " " << c << endl;
}

int main()
{
    int n;
    cin >> n;

    cout << staircount(n);
}
