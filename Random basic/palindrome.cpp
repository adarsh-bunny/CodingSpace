#include <bits/stdc++.h>
using namespace std;
int palindrome(char inp[], int s, int l)
{
    if (l <= 1)
    {
        cout << "if1" << endl;
        return true;
    }

    if (inp[s] != inp[l])
    {
        cout << inp[s] << " = " << inp[l] << "if2" << endl;
        return false;
    }
    else
    {
        cout << inp << " val " << s << l << endl;
        return palindrome(inp, s + 1, l - 1);
    }

    // cout << inp << " val " << s << l << endl;
    // bool r =
    // cout << r << endl;
}

int main()
{
    char inp[] = {"racecar"};
    //cin >> str;
    int l = sizeof(inp) - 1;
    cout << l << endl;
    int s = 0;
    int res = palindrome(inp, s, l - 1);
    cout << res;
}