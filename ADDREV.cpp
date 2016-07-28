#include<bits/stdc++.h>
#define LL long long int
#define REP(i,n) for(int i=0;i<n;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define TC int t;scanf("%d",&t);while (t-->0)
#define INP(x) scanf("%d",&x)
#define OUT(x) printf("%d\n",x)
#define INPLL(x) scanf("%lld",&x)
#define OUTLL(x) printf("%lld\n",x)
#define INPS(x) scanf("%s",x)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define VPII vector<pair<int,int >
#define F first
#define S second
#define MOD 1000000007
#define mod 10000007
using namespace std;
int rev(int n)
{
    int rev=0;
    while(n!=0)
    {
        rev=rev*10+n%10;
        n=n/10;
    }
    return rev;
}
int main()
{
    int a,b,sum;
    TC
    {
        INP(a);INP(b);
        sum=rev(a)+rev(b);
        OUT(rev(sum));
 
    }
    return 0;
}
