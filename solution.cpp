/*

Rat in a maze + longest subpath principle

*/
#include<iostream>
#define N 4
#define M 4
using namespace std;
int dp[N][M],visited[N][M];

int solve(int x,int y,int maze[N][M])
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return 0;
    if(x==N-1 && y==M-1 && maze[x][y]==1)
        return 1;
    if(dp[x][y]!=-1)
        return dp[x][y];


    int right=-1,down=-1,up=-1,c=0;
    visited[x][y]=1;
    //Go Right
    if(y<M-1 && maze[x][y+1]==1 && visited[x][y+1]!=1){
        right=1+solve(x,y+1,maze);
        c++;
    }
    //Go Down
    if(x<N-1 && maze[x+1][y]==1 && visited[x+1][y]!=1){
        down=1+solve(x+1,y,maze);
        c++;
    }
    //Go Up
    if(x>0 && maze[x-1][y]==1 && visited[x-1][y]!=1){
        up=1+solve(x-1,y,maze);
        c++;
    }
    visited[x][y]=0;
    //Return a big negative if stuck
    if(c==0)
        return -10000;

    return dp[x][y]=max(dp[x][y],max(down,max(right,up)));
}

int main()
{
//    int maze[N][M]={{1,1,1,1,1},
//                  {1,1,0,0,1},
//                  {1,1,1,1,1},
//                  {1,1,0,1,1}};
    int maze[N][M] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dp[i][j]=-1;
        }
    }
    int res=solve(0,0,maze);
    if(res>0)cout<<res<<endl;
}
