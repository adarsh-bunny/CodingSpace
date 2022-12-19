#include<bits/stdc++.h>

using namespace std;

bool isPossible( int m,vector<int> ar,int k)
{
 int count=0;
 int s=ar[0];
 for(int i=1;i<ar.size();i++)
 {
    if(ar[i]-s>=m)
    {
        count++;
    }
    if(count==k)
    return true;
 }

 return false;
}
int main()
{
    int t;
    cin>>t;
    int n,k;

    while(t--)
    {
        cin>>n>>k;
        vector<int> arr;
        int t;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            arr.push_back(t);
        }
        
       sort(arr.begin(),arr.end());

        int start=0;
        int end=arr[n-1]-arr[0];
          int res=-1;
        while(start<=end)
        {
            int mid= start + (end-start)/2;
           
            if(isPossible(mid,arr,k))
            {
                res=mid;
                start=mid+1;

            }
            else{
                end=mid-1;
            }

        }

        cout<<res<<" "<<endl;
    }
}