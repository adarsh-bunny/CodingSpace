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
        inp[0] = '3';
        inp[1] = '4';
    }
    else
        return;
}

int main()
{
    string str = {"12345"};
    //cin >> str;
    // int l = ;
    //cout << l;
    int a = 0;
    stringstream res(str);
    //getPI(inp, l - 1);
    res >> a;
    cout << a;
}