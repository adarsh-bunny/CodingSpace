#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++)
        cin >> str[i];

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++;
    }
    unsigned currentMax = 0;
    string ans;
    for (auto it = mp.cbegin(); it != mp.cend(); ++it)
    {
        if (it->second > currentMax)
        {
            ans = it->first;
            currentMax = it->second;
        }
    }
    cout << ans << " ";
}