#include<bits/stdc++.h>
using namespace std;

int getPossibleWays(int n)
{
    int a=0,b=0,c=0;
    if (n==0)
    return 1;
    if(n-1>=0)
     a= getPossibleWays(n-1);
    if(n-2>=0)
     b= getPossibleWays(n-2);
    if(n-3>=0)
     c= getPossibleWays(n-3);


    return a+b+c;
}
int output[100000];
int getPossibleWays1(int n)
{
    int a=0,b=0,c=0;
    if (n==0)
    return 1;
    if(output[n]!=0)
    return output[n];
    if(n-1>=0){
     a= getPossibleWays(n-1);
    }
    if(n-2>=0){
     b= getPossibleWays(n-2);}
    if(n-3>=0)
    {
     c= getPossibleWays(n-3);
    }

    output[n]=a+b+c;
    return a+b+c;
}
int getPossibleWays2(int n)
{
    output[0]=0;
    output[1]=1;
    output[2]=2;

    for(int i=2;i<n;i++)
    {
       output[i]=output[i-1]+output[i-2];
    }
   
    return  output[n]; 
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    output[i]=0;
    cout<<getPossibleWays( n)<<endl;
     cout<<getPossibleWays1( n)<<endl;
    cout<<getPossibleWays2( n)<<endl;
     
}