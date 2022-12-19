#include <bits/stdc++.h>
using namespace std;

int pathToMinCost(int **arr, int m, int n,int i,int j)
{
    if (i==m-1 && j==n-1)
    {
      int res= arr[i][j];
      return res;
    }
     if (i>=m || j>=n)
      return INT_MAX;
    

    int x = pathToMinCost(arr, m , n,i+1,j  );
    int y = pathToMinCost(arr, m, n ,i+1,j+1);
    int z = pathToMinCost(arr, m , n,i,j+1);

    int ans = min(x, min(y, z)) + arr[i][j];
    return ans;
}


int pathToMinCost_Mem(int **arr, int m, int n,int i,int j, int **output)
{
    if (i==m-1 && j==n-1)
    {
      int res= arr[i][j];
      return res;
    }
     if (i>=m || j>=n)
      return INT_MAX;
    
    // check if ans already exists or not
     if(output[i][j]!=-1)
     return output[i][j];

    int x = pathToMinCost_Mem(arr, m , n,i+1,j ,output );
    int y = pathToMinCost_Mem(arr, m, n ,i+1,j+1,output);
    int z = pathToMinCost_Mem(arr, m , n,i,j+1,output);

    int a = min(x, min(y, z)) + arr[i][j];
    //save ans for futur use

    output[i][j]=a;

    return a;
}



int pathToMinCost_dp(int **input, int m, int n)
{
      int **output=new int*[m];
      for (int i = 0; i < m; i++)
    {
       output[i]=new int[n]; 
    }
   // fill the last cell
   output[m-1][n-1]= input[m-1][n-1];

   // fill the last row
   for(int i=n-2;i>=0;i--)
      output[m-1][i]= input[m-1][i]+output[m-1][i+1];

         // fill the last column
   for(int i=m-2;i>=0;i--)
      output[i][n-1]= input[i][n-1]+output[i+1][n-1];


// fill remaining cells => bottom up approach
      for(int i=m-2;i>=0;i--)
      {
          for(int j=n-2;j>=0;j--)
          {
              output[i][j]= min( output[i+1][j+1], min(output[i+1][j],output[i][j+1]))+input[i][j];
          }
      }



    return output[0][0];
}
int main()
{
    int m, n;
    cin >> m >> n;
    int **arr= new int*[m];
    for (int i = 0; i < m; i++)
    {
       arr[i]=new int[n]; 
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
         for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    } 
  cout<<endl;
    cout << "Using Brute force  "<<pathToMinCost(arr, m, n,0,0)<<endl;
 
     int **output=new int*[m];
      for (int i = 0; i < m; i++)
    {
       output[i]=new int[n]; 
        for (int j = 0; j < n; j++)
         output[i][j]=-1;
    }
    cout << "Using Memorization "<<pathToMinCost_Mem(arr, m, n,0,0,output)<<endl;

    cout << "Using dp "<<pathToMinCost_dp(arr, m, n)<<endl;
}