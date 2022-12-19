#include<bits/stdc++.h>
using namespace std;
bool prime(int i)
{
    for(int j=2;j<i;j++)
      {
          if(i%j==0)
          return 0;
      }

      return 1;

}

int main(){
    int l,u,res,count=0;
    cin>>l>>u;
    int i;
    for(i=l;i<=u;i++)
    {
        res=0;
        bool res=prime(i);
      //  cout<<" prime res1 -"<<res<<endl;
      if(res==1 && i+6<=u)
      {
          
          bool res2=prime(i+6);
          
        
          if(res2==1)
          {
              count++;
               cout<<" prime pair -"<<i<<" , "<<i+6<<")"<<res2<<endl;
          }
          
      }

    }
    
   if(count==0)
    cout<<"Not present any prime pair number"<<endl;
    else 
    cout<<"prime pair number exist ="<<count<<endl;
    
}