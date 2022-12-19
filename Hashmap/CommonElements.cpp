#include<bits/stdc++.h>
using namespace std;
vector<int> intersectionElement(int *a,int *b,int s1,int s2)
{
    vector<int> ans;
    unordered_map<int,int> seen;
    for(int i=0;i<s1;i++)
    {    
        seen[a[i]]++;
    }
   for(int i=0;i<s2;i++)
    {
        seen[b[i]]++;
       
    }
    
    for(auto x:seen)
    {
        if(x.second%2==0 && x.second>1)
        {
            for(int i=0;i<x.second/2;i++)
               ans.push_back(x.first);
        }
      

    }

  map<int,int> mapp;
    for(int i=0;i<s1;i++)
        mapp[a[i]]++;
    for(int i=0 ; i<s2 ; i++){ 
        if(mapp[b[i]] > 0) {
            mapp[b[i]]--; 
            cout<<b[i] << endl;
        }
    }
    return ans;
}
int main()
{
    int a1[]={2, 6, 1, 2};
    int n1=sizeof(a1)/sizeof(a1[0]);
      int a2[]={1 ,2, 3 ,4, 2 };
    int n2=sizeof(a2)/sizeof(a2[0]);
    cout<<"Common numbers are "<<endl;
    vector<int> output= intersectionElement(a1,a2,n1,n2);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
 
}