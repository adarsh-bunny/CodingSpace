#include <bits/stdc++.h>
using namespace std;


void printDFS(int **edges,int n,int sv,bool *visited)
{
    cout<<sv<<" ";
    visited[sv]=true;
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
    cout << "print dfs" << endl;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
            cout << endl;
        }
    }
}