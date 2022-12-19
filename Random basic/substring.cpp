#include <bits/stdc++.h>
using namespace std;
int subs(string str, string output[])
{
    if (str.empty())
    {
        output[0] = "";
        return 1;
    }
    string str2 = str.substr(1);
    int si = subs(str2, output);
    for (int i = 0; i < si; i++)
    {
        //cout << str2[0] << " index0" << endl;
        output[i + si] = str[0] + output[i];
    }
    return si * 2;
}
int main()
{
    string str = {"abc"};
    long long int n = pow(2, str.size());
    cout << n << " size" << endl;
    string *output = new string[n];

    int s = subs(str, output);
    for (int i = 0; i < s; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    cout << s;
}