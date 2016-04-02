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
#define debug(x) cout<<"### x is: "<<x<<"###"<<endl
#define F first
#define S second
#define MOD 1000000007
#define mod 10000007
using namespace std;
LL dp[1000000];
LL f(LL n)
{
    if(n==0)
        return 0;
    if(n<1000000)
    {
        if(!dp[n])
        {
            dp[n]=max(f(n/2)+f(n/3)+f(n/4),n);
        }
        return dp[n];
    }
    return max(f(n/2)+f(n/3)+f(n/4),n);
}
int main()
{
    LL n;
    while(INPLL(n)!=EOF)
    {
        OUTLL(f(n));
    }
    return 0;
}