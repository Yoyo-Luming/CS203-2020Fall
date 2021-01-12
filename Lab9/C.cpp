#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 100005

using namespace std;

int n,m,i,in[MAXN];
priority_queue<int,vector<int>,greater<int> >q;
vector<int>e[MAXN],p;

void init(){
	for(int i=1;i<=n;++i){
		e[i].clear(),in[i]=0;
	}
	while(!q.empty()){
		q.pop();
	}
	p.clear();
}

void topo(){
	for(i=1;i<=n;++i)if(in[i]==0) q.push(i);
	while (!q.empty()){
		int now=q.top();q.pop();
		p.push_back(now);
		for(i=0;i<e[now].size();++i)
			if (--in[e[now][i]]==0) q.push(e[now][i]);
	}
	for(i=0;i<p.size()-1;++i)printf("%d ",p[i]);
	printf("%d",p[p.size()-1]);
}

inline int read() {
    char ch = getchar();
    int x = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main(){	
	n= read();
	m = read();
	init();
	while(m--){
		int u=read(),v=read();
		e[u].push_back(v);
		++in[v];
	}
	topo();
	return 0;
}
/*
3 3
1 2
2 3
1 3
*/
