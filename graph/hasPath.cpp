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
void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;

    visited[sv] = true;
    pendingVertices.push(sv);
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (currentVertex == i)
                continue;

            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
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

void BFS(int **edges, int n)
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


bool hasPathDFS(int **edges, int n, int sv,int ev, bool *visited )
{
    visited[sv]=true;
    if(sv==ev)
    return true;
    bool res=false;
    for(int i=0;i<n;i++)
    {
        if (sv == i)
            continue;
        if (visited[i])
            continue;
        
        if(edges[sv][i]==1)
        res= hasPathDFS(edges,n,i,ev,visited);

        if( res== true)
            return true;
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
    // cout << "print bfs " << endl;
    // BFS(edges, n);
    
   bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    cout<<"Haspath "<<endl;
    cout<<std::boolalpha;
    cout<<hasPathDFS(edges,n,a,b,visited)<<endl;
    delete[] edges;
}