#include <bits/stdc++.h>
using namespace std;
int matrixMultiplication(int a[], int s, int e)
{
    if (e-s <= 1 )
        return 0;
    int res = INT_MAX;
    for (int k = s + 1; k < e; k++)
    {
        //cout<< a[s]<<" a[k]: "<<a[k]<<" "<<a[e]<<endl;
          int t =matrixMultiplication(a, s, k)+ matrixMultiplication(a, k, e)+ a[s] * a[k] * a[e];
        res=min(t,res);
       // cout<<res<<" t: "<<t<<" "<<endl;
    }

    return res;
}
int matrixMultiplication_dp( vector <vector <int> >  &dp,int a[], int s, int e)
{
    if (e-s <= 1 )
        return 0;
        if(dp[s][e]!=0)
        return dp[s][e];

    int res = INT_MAX;
    for (int k = s + 1; k < e; k++)
    {
        
          int t =matrixMultiplication(a, s, k)+ matrixMultiplication(a, k, e)+ a[s] * a[k] * a[e];
        res=min(t,res);
   

    }
    dp[s][e]=res;

    return dp[s][e];
}
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    

    cout<<" Brute force recursive =================================="<<endl;
    cout << matrixMultiplication(a, 0, n) << endl;
    cout<<endl;


    cout<<"dp method =================================="<<endl;
       vector <vector <int> > dp(n+1,vector<int>(n+1,0));
    
    cout << matrixMultiplication_dp(dp,a, 0, n) << endl;
    cout<<endl;
}