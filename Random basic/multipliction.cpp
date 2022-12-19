#include <bits/stdc++.h>
using namespace std;
//static int res = 0;
int multiply(int n, int m)
{
    if (m == 1)
        return n;

    cout << " val " << m << endl;
    int res = multiply(n, m - 1);
    int result = res + n;
    return result;
}

int main()
{
    int n = 4;
    int m = 5;
    int res1 = multiply(n, m);
    cout << res1;
}
