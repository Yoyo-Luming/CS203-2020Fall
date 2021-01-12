#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <list>
#include <cstdio>

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

void find(int n, int *pre, int *in, int* post){
	if(n <= 0){
		return;
	}
	int root = pre[0], p;
	for(int i=0;i<n;++i){
		if(in[i] == root){
			p = i;
			break;
		}
	}
	find(p, pre+1,in,post);
	find(n-p-1,pre+p+1,in+p+1,post+p);
	post[n-1] = pre[0];	
}

int main(){
	int T = read();
	while(T--){
		int n = read();
		int pre[n], in[n], post[n];
		for(int i=0;i<n;++i){
			pre[i] = read();
		}
		for(int i=0;i<n;++i){
			in[i] = read();
		}
		find(n,pre,in,post);
		for(int i=0;i<n;++i){
			printf("%d ",post[i]);
		}
		printf("\n");
	}
}
