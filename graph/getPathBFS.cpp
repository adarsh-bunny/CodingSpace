#include <bits/stdc++.h>
using namespace std;

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
    
}



void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }

    delete[] visited;
}


void getPathBFS(int **edges, int n, int sv,int ev, bool *visited, unordered_map <int,int> &map )
{
    if(sv==ev)
    {
            cout<<sv<<" "<<endl;
            return;

    }

    queue<int> pendingVertices;
    visited[sv]=true;
    pendingVertices.push(sv);

    while(!pendingVertices.empty())
    {
       int currentVertex = pendingVertices.front();
        pendingVertices.pop();
         for (int i = 0; i < n; i++)
        {
         if (edges[currentVertex][i] == 1 && !visited[i])
            {
               if(i == ev)
                {
                    cout << ev << " ";
                    map[ev] = currentVertex;
                    
                    int j = ev;
                    while(j != sv)
                    {
                        cout << map[j] << " ";
                        j = map[j];
                    }
                    return;
            }
             else
                {
                    pendingVertices.push(i);
                    visited[i] = true;
                    map[i] = currentVertex;
                }
        }
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
    int a ,b;
    cout<<"Enter the edges to find path"<<endl;
    cin>>a>>b;

    
    
     //cout << "print bfs " << endl;
    // BFS(edges, n);
    
   bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    cout<<"Getpath "<<endl;
      unordered_map <int,int> map;
    getPathBFS(edges,n,a,b,visited,map);
    delete[] edges;
    delete [] visited;
}