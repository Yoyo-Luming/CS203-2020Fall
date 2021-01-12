#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

inline long long read() {
    char ch = getchar();
    long long x = 0;
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
	long long sum[100000];
	sum[0] = 0;
	long long T=read();
	while(T--){
		long long n, i=1;
		n = read();
		while(1){
			sum[i] = pow(2,i) - 1; 
			if(sum[i-1] < n && sum[i] >= n){
				cout << i << endl;
				break;
			}
			i++;
		}
	}
}
