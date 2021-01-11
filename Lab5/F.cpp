#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mymax(a,b) a>b?a:b
#define mymin(a,b) a<b?a:b
#define LL long long

using namespace std;

inline const int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){ if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}

int main(){
	int k = read();
	int n = read();
	int num[n];
	int jud=0;
	LL ans=0,minnum=0,maxnum=0,temmin,temmax;
	for(int i=0;i<n;i++){
		num[i] = read();
	}
	for(int i=0;i<n-ans;i++){
//		if(jud!=0 && num[i] != temmin && num[i] != temmax){
//			continue;
//		}
		minnum = num[i];
		maxnum = num[i]; 
		for(int j=i+1;j<n;j++){
			minnum = mymin(minnum,num[j]);
			maxnum = mymax(maxnum,num[j]);
			
			if((maxnum-minnum)>k){
				break;
			}else{
				jud=1;
				ans = mymax(ans,j-i);
//				temmin = minnum;
//				temmax = maxnum;
			}
		}
	}
	printf("%d",ans+1); 
	
}
/*
3 9
5 1 3 5 8 6 6 9 10
*/ 
