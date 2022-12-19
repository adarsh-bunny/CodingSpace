#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
 cin>>n;
 cin>>k;
 vector<int> a(n);
 for(int i=0;i<n;i++)
     cin>>a[i];

    int m=0,res=0;
    int j=n-1;
sort(a.begin(),a.end());
while(m<j)
{   
    if(a[m]==k)
    {
        res++;
        m++;
    }
    else if(a[j]==k)
    {
        res++;
        j--;
    }
    else if(a[m]+a[j]<=k)
    {
        m++;
        j--;
        res++;
    }
    else if(a[m]+a[j]>k)
    {
       j--;
    }
}

cout<<res;
}