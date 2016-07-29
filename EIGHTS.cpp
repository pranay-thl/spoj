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
LL power10(LL n)
{
    LL ans=1;
    while(n--)
        ans*=10;
    return ans;
}
LL a[4]={192,442,692,942};
int main()
{
    LL n,r,temp;
    TC
    {
        INPLL(n);
        r=n%4;
        r=1000*((n-1)/4)+a[r==0?3:r-1];
        OUTLL(r);
        
    }
    return 0;
}
