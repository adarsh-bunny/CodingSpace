#include <bits/stdc++.h>
using namespace std;
void getPI(char inp[], int l)
{
    if (l <= 1)
        return;

    getPI(inp + 1, l - 1);
    cout << inp << " val " << l << endl;
    if (inp[0] == 'p' && inp[1] == 'i')
    {
        inp[0] = '3.';
        inp[1] = '14';
    }
    else
        return;
}

int main()
{
    char inp[] = {"xpixpi"};
    //cin >> str;
    int l = sizeof(inp);
    //cout << l;
    getPI(inp, l - 1);
    cout << inp;
}