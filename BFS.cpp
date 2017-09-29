#include<bits/stdc++.h>
#define mx 1000
using namespace std;

int main()
{
    int no_edge,no_node,a,b,visited[mx]={0},level[mx]={0},parent[mx],src,dest;
    vector<int>edge[mx];
    queue<int>q;
    cout<<"Enter the no of Nodes(1st) and Edges :"<<endl;
    cin>>no_node>>no_edge;

    for(int i=0;i<no_edge;i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    cout<<"Enter the source and destination :"<<endl;
    cin>>src>>dest;
    int u,v;
    visited[src]=1;
    level[src]=0;
    q.push(src);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            v=edge[u][i];
            if(visited[v]==1){
                continue;
            }
            else{
                visited[v]=1;
                level[v]=level[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
    cout<<"Shortest path to reach from Source to Destination is : "<<level[dest]<<endl;
    cout<<"And the path is : ";
    stack<int>stk;

    stk.push(dest);
    a=dest;
    while(1){
        int k=parent[a];
        stk.push(k);
        a=k;
        if(k==src){
            break;
        }
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}
/*
10 13
1 2
1 3
1 4
2 6
3 7
3 8
4 7
6 10
8 7
7 9
8 5
9 10
5 10
*/
