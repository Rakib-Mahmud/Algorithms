#include<bits/stdc++.h>
using namespace std;


//int mark[1000002];
vector<int> divisors[1000002];
void Divisors(int n)
{
 int i, j;
 for(i = 1; i <= n; i++)
 for(j = i; j <= n; j += i)
 divisors[j].push_back(i);
 }

 int main()
 {
    int n=1000000;
    Divisors(n);
    for(int i=0;i<divisors[10000].size();i++)
    cout<<divisors[10000][i]<<" ";


 }
