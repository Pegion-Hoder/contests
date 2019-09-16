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
const int maxn=1e5+2;
set<int>v;
vector<int>li[maxn];
char s[maxn],t[maxn];
ull h[26];
ull ha[maxn];
pair<pii,ull>q[20001];
int r[20001],len[20001];
void init()
{
    for(int i=0;i<26;++i)
    {
        h[i]=1;
        int j=rand()%20;
        while(j--)
        {
            int v=rand();
            if(v!=0)
                h[i]*=rand();
        }
    }
}
inline ull hs(int l,int r)
{
    if(l>r)
        return 0;
    ull v=0;
    for(int i=l;i<=r;++i)
        v+=h[t[i]-'a'];
    return v;
}
int main()
{
#ifdef localll
freopen("in.txt","r",stdin);
#endif // localll
init();
    int _,cas=1;
    for(scanf("%d",&_);_;--_)
    {
        v.clear();
        scanf("%s",s);
        int m,n=strlen(s);
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf("%s",t);
            int l=strlen(t);
            q[i].fi=mp(t[0]-'a',t[l-1]-'a');
            q[i].se=hs(1,l-2);
            v.insert(l);
            len[i]=l;
        }
        ha[0]=h[s[0]-'a'];
        for(int i=1;i<n;++i)
            ha[i]=ha[i-1]+h[s[i]-'a'];
        for(int l:v)
            li[l].clear();
        for(int i=0;i<m;++i)
            li[len[i]].push_back(i);
        for(int l:v)
        {
            map<ull,int>p[26][26];
            for(int k:li[l]){
                p[q[k].fi.fi][q[k].fi.se][q[k].se]=0;
            }
            for(int i=0;i<=n-l;++i)
            {
                int lc=s[i]-'a',rc=s[i+l-1]-'a';
                ull val=0;
                int L=i+1,R=i+l-2;
                if(L<=R)
                    val=ha[R]-ha[L-1];
                if(p[lc][rc].count(val))
                    ++p[lc][rc][val];
            }
            for(int k:li[l])
                r[k]=p[q[k].fi.fi][q[k].fi.se][q[k].se];
        }
        for(int i=0;i<m;++i)
            printf("%d\n",r[i]);
    }

#ifdef localll
printf("\n\n*********OK************\n\n");
#endif // localll
}
