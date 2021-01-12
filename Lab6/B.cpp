#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <string>

using namespace std; 
string s;

void Getnext(int next[]) {
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

int main(){
ios::sync_with_stdio(false);
	cin >> s;
	int next[s.size()+1];
	Getnext(next);
	for(int i=1;i<=s.size();i++){
		if(i<s.size()){
			printf("%d\n",next[i]);			
		}else{
			printf("%d",next[i]);
		}
	}
}



