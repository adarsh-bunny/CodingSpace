#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
int solve(int n,int k,vector<int> h)
{
    if(n==0)
    return 0;
    int res=1;
for(int i=0;i<n-1;i++)
{
    int temp=1;
    res++;
   //cout<<"loop "<<i<<" "<<res<<endl;
    while(temp<=k && i+temp<n)
    {
        if(h[i]<=h[i+temp])
        {
            res--;
            break;
        }


        temp++;

    }
   
}
 return res;
}
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
       
        cin>>n>>k;
         vector<int> a(n);
        for(int i=0;i<n;i++)
        cin>> a[i];

        Solution ob;
        cout<<ob.solve(n,k,a)<<endl;
    }
}