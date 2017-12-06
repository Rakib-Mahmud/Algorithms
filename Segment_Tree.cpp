#include<bits/stdc++.h>
#define mx 10001
using namespace std;

int input[mx],tree[3*mx],ma=-INFINITY,mi=INFINITY;

void make_tree(int node,int i,int j)
{
    if(i==j){
        tree[node]=input[i];
        if(tree[node]>ma){ ma=tree[node]; }
        if(tree[node]<mi){ mi=tree[node]; }
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(i+j)/2;

    make_tree(left,i,mid);
    make_tree(right,mid+1,j);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j){
        return tree[node];
    }

    else if(b>j || e<i){
        return 0;
    }

    else {
        int left=2*node;
        int right=2*node+1;
        int mid=(b+e)/2;

        return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
    }

}

void update(int node,int b,int e,int i,int nwvalue)
{
    if(b>i || e<i){
        return;
    }

    else if(b>=i && e<=i){
        tree[node]=nwvalue;
        if(tree[node]>ma){ ma=tree[node]; }
        if(tree[node]<mi){ mi=tree[node]; }
    }

    else {
        int left=2*node;
        int right=2*node+1;
        int mid=(b+e)/2;

        update(left,b,mid,i,nwvalue);
        update(right,mid+1,e,i,nwvalue);
        tree[node]=tree[left]+tree[right];
    }

}

int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&input[i]);
    }

    make_tree(1,1,n);
    q=query(1,1,n,2,2);
    cout<<tree[1]<<" Max = "<<ma<<" Min = "<<mi<<endl;
    cout<<q<<endl;
    update(1,1,n,2,9);
    q=query(1,1,n,2,2);
    cout<<"After  Update : \n";
    cout<<tree[1]<<endl;
    cout<<q<<" Max = "<<ma<<" Min = "<<mi<<endl;
    return 0;
}
