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
    int n,l;
    char s[202];
    char a[202][202],b[202][202];
    while(true)
    {
        INP(n);
        if(n==0)
            break;
        INPS(s);
        l=strlen(s);
        int i=0,k=0;
        for(int j=0;j<l;j++)
        {
            if((j)%n==0&&j!=0)
            {
                i++;
                k=0;
            }
            a[i][k++]=s[j];
        }
        k=0;
        REP(i,l/n)
        {
        	if(!(i&1))
        	{
            	REP(j,n)
            	{
                	b[i][k++]=a[i][j];
            	}
        	}
            else
            {
            	for(int j=n-1;j>=0;j--)
            	{
            		b[i][k++]=a[i][j];
            	}
            }
            k=0;
        }
        REP(i,n)
        {
        	REP(j,l/n)
        	{
        		printf("%c",b[j][i]);
        	}
        }
        printf("\n");
    }
    return 0;
}