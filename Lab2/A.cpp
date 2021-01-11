#include<iostream>

using namespace std;

int main() {
	long long n=0,m=0,a=1;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >>m;
		a = m * (m+1)%1000000007;
		a = ((a * a)%1000000007)*250000002%1000000007;
		cout << a << endl;
	}
}