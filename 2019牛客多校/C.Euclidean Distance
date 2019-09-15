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
 
ll a[100005];
int main()
{
    int n;
    ll m;
    while(~scanf("%d%lld",&n,&m))
    {
    mem(a,0);
        for(int i=1;i<=n;++i)
            scanf("%lld",a+i);
        sort(a+1,a+n+1);reverse(a+1,a+n+1);
        ll v=0,st=1;
        for(int i=1;i<=n;++i)
        {
            st=i;
            if(i<n&&(a[i]-a[i+1])*i+v<=m)
            {
                v+=(a[i]-a[i+1])*i;
            }
            else break;
        }
        ll r1=m-v-a[st]*st;r1*=r1;
        for(int i=st+1;i<=n;++i)
            r1+=st*a[i]*a[i];
        ll r2=st*m*m;
        //cout<<st<<' '<<r1<<' '<<r2<<endl;
        ll g=__gcd(r1,r2);
        r1/=g;r2/=g;
        if(r2==1)
            printf("%lld\n",r1);
        else printf("%lld/%lld\n",r1,r2);
     
         
    }
         
}
