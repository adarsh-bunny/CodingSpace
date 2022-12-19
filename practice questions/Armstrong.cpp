#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp=n;
    int sum=0,p=0;
    while(temp!=0)
    {
         p++;
         temp=temp/10;
    }
    cout<<"no. of digits= "<<p<<endl;
    temp=n;
    while(temp>0)
    {
        int i=temp%10;
        int power= pow(i,p);  
        sum=sum+ power;
        temp/=10;

    }
    if (sum==n)
        cout << n << " is a Armstrong number" << endl;
    else
        cout << n << " is not a Armstrong number" << endl;
}