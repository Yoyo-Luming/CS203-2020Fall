#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<cstdio>
#define MAXN 500005
#define ll long long
#define INF 800005

using namespace std;

long long dis[MAXN];
int u[MAXN],v[MAXN],w[MAXN],n,m,s=1,flag;

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
	n = read();
	m = read();
	for(int i=1;i<=m;++i){
		u[i] = read();
		v[i] = read();
		w[i] = read();
	}
	for(int i=1;i<=n;++i){
		dis[i] = INF;
	}
	dis[s]=0;
	for(int k=1;k<=n-1;++k){
		flag=0;
		for(int i=1;i<=m;++i){
			if(dis[v[i]]>dis[u[i]]+w[i]){
				dis[v[i]]=dis[u[i]]+w[i];
				flag=1;
			}	
		}
		if(flag==0)
			break; 
	}
	if(dis[n]>=INF || dis[n]<=0){
		printf("-1");
	}else{
		printf("%d",dis[n]);
	}
	return 0;
}
/*
4 5
1 2 1
2 4 1
2 3 2
3 4 1
1 3 1

3 1
1 2 2

4 2
2 3 2
1 3 1

8 4
1 3 2
1 3 1
1 3 1
1 3 2

8 2
1 8 2
1 2 1
*/
