#include <bits/stdc++.h>

using namespace std;


int findXor(vector<int> a, int n)
{
    sort(a.begin(),a.end());
    int bits = log2(a[n-1]) + 1;
    int res = 0;
    for (int i = 0; i < bits; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) 
            if (a[j] & (1 << i)) 
                count++;
            
        

        if (count > (n / 2)) 
            res += 1 << i;
        
    }
    return res;

} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         
        int x;
        cin>>x;
         vector<int> a(x);
        long long sum=0;
         for(int i=0;i<x;i++)
            cin>>a[i];
        
      
        int ans= findXor(a,x);
        for(int i=0;i<x;i++)
            sum+=a[i]^ans;
        
        cout<<sum<<endl;
    }
}