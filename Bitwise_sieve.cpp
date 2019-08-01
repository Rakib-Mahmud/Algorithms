#include<bits/stdc++.h>
#define mx 1e8
using namespace std;

long long k=mx;
int isprime[(int)mx/32];
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

void sieve(int n)
{
    int p=int(sqrt(n));
    for(int i=3;i<=p;i+=2){
        if(check(isprime[i>>5],i&31)==0){
            for(int j=i*i;j<=n;j+=(i<<1)){
                isprime[j>>5]=Set(isprime[j>>5],j & 31);
            }
        }
    }
}


int main()
{
    int k;
    cin>>k;
    sieve(k);
    cout<<2<<" ";
    for(int i=3;i<=k;i+=2){
        if((check(isprime[i>>5],i&31))==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
