#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T, n, ans;
	long long sum[100000];
	double k;
	long long num;
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n >> k;
		int i = 1;
		sum[0] = 0;
		while(1){
			sum[i] = (1-pow(k,i))/(1-k); 
			if(sum[i-1] < n && sum[i] >= n){
				ans = n - sum[i-1];
				ans += (sum[i] - sum[i-1] - ans)/k ;
				break;
			}
			i++;
		}
		cout << ans << endl;	
	}	
}
/*
2
5 2
10 3

*/
