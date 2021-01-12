#pragma GCC optimize(3, "Ofast", "inline")
#include <cstdio>
#include <vector>
#include <string.h>
#define MAXN 100005
#define ll long long

using namespace std;

vector<int>g1[MAXN];
vector<int>g2[MAXN];
int flag[MAXN];
int cnt=0;

void dfs1(int n){
    flag[n]=1;
    ++cnt;
    for(int i=0;i<g1[n].size();++i){
        int x=g1[n].at(i);
        if(flag[x]==0)
            dfs1(x);
    }
}
void dfs2(int n){
    flag[n]=1;
    ++cnt;
    for(int i=0;i<g2[n].size();++i){
        int x=g2[n].at(i);
        if(flag[x]==0)
            dfs2(x);
    }
}
 
inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
 
int main(){
    int n=read(),m=read(),a,b,jud = 0;
    for(int i=1;i<=m;i++){
        a = read();
        b = read();
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    memset(flag,0,sizeof(flag));
    cnt=0;
    dfs1(1);
    if(cnt!=n){
        printf("wawawa");
        jud = 1;
    }
    if(jud ==0){
    	memset(flag,0,sizeof(flag));
    	cnt=0;
    	dfs2(1);
    	if(cnt!=n){
        	printf("wawawa");
        	jud = 1;
    	}
	}
    if(jud == 0){
    	printf("Bravo");
	}
    return 0;
}
/*
3 3
1 2
2 3
3 2
*/
