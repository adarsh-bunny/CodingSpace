#include <bits/stdc++.h>
using namespace std;
void print(int **edges,int n,int sv,bool *visited )
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(sv==i)
        continue;
        if(visited[i])
        {
            continue;
        }
        if(edges[sv][i]==1)
        {
            print(edges,n,i,visited);

        }
    }
}
void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    visited[sv] = true;
    pendingVertices.push(sv);
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
          pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
             if(currentVertex==i)
        continue;

            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;

            }
        }
    }
    delete []visited;
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
        cout<<"print dfs"<<endl;
    bool *visited= new bool[n];
 for(int i=0;i<n;i++)
{
    visited[i]=false;
}
    print(edges,n,0,visited);

    cout<<endl;
    cout<<"print bfs "<<endl;
    printBFS(edges, n, 0);

    delete []visited;
    delete [] edges;
}