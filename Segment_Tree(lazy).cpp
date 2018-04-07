#include<bits/stdc++.h>
#define mx 100005
using namespace std;

struct lazy{
    int sum,prop;
}tree[mx*3];

int input[mx];

void make_tree(int node,int i,int j)
{
    if(i==j){
        tree[node].sum=input[i];
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(i+j)/2;
    make_tree(left,i,mid);
    make_tree(right,mid+1,j);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=0;
    return;
}

void update(int node,int b,int e,int i,int j,int x)
{
    if(b>j || e<i){
        return;
    }

    if(b>=i && e<=j){
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
    return;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(b>j || e<i){
        return 0;
    }

    if(b>=i && e<=j){
        return (tree[node].sum+((e-b+1)*carry));
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int ob1=query(left,b,mid,i,j,carry+tree[node].prop);
    int ob2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return ob1+ob2;
}

int main()
{
    int n,q,u,a,b,c;
    scanf("%d%d%d",&n,&q,&u);
    for(int i=1;i<=n;i++){
        scanf("%d",&input[i]);
    }
    make_tree(1,1,n);
    for(int i=0;i<q;i++){
    scanf("%d%d",&a,&b);
    printf("%d\n",query(1,1,n,a,b));
    }
    for(int i=0;i<u;i++){
    scanf("%d%d%d",&a,&b,&c);
    update(1,1,n,a,b,c);
    for(int i=0;i<2;i++){
    scanf("%d%d",&a,&b);
    printf("%d\n",query(1,1,n,a,b));
    }
}
    return 0;
}
