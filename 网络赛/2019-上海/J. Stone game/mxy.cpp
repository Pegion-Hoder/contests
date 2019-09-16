//#pragma GCC optimize(2)


#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>*/
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//void err(istream_iterator<string> it){cerr<<endl;}
//template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args){cerr << *it << " = " << a << " , ";err(++it, args...);}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define mem(a,b) memset((a),b,sizeof((a)))
#define fpre(x) cout<<fixed<<setprecision(x)
#define clr(v) (v).clear()
#define pii pair<int,int>
#define pdd pair<double,double>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define ushort unsigned short
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|1
#define fi first
#define se second
const double eps=1e-10;
inline int dcmp(double x){if(x<-eps)return -1;if(x>eps)return 1;return 0;}
//-----------------------------------------------head


const int maxn=305;
ll dp[maxn*505];
ll a[maxn];
const ll mod=1e9+7;
int main()
{
#ifdef localll
freopen("in.txt","r",stdin);
#endif // localll

    int _;
    for(scanf("%d",&_);_;--_)
    {
        int n;
        ll tol=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%lld",a+i),tol+=a[i];
        sort(a,a+n);
        mem(dp,0);
        dp[0]=1;
        ll ans=0;
        for(int i=n-1;~i;--i)
        {
            for(int k=tol;k>=a[i];--k)
            {
                (dp[k]+=dp[k-a[i]])%=mod;
                if(k>=tol-k&&tol-k>=k-a[i])
                    (ans+=dp[k-a[i]])%=mod;
            }
        }
        printf("%lld\n",ans);
    }








#ifdef localll
printf("\n\n\n\n*********OK************\n\n");
#endif // localll


}
