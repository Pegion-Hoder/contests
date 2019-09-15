#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),b,sizeof((a)))
#define clr(v) (v).clear()
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define Endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|1
#define pii pair<int,int>
 
const ll mod=1e9+7;
inline ll qp(ll x,ll n)
{
    ll r=1;
    while(n)
    {
        if(n&1)
            r=r*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return r;
}
inline ll inv(ll n,ll m)
{
    return n*qp(m,mod-2)%mod;
}
ll a[1005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
            scanf("%lld",a+i);
        ll res=0;
        for(int i=0;i<n;++i)
        {
            ll t=1;
            for(int j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                t=(a[j]*a[j]-a[i]*a[i])%mod*t%mod;
            }
            t=inv(1,t*a[i]%mod);
            res+=t;
            res%=mod;
            res+=mod;
        }
        printf("%lld\n",inv(res,2));
    }
}
