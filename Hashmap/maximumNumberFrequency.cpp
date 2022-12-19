#include<bits/stdc++.h>
using namespace std;
int maxFrequencyNumber(int *a,int size)
{
   // vector<int> output;
    unordered_map<int,int> seen;
    for(int i=0;i<size;i++)
    {
        seen[a[i]]++;
    }
    int max=0;
    int key=0;
   for (auto x : seen)
   {
//cout<<" value = "<<x.first<<" is "<<x.second<< endl;
       if(max<x.second)
       {
            key=x.first;
            max= x.second;
       //  cout<<" value = "<<x.first<<" is "<<x.second<< endl;

       }
   }
    //     unordered_map<int, int>:: iterator itr;
    //       for (itr = seen.begin(); itr != seen.end(); itr++)
    // {
    //     // itr works as a pointer to pair<string, double>
    //     // type itr->first stores the key part  and
    //     // itr->second stores the value part
    //      if(max<itr->second )
    //         max= itr->first;
       
    //  }
    

  
    return key;
}
int main()
{
    int a[]={2, 12, 2, 11, 12 ,2 ,1, 2 ,2 ,11, 12 ,2 ,6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"maximum frequency number is "<< maxFrequencyNumber(a,n);
 
}