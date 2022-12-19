#include <bits/stdc++.h>
using namespace std;

vector<int> bfsGraph(int n,vector<int> adj[])
{
    vector<int> bfs;
    vector<bool> vis(n+1,0); 

    for(int i=0;i<=n;i++)
    {
        if(vis[i]==0)
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node =q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }

            }
        }
    }
    retrun bfs;

}



int main()
{
    int n,e;
    cin>>n>>e;


//adjacency list
    vector<int> adj[n+1]; // 1 based indexing
    vector<pair<int,int>> adj[n+1]; //weighted graph


    int f,s;
    for(int i=0;i<e;i++)
    {
        cin>>f>>s;
        cout<<f<<" "<<s<<endl;
        adj[f].push_back(s);
        adj[s].push_back(f);  // comment out if directed graph
   //    adj[f].push_back({s,wt})  // for wighted graph wt
    }

    ////////////////////////////////////////
    // adjacent matrix approach

    int adj[n][n];
   for(int i=0;i<e;i++)
    {
        cin>>f>>s;
        cout<<f<<" "<<s<<endl;
        adj[f][s]=1;
          adj[s][f]=1;

    }

}