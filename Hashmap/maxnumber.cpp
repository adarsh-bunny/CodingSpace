#include<bits/stdc++.h>
using namespace std;

int numberOfBenches(int m,int n,int p)
{
    if(m==0 || n==0)
    return 0;
   return max(numberOfBenches(m-1,n-1,p)+1,numberOfBenches(m-1,n-1,p-1)+1);


}

int main()
{
    int m,n,p;
    cin>>m>>n>>p;
    int res=numberOfBenches(m,n,p)-1;
  //  if(res==-1)
  //  {
//cout<<0;
  //  }
  // else
      cout<<res;

}