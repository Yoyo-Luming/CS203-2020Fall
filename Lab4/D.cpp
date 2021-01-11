#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>

using namespace std;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main(){
	int c;
	c = read();
	for(int i=0;i<c;i++){
		priority_queue<int,vector<int>,less<int> > dui1;
		priority_queue<int,vector<int>,greater<int> > dui2;
		int n = read();
		int num[500000];
		num[1] = read();
		int mid=num[1];
		printf("%d ", mid);
		for(int j=2;j<=n;j++){
			num[j] = read();
			if(num[j]>mid){
				dui2.push(num[j]); 
			}else{
				dui1.push(num[j]); 
			}
			if(j%2==1){
				while(dui1.size() != dui2.size()){
					if(dui1.size() > dui2.size()){
						dui2.push(mid);
						mid = dui1.top();
						dui1.pop();
					}else{
						dui1.push(mid);
						mid = dui2.top();
						dui2.pop();
					}
				}
				printf("%d ",mid);
			}
		}
		printf("\n");
	}
	return 0;
}
