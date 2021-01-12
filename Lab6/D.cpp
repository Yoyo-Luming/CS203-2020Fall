#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include<cstring>
#include <iostream> 
#include <string>
#define MAXN 200010

using namespace std;

char s[MAXN];

void Getnext(int next[],string s) {
    next[0] = -1;
    int i = 0, j = -1;
    while(i < s.size()) {
        if(j == -1 || s[i] == s[j]){
            next[++i] = ++j;        	
		}else{
			j = next[j];
		}
    }
}

inline string read(){
	char ch=getchar();
	string st1="";
	while (ch!=' ' && ch!='\n') 
	  st1+=ch,ch=getchar();
	return st1;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
    while(T--){
        string s;
        cin >> s; 
        int len=s.size();
        int next[len+1];
        Getnext(next,s);
        int t=len-next[len];
        if(t==len){
        	printf("%d\n",len);
		} else if(len%t){
			printf("%d\n",t-len%t);
		} else{
			printf("0\n");
		} 
    }
    return 0;
}

