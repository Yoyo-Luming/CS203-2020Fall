#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include <iostream>
#include <string>
#define mymin(a,b) a<b?a:b

using namespace std;

inline const int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){ if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}

int main(){
	int n = read();
	string s[n+1];
	int num[n+1];
	for(int i=1;i<=n;i++){
		cin >> s[i];
		num[i]=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j] != s[i][s[i].size()-1-j]){
				break;
			}
			num[i]++;
		}
	}
	int T = read();
	int i,j,cnt=0,x,y;
	char ans; 
	while(T--){
		x = y = 0;
		i = read();
		j = read();
		int minlen = min(s[i].size(),s[j].size());
		for(int k=0;k<minlen;k++){
			if(s[i][k] !=s[j][s[j].size()-1-k]){
				break;
			}
			x++;
		}
		for(int k=0;k<minlen;k++){
			if(s[j][k] !=s[i][s[i].size()-1-k]){
				break;
			}
			y++;
		}
		cin >> ans;
		if(ans=='<'){
			if(x < y){
					cnt++;
				}
		}else if(ans=='>'){
			if(x > y){
					cnt++;
				}
		}else{
			if(x == y){
					cnt++;
				}
		}	
	}
	printf("%d",cnt);
}
