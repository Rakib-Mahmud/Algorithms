#include<bits/stdc++.h>
#define mx 100

using namespace std;

struct node{
    int data;
    int Rank;
}parent[mx];

void makeset(int value)
{
    parent[value].data=value;
    parent[value].Rank=0;
}

int findset(int value)
{
    if(parent[value].data==value){
        return value;
    }
    return parent[value].data=findset(parent[value].data);
}

void Union(int x,int y)
{
    int parent1=findset(x);
    int parent2=findset(y);

    if(parent1==parent2){
        return;
    }

    if(parent[parent1].Rank>=parent[parent2].Rank){
        parent[parent1].Rank = (parent[parent1].Rank == parent[parent2].Rank) ? ++parent[parent1].Rank : parent[parent1].Rank;
        parent[parent2].data=parent1;
    }

    else{
        parent[parent1].data=parent2;
    }
}

bool isUnion(int x,int y)
{
    return findset(x)==findset(y);
}

int main()
{
    makeset(1);
    makeset(2);
    makeset(3);
    makeset(4);
    makeset(5);
    makeset(6);

    Union(1,2);
    Union(3,4);
    Union(2,4);
    Union(5,6);
    Union(6,4);

    cout<<findset(5)<<endl;
    cout<<findset(3)<<endl;
    cout<<findset(6)<<endl;
    cout<<findset(1)<<endl;

    if(isUnion(1,5)){ cout<<"Same Set"; }
}
