#include<bits/stdc++.h>
using namespace std;
priority_queue<int>a;
int mark[1000002];
vector<int> divisors[1000002];
void Divisors(int n)
{
int i, j;
for(i = 1; i <= n; i++){
 for(j = i; j <= n; j += i){
 divisors[j].push_back(i);
    }
   }
 }

 int main()
 {
    int n;
    cin>>n;
    Divisors(n);
    for(int i=1;i<=n;i++){
            cout<<"Case "<<i<<" :"<<endl;
        for(int j=0;j<divisors[i].size();j++){
            cout<<divisors[i][j]<<" ";
        }
    cout<<endl;
    }
return 0;
 }
