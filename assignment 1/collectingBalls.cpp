
#include<bits/stdc++.h>
using namespace std;
bool check(int k, int n)
{
    int temp=n;
    int curr_sum=0;
    int sum=0;

    while(temp>0)
    {
        if(n-sum<k)
       {
        temp=0;
       }

       curr_sum+=k;
       sum+=k;
       temp-=k;
       sum=sum+temp/10;
       temp=temp-temp/10;
        if(curr_sum>=n/2)
         return true;

    }
    if(curr_sum==n/2)
    return true;
     else 
    return false;

}
int optimizer(int s,int e,int n)
{
   
    int ans=-1;

    while(s<e)
    {
         int mid=(s+e)/2;
         cout<<"mid "<<mid<<" "<<endl;
        if(check(mid,n))
        {
            ans=mid;
            cout << " ans  "<< mid<<endl;
            e=mid-1;   
        }
        else
        {
            s=mid+1;
        }
    }

    return ans; 
  
}
int main()
{
	int n;
	cin >> n;
	cout << "final ans "<<optimizer(1,n,n);
}