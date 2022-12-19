#include <bits/stdc++.h>
using namespace std;
void isConnectedDFS(int **edges, int n, int sv, bool *visited)
{
    //cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
            continue;
    
        if (edges[0][i] == 1 && !visited[i])
        {
            isConnectedDFS(edges, n, i, visited);
        }
    }
}







int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int j = 0; j < e; j++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

   // cout << "print dfs" << endl;
    //DFS(edges, n);
   // cout << endl;
 
    
   bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout<<"Is connected ?"<<endl;
    cout<<std::boolalpha;
    isConnectedDFS(edges,n,0,visited);
    
     for (int i = 0; i < n; i++)
     {
         if(visited[i]==false)
         {
             cout<<"Not connected";
             break;           
         }
         if(i==n-1)
           cout<<"connected Graph";


     }
        

   
    delete[] edges;
}