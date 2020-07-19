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
using namespace std;
LL fact[1000005],fact1[1000005],s[10000001],prim[1000000],p_in=0;;
bool prime[10000000];
void Sieve(LL n)
{
    memset(s,1,sizeof(s));
    memset(prime,0,sizeof(prime));
	for(LL i=2;i<=n;i+=2)
        s[i]=2;
	for (LL i=3;i<=n;i+=2)
	{
		if (!prime[i])
		{
			s[i]=i;
			for(LL j=i;(j*i)<=n;j+=2)
			{
				if (!prime[j*i])
				{
				    prime[j*i]=true;
				    s[j*i]=i;
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
    {
        if(s[i]==i)
            prim[p_in++]=i;
    }
}
LL calc(LL idx,LL cur,LL k)
{
		LL square=prim[idx]*prim[idx];
		LL newCur=square*cur;
		LL res=0;
 
		if(newCur>k)
            return 0;
		res+=k/(newCur);
		res+=calc(idx+1,cur,k);
		res-=calc(idx+1,newCur,k);
		return res;
}
LL getNumber(LL n)
{
		LL lo=1; LL hi=2000000000l;
		while(lo<hi)
		{
			LL mid=lo+(hi-lo)/2;
			LL cnt=mid-calc(0,1,mid);
			if(cnt<n)
			{
				lo=mid+1;
			}
			else
			{
				hi=mid;
			}
		}
		return lo;
}
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL mpow(LL a, LL b,LL m)
{
    LL x=1,y=a;
    while(b>0)
    {
        if(b%2==1)
        {
            x=(x*y);
            if(x>m)
                x%=m;
        }
        y=(y*y);
        if(y>m)
            y%=m;
        b=b/2;
    }
    return x%m;
}
void f(LL n,LL m)
{
    LL res=1;
    fact[0]=1;
    REPP(i,1,n+1)
    {
        res*=i;
        res%=m;
        fact[i]=res;
    }
}
LL fact_without_p(LL n,LL p,LL mod)
{
    LL res=1;
    fact1[0]=1;
    REPP(i,1,mod+1)
    {
        if(gcd(i,p)==1)
        {
            fact1[i]=(fact1[i-1]*i)%mod;
        }
        else
            fact1[i]=fact1[i-1];
    }
    LL times,in=1,rem;
    while(in<=n)
    {
        times=(n/in)/mod;
        rem=(n/in)%mod;
        //cout<<times<<" "<<rem<<endl;
        res=(res*mpow(fact1[mod],times,mod))%mod;
        res=(res*fact1[rem])%mod;
        in*=p;
    }
    return res;
}
LL power(LL a,LL b)
{
    if(b==0)
        return 1;
    LL ans=power(a,b/2);
    if(b%2==0)
    {
        return ans*ans;
    }
    return ans*ans*a;
}
LL inv(LL a,LL m)
{
    LL m0=m,t,q;
    LL x0=0,x1=1;
    if (m==1)
       return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m,a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if(x1<0)
       x1+=m0;
    return x1;
}
LL CRT(LL num[][2], LL *rem, LL k)
{
    LL prod = 1;
    REP(i,k)
        prod *= power(num[i][0],num[i][1]);
    LL result=0;
    REP(i,k)
    {
        LL pp=prod/power(num[i][0],num[i][1]);
        result+=rem[i]*inv(pp,power(num[i][0],num[i][1])) * pp;
    }
    return result%prod;
}
LL nCr(LL n,LL r,LL m)
{
    LL ans=1;
    LL n1,r1,num,den;
    while(n)
    {
        n1=n%m;
        r1=r%m;
        if(n1<r1)
        {
            return 0;
        }
        //cout<<n1<<" "<<fact[n1]<<" "<<r1<<" "<<fact[r1]<<endl;
        num=fact[n1];
        den=(fact[n1-r1]*fact[r1])%m;
        ans=(ans*(num*mpow(den,m-2,m)%m)%m);
        n=n/m;
        r=r/m;
    }
    return (ans)%m;
}
LL power_in_fact(LL n,LL p)
{
    LL res=0;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res;
}
LL nCr2(LL n,LL r,LL p,LL k)
{
    LL e=power_in_fact(n,p)-power_in_fact(r,p)-power_in_fact(n-r,p);
    //cout<<e<<endl;
    if(k<=e)
        return 0;
    LL mod=power(p,k);
    //cout<<fact_without_p(n,p,mod)%mod<<endl;
    LL n1=fact_without_p(n,p,mod)%mod;
    LL r1=fact_without_p(r,p,mod)%mod;
    LL n1_r1=fact_without_p(n-r,p,mod)%mod;
   // LL ans=(((n1*mpow(r1,mod-2,mod))%mod)*mpow(n1_r1,mod-2,mod))%mod;
    LL ans=n1;
    REP(i,mod)
    {
        if(r1*i%mod==1)
        {
            ans=(ans*i)%mod;
        }
        if(n1_r1*i%mod==1)
        {
            ans=(ans*i)%mod;
        }
    }
    return (ans*power(p,e))%mod;
}
LL calculate(LL m,LL num[][2])
{
    LL curr=s[m],cnt=1,in=0;
    while(m>1)
    {
        m/=s[m];
        if(curr==s[m])
        {
            cnt++;
        }
        else
        {
            num[in][0]=curr;
            num[in++][1]=cnt;
            curr=s[m];
            cnt=1;
        }
    }
    return in;
}
LL calculateBrute(LL m,LL num[][2])
{
    LL in=0,cnt=0;
    if(m%2==0)
    {
        num[in][0]=2;
        while(m%2==0)
        {
            m/=2;
            cnt+=1;
        }
        num[in++][1]=cnt;
    }
    for(LL i=3;i*i<=m;i+=2)
    {
        cnt=0;
        if(m%i==0)
        {
            num[in][0]=i;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            num[in++][1]=cnt;
        }
    }
    if(m>2)
    {
        num[in][0]=m;
        num[in][1]=1;
        in++;
    }
    return in;
}
LL l_fact(LL n)
{
    LL m=1;
    while(n>1)
    {
        m=max(m,s[n]);
        n/=s[n];
    }
    return m;
}
int main()
{
   //freopen("in4_pytest.txt","r",stdin);
   //freopen("out4_pytest.txt","w",stdout);
    Sieve(10000000);
   //cout<<fact_without_p(66,3,27)<<endl;
    LL n,r,m,siz;
    LL num[500][2],rem[500];
    int t,st;
    INP(t);INP(st);
    if(st==1)
    {
        f(10,1000000007);
        while(t--)
        {
            INPLL(n);INPLL(r);INPLL(m);
            OUTLL(nCr(n,r,m)%m);
        }
    }
    else if(st==2)
    {
        f(1000005,1000003);
        while(t--)
        {
            INPLL(n);INPLL(r);INPLL(m);
            OUTLL(nCr(n,r,m)%m);
        }
    }
    else if(st==3)
    {
        while(t--)
        {
            INPLL(n);INPLL(r);INPLL(m);
            m=getNumber(m);
            f(50,m);
            siz=calculate(m,num);
            REP(i,siz)
            {
                if(num[i][1]==1)
                    rem[i]=nCr(n,r,num[i][0]);
                else
                {
                //cout<<num[i][0]<<" "<<num[i][1]<<endl;
                    rem[i]=nCr2(n,r,num[i][0],num[i][1]);
                }
            //cout<<n<<" "<<r<<" "<<num[i]<<" "<<rem[i]<<endl;
            }
            OUTLL(CRT(num,rem,siz));
 
        }
    }
    else if(st==4)
    {
        while(t--)
        {
            INPLL(n);INPLL(r);INPLL(m);
            f(100,m);
            siz=calculateBrute(m,num);
            REP(i,siz)
            {
                if(num[i][1]==1)
                    rem[i]=nCr(n,r,num[i][0]);
                else
                {
                    //cout<<num[i][0]<<" "<<num[i][1]<<endl;
                    rem[i]=nCr2(n,r,num[i][0],num[i][1]);
                }
                //cout<<num[i][0]<<" "<<num[i][1]<<" "<<rem[i]<<" "<<endl;
            }
            OUTLL(CRT(num,rem,siz));
        }
    }
    return 0;
}
