#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,q;
    cin>>n>>q;
    long long a[n];
    for(i=0;i<n;i++) 
    cin>>a[i];
    
    while(q--)
    {
        int a1,b;
        cin>>a1>>b; 
            long long sum=0;
            for(int i=a1; i<=b;i++)
            {
                sum+=a[i];
            }
            cout<<sum<<endl;
    
    
    
    }
}