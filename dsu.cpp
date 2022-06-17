#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> parent(N+1);
vector<int> Rank(N+1);

void makeSet()
{
    for(int i=1;i<=N;i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findpar(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    return parent[node] = findpar(parent[node]);     // path compression
}

void Union(int u,int v)
{
    u = findpar(u);
    v = findpar(v);
    if(Rank[u] > Rank[v])
    {
        parent[v] = u;
    }
    else if(Rank[v] > Rank[u])
    {
        parent[u] = v;
    }
    else{
        parent[v] = u;
        Rank[u]++;  
    }
}


int main()
{
    makeSet();
    int queries;
    cin>>queries;
    while(queries--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    
    // check whether two nodes belong to the same connected component or not
    int u,v;
    cin>>u>>v;
    if(findpar(u) == findpar(v))
    {
        cout<<"Both nodes belong to the same connected component\n";
    }
    else{
        cout<<"Both nodes belongs to different connected components.\n";
    }
}