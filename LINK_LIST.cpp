#include<stdio.h>

struct node
{
    int roll;
    node *next;
    node *prev;
};

node *root=NULL;
node *tail=NULL;

void modify(int roll){
    if(root==NULL){
        root=new node();
        root->roll=roll;
        root->next=NULL;
        root->prev=NULL;
        tail=root;
    }
    else{
        /*node *last_node=root;
        while(last_node->next!=NULL){
            last_node=last_node->next;
        }*/
        node *newnode=new node();
        newnode->roll=roll;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;

        ///last_node->next=newnode;
    }
}

void del(int roll)
{
    node *current_node=root;
    node *previous_node=NULL;
    node *next_node=root->next;

    while(current_node->roll!=roll){
        previous_node=current_node;
        current_node=current_node->next;
        next_node=current_node->next;
    }

    if(current_node==root){
        node *temp=root;
        root=root->next;
        root->prev=NULL;
        delete(temp);
    }

    else{
        previous_node->next=current_node->next;
        next_node->prev=current_node->prev;
        delete(current_node);
    }
}

void insert (int roll1,int roll2)
{
    node *current_node=root;
    node *previous_node=NULL;

    while(current_node->roll!=roll1){
        previous_node=current_node;
        current_node=current_node->next;
    }
    node *newnode=new node();

    if(current_node==root){
        newnode->next=current_node;
        newnode->roll=roll2;
        newnode->prev=NULL;
        root->prev=newnode;
        root=newnode;
    }

    else {
        newnode->next=current_node;
        newnode->roll=roll2;
        newnode->prev=previous_node;
        previous_node->next=newnode;
    }
}
void print()
{
    node *current_node=root;

    while(current_node!=NULL){
        printf("%d ",current_node->roll);
        current_node=current_node->next;

    }
    printf("\n");
}

void print_reverse()
{
    node *current_node=tail;

    while(current_node!=NULL){
        printf("%d ",current_node->roll);
        current_node=current_node->prev;
    }
    printf("\n");
}

int main()
{
    modify(1);
    modify(2);
    modify(3);
    modify(5);
    modify(10);
    modify(11);
    modify(15);
    print();
    del(10);
    print();
    del(1);
    print();
    insert(2,55);
    print();
    insert(11,20);
    print();
    del(55);
    del(20);print();
    print_reverse();
}
