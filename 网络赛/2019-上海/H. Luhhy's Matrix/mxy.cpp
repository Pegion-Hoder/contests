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


const int SIZ=16;
const int maxn=5e4+5;
struct mat
{
    bitset<SIZ>a[SIZ];
    mat(){for(int i=0;i<SIZ;++i)a[i].reset();}
    void one()
    {
        for(int i=0;i<SIZ;++i)
            a[i].reset(),a[i].set(i);
    }
    mat operator*(const mat &t)const
    {
        mat r;
        for(int i=0;i<SIZ;++i)
            for(int j=0;j<SIZ;++j)
                if(a[i][j])
                    r.a[i]^=t.a[j];
        return r;
    }
    void show()
    {
        for(int i=0;i<SIZ;++i)
            cout<<a[i]<<endl;
    }
}a[maxn],now,ri;

inline void go(uint seed)
{
    for(int i=0;i<16;++i)
    {
        seed^=seed*seed+15;
        now.a[i]=(bitset<SIZ>)seed;
    }
}
uint pp[16][16],p1[16],p2[16];
inline uint val(const mat &t)
{
    uint r=0;
    for(int i=0;i<SIZ;++i)
        for(int j=0;j<SIZ;++j)
            if(t.a[i][j])
                r+=pp[i][j];
    return r;
}
int main()
{
#ifdef localll
freopen("in.txt","r",stdin);
#endif // localll
p1[0]=p2[0]=1;
for(int i=1;i<16;++i)
p1[i]=p1[i-1]*17u,p2[i]=p2[i-1]*19u;
for(int i=0;i<16;++i)
for(int j=0;j<16;++j)
pp[i][j]=p1[i]*p2[j];
    int _;
    for(scanf("%d",&_);_;--_)
    {
        int n;
        scanf("%d",&n);
        a[0].one();
        ri.one();
        int t;
        uint ans=0,sd;
        int l=1,r=n;
        for(int i=0;i<n;++i)
        {
            scanf("%d%u",&t,&sd);
            if(t==1)
            {
                sd^=ans;
                go(sd);
                a[r--]=now;
                ri=now*ri;
            }
            else
            {
                if(l==1)
                {
                    while(r!=n)
                    {
                        a[l++]=a[++r];
                        a[l-1]=a[l-2]*a[l-1];
                    }
                    ri.one();
                }
                --l;
            }
            mat re=ri*a[l-1];
            ans=0;
            if(l!=1||r!=n)
                ans=val(re);
            printf("%u\n",ans);
        }
    }








#ifdef localll
printf("\n\n\n\n*********OK************\n\n");
#endif // localll


}
