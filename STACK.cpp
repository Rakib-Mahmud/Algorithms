#include<iostream>
#include<stdio.h>
#define mx 3
using namespace std;

class Stack{
public:
    int top=-1;
    int ara[mx]={0};

    void push(){
        if(top==mx){cout<<"Maximum limit exceeds"<<endl;}
        else{
        int nw=0;
        top++;
        scanf("%d",&nw);
        ara[top]=nw;
        }
    }

    int pop(){
        if(top==-1){cout<<"Nothing to pop"<<endl;}
        else{
        int last=ara[top];
        top--;
        return last;
            }
        }

    int peek(){
        return ara[top];
    }

    bool mpty(){
        return top==-1;
    }

    void print(){
        cout<<"Elements are :"<<endl;
        for(int i=0;i<=top;i++){
            cout<<ara[i]<<" "<<endl;
        }
    }
};

int main()
{
    Stack frst;
    if(frst.mpty()){
        printf("EMPTY...\n");
    }
    frst.push();
    frst.push();
    frst.push();
    cout<<"PEEK-> "<<frst.peek()<<endl;
    frst.push();
    frst.push();
    if(frst.mpty()){
        printf("EMPTY...\n");
    }
    frst.print();
    frst.pop();
    frst.pop();
    frst.pop();
    cout<<"PEEK-> "<<frst.peek()<<endl;
    frst.pop();
    frst.pop();
    if(frst.mpty()){
        printf("EMPTY...\n");
    }
    frst.pop();
    return 0;
}
