#include <bits/stdc++.h>
using namespace std;
int stoif(char inp[], int l)
{
    if (l < 1)
        return 0;

    int x = inp[0];
    int res = x - 48;
    cout << inp[0] << " val " << res << " length" << l << endl;
    for (int i = 1; i < l; i++)
        res *= 10;

    return res + stoif(inp + 1, l - 1);
}

int main()
{
    char inp[] = {"12345"};
    int l = sizeof(inp) - 1;
    cout << l << " size" << endl;

    cout << stoif(inp, l);
}