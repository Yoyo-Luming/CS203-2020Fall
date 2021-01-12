#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstdio>

using namespace std;

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
	ios::sync_with_stdio(false);	
    int n, T = read();
	while(T--){
		n = read();
        priority_queue<int ,vector<int >,greater<int> >s;
        for(int i=0;i<n;++i){
            s.push(read());
        }
        int ans = 0;
        while(s.size() >= 2){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            int temp = a + b;
            ans += temp;
            s.push(temp);
        }
        printf("%d\n",ans);
   }
}
/*
1
4
1 4 2 6
*/
