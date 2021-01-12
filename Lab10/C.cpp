#pragma GCC optimize(3, "Ofast", "inline")
#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <cmath> 
#define MAXN 302
#define inf 99999999999
 
using namespace std;
 
struct node{
	int x,y;
	double dis;
	bool operator < (const node &a) const{return dis>a.dis;}
};

int dic[4][2]={0,1,1,0,-1,0,0,-1};
int at[MAXN][MAXN];
double mp[MAXN][MAXN];
double dis[MAXN][MAXN];
bool flag[MAXN][MAXN];
int v=1,r,c;

void init(){
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			dis[i][j]=inf;
	memset(flag,0,sizeof(flag));
}

double get_cost(int h){
	return v*1.0*pow(2*1.0,at[1][1]-h);
}

bool jud(int x,int y){
	if(x>0&&x<=r&&y>0&&y<=c)
		return true;
	else 
		return false;
}

void dijkstra(){
	priority_queue<node> q;
	node now,next;
	now.x=1;
	now.y=1;
	now.dis=0;
	dis[1][1]=0;
	q.push(now);
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(flag[now.x][now.y]) continue;
		flag[now.x][now.y]=true;
		if(now.x==r&&now.y==c)
			break;
		for(int i=0;i<4;++i){
			int x=now.x+dic[i][0];
			int y=now.y+dic[i][1];
			if(!jud(x,y)) continue;
			if(!flag[x][y]&&dis[x][y]>now.dis+1.0/mp[now.x][now.y]){
				dis[x][y]=now.dis+1.0/mp[now.x][now.y];
				next.x=x;
				next.y=y;
				next.dis=dis[x][y];
				q.push(next);
			}
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
	r = read();
	c = read();
	init();
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			at[i][j] = read();
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			mp[i][j]=get_cost(at[i][j]);
	dijkstra();
	printf("%.2f",dis[r][c]);
	return 0;
}

/*
2 3
1 2 3
4 5 6

ans:
7.00 
*/
