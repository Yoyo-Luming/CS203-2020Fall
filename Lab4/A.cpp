#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

ll next[100000];

ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}

int main() {
	ll c = read_ll();
	for(int i=0;i<c;i++){
		ll n = read_ll();
		ll m = read_ll();
		for (int j = 0; j < n; j++) next[j] = j + 1;
		next[n] = 1;
		ll position = 0;
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b < m; b++)
				position = next[position];
			printf("%d ", next[position]);
			next[position] = next[next[position]];
		}
		printf("\n");
	}
	return 0;
}
