#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <vector>
#define long long ll

using namespace std;

const int MAX_N = 200005;
int  vis[MAX_N];
int n, k, s, ans;
vector<int> Tree[MAX_N];

inline const int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){ if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}

void dfs(int x,int pre,int num){
	if(vis[x]&&ans<num){
		ans=num;
		s=x;
	}
	for(int i=0;i<Tree[x].size();++i){
		int u=Tree[x][i];
		if(u!=pre){
			dfs(u,x,num+1);		
		}
	}
}

int main(){
	int T = read();
	while(T--){
		ans=0, s=0;
		n = read();
		k = read();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			Tree[u].push_back(v);
			Tree[v].push_back(u);
		}
		int temp;
		for(int i=1;i<=k;++i){
			temp = read();
			vis[temp] = 1;
		}
		dfs(temp,0,1);
		dfs(s,0,1);
		printf("%d\n",ans/2);
		for(int i=0;i<MAX_N;i++){
			Tree[i].clear();
			vis[i] = 0;
		}		
	}
	return 0;
}
/*
1
4 2
1 2
2 4
2 3
1 3

ans:
1
*/
