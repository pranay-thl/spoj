#include<bits/stdc++.h>
using namespace std;
int mpow(int a,int b)
{
    if(b==0)
        return 1;
    int ans=(mpow(a,b/2))%10;
    if(b%2==0)
        return (ans*ans)%10;
    else
        return (ans*ans*a)%10;
}
int main()
{
    int t,a,b,ans;
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>a>>b;
        cout<<mpow(a,b)<<endl;
    }
}