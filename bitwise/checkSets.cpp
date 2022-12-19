#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n,i;
    cin>>n>>i;

    // check for N & pow(2,i)  //  if it non zero then its set else not set but log(i) complexity

    //using bitwise left shift = n*2powi

    if((n & (1<<i))>0)   // 1 * pow(2,i)
    cout<<"Sets- true"<<endl;
    else
     cout<<"Not Sets- False"<<endl;

     int y=1;
     auto k=y & (y=2);
     auto a=(y=2);
         if(y & (y=2))   // 1 * pow(2,i)
    cout<<"True "<<k<<"-"<<a<<endl;
    else
     cout<<"False"<<endl;
     

}