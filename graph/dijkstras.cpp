#include <bits/stdc++.h>
using namespace std;

int findMinvertex(int *dist, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex]))
            minVertex = i;
    }

    return minVertex;
}

void dijkstra(int **edges, int n)
{
    bool *visited = new bool[n];
    int *dist = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u = findMinvertex(dist, visited, n);
        visited[u] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[u][j] != 0 && !visited[j])
            {
                int curr_dist = dist[u] + edges[u][j];
                if (dist[j] > curr_dist)
                    dist[j] = curr_dist;
            }
        }
    }

       for(int i=0;i<n;i++)
   {      
       cout<<i<<" "<<dist[i]<<endl;
   }

   delete [] visited;
   delete [] dist;
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

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    cout << endl;

    dijkstra(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
} 