#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),b,sizeof((a)))
#define clr(v) (v).clear()
#define pii pair<int,int>
#define mp make_pair
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

int a[100005],b[100005];
stack<int>q,w;
int main()
{
    IOS;
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        for(int i=0;i<n;++i)
            scanf("%d",b+i);
        while(!q.empty())
            q.pop();
        while(!w.empty())
            w.pop();
        int res=n-1;
        for(int i=0;i<n;++i)
        {
            while(!q.empty()&&q.top()>=a[i])
                q.pop();
            q.push(a[i]);
            while(!w.empty()&&w.top()>=b[i])
                w.pop();
            w.push(b[i]);
            if(q.size()!=w.size())
                break;
            res=i;
        }
        printf("%d\n",res+1);
    }
}
