#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define ll long long
#define ull unsigned long long

using namespace std;

const ull B = 1e8+7;    
const int N = 100010;
char a[N],b[N],tmp[N];
int n,m;
ull ha[N],base[N];
 
int find(int l){
    int pos=m-l+1;
    ull hb=0,temp=0;
    for(int i=0;i<l;++i){
        temp=temp*B+a[i];    	
	}
        
    ha[0]=temp;
    for(int i=0;i+l<=n;++i){
        ha[i+1]=ha[i]*B+a[i+l]-a[i]*base[l];    	
	}
        
    sort(ha,ha+n-l+1);
    
    for(int i=0;i<l;++i){
        hb=hb*B+b[i];    	
	}
        
    for(int j=0;j<pos;++j){
        if(binary_search(ha,ha+n-l+1,hb)){
            return 1;
        }
        hb=hb*B+b[j+l]-b[j]*base[l];
    }
    return 0;
}
 
int getMax(){
    n=strlen(a),m=strlen(b);
    if(n<m){
        swap(n,m);
        strcpy(tmp,a);
        strcpy(a,b);
        strcpy(b,tmp);
    }
    int ans=0,up=m+1,mid;
    while(up>ans+1){
        mid=(ans+up)/2;
        if(find(mid)){
        	ans=mid;
		}else{
			up=mid;
		}
    }
    return ans;
}
 
int main(){
	ios::sync_with_stdio(false);
    base[0]=1;
    for(int i=1;i<N;++i){
        base[i]=base[i-1]*B;    	
	}
    cin >> a >> b; 
	printf("%d",getMax());
    return 0;
}
/*
B.Tang
B.Tarjan

aabb
acbb

rtrwiuojih
shuhuehuhuhjih
*/

