#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

inline const int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}


int main(){
	register int op1,op2,que1,que2,u,v,val,count=0,n,m;
	while(scanf("%d%d",&n,&m)==2){
		register int num[n][16];
		register int index[n][3];
		for(int i=0;i<n;i++){
			index[i][0] = 8;
			index[i][1] = 9;
			index[i][2] = 0;
		}
		for(int i=0;i<m;i++){
			op1 = read();
			if(op1==1){
				n = read()-1;
				op2 = read();
				if(op2==1){
					num[n][index[n][1]]=read();
					++index[n][1];
					++index[n][2];
				}else{
					num[n][index[n][0]]=read();
					--index[n][0];
					++index[n][2];
				}
			}else if(op1==2){
				n = read()-1;
				//printf("%d size: %d\n",n+1,index[n][2]);
				op2 = read();
				if(index[n][2]<=0){
					printf("-1\n");
					continue;
				} 
				if(op2==1){
					printf("%d\n",num[n][index[n][1]-1]);
					--index[n][1];
					--index[n][2];
				}else{
					printf("%d\n",num[n][index[n][0]+1]);
					++index[n][0];
					--index[n][2];
				}
			}else{
				u = read()-1;
				v = read()-1;
				op1 = read();
				if(op1==0){
					int len = index[v][2];
					for(int j=0;j<len;++j){
						num[u][index[u][1]]=num[v][index[v][0]+1];
						++index[u][1];
						++index[u][2];
						++index[v][0];
					}
				}else{
					int len = index[v][2];
					for(int j=0;j<len;++j){
						num[u][index[u][1]]=num[v][index[v][1]-1];
						++index[u][1];
						++index[u][2];
						--index[v][1];
					}
				}
				index[v][0] = 8;
				index[v][1] = 9;
				index[v][2] = 0;
			}
		}
		++count;		
	}
	return 0;
}
