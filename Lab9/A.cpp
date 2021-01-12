#pragma GCC optimize(3, "Ofast", "inline")
#include<cstdio>

using namespace std;

inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}

int main(){
	int T = read();
	while(T--){
		register int n= read(),cities[n][n], r = read(),c1,c2;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cities[i][j]=0;
			}
		}
		for(int i=0;i<r;++i){
			c1 = read(), c2 = read();
			++cities[c1-1][c2-1];
			//cities[c2][c1]++;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				printf("%d ",cities[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
