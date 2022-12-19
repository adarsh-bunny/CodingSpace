#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rankArr[10000];

void init(int m)
{
    for(int i=0;i<m;i++)
    {
        parent[i]=i;
        rankArr[i]=0;

    }
}

int findPar(int node)
{
    if(node== parent[node])
    {
        return node;
    }

    return parent[node]=findPar(parent[node]); //pathCompression
}

void Union(int x,int y)
{
    int u=findPar(x);
    int v=findPar(y);
    if(u==v)
    return;  //same parent

    if(rankArr[u]<rankArr[v])
    {
        parent[u]=v; //make parent whose rank is high 
    }
    else if(rankArr[u]>rankArr[v])  //low rank attach
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rankArr[u]++;

    }
}

int main()
{
    int m,x,y;
    cin>>m;
    init(m);
    while(m--)
    {
        
        cin>>x>>y;
        Union(x,y);
       
       
    }

    //finding nodes is of same component or not
    cout<<"Finding components"<<endl;
     cin>>x>>y;
     if(findPar(x)==findPar(y))   //dont use parent array as it will provide immediate parent 
     {
        cout<<"Same Component"<<endl;
     }
     else 
         cout<<"Different Component"<<endl;
}