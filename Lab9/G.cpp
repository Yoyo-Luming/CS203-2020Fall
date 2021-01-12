#pragma GCC optimize(3, "Ofast", "inline")
#include <cstdio>
#include <vector>
#include <map>
#include <bitset>
#include <string.h>
#define ll long long
#define MAXN 100005
#define mod 1000000007

using namespace std;

ll a[MAXN],b[MAXN],dp[MAXN];
vector<int> G[MAXN];
int flag[MAXN],n,m;

struct Edge{
    int u,v;
    Edge(int u,int v){this->u=u,this->v=v;}
};

vector<Edge> E;

void init(int l,int r){
    E.clear();
    for(int i=l;i<=r;++i){
    	G[i].clear();
	} 
}

void add(int u,int v){
    E.push_back(Edge(u,v));
    G[u].push_back(E.size()-1);
}

ll dfs(int u){
    if(dp[u]!=-1){
    	return dp[u];
	} 

    dp[u]=0;
    int len = G[u].size();
    for(int i=0;i<len;++i){
        Edge &e=E[G[u][i]]; 
		int v=e.v;
        dp[u]=(dp[u]+b[v]+dfs(v))%mod;
    }
    return dp[u];
}

inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}

int main(){
	int T = read();
    while(T--){
    	n = read();
    	m = read();
        for(int i=1;i<=n;++i){
        	a[i] = read();
        	b[i] = read();
		} 
        init(1,n);
        
        memset(flag,0,sizeof(flag));
        
        for(int i=0;i<m;++i){
        	int x=read(), y=read();
            add(x,y);
            ++flag[y];
        }

        memset(dp,-1,sizeof(dp));
        
        for(int i=1;i<=n;++i){
            if(flag[i]==0){
            	dfs(i);
			} 
        }

        ll ans=0;
        
        for(int i=1;i<=n;++i){
        	ans = ( ans + (dp[i]*a[i]) % mod ) % mod;
		} 

        printf("%lld\n",ans);
    }
}
/*
3
3 3
1 1
1 1
1 1
1 2
1 3
2 3
2 2
1 0
0 2
1 2
1 2		
2 1
500000000 0
0 500000000
1 2

1
3 3
1 1
1 1
1 1
1 2
1 3
2 3
*/ 
