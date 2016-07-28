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
bool is_num(char a,char b)
{
	return ((a-'0')*10+b-'0')<=26&&((a-'0')*10+b-'0')>9?true:false;
}
LL solve(char *s)
{
	int l=strlen(s);
	LL dp[l+1];
	MEM(dp,0);
	dp[0]=1;
	REPP(i,1,l)
	{
		dp[i]=(s[i]-'0')==0?0:dp[i-1];
		if(is_num(s[i-1],s[i]))
		{
			dp[i]+=dp[i-2<0?0:i-2];
		}
	}
	return dp[l-1];
}
int main()
{
	char s[5001];
	while(1)
	{
		INPS(s);
		if(s[0]=='0')
			break;
		else
		{
			OUTLL(solve(s));
		}
	}
	return 0;
}