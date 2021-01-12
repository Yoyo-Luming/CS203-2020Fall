#include <iostream>
#include <string>
#define mymin(a,b) a<b?a:b

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,p,pre,suf,minlen=1000,maxlen,pos;
	cin >> n;
	string s[n],prefix,suffix;
	for(int i=0;i<n;i++){
		cin >> s[i];
		minlen=mymin(minlen,s[i].size());
	}
	pre = suf = minlen;
	prefix=s[0].substr(0,minlen);
	suffix=s[0].substr(s[0].size()-minlen,s[0].size());
	for(int i=1;i<n;i++){
		for(int j=0;j<pre;j++){
			if(s[i][j] != prefix[j]){
				prefix = prefix.substr(0,j+1);
				pre = j;
				break;
			}
		}
		for(int j=0;j<suf;j++){
			if(s[i][s[i].size()-j-1] != suffix[suf-j-1]){
				suffix = suffix.substr(suf-j,suf);
				suf = j;
				break;
			}
		}
	}
	printf("%d",suf*pre);
}
