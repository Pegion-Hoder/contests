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
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|1
#define fi first
#define se second
const double eps=1e-10;
inline int dcmp(double x){if(x<-eps)return -1;if(x>eps)return 1;return 0;}
//-----------------------------------------------head
const int maxn=1e3;
pii a[maxn*2];
int main()
{
#ifdef localll
freopen("in.txt","r",stdin);
#endif // localll

    int _,cas=1;
    for(scanf("%d",&_);_;--_)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        m<<=1;
        for(int i=0;i<m;++i)
        {
            scanf("%d",&a[i].fi);
            if(i&1)
                a[i].se=1;
            else
                a[i].se=0;
        }
        sort(a,a+m);
        int r=0,k=0;
        bool v=0;
        for(int i=0;i<m;++i)
        {
            if(v)
                r+=a[i].fi-k+a[i].se;
            k=a[i].fi+a[i].se;
            v=!v;
        }
        printf("Case #%d: %d\n",cas++,r);
    }

}
