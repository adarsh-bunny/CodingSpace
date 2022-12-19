#include <bits/stdc++.h>
using namespace std;
void toi(int n, char a, char b, char c)
{

    if (n == 0)
        return;

    toi(n - 1, a, c, b);
    cout << a << " " << c << endl;
    toi(n - 1, b, a, c);
    // cout << a << " " << c << endl;
}

int main()
{
    int n;
    cin >> n;
    char a = {'a'}, b = {'b'}, c = {'c'};
    toi(n, a, b, c);
}
