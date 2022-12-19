#include <bits/stdc++.h>
using namespace std;
void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
            continue;
        if (visited[i])
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            printDFS(edges, n, i, visited);
        }
    }
}


void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }

    delete[] visited;
}




bool getPathDFS(int **edges, int n, int sv,int ev, bool *visited,vector<int> &ans )
{
    
    visited[sv]=true;
    if(sv==ev)
    {
    ans.push_back(sv);
      return true;
    }
    
    bool res=false;
    for(int i=0;i<n;i++)
    {   
        
        if (sv == i)
            continue;
        if (visited[i])
            continue;
        
        if(edges[sv][i]==1)
        res= getPathDFS(edges,n,i,ev,visited,ans);
        cout<<res<<" "<<i<<"sv "<<sv<<endl;
        if( res== true)
        {
            ans.push_back(sv);
            return res;

        }
            
    }
 return res;
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
    int a ,b;
    cout<<"Enter the edges to find path"<<endl;
    cin>>a>>b;

    cout << "print dfs" << endl;
    DFS(edges, n);
    cout << endl;
 
    
   bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    vector<int> ans;
    cout<<"Get path "<<endl;
    cout<<std::boolalpha;
    if(getPathDFS(edges,n,a,b,visited,ans))
    {
        for(auto i:ans)
        cout<<i<<" ";
    }
    else 
    cout<<"No path exist"<<endl;
    delete[] edges;
}