#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=0,a;
    int sum;
    a=(i*i*i);
    while(i<100)
    {
        
        sum=sum+a;
        i=i+1;
        a=(i*i*i);
        cout<<i<<" "<<a<<endl;

    }

    cout<<sum;
}