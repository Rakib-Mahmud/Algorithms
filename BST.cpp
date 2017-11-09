#include<bits/stdc++.h>
using namespace std;

int minimum,maximum;

struct node{
  int data;
  node *left;
  node *right;
}*root=NULL;

node* getnewnode(int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* findmin(node* root)
{
    node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* insert(node* root,int data)
{
    if(root==NULL){
        root=getnewnode(data);
    }
    else if(data <= root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

bool search(node* root,int data)
{
//    if(root==NULL){
//        cout<<"Nothing in the tree"<<endl;
//    }
    if(root==NULL){
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if(data <= root->data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
//    else{
//    return false;
//    }
}

int depth(node* root)
{
    if(root==NULL){
        return -1;
    }

    else{
        int lefth=depth(root->left);
        int righth=depth(root->right);

        return (max(lefth,righth)+1);
    }
}

void min_max()
{
    node *temp=root;
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    if(root->left==NULL){
        minimum=root->data;
        if(root->right==NULL){
            maximum=root->data;
            return;
        }
    }
    if(root->right==NULL){
        maximum=root->data;
        if(root->left==NULL){
            minimum=root->data;
            return;
        }
    }
    while(temp!=NULL){
        minimum=temp->data;
        temp=temp->left;
    }
    temp=root;
    while(temp!=NULL){
        maximum=temp->data;
        temp=temp->right;
    }
}

void bfs()
{
    if(root==NULL){
        cout<<"Empty tree "<<endl;
        return;
    }
    node *current=root;
    queue<node*>q;

    q.push(current);
    while (!q.empty()){
        current=q.front();
        cout<<current->data<<" ";

        if(current->left!=NULL){ q.push(current->left) ;}
        if(current->right!=NULL){ q.push(current->right) ;}
        q.pop();
    }
    cout<<endl;
}

void dfs_pre(node* root)
{
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    dfs_pre(root->left);
    dfs_pre(root->right);
}

void dfs_in(node* root)
{
    if(root==NULL){
        return;
    }

    dfs_in(root->left);
    cout<<root->data<<" ";
    dfs_in(root->right);
}

void dfs_post(node* root)
{
    if(root==NULL){
        return;
    }

    dfs_post(root->left);
    dfs_post(root->right);
    cout<<root->data<<" ";
}

node* Delete(node *root,int data)
{
    if(root==NULL){
        return root;
    }

    if(data < root->data){
        root->left=Delete(root->left,data);
    }
    else if(data > root->data){
        root->right=Delete(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete(root);
            root=NULL;
        }
        else if(root->left==NULL){
            node* temp=root;
            root=root->right;
            delete(temp);
        }
        else if(root->right==NULL){
            node* temp=root;
            root=root->left;
            delete(temp);
        }
        else{
            node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    int n,entry,element;
//    cout<<"Enter the number of elements in the tree :"<<endl;
//    cin>>entry;
//    cout<<"Enter the elements :"<<endl;
//    for(int i=0;i<entry;i++){
//        cin>>element;
//        root=insert(root,element);
//    }
    root=insert(root,15);
    root=insert(root,19);
    root=insert(root,17);
    root=insert(root,11);
    root=insert(root,14);
    root=insert(root,2);
    root=insert(root,100);
    root=insert(root,0);
    root=insert(root,1000);
    root=insert(root,101);
    root=insert(root,10);
    root=insert(root,13);
    root=insert(root,300);
    cout<<"Enter a number to search"<<endl;
    cin>>n;
    if(search(root,n)){
        cout<<"Data Found!"<<endl<<endl;
    }

    else{
        cout<<"Data not Found!!"<<endl<<endl;
    }
    cout<<"Depth of tree is "<<depth(root)<<endl;
    min_max();
    cout<<"Minimum element in the tree is "<<minimum<<endl;
    cout<<"Maximum element in the tree is "<<maximum<<endl;
    cout<<"Breadth-First-Traversal "; bfs();
    cout<<"Depth-First-Traversal (Pre-order)       "; dfs_pre(root); cout<<endl;
    cout<<"Depth-First-Traversal (In-order)/Sorted "; dfs_in(root); cout<<endl;
    cout<<"Depth-First-Traversal (Post-order)      "; dfs_post(root); cout<<endl;
    Delete(root,15);
    cout<<"Depth-First-Traversal (In-order)/Sorted "; dfs_in(root); cout<<endl;
    return 0;
}
