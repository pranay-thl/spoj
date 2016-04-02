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
bool a[31623];
bool diff[100005];
void Sieve(int n)
{
    memset(a,true,sizeof(a));
    a[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(a[i])
        {
            for(int j=2*i;j<=n;j+=i)
                a[j]=false;
        }
    }
}
int main()
{
    Sieve(31622);
    int l,r;
    TC
    {
        INP(l);INP(r);
        if(l==1)
            l++;
        memset(diff,true,sizeof(diff));
        for(int i=2;i*i<=r;i++)
        {
            if(a[i])
            {
                int k=l/i;
                k=k*i;
                if(k==0)
                    k=i;
                //cout<<"k: "<<k<<endl;
                for(int j=k;j<=r;j+=i)
                {
                    if(j<l)
                        continue;
                    if(j!=i)
                        diff[j-l]=false;
                }
            }
        }
        REPP(i,l,r+1)
        {
            if(diff[i-l])
            {
                OUT(i);
            }
        }
    }
    return 0;
}
