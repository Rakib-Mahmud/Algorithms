#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int gcd(int a,int b) /* to find gcd of 2 numbers */
{
int t;
if(a<b)
{
t=a;
a=b;
b=t;
}

if(b==0)
return a;

else
return gcd(b,a%b);
}

int GCD(int numbers[], int p, int q) /* to find gcd of all numbers in array a[], from index p to index q */
{
int x;
int r=(q+p)/2;

if(p==q)
{
return numbers[p];
}

else
{
int left = GCD(numbers, p, r);
int right = GCD(numbers, r+1, q);
int x= gcd(left,right);
return x;
}
}

int main()
{

}
