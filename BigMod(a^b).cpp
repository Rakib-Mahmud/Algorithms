#include<bits/stdc++.h>
using namespace std;

long long int M;
long long int big_mod(long long int N,long long int P)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		long long int ret=big_mod(N,P/2);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(big_mod(N,P-1)%M))%M;
}

int main()
{
    long long int n,p,mod;
    scanf("%lld%lld%lld",&n,&p,&M);
    mod=big_mod(n,p);
    cout<<"Modulo "<<mod<<endl;
    return 0;
}
