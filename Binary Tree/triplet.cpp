#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, u, b, j, k;
        cin >> n;
        int a[n];
        for (i = 0; i < n; ++i)
            cin >> a[i];
        cin >> b;
        for (int u = 0; u < b; ++u)
        {
            int ans = 0;
            for (i = 0; i < n; ++i)
            {
                for (j = i + 1; j < n; ++j)
                {
                    for (k = j + 1; k < n; ++k)
                    {
                        if ((a[i] + a[j] + a[k]) % b == u)
                            ++ans;
                    }
                }
            }
            cout << ans<<" " ;
        }
        cout<<"\n";
    }
    return 0;
}

vector<long, long> count_triplets(int N, vector<int> A, int B){
    long long ans[B];//={0};
    int l=0;
    while(l<N-2)
    {
         for (int i = l + 1; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                ans[(A[l] + A[i] + A[j]) % B]++;
            }
        }
        l++;
    }
return ans;
    
}
vector<long, long> count_triplets(int N, vector<int> A, int B){
    vector<long long> res(B, 0);//={0};

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                res[(A[i] + A[j] + A[k]) % B]++;
            }
        }
    }
    return res;
}