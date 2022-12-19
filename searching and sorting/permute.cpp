#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> permute(vector<int> &nums) {
// 1 2 3
vector<vector<int>> res;
res.push_back(nums);
for(int i= 0;i<nums.size()-1;i++)
{
    int x=nums[i];
    for(int j=i+1;j<nums.size();j++)
    {
        
        swap(x,nums[j]);
        res.push_back(nums);
          swap(x,nums[j]);
    }
}
 
return res;
}
int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
   vector<vector<int>> res= permute(arr);

    for(int i=0;i<res.size();i++)
    {
        cout<<"[";
        for(int j=0;j<res[i].size();j++)
        {
            if(j==0)
            {
                cout<<"[";
            }
            cout<<res[i][j]<<",";
            
        }
         cout<<"]]"<<endl;
    }

}