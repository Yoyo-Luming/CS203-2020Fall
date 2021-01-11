#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>

int num[600000],temp,T,n,jud,i,j;

inline const int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){ if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}

int main(){
	T = read();
	while(T--){
		n= read();
		for(i=0;i<n;++i){
			num[i] = read();
		}
		int ans[n];
		for(i=0;i<n-1;++i){
			jud=0;
			temp = num[i];
			for(j=i+1;j<n;++j){
				if(temp < num[j]){
					ans[i] = j-i;
					++jud;
					break;
				}
			}
			if(jud==0){
				ans[i] = -1;
			}
		}
		ans[i] = -1;
		n = read();
		int index;
		for(int i=0;i<n;i++){
			index = read();
			printf("%d\n",ans[index-1]);
		}
	}
	return 0;
}
