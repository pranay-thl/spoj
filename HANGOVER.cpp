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
#define INPD(x) scanf("%lf",&x)
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
double a[300];
void pre()
{
    int i=2;
    double sum=0.0;
    while(true)
    {
        if(abs(sum-5.20)<0.001)
        {
            break;
        }
        else
        {
            sum+=1.0/(double)i;
            a[i-1]=sum;
            i++;
        }
    }
}
int main()
{
    pre();
    double n;
    while(true)
    {
       INPD(n);
       if(abs(n-0.0)<0.0001)
       {
           break;
       }
       else
       {
           REP(i,279)
           {
               if(abs(a[i]>n))
               {
                   printf("%d card(s)\n",i);
                   break;
               }
           }
       }
 
    }
    return 0;
}