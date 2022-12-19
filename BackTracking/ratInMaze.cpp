#include<bits/stdc++.h>
using namespace std;
#define MAX_INP 500
int maze[MAX_INP][MAX_INP];

void  mazeSolution(int n,int **output,int x,int y)
{
    if(x==n-1 && y==n-1 && maze[x][y]==1)
    {
        output[x][y]=1;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {  
          cout<<output[i][j]<<" ";
        }
          cout<<endl;
      }
         cout<<"======================"<<endl;
         return;
    }
    if(x>=n ||y >=n || x<0 || y<0|| output[x][y]==1 || maze[x][y]==0 )
    return;

    output[x][y]=1;
    mazeSolution(n,output, x-1,y);
    mazeSolution(n,output, x+1,y);
    mazeSolution(n,output, x,y-1);
    mazeSolution(n,output, x,y+1);
     output[x][y]=0;
    

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    int** output=new int*[n];
   for(int i=0;i<n;i++)
   {
      output[i]= new int[n];
    for(int j=0;j<n;j++) 
      output[i][j]=0;
   }

    cout<<"=========start============="<<endl;
    mazeSolution(n,output,0,0);

   
}