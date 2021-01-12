#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <vector>
#include<algorithm>
#define ll long long
#define MAXN 100005

using namespace std;

int deep[MAXN], deepest[MAXN], pre[MAXN];
vector<int> coco[MAXN];
ll ans = 0;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline int mymax(int x, int y){return x>y?x:y;}
inline int mymin(int x, int y){return x<y?x:y;}

void dfs(int type, int cur, int x){
	if(type == 0){
		deep[cur] = deep[x] + 1;
		deepest[cur] = deep[cur];
		for(int i=0;i<coco[cur].size();++i){
			int temp = coco[cur][i];
			if(temp != x){
				dfs(0, temp, cur);
				deepest[cur] = mymax(deepest[cur], deepest[temp]);
			}
		}
	}else{
		pre[cur] = cur;
		for(int i=0;i<coco[cur].size();++i){
			int temp = coco[cur][i];
			if(temp != x){
				ans += mymin(deep[cur], deep[pre[cur]] - deep[cur] + 1);
				dfs(1, temp, cur);
				pre[cur] = pre[temp];
			}
		} 
	}
}

bool cmp(int x, int y){
    return deepest[x] < deepest[y];
}

int main(){
	int T = read();
	while(T--){
		int n = read(), temp;
		ans = 0;
		for(int i=2;i<=n;++i){
			temp = read();
			coco[i].push_back(temp);
			coco[temp].push_back(i);
		}
		dfs(0, 1, 0);
		for(int i=1;i<=n;++i){
			sort(coco[i].begin(),coco[i].end(),cmp);
		}
		dfs(1, 1, 0);
		printf("%lld\n",ans);
		for(int i=0;i<=n;++i){
			coco[i].clear();
		}
	}
}
/*
2
3 
1 1 
6 
1 2 3 4 4 

1
13
1 2 3 3 5 3 7 8 3 10 11 12
*/
