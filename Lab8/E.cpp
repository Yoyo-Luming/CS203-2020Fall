#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100001

using namespace std;

struct Node{
    int left,right,cnt;
}mytree[MAXN*20];

int cur=0,rt[MAXN],num[MAXN],sorted[MAXN];

inline void push_up(int x){
    mytree[x].cnt = mytree[mytree[x].left].cnt + mytree[mytree[x].right].cnt;
}

int build(int l,int r){
    int k=cur++;
    if(l==r){
        mytree[k].cnt=0;
        return k;
    }
    int mid=(l+r)>>1;
    mytree[k].left=build(l,mid);
    mytree[k].right=build(mid+1,r);
    push_up(k);
    return k;
}

int update(int x,int l,int r,int pos,int val){
    int k=cur++;
    mytree[k]=mytree[x];
    if(l==pos&&r==pos){
        mytree[k].cnt+=val;
        return k;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
    	mytree[k].left=update(mytree[x].left,l,mid,pos,val);	
	} else {
		mytree[k].right=update(mytree[x].right,mid+1,r,pos,val);
	}
    push_up(k);
    return k;
}

int find(int l,int r,int x,int v,int kth){
    if(l==r) return l;
    int mid = (l+r)/2;
    int res = mytree[mytree[v].left].cnt-mytree[mytree[x].left].cnt;
    if(kth<=res){
    	return find(l,mid,mytree[x].left,mytree[v].left,kth);	
	} else {
		return find(mid+1,r,mytree[x].right,mytree[v].right,kth-res);	
	}
}

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
    int n=read(), s = read(), m = n-s+1, ans, cnt=1;
    
    for(int i=1;i<=n;i++){
    	num[i] = read();
        sorted[i]=num[i];
    }
    
    sort(sorted+1,sorted+1+n);
    
    for(int i=2;i<=n;++i){
    	if(sorted[i]!=sorted[cnt]){
    		sorted[++cnt]=sorted[i];		
		}
	}
	
    rt[0]=build(1,cnt);
    
    for(int i=1;i<=n;++i){
        int p=lower_bound(sorted+1,sorted+1+cnt,num[i])-sorted;
        rt[i]=update(rt[i-1],1,cnt,p,1);
    }
    
    for(int i=0;i<m;++i){
        int winl=i,winr=i+s,k=read();
        ans = sorted[find(1,cnt,rt[winl],rt[winr],k)];
        printf("%d\n",ans);
    }
    
    return 0;
}

/*
6 3
201 91 29 13 11 -5
3 1 2 1

6 3
1 2 3 4 5 6
1 1 1 1
*/
