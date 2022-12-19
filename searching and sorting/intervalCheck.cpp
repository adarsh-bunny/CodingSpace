#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        vector<pair<int,int>> intervals;
        cin>>n>>m;

        for(int i=0;i<n;i++)
         {
            int f,s;
            cin>>f>>s;
            intervals.push_back(make_pair(f,s));
         }
         sort(intervals.begin(),intervals.end());
         while(m--)
         {
            int q;
            cin>>q;
            int pos= lower_bound(intervals.begin(),intervals.end(),make_pair(q,0))-intervals.begin();
            if(pos==0)
            {
               int ans= intervals[0].first-q;
               cout<<ans<<endl;
            }
            else
            {
               int ans=-1;
               if(intervals[pos-1].second>q)
               {
                  ans=0;
               }
               else if(pos<intervals.size()) {
                  ans= intervals[pos].first-q;

               }
                  cout<<ans<<endl;
            }
         }

         // for(int i=0;i<n;i++)
         // {
         //    cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
         // }
    }
}