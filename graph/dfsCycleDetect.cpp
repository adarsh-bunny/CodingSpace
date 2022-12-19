#include<bits/stdc++>
using namespace std;
// directed
int graph[100][100]
int n;

bool dfsCycle(int node,bool *dfsVis,bool *vis)
{
    vis[node]=1;
    dfsVis[node];
    for(int i=0;i<n;i++)
    {
        if(a[node][i] == 1 &&!vis[i])
        {
            if(dfsCycle(i,dfsVis,vis)) return true;   
        }
        else if(a[node][i] == 1 && dfsVis[i])
            return true;
    }
    dfsVis[node]=0;
    return false;
}
bool checkCycle(bool *vis)
{
    bool dfsVis[n]={false};

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
              if(dfsCycle(i,dfsVis,vis))
              return true;
        }
        
    }

    return false;
}

int main()
{
    cin>>n;

    bool vis[n]={false};
int x,int y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        graph[i][j]=1;
    }

    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        graph[x][y]=1;
    }

    cout<<checkCycle(vis)<<endl;
}