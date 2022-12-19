#include <bits/stdc++.h>
using namespace std;
void get(string &inp, string &output, int l)
{
    output = output + inp[0];
    if (l <= 1)
        return;

    string s = inp.substr(1, l);

    string p = {"*"};
    //cout << inp.at(0) << " val " << l << endl;
    if (inp.at(0) == inp.at(1))
    {
        output = output + '*';
        cout << inp << " if " << output << endl;
    }
    get(s, output, l - 1);
    return;
}

int main()
{
    string inp = {"hello"};
    //cin >> str;
    //int l = sizeof(inp);
    int l = inp.length();
    string output = {""};
    cout << l << endl;
    get(inp, output, l);
    cout << output;
}
// #include <bits/stdc++.h>
// using namespace std;

// string func(string &s, int i)
// {
//     //base case
//     if (s[i + 1] == '\0')
//         return s;
//     //recursive case
//     else
//     {
//         if (s[i] == s[i + 1])
//         {
//             s[i + 2] = s[i + 1];
//             s[i + 1] = '*';
//             func(s, i + 1);
//         }
//         else
//             func(s, i + 1);
//     }
//     return s;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     string s = {"hello"};
//     //  cin >> s;
//     cout << func(s, 0) << endl;
//     ;

//     return 0;
// }