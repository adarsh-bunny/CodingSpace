#include<bits/stdc++.h>
using namespace std;

void unique(int l,int u)
{
    vector <int> res(10,0);
    for(int i=l;i<=u;i++)
    {
        int num=i;
        while(num)
        {
            res[num%10]++;
            num/=10;
        }

    }
    int count=0;
    for(int k=0;k<10;k++)
    {
        if(res[k]==1)
            count++;    
    }
    if(count==0)
    cout<<"Not present any unique digit";
    else 
    cout<<"present unique digit = "<<count;

}
int main(){
   int l,u;
cout<<"USER INPUT";
   cin>>l>>u;
   unique(l,u);
   return 0;
}