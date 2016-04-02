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
int main()
{
    int n,a[10000];
    LL sum;
    while(true)
    {
        sum=0;
        INP(n);
        if(n==-1)
            break;
        REP(i,n)
        {
            INP(a[i]);
            sum+=a[i];
        }
        if(sum%n!=0)
        {
            OUT(-1);
        }
        else
        {
            LL ans=0;
            int k=sum/n;
            REP(i,n)
            {
                if(a[i]<k)
                {
                    ans+=k-a[i];
                }
            }
            OUTLL(ans);
        }
    }
    return 0;
}