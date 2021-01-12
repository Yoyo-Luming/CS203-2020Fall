#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define ll long long 
#define MAXN 100005

using namespace std;

vector<vector<int> > g; 
int fa[MAXN],a,b;
ll cnta=0,cntb=0;
vector<int> temp,num;
queue<vector<int> > q;

inline void dfs1(int x){
	num.push_back(x);
	q.push(num);
	num.clear();
	while(!q.empty()){
		temp = q.front();
		for(int i=0;i<temp.size();++i){
			if(fa[temp[i]] == 0){
				if(temp[i]==b){
					continue;
				}
				fa[temp[i]] = x;
				q.push(g[temp[i]]);	
 		 	}
		}
		q.pop();
	}
}

inline void dfs2(int x){
	num.push_back(x);
	q.push(num);
	num.clear();
	while(!q.empty()){
		temp = q.front();
		for(int i=0;i<temp.size();++i){
			if(fa[temp[i]] == 0){
				if(temp[i]==a){
					continue;
				}
				fa[temp[i]] = x;
				q.push(g[temp[i]]);	
 		 	}else if(fa[temp[i]] == a){
				if(temp[i]==a){
					continue;
				}
				fa[temp[i]] = a+x;
				q.push(g[temp[i]]);	 		 		
			}
		}
		q.pop();
	}
}

inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}

int main() {
	register int n = read(), m = read();
	a = read(), b = read();
	register ll ans = 0;
	g.resize(n+1);
	for(int i=0;i<m;++i) {
		int p1 = read(), p2 = read();
		g[p1].push_back(p2);
		g[p2].push_back(p1);
	}
	
	for(int i=0;i<=n;++i){
		fa[i] = 0;
	}
	
	dfs1(a);
	dfs2(b);
	
	
	for(int i=1;i<=n;++i){
		if(fa[i]==a && i!=a){
			++cnta;
		}else if(fa[i]==b && i!=b){
			++cntb;
		}
	}
	//cout << cnta << " " <<cntb << endl;
	ans = cnta * cntb;
	printf("%lld",ans);
	return 0;
} 
/*
7 7 3 5
1 2
2 3
3 4
4 5
5 6
6 7
7 5
*/
