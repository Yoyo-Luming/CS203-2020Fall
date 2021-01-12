#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 100007
 
using namespace std;

queue<int> myqueue;
vector<int> fa[MAX_N];

inline const int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){ if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}

void myprint(){
	while(myqueue.size()>0){
		int temp = myqueue.front();
		myqueue.pop();
		for(int i=0;i<fa[temp].size();++i){
			printf("%d ",fa[temp][i]);
			myqueue.push(fa[temp][i]);
		}
	}
}

void myclear(){
	for(int i=0;i<MAX_N;++i){
		fa[i].clear();
	}
}

int main(){
	int T = read();
	while(T--){
		register int n = read(), temp, i;
		
		for(i=2;i<=n;++i)
			fa[read()].push_back(i);
			
		for(i=1;i<=n;++i)
			sort(fa[i].begin(),fa[i].end());
		
		myqueue.push(1);
		printf("%d ",1);
		myprint();
		printf("\n");
		
		myclear();
	}
}

/*
2
4
1 1 1
5
1 1 3 2
*/
