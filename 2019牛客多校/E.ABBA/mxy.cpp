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
ll dp[2005][2005];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int k=n+m;
        for(int i=0;i<=k;++i)
            for(int j=0;j<=k;++j)
                dp[i][j]=0;
        dp[0][0]=1;
        for(int i=0;i<=k;++i)
            for(int j=0;j<=k;++j)
            {
                if(j+n>=i&&i)
                    dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                if(i+m>=j&&j)
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            }
        cout<<dp[k][k]<<endl;
    }
}
