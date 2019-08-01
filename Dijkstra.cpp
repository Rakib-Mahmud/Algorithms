#include<bits/stdc++.h>
#define mx 1000
#define inf 1e4
using namespace std;

struct node
{
    int u,cost;
    node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
    bool operator < (const node &p)const
    {
        return cost>p.cost;
    }
};

void dijk(int n,int s,vector<int>g[],vector<int>cost[])
{
    int dist[n+1];
    memset(dist,inf,sizeof(dist));
    //for(int i=1;i<=n;i++)dist[i]=inf;
    priority_queue<node>Q;
    Q.push(node(s,0));
    dist[s]=0;

    while(!Q.empty())
    {
        node u=Q.top();
        Q.pop();
        if(u.cost!=dist[u.u])continue;
        for(int i=0; i<g[u.u].size(); i++)
        {
            int v=g[u.u][i];
            if(dist[u.u]+cost[u.u][i]<dist[v])
            {
                dist[v]=dist[u.u]+cost[u.u][i];
                Q.push(node(v,dist[v]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<s<<" --> "<<i<<" = "<<dist[i]<<endl;
    }
}

int main()
{
    int no_node,no_edge,a,b,w,s;
    vector<int>graph[mx],cost[mx];
    cin>>no_node>>no_edge;
    for(int i=0;i<no_edge;i++){
        cin>>a>>b>>w;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }
    cin>>s;
    dijk(no_node,s,graph,cost);
//    for(int i=1;i<=no_node;i++){
//        cout<<s<<" --> "<<i<<" = "<<dist[i]<<endl;
//    }
    return 0;
}

/*
5 5
1 2 2
1 3 3
2 4 5
3 4 1
4 5 2
1
*/
