#pragma GCC optimize(3, "Ofast", "inline")
#include<cstdio>
#define MAXN 100005

using namespace std;

int fa[MAXN]; 

int get_fa(int a){
    if(fa[a]!=a){
        fa[a]=get_fa(fa[a]);   	
	}
    return fa[a];
}

int Merge(int a,int b){
    int fa_a=get_fa(a);
    int fa_b=get_fa(b);
    if(fa_a==fa_b){
        return 0;   	
	}  
	fa[fa_a]=fa_b;
    return 1;
}

inline int read() {
    char ch = getchar();
    int x = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;++i){
    	fa[i]=i;
	}
    int flag=0;
    for(int i=1;i<=m;++i){
        int a=read(),b=read();
        if(Merge(a,b)==0){
                flag=1;  
        }
    }
    if(flag==0){
    	printf("Good");	
	}else{
		printf("Bad");	
	}
    return 0;
}
/*
3 3
1 2
2 3
1 3
*/

