#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i;
cin>>i;
if(i%4==0)
{
    if(i%100==0)
    {
        if(i%400==0)
        cout<<"It is a leap year";
        else 
        cout<<"Not a leap year";
    }
    else 
     cout<<"It is a leap year";
}
else
cout<<"It is not a leap year";
}