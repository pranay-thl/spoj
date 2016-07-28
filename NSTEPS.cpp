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
int main()
{
    int a,b;
    TC
    {
        INP(a);INP(b);
        if(a==b)
        {
            if(a%2==0)
            {
		OUT((a/2)*3+a/2);
            }
            else
            {
		OUT(((a/2)+1)+(a/2)*3);
            }
        }
        else if(b==a-2)
        {
            if(a%2==0)
            {
                OUT(a+b);
            }
            else
            {
                OUT(a+b-1);
            }
        }
        else
            printf("No Number\n");
 
    }
    return 0;
}
