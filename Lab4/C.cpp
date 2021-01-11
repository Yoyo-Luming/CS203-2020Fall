#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

typedef struct POLYNOMIAL{
	ll xishu;
	ll mi;
}Pol;

Pol x[200000];


ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}

bool cmp(Pol x1,Pol x2){
	return x1.mi <= x2.mi;
}

int main() {
	ll c = read_ll();
	for(int i=0;i<c;i++){
		ll n1 = read_ll();
		Pol x1[n1];
		for(int j=0;j<n1;j++){
			x1[j].xishu = read_ll();
			x1[j].mi = read_ll();
		}
		ll n2 = read_ll();
		Pol x2[n2];
		for(int j=0;j<n2;j++){
			x2[j].xishu = read_ll();
			x2[j].mi = read_ll();
		}
		ll index1=0,index2=0,index=0;
		while(index1<n1||index2<n2){
			if(index1<n1 && (index2 >=n2 || x1[index1].mi <= x2[index2].mi) ){
				if(index2 >=n2 || (index2 <n2 && x1[index1].mi < x2[index2].mi)){
					if(x1[index1].xishu != 0){
						x[index].mi = x1[index1].mi;
						x[index].xishu = x1[index1].xishu;
					}else{
						index--;
					}
					index++;
					index1++;
				}else{
					if(x1[index1].xishu + x2[index2].xishu !=0){
						x[index].mi = x1[index1].mi;
						x[index].xishu = x1[index1].xishu + x2[index2].xishu;
					}else{
						index--;
					}
					index++;
					index1++;
					index2++;
				}
			}else{
				if(x2[index2].xishu !=0){
					x[index].mi = x2[index2].mi;
					x[index].xishu = x2[index2].xishu;
				}else{
					index--;
				}
				index++;
				index2++;
			}
		}
		for(int j=0;j<index;j++){
			while(index >1 && j < index && x[j].mi == x[j+1].mi){
				x[j+1].xishu = x[j+1].xishu+x[j].xishu;
				j++;
			}
			if(x[j].xishu == 0){
				if(j ==index-1){
					printf("0");
				}
				continue;
			}
			if(x[j].mi ==0){
				printf("%d",x[j].xishu);
				if(j != index-1 && x[j+1].xishu > 0){
					printf("+");
				}
				continue;
			}
			if(j != index-1){
				if(x[j].xishu != -1 && x[j].xishu != 1 && x[j].mi != 1){
					printf("%dx^%d",x[j].xishu,x[j].mi);
				}else if(x[j].xishu == 1 && x[j].mi != 1){
					printf("x^%d",x[j].mi);
				}else if(x[j].xishu == -1 && x[j].mi != 1){
					printf("-x^%d",x[j].mi);
				}else if(x[j].xishu == -1 && x[j].mi == 1){
					printf("-x");
				}else if(x[j].xishu != -1 && x[j].xishu != 1 && x[j].mi == 1){
					printf("%dx",x[j].xishu);
				}else{
					printf("x");
				}
				if(x[j+1].xishu > 0){
					printf("+");
				}
			}else{
				if(x[j].xishu != -1 && x[j].xishu != 1 && x[j].mi != 1){
					printf("%dx^%d",x[j].xishu,x[j].mi);
				}else if(x[j].xishu == 1 && x[j].mi != 1){
					printf("x^%d",x[j].mi);
				}else if(x[j].xishu == -1 && x[j].mi != 1){
					printf("-x^%d",x[j].mi);
				}else if(x[j].xishu == -1 && x[j].mi == 1){
					printf("-x");
				}else if(x[j].xishu != -1 && x[j].xishu != 1 && x[j].mi == 1){
					printf("%dx",x[j].xishu);
				}else{
					printf("x");
				}
			}
		}
		if(index ==0){
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
