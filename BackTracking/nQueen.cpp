#include<bits/stdc++.h>
using namespace std;
int board[11][11];


bool isPossible(int n,int row,int col)
{
    // same column check
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
        return false;
    }

    // left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        return false;
    }
  // right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]==1)
        return false;
    }
   return true;
}
void nQueen(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";

            }
            cout<<endl;
        }
        cout<<"================="<<endl;
        return ;

    }


    for(int j=0;j<n;j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j]=1;
            nQueen(n,row+1);
            board[row][j]=0;
        }
    }
    return;
}


int main()
{
    int n;
    cin>>n;
   memset(board,0,n*n* sizeof(int));
    nQueen(n,0);
}