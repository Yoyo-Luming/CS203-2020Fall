#pragma GCC optimize(3, "Ofast", "inline")
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdlib> 
#define MAXN 1000006
#define ll long long

using namespace std;

int n, m;

struct node{
	int u,v,w;
}e[MAXN];

int fa[MAXN], cnt, num;
ll sum;

void add(int x, int y, int w){
	e[++ cnt].u = x;
	e[cnt].v = y;
	e[cnt].w = w;
}

bool cmp(node x, node y){
	return x.w < y.w;
}

int find(int x){
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}


void kruskal(){
	for(int i=1;i<=cnt;++i){
		int x = find(e[i].u);
		int y = find(e[i].v);
		if(x == y){
			continue;
		} 
		fa[x] = y;
		sum += e[i].w;
		if(++ num == n - 1){
			break;
		} 
	}
}

inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}

int main(){
	n = read();
	m = read();
	for(int i=1;i<=n;++i){
		 fa[i] = i;
	}
	while(m --){
		int x=read(), y=read(), w=read();
		add(x, y, w);
	}
	sort(e + 1, e + 1 + cnt, cmp);
	kruskal();
	printf("%lld",sum);
	return 0;
}
/*
4 4
1 2 2
2 3 2
3 4 2
4 1 2
*/ 
