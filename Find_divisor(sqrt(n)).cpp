#include<bits/stdc++.h>
using namespace std;


//int mark[1000099];
vector<int> divisors[1000099];
void Divisors(int n)
{
 int i, j;
 for(i = 1; i <= n; i++){
 for(j = 1; j <= sqrt(i); j++){
        if(i%j==0){
            divisors[i].push_back(j);
        }
        else{continue;}
        if(j!=sqrt(i)){
            int p=i/j;
            divisors[i].push_back(p);
        }
      }
    }
 }

 int main()
 {
    int n=1000000;
    Divisors(n);
    for(int i=0;i<divisors[10000].size();i++)
    cout<<divisors[10000][i]<<" ";


 }

