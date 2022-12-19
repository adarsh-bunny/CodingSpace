#include<bits/stdc++.h>
using namespace std;

int coinChange(int v,int n,int a[])
{

 int dp[n+1][v+1];
 for(int i=0;i<n+1;i++)
    dp[i][0]=1;
     for(int i=0;i<v+1;i++)
    dp[0][i]=0;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v;j++)
        {
           // cout<<"i value:"<<i<<" "<<j<<endl;

            if(j>=a[i-1])
            {
                dp[i][j]= dp[i][j-a[i-1]]+dp[i - 1][j];
            }
            else{
                  dp[i][j]=dp[i-1][j];
            }
        }
        
     
        

    }

       for(int i=0;i<=n;i++)
   {
    for(int j=0;j<=v;j++)
       cout<<dp[i][j]<<" ";
       cout<<endl;
   }
    return dp[n][v];

    


}

int main()
{
    int n,v;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++ )
    {
        cin>>a[i];
    }

    cin>>v;

    // int **dp=new int*[n+1];
    // for(int i=0;i<=n;i++)
    // {
    //     dp[i]=new int[v+1];
    //     for(int j=0;j<=v;j++)
    //     {
    //         dp[i][j]=-1;
    //     }
    // }
 

  
   cout<< coinChange(v,n,a)<<endl;

//    for(int i=0;i<=n;i++)
//    {
//     for(int j=0;j<=v;j++)
//        cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
}